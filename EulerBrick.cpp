/*
 *
 * File: EulerBrick.cpp
 * Author: jtucker
 *
 * Created 12_30_16
 *
 */


#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"
#include "EulerBrick.h"
#include "SearchFunctions.h"

EulerBrick::EulerBrick(){

//NOT TO BE USED!
	//Why must the argumentless constructor be defined?

	std::cout<< "NOT TO BE USED!!!" << std::endl;

}

EulerBrick::EulerBrick(PTriples fst, PTriples scnd, Path pth1, Path pth2){

	first = fst;
	second = scnd;
	pathFirst = pth1;
	pathSecond =pth2;

	//How do we prevent <a,b,c> brick = <b, c, a> brick = <c, a, b> etc.?
	
	mpz_t temp1, temp2, temp3, temp4;
	mpz_t diagT1, diagT2, zero, one;

	mpz_init_set_str(a, "0", 10);
	mpz_init_set_str(b, "0", 10);
	mpz_init_set_str(c, "0", 10);

	mpz_init_set_str(diagonalAB, "0", 10);
	mpz_init_set_str(diagonalAC, "0", 10);
	mpz_init_set_str(diagonalBC, "0", 10);
	
	mpz_init_set_str(spaceDiagonal2, "0", 10);
	mpz_init_set_str(perfectSpaceDiagonal, "0", 10);
	mpf_init_set_str(spaceDiagonal, "0", 10);

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
		//mpz_out_str(stdout, 10, perfectSpaceDiagonal);
	} else {
		isPerfect = false;
		mpf_set_default_prec(100);
		mpf_t spD;
		mpf_init(spD);
		mpf_init(spaceDiagonal);
		mpf_set_z(spD, spaceDiagonal2);
		size_t size = 0;
		mpf_out_str(stdout, 10, size, spD);
		std::cout<< std::endl;

		mpf_sqrt(spaceDiagonal, spD);
	}

	
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

	std::cout << "Space diagonal ";
	if (isPerfect){ 
		std::cout << "IS a perfect Brick" << std::endl;
		std::cout <<  "It does have a space diagonal of: ";
		mpz_out_str(stdout, 10, perfectSpaceDiagonal);
		std::cout << std::endl;
	}
	else{ 
		std::cout << "is NOT ";
		std::cout << "a perfect Brick" << std::endl;
		std::cout << "Even though it wasn't a perfect brick," << std::endl;
		std::cout <<  "it does have a space diagonal of: ";
		mpf_out_str(stdout, 10, 10, spaceDiagonal);
		std::cout << std::endl;
	}
	
	
}

bool EulerBrick::isBrickClose(){


	return false;
}


PTriples EulerBrick::getFirstPTriple(){

	return first;

}

PTriples EulerBrick::getSecondPTriple() {

	return second;

}

std::string EulerBrick::getA(){

	return mpz_get_str(NULL, 10, a);
        
}

std::string EulerBrick::getB(){

	return mpz_get_str(NULL, 10, b);

}

std::string EulerBrick::getC(){

	return mpz_get_str(NULL, 10, c);
}
		
std::string EulerBrick::getDiagonalAB(){
	return mpz_get_str(NULL, 10, diagonalAB);
}

std::string EulerBrick::getDiagonalAC(){
	return mpz_get_str(NULL, 10, diagonalAC);
}

std::string EulerBrick::getDiagonalBC(){
	return mpz_get_str(NULL, 10, diagonalBC);
}

void EulerBrick::getShortestSide(mpz_t returnside){

	int aTOb = mpz_cmp(a,b);
	int aTOc = mpz_cmp(a,c);
	int bTOc = mpz_cmp(b,c);

	if (aTOb > 0 && aTOc > 0 && bTOc > 0){
		mpz_set(returnside,c);
	}
	if (aTOb < 0 && aTOc > 0 && bTOc > 0){
		mpz_set(returnside,c);
	}
	if (aTOb < 0 && aTOc < 0 && bTOc > 0){
		mpz_set(returnside, a);
	}
	if (aTOb < 0 && aTOc < 0 && bTOc < 0) {
		mpz_set(returnside, a);
	}
	if (aTOb > 0 && aTOc > 0 && bTOc < 0) {
		mpz_set(returnside, b);
	}
	if ( aTOb >0 && aTOc < 0 && bTOc < 0) {
		mpz_set(returnside, b);
	}
}






