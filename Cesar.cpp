#include "Cesar.h"

Cesar::Cesar(int clave1)
{
    clave=clave1;
    cout<<"La clave es:"<<clave<<endl;
}
string Cesar::encriptado(string mensaje_o)
{
    string mensaje_e;
    for(int = 0;i<mensaje_o.size();i++){
        int c=mod(alfabeto.find(mensaje_o[i])+clave,alfabeto.size());
        mensaje_e+=alfabeto[c];
        }
        return mensaje_e;
}
string descifrar(string mensaje, int clave1) {
    for(int i=0; i<mensaje.size() ;i++) {
        int d = mod(alfabeto.find(mensaje[i])-clave1,len);
        mensaje[i] = alfabeto[d];
        }
        return mensaje;
}
