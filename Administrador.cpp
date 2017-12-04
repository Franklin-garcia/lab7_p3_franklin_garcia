#include "Administrador.h"
#include <string>

Administrador::Administrador(){
  this->contratados;
  this->despedidos;
}
Administrador::Administrador(int pContratados,int pDespedidos,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Usuario(pUsername, pPassword,pNombre,pEdad, pId,pTelefono){
    contratados=pContratados;
    despedidos=pDespedidos;
}

int Administrador::getContratados(){
  return contratados;
}
int Administrador::getDespedidos(){
  return despedidos;
}
