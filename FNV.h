/*
* File: FNV.h
* Author: jtucker
*
* Created on 12_25_16
*/

#ifndef FNV_H
#define FNV_H

#include <array>
#include <memory>
#include <type_traits>
#include <iostream>
#include <iomanip>

#include <gmp.h>
#include <gmpxx.h>

	using byte = unsigned char ;
	
	static const uint32_t Prime = 0x01000193;
	static const uint32_t Seed = 0x811C9DC5;


	

	template< typename T > std::array< byte, sizeof(T) >  to_bytes( const T& object )
	{
			    std::array< byte, sizeof(T) > bytes ;

			    const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
			    const byte* end = begin + sizeof(T) ;
			    std::copy( begin, end, std::begin(bytes) ) ;

			    return bytes ;
	}

	template< typename T > T& from_bytes( const std::array< byte, sizeof(T) >& bytes, T& object )
	{
			    // http://en.cppreference.com/w/cpp/types/is_trivially_copyable
			    static_assert( std::is_trivially_copyable<T>::value, "not a TriviallyCopyable type" ) ;

			    byte* begin_object = reinterpret_cast< byte* >( std::addressof(object) ) ;
			    std::copy( std::begin(bytes), std::end(bytes), begin_object ) ;

			    return object ;
	}


	class FNV
	{
		public:
			FNV();
			

			uint32_t fnv1a(unsigned char oneByte, uint32_t hash)
			{
				return (oneByte ^ hash) * Prime;
			}

			uint32_t fnv1aArray(const auto bytes)
			{
				uint32_t hash = Seed;
				for(byte b : bytes){
					hash = fnv1a(b,hash);
				} 
				return hash;
			}
			
			uint32_t fnv1aHashOfMpz_t(const mpz_t x)
			{
				size_t size = (mpz_sizeinbase (x, 2) + CHAR_BIT-1) / CHAR_BIT;
    				std::vector<byte> v(size);
    				mpz_export(&v[0], &size, 1, 1, 0, 0, x);
    				v.resize(size);
				uint32_t hash = Seed;
				for(unsigned int i = 0; i < v.size(); i++)
				{
					byte b = v[i];
					hash = fnv1a(b, hash);
				}					
				return hash;
			}

			
		private:
			

			

	};
#endif
