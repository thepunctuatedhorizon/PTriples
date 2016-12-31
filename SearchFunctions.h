/*
* File: SearchFunctions.h
* Author: jtucker
*
* Created on 12_28_16
*/

#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H

#include <gmp.h>
#include <gmpxx.h>

#include "FNV.h"
#include "PTriples.h"
#include "Node.h"
#include "Path.h"


	class SearchFunctions {

		public:
			SearchFunctions();

			//Depreciated
			static bool rawEquals(PTriples firstT, PTriples secondT, int first, int second);

			static int CMP(PTriples firstT, PTriples secondT, int first, int second);

			static bool HashEquals(PTriples firstT, PTriples secondT, int first, int second);

			static bool HashDiagonalEquals(PTriples firstT, PTriples secondT);

			static void traverseTreeUtil(Node rootNode, PTriples requirement, int depth); 

			static int HashEqualsAny(PTriples firstT, PTriples secondT);
		
		
		private:
			




	};
#endif
