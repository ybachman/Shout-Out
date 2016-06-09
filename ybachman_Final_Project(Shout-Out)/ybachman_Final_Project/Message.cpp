#include "Message.h"

using namespace std;

//Default Constructor 
Message::Message(int typ, string name1, string name2, string txt)
{
	type= typ;
	nameA = name1;
	nameB = name2;
	text = txt;
	//setTimestamp();
}

//Destructor 
Message::~Message()
{
  
}

void Message::showShout()
{
	if(getType() == 1)
	{
		cout << "\n***<" << getNameA() << ">************************************************************\n\n";
		cout << " " << text << endl << endl;
		cout << "*********************************************************************\n\n";  
	}
	if(getType() == 2)
	{
		cout << "\n***<" << getNameA() << ">************************************************************\n\n";
		cout << " " << text << endl << endl;
		cout << "*********************************************************************\n\n";  
	}
}

// Mutators 
void Message::setType(int t)
{
	type = t;
}

void Message::setNameA(string n)
{
	nameA = n;
}

void Message::setNameB(string n)
{
    nameB = n;
}

void Message::setText(string t)
{
    text = t;
}

/*
void Message::setTimestamp()
{

}
*/

// Accessors 
int Message::getType()
{
    return type;
}

string Message::getNameA()
{
    return nameA;
}

string Message::getNameB()
{
    return nameB;
}

string Message::getText()
{
    return text;
}

/*
string Message::getTimestamp()
{
	return timestamp;
}
*/