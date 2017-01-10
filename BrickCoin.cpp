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

		//Getting the Hash valuse converted to strings
		char hashA[17];
		char hashB[17];
		char hashC[17];
	
		//Storing the string values of the hash
		std::snprintf(hashA, sizeof(hashA), "%x", brick.getHashA());
		std::snprintf(hashB, sizeof(hashB), "%x", brick.getHashB());
		std::snprintf(hashC, sizeof(hashC), "%x", brick.getHashC());

	


		//Signature generation
		signature = "<"+brick.getA() + ", " + brick.getB() + ", " + brick.getC() + ">\n";
	
		signature = signature + "<" + hashA + ", " + hashB + ", " + hashC + ">";
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
		unsigned char data[sizeof(signature)];
		strcpy((char *)data,signature.c_str());

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
