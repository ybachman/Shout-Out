/*
Author: Yulia
Program: Shout-Out, Final Project

*/

#include <iostream>
#include <string>
#include <map>
#include "ShoutOut.h"
#include "sff_Holder.h"		 

using namespace std;

int main()
{
	//Blue text color
	system( "color 0B" );

	sff_Holder* sffH; //Shout, Followers, Following Holder
	sffH= sff_Holder::getSFF();

	ShoutOut  shoutout;

	shoutout.Start();
	
	delete sffH;
  
	cout<<"\n\n";
	system("pause");

	return 0;
}