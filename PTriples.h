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
        
        PTriples(mpz_t& nA, mpz_t& nB, mpz_t& nC);

        void getA(mpz_t& result){  mpz_set(result, a);}
        void getB(mpz_t& result){  mpz_set(result, b);}
        void getC(mpz_t& result){  mpz_set(result, c);}

        //void getA2(mpz_t& result){  mpz_set(result, a2);}
        //void getB2(mpz_t& result){  mpz_set(result, b2);}
        //void getC2(mpz_t& result){  mpz_set(result, c2);}

        void printOutTriple();
	
	uint32_t getAHash(){ return ha;}
	uint32_t getBHash(){ return hb;}
	uint32_t getCHash(){ return hc;}

	//uint32_t getA2Hash(){ return ha2;}
	//uint32_t getB2Hash(){ return hb2;}
	//uint32_t getC2Hash(){ return hc2;}

	



    private:
        mpz_t a;
        mpz_t b;
        mpz_t c;

	//DO NOT NEED  Can be easily calculated OUTSIDE of the ptriple.
        //mpz_t a2;
        //mpz_t b2;
        //mpz_t c2;

	uint32_t ha;
	uint32_t hb;
	uint32_t hc;

	//Don't need.  Save space.
	//uint32_t ha2;
	//uint32_t hb2;
	//uint32_t hc2;
};

#endif
