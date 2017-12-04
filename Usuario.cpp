#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

Usuario::Usuario(){
  this->username;
  this->password;
  this->nombre;
  this->edad;
  this->id;
  this->telefono;
}

Usuario::Usuario(string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono){
  username=pUsername;
  password=pPassword;
  nombre=pNombre;
  edad=pEdad;
  id=pId;
  telefono=pTelefono;
}
string Usuario::getUsername(){
  return username;
}
string Usuario::getPassword(){
  return password;
}
string Usuario::getNombre(){
  return nombre;
}
int Usuario::getEdad(){
  return edad;
}
string Usuario::getId(){
  return id;
}
string Usuario::getTelefono(){
  return telefono;
}
