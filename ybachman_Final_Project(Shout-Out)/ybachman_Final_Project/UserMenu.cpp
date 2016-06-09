#include "UserMenu.h"

using namespace std;

// Default Constructor 
UserMenu::UserMenu(map<string, User*, abcOrder>* accountList)
{
	members = accountList;	
	holdSFF= sff_Holder::getSFF();
  
	user="";
}

// Destructor 
UserMenu::~UserMenu()
{
  
}

//Menu prompts and headers

void UserMenu::showHeader()	 //Displays a header of who the current loged in user is.
{
	system("CLS");
	cout << "Current User <"<< getUser() <<">\n";
}

char UserMenu::pageOptions(string options)	//Displays the menu options based on which menu called it.
{
	//Reset choice
	char choice='a';
  
	cout << "\n" << options << "\n\n>";

	cin >> choice;

	return choice;
}

string UserMenu::pagePrompt(string prompt)	//getline prompt for getting a username or text for a shout.
{
	cin.clear(); cin.ignore(INT_MAX,'\n');
	string msg;
	cout << "\n" << prompt << "\n\n>";
  
	getline(cin,msg);
  
	return msg;
}

bool UserMenu::confirm(string ask)
{
	char choice;
	cout << "\n" << ask <<"\n\n>";
	cin >> choice;
	return choice == '1';
}

//View the shouts

void UserMenu::UserPage(string pName)
{
	char choice='a';

	//Loop until user selects exit
	while(choice != '2')
	{
		showHeader();
		cout << "\t" << pName << "'s Shout Page\n\n";

		for(Snum = holdSFF->Shouts.begin(); Snum != holdSFF->Shouts.end(); Snum++)
		{
			if(Snum->second->getNameA() == pName) //Display Shouts Posted by A certian User
			{
				if(Snum->second->getType() == 1)	//Display Public Shouts
				{
					if(Snum == holdSFF->Shouts.end())
					{
						break;
					}
					else
					{			
						Snum->second->showShout();
						choice = pageOptions("1)More Shouts\n2)Exit");
					}
				}
			}
		}

		//choice = pageOptions("1)More Shouts\n2)Exit");
  
	}

	cout << endl << endl;
	system("pause");   
}

void UserMenu::PrivatePage()
{
	char choice='a';
  
	do
	{
		showHeader();
		cout << "\t" << user <<"'s Private Shout Page \n\n";

		for(Snum = holdSFF->Shouts.begin(); Snum != holdSFF->Shouts.end(); Snum++)
		{
			if(Snum->second->getNameB() == user) //Display Shouts Posted by A certian User
			{
				if(Snum->second->getType() == 2)	//Display Public Shouts
				{
					if(Snum == holdSFF->Shouts.end())
					{
						break;
					}
					else
					{			
						Snum->second->showShout();
						choice = pageOptions("1)More Shouts\n2)Exit");
					}

				}
			}

		}

	choice = pageOptions("1)More Shouts\n2)Exit");
  
	}while(choice != '2');

	cout << endl << endl;
	system("pause");   
}


void UserMenu::ShoutPage()
{
	char choice='a';
	showHeader();

	choice = pageOptions("1)View Public Shouts\n2)View Private Shouts\n3)Exit");

	if(choice == '1')
	{
		UserPage(user);
	}
	else 
	{
		if(choice == '2')
		{
			PrivatePage();
		}
	}

	cout << "\n\nExiting...";
}



//User menus
void UserMenu::accPage()
{
	char choice='a';

	do{
		showHeader();

		choice = pageOptions(" 1)Post Shout\n\n 2)Send Whisper\n\n 3)Shout Page\n\n 4)View Following\n\n 5)View Followers\n\n 6)Logout");
	 
				switch(choice)		//Case Structure for The Account Page 
		{
			case '1':
				cout << "\nPost Shout\n\n";
				makeMsg(1);		 //send 1 to indicate standard shout.
				break;

			case '2':
				cout << "\nSend Whisper\n\n";
				makeMsg(2);		 //send 2 to indicate private shout.
				break;
		  
			case '3':
				cout << "\nShout Menu\n\n";
				ShoutPage();
				break;

			case '4':
				cout << "\nView Following\n\n";
				viewFollowing();
				break;
		  
			case '5':
				cout << "\nView Followers\n\n";		 
				viewFollowers();
				break;

			case '6':
				cout << "\nLogging Out..\n\n";
				break;

			default:
				cout << "\ninvalid option\n\n";
				break;		
		}  
  
	}while(choice != '6');

}

//Used to make Public Shouts and Private Whispers
void UserMenu::makeMsg(int type)			
{
	string nameA = user;
	string nameB = "";
	string text = "";

	//setTimestamp();

	switch (type)
	{
	case 1:			//Tpye 1 Public Shout
		showHeader();
		text = pagePrompt("-Public Shout\nPlease Enter your message below.(under 80 characters)");	//Send Prompt Message and get Input from user.
		nameB = "0";
		break;

	case 2:		 //Type 2 Private Shout/Whisper
		showHeader();
		nameB = pagePrompt("Who would you like to send a message to?");
		
		//Validate user to send to
		if(validName(nameB))
		{
			text = pagePrompt("-Private Whisper\nPlease Enter your message below.(under 80 characters)");
		}
		else
		{
			type = -1; //Name didn't match.
		}
		break;

	default:
		break;
	};

	//Check Text Length
	if(text.length() > 80)
	{
		cout << "\nYour message exceeds the 80 character limit\nYour message is " << text.length() << " characters long\n\n";		
	}
	else if(type == -1)
	{
		cout << "User " << nameB << " does not exist.\n\n";		
	}
	else
	{
		if(confirm("Post Shout    1)Post    2)Cancel"))
		{
			cout << "\n\nMessage Posted";
			holdSFF->addS(type, user, nameB, text);
		}		
	}

	cout << endl << endl;
	system("pause");
}

