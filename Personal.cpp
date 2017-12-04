#include "Personal.h"
#include <string>

Personal::Personal(){
  this->fecha;
  this->sueldo;
}

Personal::Personal(string pFecha,int pSueldo,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Usuario(pUsername, pPassword,pNombre,pEdad, pId,pTelefono){
  fecha=pFecha;
  sueldo=pSueldo;
}
string Personal::getFecha(){
  return fecha;
}
int Personal::getSueldo(){
  return sueldo;
}
void Personal::setSueldo(int pSueldo){
  sueldo=pSueldo;
}
