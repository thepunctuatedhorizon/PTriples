/*
* File: PTriples.h
* Author: jtucker
*
* Created on 12_13_16
*/

#ifndef PTRIPLES_H
#define PTRIPLES_H


#include <stdio.h>
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

#include "FNV.h"

class PTriples
{
    public:
        PTriples();
        
        PTriples(mpz_t &nA, mpz_t &nB, mpz_t &nC);

        void getA(mpz_t& result){  mpz_set(result, a);}
        void getB(mpz_t& result){  mpz_set(result, b);}
        void getC(mpz_t& result){  mpz_set(result, c);}

        void printOutTriple();
	
	uint32_t getAHash(){ return ha;}
	uint32_t getBHash(){ return hb;}
	uint32_t getCHash(){ return hc;}


    private:
        mpz_t a;
        mpz_t b;
        mpz_t c;

	uint32_t ha;
	uint32_t hb;
	uint32_t hc;

};

#endif
