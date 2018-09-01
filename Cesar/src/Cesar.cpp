#include "Cesar.h"

Cesar::Cesar(int clave1)
{
    clave=clave1;
    cout<<"La clave es:"<<clave<<endl;
}
string Cesar::encriptado(string mensaje_o)
{
    string mensaje_e;
    for(int i = 0;i<mensaje_o.size();i++){
        int c=mod(alfabeto.find(mensaje_o[i])+clave,alfabeto.size());
        mensaje_e+=alfabeto[c];
        }
        return mensaje_e;
}
string Cesar::desencriptado(string mensaje_e){

    string mensaje_d;
    for(int i=0; i<mensaje_e.size() ;i++) {
        int d = mod(alfabeto.find(mensaje_e[i])-clave,alfabeto.size());
        mensaje_d += alfabeto[d];
        }
        return mensaje_d;
}
