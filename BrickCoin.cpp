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
	didItVerify = false;
	EBVerify* verifier = new EBVerify(brick);
	didItVerify =(*verifier).didItVerify();

	if (didItVerify){


		char hashA[17];
		char hashB[17];
		char hashC[17];
	
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

	char mdString[SHA512_DIGEST_LENGTH*2+1];
	if(didItVerify) {
		unsigned char data[sizeof(signature)];
		strcpy((char *)data,signature.c_str());
		unsigned char hash[SHA512_DIGEST_LENGTH];
		SHA512(data, sizeof(data), hash);

		
 
		for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
			std::sprintf(&mdString[i*2], "%02x", (unsigned int)hash[i]);
 		}
	} else {
		std::string mdString = "Coin Not Valid";
	}
	return mdString;
}
