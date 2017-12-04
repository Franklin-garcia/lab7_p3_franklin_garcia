#include "Mesero.h"
#include <string>
#include <vector>

Mesero::Mesero(){
  this->platillos;
}

Mesero::Mesero(string pFecha,int pSueldo,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Personal(pFecha,pSueldo, pUsername,pPassword,  pNombre, pEdad, pId,pTelefono){

}

vector<string> Mesero::getPlatillos(){
  return platillos;
}
