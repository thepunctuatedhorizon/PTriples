/* File: ptriples.cpp
* Author: jtucker
*
* Created 12_13_16
*/

#include <stdio.h>
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"

PTriples::PTriples(){

	mpz_init_set_str (a,"3",10);
	mpz_init_set_str (b,"4",10);
	mpz_init_set_str (c,"5",10);
	
	ha = FNV::fnv1aHashOfMpz_t(a);
	hb = FNV::fnv1aHashOfMpz_t(b);
	hc = FNV::fnv1aHashOfMpz_t(c);	
 
}

PTriples::PTriples(mpz_t & nA, mpz_t & nB, mpz_t & nC){

	mpz_init_set_str(a, "0", 10);
	mpz_init_set_str(b, "0", 10);
	mpz_init_set_str(c, "0", 10);

	mpz_set(a, nA);
	mpz_set(b, nB);
	mpz_set(c, nC);

	ha = FNV::fnv1aHashOfMpz_t(a);
	hb = FNV::fnv1aHashOfMpz_t(b);
	hc = FNV::fnv1aHashOfMpz_t(c);

}




void PTriples::printOutTriple() {

	std::cout << "<";	
        mpz_out_str(stdout,10,a);
        std::cout << ", ";
        mpz_out_str(stdout,10,b);
        std::cout << ", ";
        mpz_out_str(stdout,10,c);
        std::cout << ">" << std::endl;
}



