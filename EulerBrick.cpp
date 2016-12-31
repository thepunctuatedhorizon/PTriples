/*
 *
 * File: EulerBrick.cpp
 * Author: jtucker
 *
 * Created 12_30_16
 *
 */

#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "EulerBrick.h"
#include "SearchFunctions.h"

EulerBrick::EulerBrick(PTriples fst, PTriples scnd, Path pth1, Path pth2){

	first = fst;
	second = scnd;
	pathFirst = pth1;
	pathSecond =pth2;

	

	//Let's let the shortest side be a.
	//TODO: MAKE IT FIND THE SHORTEST SIDE!!
	
	mpz_t temp1, temp2, temp3, temp4;
	mpz_t diagT1, diagT2;
	mpz_init_set_str(temp1, "0", 10);
	mpz_init_set_str(temp2, "0", 10);
	mpz_init_set_str(temp3, "0", 10);
	mpz_init_set_str(temp4, "0", 10);
	mpz_init_set_str(diagT1, "0", 10);
	mpz_init_set_str(diagT2, "0", 10);

	first.getA(temp1);
	first.getB(temp2);
	second.getA(temp3);
	second.getB(temp4);

	int whereE = SearchFunctions::HashEqualsAny(first, second);

	if (whereE == 0){
		std::cout << "ERROR" << std::endl;
	} else if (whereE == 1){
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp4);

		first.getC(diagonalAB);
		//Diagonal AC need's to be calculated.

		//What if AC IS NOT ROOTABLE!??!  
		bool notRootable = false;
		if (notRootable) {std::cout << "ERROR, NOT ROOTABLE" << std::endl;}
		second.getC(diagonalBC);

		hashA = first.getAHash();
		hashB = first.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagBC = second.getCHash();


	} else if (whereE == 2){
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp3);

		first.getC(diagonalAB);
		//Diagonal AC needs to be calculated.

		//What if AC is not rootable?
		bool notRootable = false;
		if (notRootable) {std::cout << "Error, Not Rootable" << std::endl;}
		second.getC(diagonalBC);

		hashA = first.getAHash();
		hashB = first.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagBC = second.getCHash();

	} else if (whereE == 3){
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp4);

		first.getC(diagonalAB);
		//Diagonal AC needs to be calculated.

		//What if AC is not rootable?
		bool notRootable = false;
		if (notRootable) {std::cout << "Error, Not Rootable" << std::endl;}
		second.getC(diagonalBC);

		hashA = first.getAHash();
		hashB = first.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagBC = second.getCHash();

	} else if (whereE == 4) {
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp3);

		first.getC(diagonalAB);
		//Diagonal AC needs to be calculated.

		//What if AC is not rootable?
		bool notRootable = false;
		if (notRootable) {std::cout << "Error, Not Rootable" << std::endl;}
		second.getC(diagonalBC);


		hashA = first.getAHash();
		hashB = first.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagBC = second.getCHash();
	}
			
	
	//mpz_add(            first.getC2() + second.getC2() + diagonalAC2 )

		/*
		
			mpz_t diagonalAC;
			
			
			mpz_t spaceDiagonal2;



			uint32_t hashB2;

			uint32_t hashDiagAB;
			uint32_t hashDaigAC;
			uint32_t hashDaigBC;
		*/

}




void EulerBrick::print(){
	std::cout << "This Brick has the following signatures" << std::endl;
	std:: cout << "<";
	mpz_out_str(stdout,10,a);
        std::cout << ", ";
        mpz_out_str(stdout,10,b);
        std::cout << ", ";
        mpz_out_str(stdout,10,c);
        std::cout << ">" << std::endl;
	std::cout << "DiagonalAB: ";
	mpz_out_str(stdout,10,diagonalAB);
	std::cout << std::endl << "DiagonalAC:";
	mpz_out_str(stdout,10,diagonalAC);
	std::cout << std::endl << "DiagonalBC:";
	mpz_out_str(stdout,10,diagonalBC);
	std::cout << std::endl;

	std::cout << "Hashs: <";
	std::cout << std::hex << hashA << ", ";
	std::cout << hashB << ", " << hashC ;
	std::cout << ">" << std::endl;
	
}







