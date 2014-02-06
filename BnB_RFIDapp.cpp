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
  map<string,bnb_member> myMap;
  fstream bnb_members;//final file
  bnb_members.open ("/Workspace/TEMP/TEMP/bnb_members.txt", ios::in);
  string line_of_txt;

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

  fstream temp_bnb_members;//temporary file
  string temp_id;
  temp_bnb_members.open ("/Workspace/TEMP/TEMP/temp_bnb_members.txt", ios::in);

   while (getline(temp_bnb_members,temp_id))
   {
    myMap[temp_id].increase_count();
   }

    fstream final;//final file
    final.open ("/Workspace/TEMP/TEMP/final.txt", ios::out);

    typedef map<string, bnb_member>::iterator it_type;
    for(it_type iterator = myMap.begin(); iterator != myMap.end(); iterator++)
    {
      final<<iterator->first<<" "<<myMap[iterator->first].get_name()<<" "<<myMap[iterator->first].get_count()<<"\n";
    }

    final.close();
}
