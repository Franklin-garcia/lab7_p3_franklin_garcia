#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>

using namespace std;
class Usuario{
public:
    string username,password,nombre;
    int edad;
    string id,telefono;
  public:
    Usuario(string,string,string,int,string,string);
    Usuario();
    string getUsername();
    string getPassword();
    string getNombre();
    int getEdad();
    string getId();
    string getTelefono();
};
#endif
