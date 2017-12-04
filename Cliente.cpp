#include "Cliente.h"
#include <string>

Cliente::Cliente(){
  this->direccion;
  this->rating;
}

  Cliente::Cliente(string pDireccion, int pRating,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Usuario(pUsername, pPassword,pNombre,pEdad, pId,pTelefono){
            direccion=pDireccion;
            rating=pRating;
  }

  string Cliente::getDireccion(){
    return direccion;
  }
  int Cliente::getRating(){
    return rating;
  }
