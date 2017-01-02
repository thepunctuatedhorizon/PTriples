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
	mpz_init_set_str(brickL, "240", 10);
	
	std::cout << "Here\n";

	Multiplier mult;

	SearchFunctions searcher;

	PTriples test1;
	PTriples test2;

	std::cout << "There\n";	

	Path path;

	Node* node = new Node(test1, mult, -2, path, 0);
	Node* node1 = new Node(test2, mult, -2, path, 0);

	std::cout << "Everywhere \n";
	
	std::cout << std::hex << (*node).getUp().getAnchor().getAHash() << std::endl;
	std::cout << std::hex << (*node1).getUp().getAnchor().getAHash() << std::endl;

	bool eq = SearchFunctions::HashDiagonalEquals((*node).getUp().getAnchor(),(*node1).getUp().getAnchor());
	if (eq){

		std::cout << "true" << std::endl;

	}

	std::cout << std::dec << SearchFunctions::CMP((*node).getUp().getAnchor(), (*node1).getUp().getAnchor(), 3, 1) << std::endl;


	std::cout << "End of the line" << std::endl;

	
	SearchFunctions::traverseTreeUtil((*node), (*node).getUp().getAnchor(), 3);

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


	std::cout << "Here's a match, is it a brick?" << std::endl;
	
	EulerBrick* eulerB = new EulerBrick((*node).getUp().getAnchor(), (*node).getDown().getDown().getAnchor(),p,p);
	(*eulerB).print();


    	return 0;
}
