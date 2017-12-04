#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "Usuario.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Personal.h"
#include "Chef.h"
#include "Lavaplatos.h"
#include "Mesero.h"

using namespace std;

Chef* agregar_Chef();
Lavaplatos* agregar_lavaplatos();
Mesero* agregar_mesero();
Cliente* agregar_cliente();
vector<Chef*> eliminar_chef(vector<Chef*> );
vector <Lavaplatos*> eliminar_lavaplatos(vector <Lavaplatos*>);
vector <Mesero*> eliminar_mesero(vector <Mesero*>);
string cast1(int);
string max_empleado(vector<Chef*>,vector <Lavaplatos*>,vector <Mesero*>);
string min_empleado(vector<Chef*>,vector <Lavaplatos*>,vector <Mesero*>);
int promedio_sueldo(vector<Chef*>,vector <Lavaplatos*>,vector <Mesero*>);
vector <Lavaplatos*> gritar_lavaplatos(vector <Lavaplatos*>);
vector <Lavaplatos*> agradar_lavaplatos(vector <Lavaplatos*>);
vector <Lavaplatos*> renunciar(vector <Lavaplatos*>,int);
vector <Lavaplatos*> aumento(vector <Lavaplatos*>,int);
vector <Mesero*> agregar_platillo(vector <Mesero*>);
vector <Mesero*> dar_platillo(vector <Mesero*>,int);
vector <Mesero*> dar_platillos(vector <Mesero*>,int);
void escribir_chef(vector<Chef*>);
void escribir_lavaplatos(vector<Lavaplatos*>);
void escribir_mesero(vector<Mesero*>);
void escribir_cliente(vector<Cliente*>);
void escribir_administrador(Administrador*);
int main(){
    bool seguir=true;
    int opcion,llenados=0;
    vector<Chef*> lista_chef;
    vector<Lavaplatos*>lista_lavaplatos;
    vector<Mesero*>lista_meseros;
    vector<Cliente*>lista_cliente;//
    Administrador *admin;
    while(seguir){
      cout<<"Ingrese opcion menu"<<endl<<
      "1-Ingresar al Administrador"<<endl<<
      "2-Agregar a clientes"<<endl<<
      "3-Ingresar a login del personal"<<endl<<
      "4-Guardar todo"<<endl<<
      "5-Salir"<<endl;
      cin>>opcion;
      switch(opcion){
        case 1:{//Administrador
          int op;
          cout<<"Ingrese opcion"<<endl<<"1-llenar datos"<<endl<<"2-Ingresar a login"<<endl;
          cin>>op;
          if(op==1){//llenar datos
            int contratados=0,despedidos=0;
            string username,password,nombre;
            int edad;
            string id,telefono;
            cout<<"Username"<<endl;
            cin>>username;
            cout<<"password"<<endl;
            cin>>password;
            cout<<"nombre"<<endl;
            cin>>nombre;
            cout<<"edad"<<endl;
            cin>>edad;
            cout<<"Id"<<endl;
            cin>>id;
            cout<<"telefono"<<endl;
            cin>>telefono;
            if(edad>=18){
              llenados=1;
              admin=new Administrador(contratados,despedidos,username,password, nombre,edad, id,telefono);
              cout<<"llenado"<<endl;
            }else {
              cout<<"no se guardo porque la edad es menor a 18"<<endl;
            }
          }
          else if(op==2 && llenados==1){//entrar al login del adiminstrador
            Usuario *u;//apuntador para obtener metodos de usuario
            u=admin;//apuntando a Administrador
            int o;
            cout<<"Ingrese username"<<endl;
            string user;
            cin>>user;
            cout<<"Ingrese password"<<endl;
            string pass;
            cin>>pass;
            //admin=static_cast<Administrador*>(u);
            string usua=u->getUsername();
            string contra=u->getPassword();
            if(usua.compare(user)==0 && contra.compare(pass)==0){
              cout<<"Ha ingresado"<<endl;
              cout<<"Ingrese opcion"<<endl<<
              "1. Contratar empleado"<<endl<<
              "2. Despedir empleado"<<endl<<
              "3. Conseguir al empleado con menor sueldo"<<endl<<
              "4. Agregar platillo a un mesero"<<endl<<
              "5. Conseguir al empleado con mayor sueldo"<<endl<<
              "6. Conseguir el promedio de sueldo de todos los empleadsos."<<endl<<
              "7. Salir"<<endl;
                cin>>o;
                switch(o){
                  case 1:{//Contratar empleado
                      cout<<"Ingrese opcion"<<endl<<
                      "1-Chef"<<endl<<
                      "2-Lavaplatos"<<endl<<
                      "3-Mesero"<<endl<<
                      "4-salir"<<endl;
                      int p;
                      cin>>p;
                      switch (p){
                        case 1:{//Chef
                            lista_chef.push_back(agregar_Chef());
                            cout<<"Hecho!"<<endl;
                        }break;
                        case 2:{//Lavaplatos
                            lista_lavaplatos.push_back(agregar_lavaplatos());
                            cout<<"Hecho!"<<endl;
                        }break;
                        case 3:{//Meseros
                             lista_meseros.push_back(agregar_mesero());
                             cout<<"hecho!"<<endl;
                        }break;
                        case 4:{
                            break;
                        }break;
                      }//fin de switch contratar
                  }break;//finde empleado
                  case 2:{//despedir empleado
                    cout<<"Ingrese opcion"<<endl<<
                    "1-Chef"<<endl<<
                    "2-Lavaplatos"<<endl<<
                    "3-Mesero"<<endl<<
                    "4-salir"<<endl;
                    int p;
                    cin>>p;
                    switch (p){
                      case 1:{//Chef
                        lista_chef=eliminar_chef(lista_chef);
                        cout<<"eliminado!"<<endl;
                      }break;
                      case 2:{//Lavaplatos
                        lista_lavaplatos=eliminar_lavaplatos(lista_lavaplatos);
                        cout<<"eliminado!"<<endl;
                      }break;
                      case 3:{//mesero
                        lista_meseros=eliminar_mesero(lista_meseros);
                        cout<<"eliminado!"<<endl;
                      }break;
                      case 4:{//salir
                        break;
                        int p;
                      }break;
                    }
                  }break;
                  case 3:{//conseguir al empleado de menor sueldo
                    cout<<min_empleado(lista_chef,lista_lavaplatos,lista_meseros)<<endl;
                  }break;//fin del empleado menor
                  case 4:{//Agregar platillo a un mesero
                    lista_meseros=agregar_platillo(lista_meseros);
                    cout<<"hecho"<<endl;
                  }break;//fin  del platillo
                  case 5:{//conseguir al empleado de mayor sueldo
                    cout<<max_empleado(lista_chef,lista_lavaplatos,lista_meseros)<<endl;
                  }break;//fin del mayor empleado
                  case 6:{//conseguir promedio de sueldos
                    cout<<"El promedio de sueldos es:"<<promedio_sueldo(lista_chef,lista_lavaplatos,lista_meseros);
                  }break;//fin de promedio
                  case 7:{//salir
                    break;
                  }break;
                }
            }else{
              cout<<"Usuario y/o contraseña incorrectos"<<endl;
            }
          }else{
            cout<<"Llene sus datos por favor"<<endl;
          }
        }break;//fin de Administrador
        case 2:{//clientes
            lista_cliente.push_back(agregar_cliente());
            cout<<"agregado!"<<endl;

        }break;//fin de clientes
        case 3:{//personal
          int o;
          cout<<"Ingrese opcion"<<endl<<"1-Chef"<<endl<<"2-Lavaplatos"<<endl<<"3-meseros"<<endl;
          switch(o){
            case 1:{//chef
              int pos;
              cout<<"Ingrese pos"<<endl;
              for(int i=0;i<lista_chef.size();i++){
                  cout<<i<<"-"<<lista_chef.at(i)->getNombre()<<endl;
              }
              cin>>pos;
              string u=lista_chef.at(pos)->getUsername(),c=lista_chef.at(pos)->getPassword();
              string user,contra;
              cout<<"Ingrese usuario"<<endl;
              cin>>user;
              cout<<"Ingrese contraseña"<<endl;
              cin>>contra;
              if(user.compare(u)==0 && contra.compare(c)==0){
                cout<<"Ha entrado"<<endl;
                cout<<"Ingrese opcion"<<endl<<"1-Gritar a un lavapatos"<<endl<<"2-Agradar a un lavaplatos"<<endl<<"3.salir"<<endl;
                int oo;
                cin>>oo;
                switch(oo){
                  case 1:{
                    lista_lavaplatos=gritar_lavaplatos(lista_lavaplatos);
                    cout<<"hecho!"<<endl;
                  }break;
                  case 2:{
                    lista_lavaplatos=agradar_lavaplatos(lista_lavaplatos);
                    cout<<"hecho!"<<endl;
                  }break;
                  case 3:{
                    break;
                  }break;
                }
              }else{
                cout<<"Usuario y/o contraseña incorrectos"<<endl;
              }
            }break;
            case 2:{//lavaplatos
              int pos;
              string user,contra;
              cout<<"Ingrese pos"<<endl;
              for(int i=0;i<lista_lavaplatos.size();i++){
                  cout<<i<<"-"<<lista_lavaplatos.at(i)->getNombre()<<endl;
              }
              cin>>pos;
              string u=lista_lavaplatos.at(pos)->getUsername(),c=lista_lavaplatos.at(pos)->getPassword();
              cout<<"Ingrese usuario"<<endl;
              cin>>user;
              cout<<"Ingrese contraseña"<<endl;
              cin>>contra;
              if(user.compare(u)==0 && contra.compare(c)==0){
                cout<<"ha ingresado"<<endl;
                cout<<"1-Renuciar"<<endl<<"2-Pedir aumento"<<endl<<"3-salir"<<endl;
                  int oo;
                  cin>>oo;
                  switch(oo){
                    case 1:{//Renuciar
                      lista_lavaplatos=renunciar(lista_lavaplatos,pos);
                    }break;
                    case 2:{//aumento
                      lista_lavaplatos=aumento(lista_lavaplatos,pos);
                    }break;
                    case 3:{
                      break;
                    }break;
                  }
              }else {
                cout<<"usuario y/o contraseña incorrectas"<<endl;
              }

            }break;
            case 3:{//meseros
              int pos;
              cout<<"Ingrese pos"<<endl;
              for(int i=0;i<lista_meseros.size();i++){
                  cout<<i<<"-"<<lista_meseros.at(i)->getNombre()<<endl;
              }
              cin>>pos;
              string u=lista_meseros.at(pos)->getUsername(),c=lista_meseros.at(pos)->getPassword();
              string user,contra;
              cout<<"Ingrese usuario"<<endl;
              cin>>user;
              cout<<"Ingrese contraseña"<<endl;
              cin>>contra;
              if(user.compare(u)==0 && contra.compare(c)==0){
                cout<<"Ingrese opcion"<<endl<<"1-Dar un platillo"<<endl<<"2-Dar todos los platillos"<<endl<<"3-salir"<<endl;
                int oo;
                cin>>oo;
                switch(oo){
                  case 1:{//dar un platillo
                    lista_meseros=dar_platillo(lista_meseros,pos);
                    cout<<"hecho"<<endl;
                  }break;
                  case 2:{//darlos todos
                    lista_meseros=dar_platillos(lista_meseros,pos);
                    cout<<"hecho"<<endl;
                  }break;
                  case 3:{
                    break;
                  }break;
                }
              }else{
                cout<<"Usuario o/contraseña incorrectas"<<endl;
              }
            }break;
          }

        }break;//fin de personal
        case 4:{//salir
          escribir_cliente(lista_cliente);
          escribir_chef(lista_chef);
          escribir_mesero(lista_meseros);
          escribir_lavaplatos(lista_lavaplatos);
          escribir_administrador(admin);
        }break;
        case 5:{
          break;
        }break;
      }//fin del switch
    }//fin del while
return 0;
}

