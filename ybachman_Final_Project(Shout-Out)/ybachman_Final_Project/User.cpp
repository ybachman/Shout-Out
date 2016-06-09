#include "User.h"
#include <string>

using namespace std;

//Default Constructor 
User::User()
{
  username="";
  password="";
}

//Constructor
User::User(string name, string pass)
{
  username = name;
  password = pass;
}
//Destructor 
User::~User()
{

}

//Accessors 
string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}

//Mutators 
void User::setUsername(string name)
{
    username = name;
}

void User::setPassword(string pass)
{
    password = pass;
}