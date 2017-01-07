/*
 *
 * File: BrickCoin.cpp
 * Author: jtucker
 *
 * Created 1_4_17
 *
 */


#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>
#include <openssl/sha.h>

#include "PTriples.h"
#include "EulerBrick.h"
#include "BrickCoin.h"



BrickCoin::BrickCoin(EulerBrick brck){

	brick = brck;
	
	char hashA[17];
	char hashB[17];
	char hashC[17];
	std::snprintf(hashA, sizeof(hashA), "%x", brick.getHashA());
	std::snprintf(hashB, sizeof(hashB), "%x", brick.getHashB());
	std::snprintf(hashC, sizeof(hashC), "%x", brick.getHashC());

	


	//Signature generation
	signature = "<"+brick.getA() + ", " + brick.getB() + ", " + brick.getC() + ">\n";
	
	signature = signature + "<" + hashA + ", " + hashB + ", " + hashC + ">\n";

	

}

std::string BrickCoin::getSignature(){
	return signature;
}


unsigned char* BrickCoin::getHashSignature(){

	const unsigned char data[ ] = "This is the signature, NOT";
	unsigned char hash[SHA512_DIGEST_LENGTH];
	SHA512(data, sizeof(data) - 1, hash);

	return hash;
}
