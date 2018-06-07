#include <cstring>                        // use of string
#include <iostream>                      // use of in out
#include <vector>                       // vector to store my blockchain
#include <cstdint>                     // use for bitwise integer values
#include "BlockChain.h"               //  Blockchain.h header to implement the corresponding methods
#include "Critical_Block.h"          // CriticalBlock for the block object
using namespace std;

Block BlockChain::RetrievePreviousBlock() const 
{
	return ChainSystem.back(); // returns previous block vector object
}

BlockChain::BlockChain()
//	Block( const string& data, int VoterIDNumber); // updating constructor
{
   ChainSystem.emplace_back(Block("Genisis Block", 0)); // genisis block
	//index, p1tdata, p2tdata
}

void BlockChain::NewBlock(Block NewBlock)
{
	// add in new block unit, // form previous hash//
	NewBlock.previoushash = RetrievePreviousBlock().getHash(); // sets previous hash from the retrival of previousblock
	NewBlock.HashBlock();  // calls hashing function for the current block
	NewBlock.MineBlock(NewBlock); // mines the newblock 
	ChainSystem.push_back(NewBlock);  // pushes the chainsystemback using vector
	Chain_Size++; // increases chainsize
	CurrentBlockContent(NewBlock);  // displays the current block content
}

void BlockChain::CurrentBlockContent(Block &Block)
{
	/*
	Here we are going to insert the postgre link.
	make sure that we have a table for:
	Bot Number
	Bot Vote
	Current Hash
	Previous Hash
	Accreditied Nonce Value
	Solution Hash
	*/

	/*
	
	
	*/
	cout << "Bot Number" << endl;
	Block.displayid();
	cout << " " << endl;
	cout << " " << endl;
	

	cout << "Bot Vote" << endl;
	Block.displaydata();
	cout << " " << endl;


	cout << "Current Hash: " << endl;
	Block.displayCurrenthash();
	cout << " " << endl;



	cout << "Previous Hash:" << endl;
	Block.displayPreviousHash();
	cout << " " << endl;

	cout << "Accredited Nonce value for Hash Validation" << endl;
	Block.displayNonce();
	cout << " " << endl;

	cout << "Solution Hash: " << endl;
	Block.displayProofHash();
	cout << " " << endl;

	cout << "Chain Size" << endl;
	cout << Chain_Size << endl;


	cout << "-----------------------------------------------------------" << endl;

}