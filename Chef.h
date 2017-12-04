#ifndef CHEF_H
#define CHEF_H
#include <string>
#include "Personal.h"

class Chef:public Personal{
  public:
    string platillo;
  public:
  Chef(string,string,int,string,string,string,int,string,string);
  Chef();
  string getPlatillo();
};
#endif
