#include "Lavaplatos.h"
#include <string>


Lavaplatos::Lavaplatos(){
  this->motivacion;
}

Lavaplatos::Lavaplatos(int pMotivacion,string pFecha,int pSueldo,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Personal(pFecha,pSueldo, pUsername,pPassword,  pNombre, pEdad, pId,pTelefono){
  motivacion=pMotivacion;
}

int Lavaplatos::getMotivacion(){
  return motivacion;
}

void Lavaplatos::setMotivacion(int pMotivacion){
  motivacion=pMotivacion;
}
