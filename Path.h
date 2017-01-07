/*
* File: Path.h
* Author: jtucker
*
* Created on 12_29_16
*/



#ifndef PATH_H
#define PATH_H


#include <vector>
#include <string>

	class Path{

		public:
			Path();
			
			void foundAtThisNode(int whereFound);

			void addUp();
			void addSide();
			void addDown();

			void setRoot();

			
		
			int size() {return pathVector.size();}

			int getInt(int i) {return pathVector[i];}

			std::string getPath();
			
		private:
			std::vector<int> pathVector;


	};

#endif


