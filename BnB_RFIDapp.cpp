// Author: Ibrahim Altaweel

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "BnB_RFID.h"

using namespace std;

#include <cstdlib>

int main()
{
  cout<<"processing the files...\n";
  map<string,bnb_member> myMap;//a map to update counts.key:id, value:BnB_RFID object
  fstream bnb_members;//file to be read
  bnb_members.open ("bnb_members.txt", ios::in);
  if (!(bnb_members.is_open()))
  {
    cout<<"bnb_members.txt does not exsist!\n";
  }
  else
  {
    cout<<"bnb_members.txt exsist!\n";
  }
  string line_of_txt;

  //loop to fill in myMap
  while (getline(bnb_members,line_of_txt))
    {
      istringstream iss(line_of_txt);
      string id,name,count;
      bnb_member member;
      getline( iss, id, ' ' );
      member.set_id(id.c_str());
      getline( iss, name, ' ' );
      member.set_name(name.c_str());
      getline( iss, count, ' ' );
      member.set_count(atoi(count.c_str()));
      myMap[id]=member;
    }

  bnb_members.close();

  fstream temp_bnb_members;//temporary file to record current attendance
  string temp_id;
  temp_bnb_members.open ("temp_bnb_members.txt", ios::in);
  if (!(temp_bnb_members.is_open()))
  {
    cout<<"temp_bnb_members.txt does not exsist!\n";
  }
  else
  {
    cout<<"temp_bnb_members.txt exsist!\n";
  }


  //if id is present, increase count
   while (getline(temp_bnb_members,temp_id))
   {
      myMap[temp_id].increase_count();
   }

  fstream final;//final file
  final.open ("final.txt", ios::out);
  if (!(final.is_open()))
  {
    cout<<"final.txt does not exsist!\n";
  }
  else
  {
    cout<<"final.txt exsist!\n";
  }
    typedef map<string, bnb_member>::iterator it_type;
    for(it_type iterator = myMap.begin(); iterator != myMap.end(); iterator++)
    {
      final<<iterator->first<<" "<<myMap[iterator->first].get_name()<<" "<<myMap[iterator->first].get_count()<<"\n";
    }

    final.close();
}
