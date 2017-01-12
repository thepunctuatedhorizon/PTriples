/*
 *
 * File: BrickCoin.cpp
 * Author: jtucker
 *
 * Created 1_4_17
 *
 */


#include <stdio.h>
#include <string>
#include <gmp.h>
#include <gmpxx.h>
#include <openssl/sha.h>

#include "PTriples.h"
#include "EulerBrick.h"
#include "BrickCoin.h"
#include "EBVerify.h"



BrickCoin::BrickCoin(EulerBrick brck){

	//Storing the brick to the coin;
	brick = brck;

	//Initializing didItVerify to the false state to prevent invalid verifications;
	didItVerify = false;
	
	//Starting up the Verification process;
	EBVerify* verifier = new EBVerify(brick);

	//Recording what the verifier returns;
	didItVerify =(*verifier).didItVerify();

	if (didItVerify){

		//We need to initialize and generate the other five bricks. 

		//Initialization and setting requisite variables.
		mpz_t a, b, c;
		mpz_t abD, acD, bcD;

		mpz_init_set_str(a, "0", 10);
		mpz_init_set_str(b, "0", 10);
		mpz_init_set_str(c, "0", 10);

		mpz_init_set_str(abD, "0", 10);
		mpz_init_set_str(acD, "0", 10);
		mpz_init_set_str(bcD, "0", 10);

		brick.getAmpz(a);
		brick.getBmpz(b);
		brick.getCmpz(c);

		brick.getDiagonalABmpz(abD);
		brick.getDiagonalACmpz(acD);
		brick.getDiagonalBCmpz(bcD);

		// Now we need to make the proper PTriples.
		PTriples* triple1 = new PTriples(a, b, abD);
		PTriples* triple2 = new PTriples(a, c, acD);
		PTriples* triple3 = new PTriples(b, c, bcD);
		PTriples* triple4 = new PTriples(b, a, abD);
		PTriples* triple5 = new PTriples(c, a, acD);
		PTriples* triple6 = new PTriples(c, b, bcD);

		//Initializing the paths
		//TODO: FIND THE RIGHT PATHS.
		Path p;

		//Now to make the remaining EulerBricks.
		//We already have <a, b, c>
		brick2 = (* new EulerBrick((*triple2), (*triple6), p, p));  // <a, c, b>
		brick3 = (* new EulerBrick((*triple4), (*triple2), p, p));  // <b, a, c>
		brick4 = (* new EulerBrick((*triple3), (*triple5), p, p));  // <b, c, a>
		brick5 = (* new EulerBrick((*triple5), (*triple1), p, p));  // <c, a, b>
		brick6 = (* new EulerBrick((*triple6), (*triple4), p, p));  // <c, b, a>




		//Getting the Hash valuse converted to strings
		char hashA1[17];
		char hashB1[17];
		char hashC1[17];

		char hashA2[17];
		char hashB2[17];
		char hashC2[17];
		
		char hashA3[17];
		char hashB3[17];
		char hashC3[17];

		char hashA4[17];
		char hashB4[17];
		char hashC4[17];

		char hashA5[17];
		char hashB5[17];
		char hashC5[17];

		char hashA6[17];
		char hashB6[17];
		char hashC6[17];
	
		//Storing the string values of the hash
		std::snprintf(hashA1, sizeof(hashA1), "%x", brick.getHashA());
		std::snprintf(hashB1, sizeof(hashB1), "%x", brick.getHashB());
		std::snprintf(hashC1, sizeof(hashC1), "%x", brick.getHashC());
		
		std::snprintf(hashA2, sizeof(hashA2), "%x", brick2.getHashA());
		std::snprintf(hashB2, sizeof(hashB2), "%x", brick2.getHashB());
		std::snprintf(hashC2, sizeof(hashC2), "%x", brick2.getHashC());

		std::snprintf(hashA3, sizeof(hashA3), "%x", brick3.getHashA());
		std::snprintf(hashB3, sizeof(hashB3), "%x", brick3.getHashB());
		std::snprintf(hashC3, sizeof(hashC3), "%x", brick3.getHashC());

		std::snprintf(hashA4, sizeof(hashA4), "%x", brick4.getHashA());
		std::snprintf(hashB4, sizeof(hashB4), "%x", brick4.getHashB());
		std::snprintf(hashC4, sizeof(hashC4), "%x", brick4.getHashC());

		std::snprintf(hashA5, sizeof(hashA5), "%x", brick5.getHashA());
		std::snprintf(hashB5, sizeof(hashB5), "%x", brick5.getHashB());
		std::snprintf(hashC5, sizeof(hashC5), "%x", brick5.getHashC());

		std::snprintf(hashA6, sizeof(hashA6), "%x", brick6.getHashA());
		std::snprintf(hashB6, sizeof(hashB6), "%x", brick6.getHashB());
		std::snprintf(hashC6, sizeof(hashC6), "%x", brick6.getHashC());
	


		//Signature generation
		//TODO: ACTUALLY MAKE THIS USEFUL!  WE NEED TO put them in order? l - g? All permutations?
		//TODO: Double SHA512 hashing? or just once?
		signature = "";
		signature = "<"+brick.getA() + ", " + brick.getB() + ", " + brick.getC() + ">\n";
		
		signature = signature + "<"+brick2.getA() + ", " + brick2.getB() + ", " + brick2.getC() + ">\n";
	
		signature = signature + "<"+brick3.getA() + ", " + brick3.getB() + ", " + brick3.getC() + ">\n";

		signature = signature + "<"+brick4.getA() + ", " + brick4.getB() + ", " + brick4.getC() + ">\n";

		signature = signature + "<"+brick5.getA() + ", " + brick5.getB() + ", " + brick5.getC() + ">\n";

		signature = signature + "<"+brick6.getA() + ", " + brick6.getB() + ", " + brick6.getC() + ">\n";

		signature = signature + "<" + hashA1 + ", " + hashB1 + ", " + hashC1 + ">\n";

		signature = signature + "<" + hashA2 + ", " + hashB2 + ", " + hashC2 + ">\n";

		signature = signature + "<" + hashA3 + ", " + hashB3 + ", " + hashC3 + ">\n";

		signature = signature + "<" + hashA4 + ", " + hashB4 + ", " + hashC4 + ">\n";

		signature = signature + "<" + hashA5 + ", " + hashB5 + ", " + hashC5 + ">\n";
	
		signature = signature + "<" + hashA6 + ", " + hashB6 + ", " + hashC6 + ">";

	} else {
	
		signature = "Coin Not Valid";
	}
	

}

std::string BrickCoin::getSignature(){
	return signature;
}


std::string BrickCoin::getHashSignature(){

	//Required definition
	char mdString[SHA512_DIGEST_LENGTH*2+1];

	//Only proceed if it verified.
	if(didItVerify) {

		//Turing the signature into unsigned chars
		size_t ss = signature.length();
		unsigned char data[ss];

		strncpy((char *)data, signature.c_str(), ss);
		data[ss] = '\0';
		

		//Initializing the hash
		unsigned char hash[SHA512_DIGEST_LENGTH];

		//Hashing and then storing to the hash variable
		SHA512(data, sizeof(data), hash);

		
 		// Converting the hash value to hex
		for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
			std::sprintf(&mdString[i*2], "%02x", (unsigned int)hash[i]);
 		}

	} else {
		std::string mdString = "Coin Not Valid";
	}

	//Returing the resulting signature string;
	return mdString;
}
