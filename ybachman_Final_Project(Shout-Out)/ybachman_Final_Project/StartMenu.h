#ifndef STARTMENU_H
#define STARTMENU_H

#include <string>
#include <iostream>
#include "User.h"
#include "abcOrder.h"
#include "UserMenu.h"
#include "sff_Holder.h"
#include <map>

using namespace std;

class StartMenu
{
private:
	string name;	  
	string pass;	  
	void Login();	  
	void newAccount();	
	bool finalize(string, string);		

protected:
	map<string, User*, abcOrder>* members;

public:
	//Default Constructor
	StartMenu(map<string, User*, abcOrder>*);
	//Destructor
	~StartMenu();

	//Accessors
	string getName();
	string getPass();
	map<string, User*, abcOrder>* getMembers();

	//Mutators
	void setName(string);
	void setPass(string);
	void setMembers(map<string, User*, abcOrder>*);

	//Other functions
	void Menu();		 
	 
	//Validate Username
	bool validName(string);
	//Validate Password
	bool validPass(string);
};

#endif  