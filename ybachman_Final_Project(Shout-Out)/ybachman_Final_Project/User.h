#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
  string username;
  string password;

public:
  //Constructors
  User();
  User(string, string);

  //Destructor
  ~User();

  //Accesors
  string getUsername();
  string getPassword();

  //Mutators
  void setUsername(string);
  void setPassword(string);

};
#endif