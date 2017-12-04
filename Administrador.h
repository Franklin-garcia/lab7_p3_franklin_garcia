#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "Usuario.h"

class Administrador:public Usuario{
  protected:
    int contratados,despedidos;
  public:
    Administrador(int,int,string,string,string,int,string,string);
    Administrador();
    int getContratados();
    int getDespedidos();
};
#endif
