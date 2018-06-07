#define _CRT_SECURE_NO_WARNINGS
#include <string>           // use of string
#include <cstdint>          // use for bitwise integer values
#include <iostream>         // use of in out
#include <sstream>          // sstream for hashing string
#include <vector>           // if mining validation needs to occur for later proof of work.

#include "Critical_Block.h" // critcal block header
#include "sha256.h"         // sha256 encryption header
#include "time.h"	        // time.h for a timevalue to add to encryption frequency



using namespace std;

Block::Block()
{// block constructor
	VoterIDNumber = -1;
	timevalue = NULL;
	hash = " ";
	data = " ";
}

Block::Block(const string& ndata, int NewId) : VoterIDNumber(NewId)
{
	//assigns the block constructor with assignmentdata and timevalue
	data.assign(ndata);
	timevalue = time(nullptr);
}

 inline string Block::CalculateHash() const
{
	 // calculates the hash via string stream input
	stringstream inputstring;
	inputstring << data << nonce << timevalue << VoterIDNumber << previoushash; // data vote - nonce - voter id tag - prevhash
	return sha256(inputstring.str()); // sha encryption for input string.
}

 void Block::HashBlock()
 {
	hash = CalculateHash(); // hash is calculate first hash.
 }
 
 void Block::MineBlock(Block& Newblock )
 {
	 const int difficult = 2;   // difficult can be changed to match. dynamic maybe?
	 char chararray[difficult + 1]; //difficult plus 1 to account for size of char array

	 for (int i = 0; i < difficult; ++i) 
	 {
		 chararray[i] = '0';  // char array[i] is all set to string 0
	 }

	 chararray[difficult] = '\0'; // null terminator
	 string str(chararray); // creates string from char array
	 Newblock.proofhash = Newblock.hash; // proofhash sets the current hash

	 while (proofhash.substr(0, difficult) != str) // pulling substring match of 0 - difficulty is not equal to the string
	 {
		 Newblock.nonce++; // increment nonce value
		 Newblock.proofhash = CalculateHash(); // proofhash is now the calculatable hash
	 }

 }
 