//View Followers
void UserMenu::viewFollowing()
{
	char choice = 'a';
	int count = 0;

	showHeader();
	cout << "Who you are Following\n\n";

	for(flNum = holdSFF->following.begin(); flNum != holdSFF->following.end(); flNum++)
	{
		if(flNum->second == user)
		{
		 cout << flNum->first << endl;
		 count++;
		}
	}

	choice = pageOptions("  1)Select Following\n\n  2)Add a Following\n\n  3)Remove a Following\n\n  4)Account Page");
	
	if(choice != '4')
	{
		followingMenu(choice);
	}

	cout << endl << endl;

	system("pause");
}

void UserMenu::followingMenu(char choice)
{
	string fName = "";
	showHeader();

	if(choice == '1')
	{
		fName = pagePrompt("Please Enter the following's UserName.");
		if(validFollowing(fName))
		{
			if(confirm("1)View Followers's Page\n2)Cancel"))	  
			{
				UserPage(fName);									
			}	 
		}
		else
		{
		cout << "\nNo following named <" << fName << ">\n";	 
		}  
	}
	if(choice == '2')	  
	{
		fName = pagePrompt("Please enter a Username.");	 //Prompt for user to enter Following's Name

		if(validFollowing(fName))				//Check to see if User is already Following
		{
		cout << "\nAlready following <" << fName << ">.\n";
		}
		else
		{
		if(validName(fName))		//Check to see if the User entered an existing name.
		{
			if(fName != user)			//Check to make sure user didn't enter his/her own name.
			{
				if(confirm("Add Following?\n\n1)Confirm\n2)Cancel"))	  //Confirm adding new Following
				{
				holdSFF->addFL(user,fName);
				}		  
			}
			else
			{
				cout << "\nYou cannot follow yourself.\n";
			}
		}
		else
		{
			cout << "\nNo user named <" << fName << "> found.\n";
		}
		}
	}

	if(choice == '3')
	{
		fName = pagePrompt("Enter a following's Username.");
		if(validFollowing(fName))
		{
			if(confirm("Remove following?\n\n1)Confirm\n2)Cancel"))
			{
				holdSFF->removeFL(user,fName);
			}
		}
		else
		{
			cout << "\nYou are not following <" << fName << ">.\n";
		}
	}
}


//View Followers
void UserMenu::viewFollowers()
{
	char choice = 'a';
	string fName = "";
	int count = 0;

	showHeader();
	cout << "\tYour Followers\n\n";

	for(flNum = holdSFF->followers.begin(); flNum != holdSFF->followers.end(); flNum++) //Display all of User's Followers.
	{
		if(flNum->second == user)
		{
		cout << flNum->first << endl;
		count++;
		}	 
	}

	cout << endl << endl;
	if(count < 1)		//Check if User has followers
	{
		cout << "you have no followers\n\n";
	}
	else
	{
		choice = pageOptions("1)Select Follower\n2)Account Page");
  
		if(choice == '1')
		{
		showHeader();
		fName = pagePrompt("\nPlease Enter the follower's Username");			//Prompt user for name of Follower
		if(validFollow(fName))															//Validate Name Entry.
		{
			if(confirm("1)View Follower's Page\n2)Cancel"))
			{
				UserPage(fName);								//Call View Page to display fName's Shouts
			}
		}
		else
		{
			cout << "\nNo follower named <"<<fName<<">.\n";
		}
		}
	}

	cout << endl << endl;
	system("pause");
}

//Validation
bool UserMenu::validFollow(string &fName)
{
	bool found = false;

	for(flNum = holdSFF->followers.begin(); flNum != holdSFF->followers.end(); flNum++)
	{
		if(flNum->first == fName && flNum->second == user)
		{
			found = true;
			fName = flNum->first;
			break;
		}
		else
		{
			found = false;
		}
	}

	return found;
}

bool UserMenu::validFollowing(string &fName)	 //Altered for Case sensitive Testing
{
	bool found = false;

	for(flNum = holdSFF->following.begin(); flNum != holdSFF->following.end(); flNum++)
	{
		if(flNum->first == fName && flNum->second == user)
		{
			found = true;
			fName = flNum->first;
			break;
		}
		else
		{ 
			found=false;
		}
	}

	return found;  
}

//Validate usernames
bool UserMenu::validName(string &username)	 
{
	bool found;
	if ((*members).find(username) == (*members).end())	  //search map for a key that matches username;
	{
		found = false;	
	}							//username did not match any of the map's keys
	else 
	{	
		found = true;	 				//username matched one of the map's keys
		username = ((*members)[username]->getUsername());	 
	}
	return found;
}

// Mutators 
void UserMenu::setUser(string u)
{    
	user = u;
}



// Accessors 
string UserMenu::getUser()
{    
	return user;
}

