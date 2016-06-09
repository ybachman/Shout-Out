#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Message
{
private:
    int type;
    string nameA;
    string nameB;
    string text;
	//string timestamp;

public:
    //Default Constructor
    Message(int, string, string, string);

    //Destructor
    ~Message();

	 void showShout();

    //Mutators
    void setType(int);
    void setNameA(string);
    void setNameB(string);
    void setText(string);
	//void setTimestamp();

    //Accessors
    int getType();
    string getNameA();
    string getNameB();
    string getText();
	//Get timestamp
	//string getTimestamp();
};

#endif 