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

	brick = brck;
	
	EBVerify* verifier = new EBVerify(brick);

	if ((*verifier).didItVerify()){


		char hashA[17];
		char hashB[17];
		char hashC[17];
	
		std::snprintf(hashA, sizeof(hashA), "%x", brick.getHashA());
		std::snprintf(hashB, sizeof(hashB), "%x", brick.getHashB());
		std::snprintf(hashC, sizeof(hashC), "%x", brick.getHashC());

	


		//Signature generation
		signature = "<"+brick.getA() + ", " + brick.getB() + ", " + brick.getC() + ">\n";
	
		signature = signature + "<" + hashA + ", " + hashB + ", " + hashC + ">";
	}
	

}

std::string BrickCoin::getSignature(){
	return signature;
}


std::string BrickCoin::getHashSignature(){

	const unsigned char data[ ] = "This is the signature, NOT";
	unsigned char hash[SHA512_DIGEST_LENGTH];
	SHA512(data, sizeof(data), hash);

	char mdString[SHA512_DIGEST_LENGTH*2+1];
 
	for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
		std::sprintf(&mdString[i*2], "%02x", (unsigned int)hash[i]);
 	}

	return mdString;
}