#ifndef SFF_HOLDER_H
#define SFF_HOLDER_H

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "abcOrder.h"
#include "Message.h"

using namespace std;

class sff_Holder 
{
private:
	friend class UserMenu;  

	unsigned int numKey;
	static sff_Holder* SFF;
	sff_Holder();

	multimap<string, string>::iterator flNum;		//Iterator for follower and following Map
	multimap<string, string, abcOrder> followers;	//Container of Followers
	multimap<string, string, abcOrder> following;		//Container of Following

	map<unsigned int, Message*> Shouts;				//Container of shouts/whispers
	map<unsigned int, Message*>::iterator sNum;		//Iterator for shouts

public:
	static sff_Holder* getSFF();
	void setNumKey(unsigned int);
	unsigned int getNumKey();

	~sff_Holder();

	//Maintain follower and following lists
	void fillFL();	
	void fillS();
	void updateFL();
	void updateS();
	void addFL(string, string);	
	void addS(int, string, string, string);
	void removeFL(string, string);		
	void viewFollow();		
	void viewFollowing();
};
#endif