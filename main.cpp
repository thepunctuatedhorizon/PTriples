#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "Multiplier.h"
#include "Node.h"

#include "FNV.h"

#include "SearchFunctions.h"


#include "Path.h"

#include "EulerBrick.h"


int main()
{

	mpz_t brickL, brickW, brickH;
	mpz_init_set_str(brickL, "44", 10);
	mpz_init_set_str(brickW, "117", 10);
	mpz_init_set_str(brickH, "240", 10);
	
	 

	Multiplier mult;

	PTriples test1;
	PTriples test2;
 
	Path path;

	Node* node = new Node(test1, mult, -2, path, 0);
	Node* node1 = new Node(test2, mult, -2, path, 0);

	//std::cout << "Everywhere \n";
	
	PTriples firstAPT = (*node).getUp().getAnchor();
	PTriples secondAPT = (*node1).getUp().getAnchor();
	
	//std::cout << std::hex << firstAPT.getAHash() << std::endl;
	//std::cout << std::hex << secondAPT.getAHash() << std::endl;

	//bool eq = SearchFunctions::HashDiagonalEquals(firstAPT,secondAPT);
	//if (eq){

	//	std::cout << "true" << std::endl;

	//}

	//std::cout << std::dec << SearchFunctions::CMP(firstAPT, secondAPT, 3, 1) << std::endl;


	std::cout << "End of the line" << std::endl;

	Node& refNode = * node;
	
	SearchFunctions::traverseTreeUtil(refNode, firstAPT, 4);

	std::cout << "End of traverse" << std::endl;

	PTriples match = (*node).getDown().getDown().getAnchor();

	match.printOutTriple();
	PTriples mmatch = (*node).getUp().getAnchor();

	mmatch.printOutTriple();






	//Here, I'm testing the Euler Brick

	mpz_t aa, bb, cc, da, db;
	mpz_init_set_str(aa, "240", 10);
	mpz_init_set_str(bb, "117", 10);
	mpz_init_set_str(cc, "44", 10);
	mpz_init_set_str(da, "267", 10);
	mpz_init_set_str(db, "125", 10);
	PTriples* aA = new PTriples(aa, bb, da);
	PTriples* bA = new PTriples(bb, cc, db);
	Path p;

	EulerBrick* eulerBrick = new EulerBrick((*aA), (*bA), p, p);

	(*eulerBrick).print();


	//std::cout << "Here's a match, is it a brick?" << std::endl;
	
	//EulerBrick* eulerB = new EulerBrick(firstAPT, (*node).getDown().getDown().getAnchor(),p,p);
	//(*eulerB).print();




	std::cout << "A meandering stream of searching." << std::dec << std::endl;
	
	PTriples* trip = new PTriples(brickW, brickL, db);

	SearchFunctions::traverseTreeUtil(refNode, (*trip), 4);


    	return 0;
}
