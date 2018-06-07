#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <cstring>                       // use of string
#include <iostream>                     // use of in out
#include <vector>                      // vector to store my blockchain
#include <cstdint>                    // use for bitwise integer values
#include "Critical_Block.h"          //includes critical block base for block use.
using namespace std;
class BlockChain 
{
	friend Block;
public:
    BlockChain();
	void NewBlock(Block bnew); // function to build in a new block for the chain
	void CurrentBlockContent(Block &Block); // gives the current information of the most recent block entry
private:
	int Chain_Size; // handles index incrementation
	vector<Block> ChainSystem;  // vector to declare the block
	Block RetrievePreviousBlock() const;  // pulls previous block for linking
};
#endif