Chef* agregar_Chef(){
  string platillo;

  string fecha;
  int sueldo;
  string username;
  string password;
  string nombre;
  int edad;
  string id;
  string telefono;
  cout<<"Platillo"<<endl;
  cin>>platillo;
  cout<<"fecha"<<endl;
  cin>>fecha;
  cout<<"sueldo"<<endl;
  cin>>sueldo;
  cout<<"Username"<<endl;
  cin>>username;
  cout<<"password"<<endl;
  cin>>password;
  cout<<"nombre"<<endl;
  cin>>nombre;
  cout<<"edad"<<endl;
  cin>>edad;
  while(edad<18){
    cout<<"Ingrese edad mayor a 18"<<endl;
    cin>>edad;
  }
  cout<<"Id"<<endl;
  cin>>id;
  cout<<"telefono"<<endl;
  cin>>telefono;
  Chef *c=new Chef(platillo,fecha,sueldo,username,password, nombre,edad, id, telefono);
  return c;
}

Lavaplatos* agregar_lavaplatos(){
  int motivacion=50;

  string fecha;
  int sueldo;
  string username;
  string password;
  string nombre;
  int edad;
  string id;
  string telefono;

  cout<<"fecha"<<endl;
  cin>>fecha;
  cout<<"sueldo"<<endl;
  cin>>sueldo;
  cout<<"Username"<<endl;
  cin>>username;
  cout<<"password"<<endl;
  cin>>password;
  cout<<"nombre"<<endl;
  cin>>nombre;
  cout<<"edad"<<endl;
  cin>>edad;
  while(edad<18){
    cout<<"ingrese una edad mayor a 18"<<endl;
    cin>>edad;
  }
  cout<<"Id"<<endl;
  cin>>id;
  cout<<"telefono"<<endl;
  cin>>telefono;
  Lavaplatos *l;
  l=new Lavaplatos(motivacion,fecha,sueldo,username,password, nombre,edad, id, telefono);
}

