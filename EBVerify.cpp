/*
 *
 * File: EBVerify.cpp
 * Author: jtucker
 *
 * Created 1_4_17
 *
 */


#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "EulerBrick.h"
#include "SearchFunctions.h"
#include "EBVerify.h"

EBVerify::EBVerify(){
	verified = false;
}


EBVerify::EBVerify(EulerBrick brick) {


 	//TODO: VERIFICATION CODE!

	first = brick.getFirstPTriple();
	second = brick.getSecondPTriple();
	pathFirst = brick.getPath1();
	pathSecond = brick.getPath2();
	verified = false;

	

	//Let's let the shortest side be a.
	//TODO: MAKE IT FIND THE SHORTEST SIDE!!
	
	mpz_t temp1, temp2, temp3, temp4;
	mpz_t diagT1, diagT2, zero, one;
	mpz_init_set_str(temp1, "0", 10);
	mpz_init_set_str(temp2, "0", 10);
	mpz_init_set_str(temp3, "0", 10);
	mpz_init_set_str(temp4, "0", 10);
	mpz_init_set_str(diagT1, "0", 10);
	mpz_init_set_str(diagT2, "0", 10);
	mpz_init_set_str(zero, "0",10);
	mpz_init_set_str(one, "1", 10);
	FNV fnv;

	first.getA(temp1);
	first.getB(temp2);
	second.getA(temp3);
	second.getB(temp4);

	int whereE = SearchFunctions::HashEqualsAny(first, second);

	if (whereE == 0){
		std::cout << "ERROR" << std::endl;
	} else if (whereE == 1 || whereE ==3){
		try{
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp4);

		first.getC(diagonalAB);
		//Diagonal AC need's to be calculated.
		mpz_set(temp3, zero);
		mpz_set(temp2, zero);
		mpz_mul(temp3, temp1, temp1);
		mpz_mul(temp2, temp4, temp4);
		mpz_add(diagT1, temp2, temp3);
		int sqrtable = mpz_perfect_square_p(diagT1);
	
		if (sqrtable > 0){
			mpz_root(diagonalAC, diagT1, 2);
		} else {
			std::cout << "ERROR, NOT ROOTABLE" << std::endl;
			throw 10;
		}
		second.getC(diagonalBC);

		hashA = first.getAHash();
		hashB = first.getBHash();
		hashC = second.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagAC = fnv.fnv1aHashOfMpz_t(diagonalAC);
		hashDiagBC = second.getCHash();
		} catch (int e) { std::cout << "caught the trown int "  << e << std::endl;}


	} else if (whereE == 2|| whereE ==4){
		try {
		mpz_set(a, temp1);
		mpz_set(b, temp2);
		mpz_set(c, temp3);

		first.getC(diagonalAB);
		//Diagonal AC need's to be calculated.
		mpz_set(temp3, zero);
		mpz_set(temp1, zero);
		mpz_mul(temp3, temp2, temp2);
		mpz_mul(temp1, temp4, temp4);
		mpz_add(diagT2, temp1, temp3);
		int sqrtable = mpz_perfect_square_p(diagT2);
		if (sqrtable > 0){
			mpz_root(diagonalAC, diagT2, 2);
		} else {
			std::cout << "ERROR, NOT ROOTABLE" << std::endl;
			throw 20;
		}
		second.getC(diagonalBC);

		hashA = first.getAHash();
		hashB = first.getBHash();
		hashC = second.getBHash();
		hashDiagAB = first.getCHash();
		hashDiagAC = fnv.fnv1aHashOfMpz_t(diagonalAC);
		hashDiagBC = second.getCHash();
		} catch (int e) { std::cout << "caught the trown int " << e << std::endl;}
	}
	
	mpz_set(temp1, zero);
	mpz_set(temp2, zero);
	mpz_set(temp3, zero);
	mpz_set(temp4, zero);
	mpz_set(diagT1, zero);
	mpz_set(diagT2, zero);

	mpz_mul(temp1, a, a);
	mpz_mul(temp2, b, b);
	mpz_mul(temp3, c, c);

	mpz_add(temp4, temp1, temp2);
	mpz_add(spaceDiagonal2, temp4, temp3);

	int spaceDiag = mpz_perfect_square_p(spaceDiagonal2);
	if (spaceDiag>0) { 
		isPerfect = true;
		mpz_root( perfectSpaceDiagonal, spaceDiagonal2, 2);
		mpz_out_str(stdout, 10, perfectSpaceDiagonal);
	} else {
		isPerfect = false;
		mpf_set_default_prec(100);
		mpf_t spD;
		mpf_init(spD);
		mpf_init(spaceDiagonal);
		mpf_set_z(spD, spaceDiagonal2);
		//size_t size = 0;
		//mpf_out_str(stdout, 10, size, spD);
		//std::cout<< std::endl;

		mpf_sqrt(spaceDiagonal, spD);
	}


	// TODO: FIGURE OUT HOW TO MAKE IT FIND THE TRIPLE IN THE PATH.

	// TODO: Verify
	
	if (brick.getHashA() == hashA && brick.getHashB() == hashB && brick.getHashC() == hashC)
	{
		verified = true;
		std::cout << "This is a match, it computes. I'm happy to report this checked out." << std::endl;
	}

}

bool EBVerify::didItVerify(){
	return verified;
}

EBVerify::EBVerify(BrickCoin coin){




}




