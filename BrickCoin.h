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
			BrickCoin(EulerBrick brck);

			std::string getSignature();
		
			std::string getHashSignature();

		private:
			
			std::string signature;
			EulerBrick brick;
	};





#endif
