#ifndef MESERO_H
#define MESERO_H
#include <string>
#include <vector>
#include "Personal.h"

class Mesero:public Personal{
  public:
    vector<string>platillos;
  public:
    Mesero(string,int, string,string,string,int,string,string);
    Mesero();
    vector<string> getPlatillos();
};
#endif
