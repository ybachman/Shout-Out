#ifndef USERMENU_H
#define USERMENU_H

#include <string>
#include <iostream>
#include "ShoutOut.h"
#include "Message.h"
#include "sff_Holder.h"

using namespace std;

class UserMenu
{
private:
    string user;

protected:
	map<string, User*, abcOrder>* members;	 //Holds pointer to map of Users
  
	sff_Holder* holdSFF;							  //Holds pointer to sfl_Holder singleton friend class.
	multimap<string, string>::iterator flNum;		  //Iterator for Following or Follower Map
	map<unsigned int, Message*>::iterator Snum;			//Iterator for shouts. 

public:
    //Default Constructor
	 UserMenu(map<string, User*, abcOrder>*);	 

    //Destructor
    ~UserMenu();

	
	// Mutators
	void setUser(string);	 //Set name of Current User for display

	// Accessors
	string getUser();

	void showHeader();
	//Account Menu
	char pageOptions(string);			  
	string pagePrompt(string);
	bool confirm(string);

	void accPage();							  
	void makeMsg(int);						  
  
	void viewFollowing();
	void followingMenu(char);
	void viewFollowers();

	bool validName(string &);
	bool validFollowing(string &);
	bool validFollow(string &);

	//Shout options
	void ShoutPage();		
	void PrivatePage();		 
	void UserPage(string);	 
	void ShowShouts();		
};

#endif    