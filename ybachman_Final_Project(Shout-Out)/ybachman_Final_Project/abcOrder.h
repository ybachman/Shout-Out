#ifndef ABCORDER_H
#define ABCORDER_H

#include<string>
#include<map>

using namespace std;

class abcOrder 
{ 
public:
	//Overloaded operator
   bool operator() (const std::string& lhs, const std::string& rhs) const 
	 {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

#endif