Mesero *agregar_mesero(){
  string fecha;
  int sueldo;
  string username;
  string password;
  string nombre;
  int edad;
  string id;
  string telefono;

  cout<<"fecha"<<endl;
  cin>>fecha;
  cout<<"sueldo"<<endl;
  cin>>sueldo;
  cout<<"Username"<<endl;
  cin>>username;
  cout<<"password"<<endl;
  cin>>password;
  cout<<"nombre"<<endl;
  cin>>nombre;
  cout<<"edad"<<endl;
  cin>>edad;
  while(edad<18){
    cout<<"Ingrese edad mayor a 18"<<endl;
    cin>>edad;
  }
  cout<<"Id"<<endl;
  cin>>id;
  cout<<"telefono"<<endl;
  cin>>telefono;
  Mesero*m;
  m=new Mesero(fecha,sueldo,username,password, nombre,edad, id, telefono);
}

vector<Chef*> eliminar_chef(vector<Chef*>lista_chef){
  int pos;
  cout<<"Ingrese pos"<<endl;
  vector<Chef*>c;
  c=lista_chef;
  for(int i=0;i<c.size();i++){
      cout<<i<<"-"<<c.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  lista_chef.erase(lista_chef.begin()+pos);
  return lista_chef;
}

vector <Lavaplatos*> eliminar_lavaplatos(vector <Lavaplatos*> lista_lavaplatos){
  int pos;
  cout<<"Ingrese pos"<<endl;
  vector<Lavaplatos*>l;
  l=lista_lavaplatos;
  for(int i=0;i<l.size();i++){
      cout<<i<<"-"<<l.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  lista_lavaplatos.erase(lista_lavaplatos.begin()+pos);
  return lista_lavaplatos;
}

vector <Mesero*> eliminar_mesero(vector <Mesero*> lista_meseros){
  int pos;
  cout<<"Ingrese pos"<<endl;
  vector<Mesero*>m;
  m=lista_meseros;
  for(int i=0;i<m.size();i++){
      cout<<i<<"-"<<m.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  lista_meseros.erase(lista_meseros.begin()+pos);
  return lista_meseros;
}
string cast1(int num){//castear de int a string
  string cad="";
  cad=static_cast<ostringstream*>(&(ostringstream()<<num))->str();//castear de entero a string
  return cad;
}

string max_empleado(vector<Chef*> chefs,vector <Lavaplatos*> lavaplatos,vector <Mesero*> meseros){
  string max="";
  int maximo=0;
  for(int i=0;i<chefs.size();i++){
    if(chefs.at(i)->getSueldo()>maximo){
        maximo=chefs.at(i)->getSueldo();
        max+="El que gana mas es: ";
        max+=chefs.at(i)->getSueldo();
        max+="  con un sueldo de: ";
        max+=cast1(chefs.at(i)->getSueldo());
    }
  }
  for(int i=0;i<lavaplatos.size();i++){
    if(lavaplatos.at(i)->getSueldo()>maximo){
        maximo=lavaplatos.at(i)->getSueldo();
        max+="El que gana mas es: ";
        max+=lavaplatos.at(i)->getSueldo();
        max+="  con un sueldo de: ";
        max+=cast1(lavaplatos.at(i)->getSueldo());
    }
  }
  for(int i=0;i<meseros.size();i++){
    if(meseros.at(i)->getSueldo()>maximo){
        maximo=meseros.at(i)->getSueldo();
        max+="El que gana mas es: ";
        max+=meseros.at(i)->getSueldo();
        max+="  con un sueldo de: ";
        max+=cast1(meseros.at(i)->getSueldo());
    }
  }
  return max;
}

string min_empleado(vector<Chef*> chefs,vector <Lavaplatos*> lavaplatos,vector <Mesero*> meseros){
  string min="";
  int minimo=300000000;
  for(int i=0;i<chefs.size();i++){
    if(chefs.at(i)->getSueldo()<minimo){
        minimo=chefs.at(i)->getSueldo();
        min+="El que gana menos es: ";
        min+=chefs.at(i)->getSueldo();
        min+="  con un sueldo de: ";
        min+=cast1(chefs.at(i)->getSueldo());
    }
  }
  for(int i=0;i<lavaplatos.size();i++){
    if(lavaplatos.at(i)->getSueldo()<minimo){
        minimo=lavaplatos.at(i)->getSueldo();
        min+="El que gana menos es: ";
        min+=lavaplatos.at(i)->getSueldo();
        min+="  con un sueldo de: ";
        min+=cast1(lavaplatos.at(i)->getSueldo());
    }
  }
  for(int i=0;i<meseros.size();i++){
    if(meseros.at(i)->getSueldo()<minimo){
        minimo=meseros.at(i)->getSueldo();
        min+="El que gana menos es: ";
        min+=meseros.at(i)->getSueldo();
        min+="  con un sueldo de: ";
        min+=cast1(meseros.at(i)->getSueldo());
    }
  }
  return min;
}

int  promedio_sueldo(vector<Chef*> chefs,vector <Lavaplatos*> lavaplatos,vector <Mesero*> meseros){
  int acum1=0,acum2=0,acum3=0,cont1=0,cont2,cont3=0,prom=0;
  for(int i=0;i<chefs.size();i++){
      acum1+=chefs.at(i)->getSueldo();
      cont1++;
  }
  for(int i=0;i<lavaplatos.size();i++){
      acum2+=lavaplatos.at(i)->getSueldo();
      cont2++;
  }
  for(int i=0;i<meseros.size();i++){
      acum3+=meseros.at(i)->getSueldo();
      cont3++;
  }
  acum1=acum1+acum2+acum3;
  cont1=cont1+cont2+cont3;
  prom=acum1/cont1;
  return prom;
}

Cliente* agregar_cliente(){
  string direccion;
  int rating;
  string username;
  string password;
  string nombre;
  int edad;
  string id;
  string telefono;
  cout<<"Direccion"<<endl;
  cin>>direccion;
  cout<<"Rating 1-5"<<endl;
  cin>>rating;
  while(rating<1 || rating >5){
    cout<<"ingrese rating de 1-5"<<endl;
    cin>>rating;
  }
  cout<<"Username"<<endl;
  cin>>username;
  cout<<"password"<<endl;
  cin>>password;
  cout<<"nombre"<<endl;
  cin>>nombre;
  cout<<"edad"<<endl;
  cin>>edad;
  while(edad<18){
    cout<<"Menor de edad ingrese edad mayor a 18"<<endl;
    cin>>edad;
  }
  cout<<"Id"<<endl;
  cin>>id;
  cout<<"telefono"<<endl;
  cin>>telefono;
    Cliente* c=new Cliente(direccion,rating,username,password, nombre,edad, id, telefono);
    return c;
}
vector <Lavaplatos*> gritar_lavaplatos(vector <Lavaplatos*> lista){
  int pos,menos=0;
  cout<<"Ingrese pos del lavaplatos que va a gritarle"<<endl;
  for(int i=0;i<lista.size();i++){
      cout<<i<<"-"<<lista.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  cout<<"Ingrese grito"<<endl;
  int grito;
  cin>>grito;
  menos=lista.at(pos)->getMotivacion();
  menos=menos-grito;
  lista.at(pos)->setMotivacion(menos);
  return lista;
}
vector <Lavaplatos*> agradar_lavaplatos(vector <Lavaplatos*> lista){
  int pos,menos=0;
  cout<<"Ingrese pos del lavaplatos que va a motivarle"<<endl;
  for(int i=0;i<lista.size();i++){
      cout<<i<<"-"<<lista.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  cout<<"Ingrese motivacion"<<endl;
  int grito;
  cin>>grito;
  menos=lista.at(pos)->getMotivacion();
  menos=menos+grito;
  lista.at(pos)->setMotivacion(menos);
  return lista;
}

vector <Lavaplatos*> renunciar(vector <Lavaplatos*> lista,int pos){
  int motivacion=lista.at(pos)->getMotivacion();
  if(motivacion<=25){
    lista.erase(lista.begin()+pos);
    cout<<"me voy"<<endl;
  }else{
    cout<<"no puede renunciar"<<endl;
  }
  return lista;
}

vector <Lavaplatos*> aumento(vector <Lavaplatos*> lista,int pos){
  int motivacion=lista.at(pos)->getMotivacion();
  int sueldo=lista.at(pos)->getSueldo();
  if(motivacion>=100){
    cout<<"Tiene derecho a un aumento"<<endl<<"sueldo actual:"<<sueldo<<endl;
    cout<<"Ingrese aumento"<<endl;
    int aumento;
    cin>>aumento;
    while(aumento<=sueldo){
      cout<<"tiene que ingresar un nuevo sueldo mayor al actual"<<endl;
    }
    lista.at(pos)->setSueldo(aumento);
    cout<<"hecho"<<endl;
  }else{
    cout<<"no esta suficientemente motivado"<<endl;
  }
  return lista;
}

vector <Mesero*> agregar_platillo(vector <Mesero*> lista){
  int pos;
  cout<<"Ingrese pos del mesero"<<endl;
  for(int i=0;i<lista.size();i++){
      cout<<i<<"-"<<lista.at(i)->getNombre()<<endl;
  }
  cin>>pos;
  cout<<"Ingrese platillo"<<endl;
  string platillo;
  cin>>platillo;
  lista.at(pos)->getPlatillos().push_back(platillo);
  return lista;
}
vector <Mesero*> dar_platillo(vector <Mesero*> lista,int pos1){
  int pos;
  cout<<"Ingrese pos del platillo"<<endl;
  for(int i=0;i<lista.at(pos1)->getPlatillos().size();i++){
      cout<<i<<"-"<<lista.at(pos1)->getPlatillos().at(i)<<endl;
  }
  cin>>pos;
  lista.at(pos1)->getPlatillos().erase(lista.at(pos1)->getPlatillos().begin()+pos);
  return lista;
}

vector <Mesero*> dar_platillos(vector <Mesero*> lista,int pos1){
  lista.at(pos1)->getPlatillos().clear();
  return lista;
}

void escribir_cliente(vector<Cliente*> lista){//escribir texto
        ofstream archivo;
        archivo.open("cliente.txt",ios::out);//Abriendo o creando el archivo
        if(archivo.fail()){
                cout<<"Hubo un error";
        }
        for(int i=0;i<lista.size();i++){
            archivo<<lista.at(i)->getDireccion();
            archivo<<",";
            archivo<<lista.at(i)->getRating();
            archivo<<",";
            archivo<<lista.at(i)->getUsername();
            archivo<<",";
            archivo<<lista.at(i)->getPassword();
            archivo<<",";
            archivo<<lista.at(i)->getNombre();
            archivo<<",";
            archivo<<lista.at(i)->getEdad();
            archivo<<",";
            archivo<<lista.at(i)->getId();
            archivo<<",";
            archivo<<lista.at(i)->getTelefono();
            archivo<<";";
        }
        archivo.close();
}
void escribir_chef(vector<Chef*> lista){//escribir texto
        ofstream archivo;
        archivo.open("cliente.txt",ios::out);//Abriendo o creando el archivo
        if(archivo.fail()){
                cout<<"Hubo un error";
        }
        for(int i=0;i<lista.size();i++){
            archivo<<lista.at(i)->getPlatillo();
            archivo<<",";
            archivo<<lista.at(i)->getFecha();
            archivo<<",";
            archivo<<lista.at(i)->getSueldo();
            archivo<<",";
            archivo<<lista.at(i)->getUsername();
            archivo<<",";
            archivo<<lista.at(i)->getPassword();
            archivo<<",";
            archivo<<lista.at(i)->getNombre();
            archivo<<",";
            archivo<<lista.at(i)->getEdad();
            archivo<<",";
            archivo<<lista.at(i)->getId();
            archivo<<",";
            archivo<<lista.at(i)->getTelefono();
            archivo<<";";
        }
        archivo.close();
}
void escribir_mesero(vector<Mesero*> lista){//escribir texto
        ofstream archivo;
        archivo.open("cliente.txt",ios::out);//Abriendo o creando el archivo
        if(archivo.fail()){
                cout<<"Hubo un error";
        }
        for(int i=0;i<lista.size();i++){
            archivo<<lista.at(i)->getFecha();
            archivo<<",";
            archivo<<lista.at(i)->getSueldo();
            archivo<<",";
            archivo<<lista.at(i)->getUsername();
            archivo<<",";
            archivo<<lista.at(i)->getPassword();
            archivo<<",";
            archivo<<lista.at(i)->getNombre();
            archivo<<",";
            archivo<<lista.at(i)->getEdad();
            archivo<<",";
            archivo<<lista.at(i)->getId();
            archivo<<",";
            archivo<<lista.at(i)->getTelefono();
            archivo<<";";
        }
        archivo.close();
}
void escribir_lavaplatos(vector<Lavaplatos*> lista){//escribir texto
        ofstream archivo;
        archivo.open("cliente.txt",ios::out);//Abriendo o creando el archivo
        if(archivo.fail()){
                cout<<"Hubo un error";
        }
        for(int i=0;i<lista.size();i++){
            archivo<<lista.at(i)->getMotivacion();
            archivo<<",";
            archivo<<lista.at(i)->getFecha();
            archivo<<",";
            archivo<<lista.at(i)->getSueldo();
            archivo<<",";
            archivo<<lista.at(i)->getUsername();
            archivo<<",";
            archivo<<lista.at(i)->getPassword();
            archivo<<",";
            archivo<<lista.at(i)->getNombre();
            archivo<<",";
            archivo<<lista.at(i)->getEdad();
            archivo<<",";
            archivo<<lista.at(i)->getId();
            archivo<<",";
            archivo<<lista.at(i)->getTelefono();
            archivo<<";";
        }
        archivo.close();
}
void escribir_administrador(Administrador *admin){//escribir texto
        ofstream archivo;
        archivo.open("cliente.txt",ios::out);//Abriendo o creando el archivo
        if(archivo.fail()){
                cout<<"Hubo un error";
        }
        archivo<<admin->getContratados();
        archivo<<admin->getDespedidos();
        archivo<<admin->getUsername();
        archivo<<admin->getPassword();
        archivo<<admin->getNombre();
        archivo<<admin->getEdad();
        archivo<<admin->getId();
        archivo<<admin->getTelefono();
        archivo.close();
}
