#include "Chef.h"
#include <string>

Chef::Chef(){
  this->platillo;
}

Chef::Chef(string pPlatillo,string pFecha,int pSueldo,string pUsername,string pPassword, string pNombre,int pEdad, string pId, string pTelefono):Personal(pFecha,pSueldo, pUsername,pPassword,  pNombre, pEdad, pId,pTelefono){
  platillo=pPlatillo;
}

string Chef::getPlatillo(){
  return platillo;
}
