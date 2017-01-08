/*
 *
 * File: EBVerify.h
 * Author: jtucker
 *
 * Created 1_4_17
 *
 */

#ifndef EBVERIFY_H
#define EBVERIFY_H

#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "Path.h"
#include "EulerBrick.h"
#include "BrickCoin.h"

	class EBVerify{
		public:
			EBVerify();
			EBVerify(EulerBrick brick);
			EBVerify(BrickCoin coin);
		
			bool didItVerify();


		private:

			bool isPerfect;
			Path pathFirst;
			Path pathSecond;

			PTriples first;
			PTriples second;
			
			mpz_t a;
			mpz_t b;
			mpz_t c;
		
			mpz_t diagonalAB;
			mpz_t diagonalAC;
			mpz_t diagonalBC;
			
			mpz_t spaceDiagonal2;
			mpz_t perfectSpaceDiagonal;
			mpf_t spaceDiagonal;

			uint32_t hashA;
			uint32_t hashB;
			uint32_t hashC;

			uint32_t hashA2;
			uint32_t hashB2;
			uint32_t hashC2;

			uint32_t hashDiagAB;
			uint32_t hashDiagAC;
			uint32_t hashDiagBC;

			bool verified;




	};




#endif
