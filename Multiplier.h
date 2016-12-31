/*
 *
 * File: Multiplier.h
 * Author: jtucker
 *
 * Created 12_23_16
 *
 */

#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include <gmp.h>
#include <gmpxx.h>

#include "PTriples.h"

class Multiplier
{
    public:
        Multiplier();

	 
	PTriples hit( PTriples currentPT, int uSd);


    private:
	long int up1, up2, up3;
	long int up4, up5, up6;
	long int up7, up8, up9;

	long int side1, side2, side3;
	long int side4, side5, side6;
	long int side7, side8, side9;

	long int down1, down2, down3;
	long int down4, down5, down6;
	long int down7, down8, down9;
	
	mpz_t interm1a, interm1b, interm1c;
	mpz_t interm2a, interm2b, interm2c;
	mpz_t interm3a;

	mpz_t result1, result2, result3;
	mpz_t zero;

	long int mtrx1, mtrx2, mtrx3;
	long int mtrx4, mtrx5, mtrx6;
	long int mtrx7, mtrx8, mtrx9;


};

#endif
