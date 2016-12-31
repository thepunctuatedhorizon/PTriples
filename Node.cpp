/*
 *
 * File: Node.cpp
 * Author: jtucker
 *
 * Created 12_23_16
 *
 */

#include <gmp.h>
#include <gmpxx.h>

#include "Multiplier.h"
#include "Node.h"
#include "Path.h"


Node::Node(){

}

Node::Node(PTriples& nodeAnchr, Multiplier& mult, int dir, Path oldPath, int dpth){
	
	depth = dpth;
	
	path = oldPath;
	
	if(dir==1){
		path.addUp();
	} else if (dir == 0) {
		path.addSide();
	} else if (dir == -1) {
		path.addDown();
	} else if (dir == -2) {
		path.setRoot();
	} else { 
		std::cout << "THERE WAS AN ERROR"  << std::endl;
	}

	nodeAnchor = nodeAnchr;
	
	initializeSubNodes(mult, depth+1);

}


void Node::initializeSubNodes(Multiplier& mult, int depth){
	
	if (depth < 5){
		
		PTriples temp = mult.hit(nodeAnchor, 1);
		PTriples temp2 = mult.hit(nodeAnchor, 2);
		PTriples temp3 = mult.hit(nodeAnchor, 3);

		up = new Node(temp, mult, 1, path, depth);
		side = new Node(temp2, mult, 0, path, depth);
		down = new Node(temp3, mult, -1, path, depth);

	}


}



