// Author: Ibrahim Altaweel (Abe)
#ifndef bnb_member_h
#define bnb_member_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class bnb_member
{
  public:
  string get_id();
  string get_name();
  int get_count();
  void set_id(string id);
  void set_name(string name);
  void set_count(int count);
  void increase_count();

  private:
  string id;
  string name;
  int count;
};
#endif
