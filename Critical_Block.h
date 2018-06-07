
#ifndef CRITICAL_BLOCK_H
#define CRITICAL_BLOCK_H
#include <cstring>  // use of string
#include <cstdint>   // use for bitwise integer values
/*
block holds all the standard elements of the transaction.
*/
using namespace std;
class Block // parent class for all critical blocks
{
public:
	Block();// standard constructor
	Block( const string& data, int VoterIDNumber); // updating constructor

	
	inline string getHash() { return hash; }; // returns hash
	inline void displayCurrenthash() { printf("%s\n", hash.c_str()); }; // displays current hash
	
	inline void displayPreviousHash() { printf("%s\n", previoushash.c_str()); }; // calls previous hash
	inline void displayProofHash() { printf("%s\n", proofhash.c_str()); };
	inline void displayNonce() { cout << nonce << endl; };
	inline string returnProofHash() { return proofhash; };
	inline void displayid() { cout << VoterIDNumber;};
	inline void displaydata() { printf("%s\n", data.c_str()); };
	void HashBlock(); // Creates a new hash for the block.
	void MineBlock(Block& NewBlock);

	string previoushash; // is the previous hash as a string
	string CalculateHash() const; // sends the inital calculation to the sha256_value
	int nonce = 0;

	private:
	int VoterIDNumber; // voting Identification Number
	time_t timevalue; // stores time value
	string hash; // stores hash
	string proofhash;
	string data; // relative data to be changed later.
};
#endif
