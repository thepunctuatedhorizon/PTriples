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

	//We shouldn't need
	//mpz_init_set_str (a2,"9",10);
	//mpz_init_set_str (b2,"16",10);
	//mpz_init_set_str (c2,"25",10);
	
	FNV fnv;

	ha = fnv.fnv1aHashOfMpz_t(a);
	hb = fnv.fnv1aHashOfMpz_t(b);
	hc = fnv.fnv1aHashOfMpz_t(c);	

	//We shouldn't need.
	//ha2 = fnv.fnv1aHashOfMpz_t(a2);
	//hb2 = fnv.fnv1aHashOfMpz_t(b2);
	//hc2 = fnv.fnv1aHashOfMpz_t(c2);
 
}

PTriples::PTriples(mpz_t& nA, mpz_t& nB, mpz_t& nC){

	mpz_set(a, nA);
	mpz_set(b, nB);
	mpz_set(c, nC);

	//We shouldn't need!
	//mpz_mul(a2, nA, nA);
	//mpz_mul(b2, nB, nB);
	//mpz_mul(c2, nC, nC);

	FNV fnv;

	ha = fnv.fnv1aHashOfMpz_t(a);
	hb = fnv.fnv1aHashOfMpz_t(b);
	hc = fnv.fnv1aHashOfMpz_t(c);

	//We shouldn't need!
	//ha2 = fnv.fnv1aHashOfMpz_t(a2);
	//hb2 = fnv.fnv1aHashOfMpz_t(b2);
	//hc2 = fnv.fnv1aHashOfMpz_t(c2);
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



