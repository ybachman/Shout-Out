#include "StartMenu.h"

using namespace std;

// Default Constructor 
StartMenu::StartMenu(map<string, User*, abcOrder>* accDat)
{
	members = accDat;
	name = "";
	pass = "";
}
// Destructor 
StartMenu::~StartMenu()
{

}

void StartMenu::Menu()
{
	char choice;

	system("CLS");
	//Continue displaying menu until user chooses to exit.
	do{

		cout << "  _______  __   __  _______  __   __  _______       _______  __   __  _______ " << endl;
		cout << " |       ||  | |  ||       ||  | |  ||       |     |       ||  | |  ||       |" << endl;
		cout << " |  _____||  |_|  ||   _   ||  | |  ||_     _|____ |   _   ||  | |  ||_     _|" << endl;
		cout << " | |_____ |       ||  | |  ||  |_|  |  |   | |____||  | |  ||  |_|  |  |   |  " << endl;
		cout << " |_____  ||       ||  |_|  ||       |  |   |       |  |_|  ||       |  |   |  " << endl;
		cout << "  _____| ||   _   ||       ||       |  |   |       |       ||       |  |   |  " << endl;
		cout << " |_______||__| |__||_______||_______|  |___|       |_______||_______|  |___| " << endl;
		cout << " ____________________________________________________________________________"<< endl;
		cout << "|                                                                            |"<< endl;
		cout << "|____________________________________________________________________________|"<< endl;
		cout << ""<< endl;
		cout << "\n1)Login\n\n2)New Account\n\n3)Exit\n\n";
		cin>>choice;

		cin.clear(); cin.ignore(INT_MAX,'\n');	 //Clears the cin buffer

		switch(choice)
		{ 
			case '1':
				cout << "\nLogging In...\n\n";
				Login();	 //Call Login Methods
				setName("");
				setPass("");
				break;

			case '2':
				cout<<"\nCreating a new Account...\n\n";
				newAccount();		 //call New Account methods
				setName("");
				setPass("");
				break;
			case '3':
				cout << "\nExiting...\n\n";
				break;
			default:
				cout<<"\ninvalid option\n\n";
				break;		
		}
  
		system("CLS");
  
	}while(choice != '3');
}

void StartMenu::Login()
{
	string username;
	string password;
	UserMenu* AccountPage;
	AccountPage = new UserMenu(members);

	char back = 'a';
	bool fail = false;
  
	do{
		system("CLS");

		cout << "Login Menu\n\nPlease Enter your Username:\n>";
		cin >> username;
		if(validName(username))
		{
			cout << "\nPlease Enter your Password\n>";
			cin >> password;

			if(validPass(password)) //test if password is valid(matches the username)
			{
				AccountPage->setUser(name);
				AccountPage->accPage();
		  
				fail=false;
			}
			else
			{ fail = true;
				cout<<"\nIncorrect Password\n";
			}
		}
		else
		{
			fail = true;
			cout << "\nThe Username: " << username << " could not be found\n";
		}

		cin.clear(); cin.ignore(INT_MAX,'\n');  //Clears the cin buffer to prevent un intended entries.

		if(fail)	 //logic which allows for failed attempts to try again.
		{
			fail = false;
			cout << "\n\n1)Retry Login\n2)Exit\n>";	 //prompt user to retry loging in.
			cin >> back;
		}
		else
		{
			back = '2';
		}
	 
		cin.clear(); cin.ignore(INT_MAX,'\n');  //Clears the cin buffer
  
	}while(back != '2');

	delete AccountPage;
}


void StartMenu::newAccount()
{
	string username = "";
	string password = "";
	UserMenu* AccountPage;
	AccountPage = new UserMenu(members);
	char choice = 'a';
	bool fail = false;
    
	do{
		system("CLS");

		cout << "New Account\nPlease Enter a Username.\n>";	  //prompt user to enter a unique username.
		cin >> username;

		if(validName(username))
		{
			cout << "The username: " << username << " has already been taken.\n";	 //display message that the name is already taken.
			fail = true;
		}
		else
		{
			cout << "\n\nPlease Enter a Password.\n>";	//prompt user to enter a password.
			cin >> password;

			if(finalize(username, password))		//Prompt user to finalize account
			{
				fail = false;
				setName(username);		//set username and password for logged in account.
				setPass(password);

				User* mem;					  //Account pointer to add into (*members)
				mem = new User(name, pass);

				(*members)[name] = mem;
		  
				AccountPage->setUser(name);	  //AutoLoging upon Account Creation.
				AccountPage->accPage();		  

			}
			else
			{ 
				fail = true;
			}
		}

		if(fail)	 //Logic which allows failed attempts to try again.
		{
			fail = false;
			cout << "\n\n1)Create New Account\n2)Exit\n>";	 //Prompt user to retry logging in.
			cin >> choice;
		}
		else
		{
			choice = '2';
		}

	}while(choice != '2');

	delete AccountPage;
}

bool StartMenu::validName(string username)
{
	bool found;
	if ((*members).find(username) == (*members).end())	  //search map for a key that matches username;
	{
		found = false;	  //username did not match any of the map's keys
	} 
	else 
	{
		found = true;	  //username matched one of the map's keys

		//set username and password of the logged in user.
		setName((*members)[username]->getUsername());	  
		setPass((*members)[username]->getPassword());
	}
	return found;	 
}


bool StartMenu::validPass(string password)  //Check if password matches username.
{
	return password == (*members)[name]->getPassword();
}

bool StartMenu::finalize(string username, string password)		//Ask user if he/she wants to create the account.
{
	char choice;

	cout << "\nFinalize Account\n\nUsername: " << username << "\nPassword: " << password;
	cout << "\n\n1) Finalize\n2) Cancel\n";
	cin >> choice;
  
	return choice == '1';	//If user enters 1. Finalize return true else return false
}

// Mutators 
void StartMenu::setName(string Name)
{  
	name = Name; 
}

void StartMenu::setPass(string Pass)
{  
	pass = Pass;
}

void StartMenu::setMembers(map<string, User*, abcOrder>* accDat)
{
  members = accDat;
}

// Accessors 
string StartMenu::getName()
{ 
	return name;
}

string StartMenu::getPass()
{  
	return pass;
}

map<string, User*, abcOrder>* StartMenu::getMembers()
{
	return members;
}
