#ifndef PERSONAL_H
#define PERSONAL_H
#include <string>
#include "Usuario.h"

class Personal:public Usuario{
  protected:
    string fecha;
    int sueldo;
  public:
    Personal(string,int, string,string,string,int,string,string);
    Personal();
    string getFecha();
    int getSueldo();
    void setSueldo(int);
};
#endif
