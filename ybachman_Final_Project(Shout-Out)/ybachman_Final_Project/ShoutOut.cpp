#include "ShoutOut.h"

using namespace std;

ShoutOut::ShoutOut()
{
  fillAccounts();
}

ShoutOut::~ShoutOut()
{
	for(accNum = accDat.begin(); accNum != accDat.end(); accNum++)
	{
		delete accNum->second;	 //Calls destructor for account object.
	}
}

void ShoutOut::fillAccounts()
{
	string tempName = "";	//Temporary variables to transfer data into the account
	string tempPass = "";

	User* acc;	//Account pointer

	fstream accFile;
	accFile.open("Accounts.dat", ios::in);	//open file of accounts.

	while(accFile >> tempName)		//While(!eof) tempName = username from file
	{
		accFile >> tempPass;			//tempPass = password from file

		//Call overloaded constructor to bypass validation
		acc = new User(tempName, tempPass);	

		accDat[tempName] = acc;
	}

	accFile.close();
}

void ShoutOut::UpdateFiles()
{
	fstream accFile;
	accFile.open("Accounts.dat",ios::out);	//reWrite file 

	for(accNum = accDat.begin(); accNum != accDat.end(); accNum++)
	{
		accFile << accNum->first << "    " << accNum->second->getPassword() << endl;
	}
	accFile.close();
}

void ShoutOut::view()
{
	//Display Accounts (Usernames and Passwords)
	//accDat map of Accounts
	//accNum iterator for accDat

	cout << "Now Displaying all User accounts\n\n";

	for(accNum = accDat.begin(); accNum != accDat.end(); accNum++)  //Loop through map.
	{
		cout << "UserName: " << accNum->second->getUsername();
		cout << "    Password: " << accNum->second->getPassword() << "\n";	 	 
	}
}

void ShoutOut::Start()
{
	StartMenu mainMenu(&accDat);
	mainMenu.Menu();//Call the ShoutOut.com menu page.
	UpdateFiles();
}