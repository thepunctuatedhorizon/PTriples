/*
 *
 * File: EulerBrick.h
 * Author: jtucker
 *
 * Created 12_30_16
 *
 */

#ifndef EULERBRICK_H
#define EULERBRICK_H

#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "Path.h"


	class EulerBrick{

		public:
			EulerBrick(PTriples fst, PTriples scnd, Path pth1, Path pth2);

			bool isBrickPerfect();

			void print();

			uint32_t getHashA() {return hashA;}
			uint32_t getHashB() {return hashB;}
			uint32_t getHashC() {return hashC;}
		
			uint32_t getHashA2() {return hashA2;}
			uint32_t getHashB2() {return hashB2;}
			uint32_t getHashC2() {return hashC2;}

			uint32_t getHashDaigAB() {return hashDiagAB;}
			uint32_t getHashDaigAC() {return hashDiagAC;}
			uint32_t getHashDiagBC() {return hashDiagBC;}
		
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

			

	};



#endif
