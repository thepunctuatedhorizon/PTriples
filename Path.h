/*
* File: Path.h
* Author: jtucker
*
* Created on 12_29_16
*/



#ifndef PATH_H
#define PATH_H


#include <vector>

	class Path{

		public:
			Path();
			
			void foundAtThisNode(int whereFound);

			void addUp();
			void addSide();
			void addDown();

			void setRoot();
			
		private:
			std::vector<int> pathVector;


	};

#endif


