#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <string>
using namespace std;

class BOT
{
public:
	BOT();
	inline int getUSERID() { return BotID; };
	inline void displayBotID() { cout << BotID << endl; };
	inline void setBotID(int& value) { BotID = value; };
	inline void setVote(string& value) { vote = value; };
	inline string returnvote() { return vote; };
	string vote;
private:
	int BotID;
};
#endif