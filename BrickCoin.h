/*
 *
 * File: BrickCoin.h
 * Author: jtucker
 *
 * Created 1_4_17
 *
 */

#ifndef BRICKCOIN_H
#define BRICKCOIN_H

#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "Path.h"
#include "EulerBrick.h"


	class BrickCoin{
		public:
			//Constructor to construct the coin frokm a EulerBrick
			BrickCoin(EulerBrick brck);

			//Function to get the signature of the BrickCoin
			std::string getSignature();
		
			//Function to get the SHA512 hash of the BrickCoin
			std::string getHashSignature();

		private:
			
			//This variable holds the signature;
			std::string signature;

			//This variable holds the brick that was used to generate the BrickCoin
			EulerBrick brick;

			//These variables hold the bricks that will be part of the BrickCoin
			EulerBrick brick2;
			EulerBrick brick3;
			EulerBrick brick4;
			EulerBrick brick5;
			EulerBrick brick6;

			//This varible indicates whether the coin is valid and verifiable;
			bool didItVerify;
	};





#endif
