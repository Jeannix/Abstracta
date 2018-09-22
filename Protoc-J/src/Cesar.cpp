#include "../include/Cesar.h"

Cesar::Cesar(int clave1)
{
    clave = clave1;
    cout <<"La clave es :"<<clave<<endl;
}
string Cesar::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;
    for(int i = 0; i<mensaje_original.size(); i++){
        int cuack = alfabetos.find(mensaje_original[i]);
        cuack +=clave;
        if(cuack>=alfabetos.size()){
            cuack -=clave;
        }
        mensaje_encriptado += alfabetos[cuack];
    }
    return mensaje_encriptado;
}
string Cesar::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    for(int i = 0; i<mensaje_encriptado.size(); i++){
        int cuack2 = alfabetos.find(mensaje_encriptado[i]-clave);
        if(cuack2<0){
            cuack2+=clave;
        }
        mensaje_desencriptado += alfabetos[cuack2];
    }
    return mensaje_desencriptado;
}
