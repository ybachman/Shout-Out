#ifndef SHOUTOUT_H
#define SHOUTOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "User.h"
#include "StartMenu.h"
#include "abcOrder.h"

using namespace std;

class ShoutOut
{
private:
	map<string, User*, abcOrder> accDat; 
	map<string, User*>::iterator accNum;

public:
	//Destructor
	~ShoutOut();

	ShoutOut();
	//Call Start object to display menus.
	void Start();
	void view();
	//Fill the Accounts map with Data
	void fillAccounts();
	//Update all files.
	void UpdateFiles();	  

};
#endif

