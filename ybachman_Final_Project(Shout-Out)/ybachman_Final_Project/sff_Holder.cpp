#include "sff_Holder.h"

using namespace std;

sff_Holder* sff_Holder::SFF = NULL;

sff_Holder* sff_Holder::getSFF()
{
	if (SFF == NULL)
	SFF = new sff_Holder();
	return SFF;
}	 

sff_Holder::sff_Holder()
{
	numKey = 0;
	fillFL();	 //Fill Container Following And Followers.
	fillS();		 //Fill Container Shouts
}

sff_Holder::~sff_Holder()	//Destructor
{
	updateS();
	updateFL();
	followers.clear();
	following.clear();

	for(sNum = Shouts.begin(); sNum != Shouts.end(); sNum++)		//deallocate Shouts.
	{
		delete sNum->second;
	}
}

void sff_Holder::setNumKey(unsigned int num)	  //Set Numkey(Key for Shout Map)
{
	numKey = num;
}

unsigned int sff_Holder::getNumKey()		//get NumKey(Key for Shout Map)
{
	return numKey;
}

//Followers/Following
void sff_Holder::fillFL()
{
	string NameA = "";
	string NameB = "";

	fstream flRead;
	flRead.open("FollowList.dat", ios::in); //open file of Followers
	 
	while(flRead >> NameA)
	{
		flRead >> NameB;
		followers.emplace(NameA, NameB);
		following.emplace(NameB, NameA);	 
	}
	flRead.close();
}

//Shouts
void sff_Holder::fillS()
{
	int typ = 0;
	string name1 = "";			//name of Author or sender
	string name2 = "";			//name of recipient
	string txt = "";			//hold text msg
	fstream readS;				//read Shouts from file


	readS.open("Shouts.dat",ios::in);

	while(readS>>typ)	//Test for End Of File and get typ
	{
		readS >> name1;	 
		readS >> name2;	 
		getline(readS,txt);		

		addS(typ,name1,name2,txt);		//Add Shouts to Container	
	}	 

	readS.close();
}

void sff_Holder::updateFL() //Update file after being Run.
{
	int check = 0;
	fstream flwrite;

	flwrite.open("FollowList.dat",ios::out);  //Write file

	for(flNum = followers.begin(); flNum != followers.end(); flNum++)
	{
		flwrite << flNum->first << "  " << flNum->second << endl;
	}

	flwrite.close();
}

void sff_Holder::updateS()
{
	fstream writeS;
	writeS.open("Shouts.dat",ios::out);

	for(sNum = Shouts.begin(); sNum != Shouts.end(); sNum++)
	{
		writeS << sNum->second->getType() << "  ";	 
		writeS << sNum->second->getNameA() << "  ";	 
		writeS << sNum->second->getNameB() << "  ";	 
		writeS << sNum->second->getText() << endl;	 
	}
}

void sff_Holder::addFL(string NameA, string NameB)	 //Add entries when User selects Add Leader.
{
	followers.emplace(NameA,NameB);
	 
	following.emplace(NameB,NameA);  
}

void sff_Holder::addS(int typ, string name1, string name2, string txt)	  //Add Shouts to Container
{
	unsigned int num = getNumKey();
	Message* ShoutNum;

	ShoutNum = new Message(typ, name1, name2, txt);

	Shouts[num] = ShoutNum;

	num++;
	setNumKey(num);
}

void sff_Holder::removeFL(string NameA, string NameB)	//Erase entries when User selects Remove Leader.
{
	for(flNum = followers.begin(); flNum != followers.end(); flNum++)
	{
		if(flNum->first == NameA && flNum->second == NameB)
		{
			followers.erase(flNum);
			break;
		}
	}

	for(flNum = following.begin(); flNum != following.end(); flNum++)
	{
		if(flNum->first == NameB && flNum->first == NameA)
		{
			following.erase(flNum);
			break;
		}
	}
}

void sff_Holder::viewFollow()
{
	system("CLS");
	cout<<"Now Displaying All Followers...\n";

	for(flNum = followers.begin(); flNum != followers.end(); flNum++)
	{
		cout << flNum->first << "is following" << flNum->second << endl;
	}  
  
	cout<<"\n\n";
	system("pause");
}

void sff_Holder::viewFollowing()
{
	system("CLS");
	cout<<"Now Displaying All Followers\n";

	for(flNum = following.begin(); flNum != following.end(); flNum++)
	{
		cout << flNum->first << " is following  "<< flNum->second << endl;
	}  
  
	cout<<"\n\n";
	system("pause");
}