#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H
#include <string>
#include "Personal.h"

class Lavaplatos:public Personal{
  public:
    int motivacion;
  public:
    Lavaplatos(int,string,int, string,string,string,int,string,string);
    Lavaplatos();
    int getMotivacion();
    void setMotivacion(int);
};
#endif
