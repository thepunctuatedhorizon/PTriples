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

#include "EBVerify.h"


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

	std::cout << match.printOutTriple() << std::endl;
	PTriples mmatch = (*node).getUp().getAnchor();

	std::cout << mmatch.printOutTriple() << std::endl;






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

	SearchFunctions::traverseTreeUtil(refNode, (*trip), 3);

	std::cout << " TOWSON UNIVERSITY GRAD" << std::endl;

	Path pathss;
	pathss.setRoot();
	pathss.addUp();
	pathss.addDown();
	pathss.addDown();

	PTriples result = SearchFunctions::traverseToAndGet((*node), pathss);
	std::cout << result.printOutTriple()<< std::endl;

	//Testing the new confirmation system.

	std::cout << "* Testing *" << std::endl;

	EBVerify * verifier = new EBVerify((*eulerBrick));

	std::cout << (*eulerBrick).getA() << std::endl;

	std::cout << (*eulerBrick).getB() << std::endl;

	std::cout << (*eulerBrick).getC() << std::endl;

	std::cout << (*eulerBrick).getDiagonalAB() << std::endl;

	std::cout << (*eulerBrick).getDiagonalAC() << std::endl;
	std::cout << (*eulerBrick).getDiagonalBC() << std::endl;

	BrickCoin* coin = new BrickCoin( (*eulerBrick));

	std::cout << (*coin).getSignature() << std::endl;
	std::cout << (*coin).getHashSignature() << std::endl;

	EBVerify * ver = new EBVerify((*coin));

	std::string coinSig = "<240, 117, 44>\n<750b7a6f, f00c3c10, 290c95cb>\n11183239fa180f33c3d168b75fe410c2addf017300288c1fe401f959d269cd0c5a8392b6bcb55fff378911c013a86aafcaa36419cde3a11ebbd459814ff61c24";

	EBVerify * stringVerify  = new EBVerify(coinSig);


    	return 0;
}
