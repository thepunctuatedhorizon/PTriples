/*
 *
 * File: Node.h
 * Author: jtucker
 *
 * Created 12_23_16
 *
 */

#ifndef NODE_H
#define NODE_H

#include "PTriples.h"
#include "Multiplier.h"
#include "Path.h"

class Node
{
	public:
		Node();

		Node(PTriples& nodeAnchr, Multiplier& mult, int dir, Path oldPath, int depth);
		
	
		//Functions
		void initializeSubNodes(Multiplier& mult, int depth);
		Node getUp() {return *up;}
		Node getSide(){return *side;}
		Node getDown(){return *down;}

		Node* getU(){return up;}
		Node* getS(){return side;}
		Node* getD() {return down;}

		int getDepth() {return depth;}	
		
		PTriples getAnchor(){return nodeAnchor;}
		Path getPath() {return path;}

	private:
		PTriples nodeAnchor;

		Path path;

		Node* up;
		Node* side;
		Node* down;

		int depth;
};
#endif
