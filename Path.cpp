/*
* File: Path.cpp
* Author: jtucker
*
* Created 12_29_16
*/


#include "Path.h"
#include "Node.h"

const size_t MAX_PATH_LENGTH = 15;
Path::Path() {
	// Initialize
	pathVector.reserve(MAX_PATH_LENGTH);
}

void Path::foundAtThisNode(int whereFound){

	//Do something
	for (int i = 0; i<pathVector.size(); i++)
	{
		std::cout << pathVector[i] << ", " ;
	}
	std::cout << std::endl;
	std::cout << "The place found = " << whereFound << std::endl;
}

void Path::addUp(){
	pathVector.push_back(1);
}

void Path::addSide(){
	pathVector.push_back(0);
}

void Path::addDown(){
	pathVector.push_back(-1);
}

void Path::setRoot(){
	
}
