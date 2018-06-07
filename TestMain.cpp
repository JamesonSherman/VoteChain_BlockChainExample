
#include <iostream>
#include <string>
#include <stdlib.h>  
#include <time.h>       /* time */
#include <chrono>
#include <cstdio>
#include <thread>
#include <ctime>
#include "Critical_Block.h"
#include "BlockChain.h"
#include "Bot.h"
#include "BotManipulation.h"
using namespace std::this_thread;     // sleep_for, sleep_until

using std::chrono::system_clock;
using namespace std;


void workspace()
{
	srand(time(NULL));
	int amd = 0;
	int intel = 0;
	// SUCCESS ON HASH BUILDING

	BlockChain testchain = BlockChain(); // creates a new blockchain system named testchain
	BOTClassModifier FullBot = BOTClassModifier();  //creates a bot controller
	//	Block( const string& data, int VoterIDNumber); // updating constructor
	for (int i = 0; i < FullBot.BOT_Swarm.size(); i++)  // for loop to cycle the blocks and bot votes
	{
		FullBot.BOT_Swarm[i].setBotID(i);  //sets the bot id based off the i value of for loop
		FullBot.setChoiceforVote(FullBot.BOT_Swarm[i]); // sets vote for bot controller

		testchain.NewBlock(Block(FullBot.BOT_Swarm[i].vote, FullBot.BOT_Swarm[i].getUSERID())); // testchain with the new block
		if (FullBot.BOT_Swarm[i].vote.compare("Intel")) //compares intel as vote otherwise increments amd
		{ 
			++intel; 
		}
		else
		{
			++amd;
		}
	//	sleep_until(system_clock::now() + 1s);
	}
	// output depending. 
	if (intel > amd)
	{
		cout << "Intel won! Won with: " << intel << " number of votes" << endl;
		cout << "AMD had: " << amd << " votes" << endl;
	}
	else if (amd > intel)
	{
		cout << "AMD won! Won with: " << amd << " number of votes" << endl;
		cout << "Intel had: " << intel << " number of votes" << endl;
	}
	else
	{
		cout << "It was a tie!" << endl;
		cout << "AMD had: " << amd << " votes" << endl;
		cout << "Intel had: " << intel << " number of votes" << endl;

	}

}


int main()
{
	clock_t start;
	double duration;

	start = clock();
	workspace();
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;

	cout << " " << endl;
	cout << "Time needed to complete transaction Cycle: " << duration << " Seconds " << endl;
	system("pause");
	EXIT_SUCCESS;
}



