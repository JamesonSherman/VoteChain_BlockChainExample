#include <iostream>
#include <string>
#include "Bot.h"
#include "BotManipulation.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

BOTClassModifier::BOTClassModifier()
{
	setswarmsize(); //set swarmsize
}

BOT::BOT()
{
	int BotID = 0; // constuctor for bot id
}


void BOTClassModifier::setBOTID(BOT& Bot)
{
	incrementationID++;  
	Bot.setBotID(incrementationID);   // sets the bot id as they increase
}

void BOTClassModifier::setChoiceforVote(BOT& bot)
{
	string Intel = "Intel";
	string AMD = "AMD";
	int votingValue = rand() % 2 + 1;

	if (votingValue == 1)
	{
		bot.setVote(Intel);
	}
	else
	{
		bot.setVote(AMD);
	}
	// creates voting set and size 
}
