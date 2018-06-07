#ifndef BOTMANIPULATION_H
#define BOTMANIPULATION_H
#include <iostream>
#include <string>
#include "Bot.h"
#include <vector>
using namespace std;

class BOTClassModifier
{
	friend BOT;
public:
	BOTClassModifier(); //constructor
	
	inline void setswarmsize() { BOT_Swarm.resize(swarmsize); }; //sets swarmsize
	void setBOTID(BOT& bot); // sets the identification number for bot
	vector<BOT> BOT_Swarm; // vector of swarm to the size of swarmsize
	void setChoiceforVote(BOT& bot);
private:
	int swarmsize =  10000; // sets swarm size
	double NewinitalWalletValue; // starting value for all bots once it has been passed
	double tradevalue; // if there is a trade then this updates to the amount to be traded
	int incrementationID = 0; 
};
#endif