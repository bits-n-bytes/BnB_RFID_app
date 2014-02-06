// Author: Ibrahim Altaweel

#include "BnB_RFID.h"

  void bnb_member::set_id(string id)
  {
    this->id = id;
  }
  void bnb_member::set_name(string name)
  {
    this->name= name;
  }
  void bnb_member::set_count(int count)
  {
    this->count = count;
  }
  string bnb_member::get_id()
  {
    return id;
  }
  string bnb_member::get_name()
  {
    return name;
  }
  int bnb_member::get_count()
  {
    return count;
  }
void bnb_member::increase_count()
{
  count=count+1;
}
