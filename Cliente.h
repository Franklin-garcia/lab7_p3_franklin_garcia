#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Usuario.h"

class Cliente:public Usuario{
  protected:
    string direccion;
    int rating;
  public:
    Cliente(string,int,string,string,string,int,string,string);
    Cliente();
    string getDireccion();
    int getRating();
};
#endif
