#include "../include/Affin.h"

Affin::Affin()
{
    tam = alfabetos.length();
    generar_claves_affin(clave_a,clave_b,tam);
    inversa_a=inversa(clave_a, tam);
}
Affin::Affin(int c1, int c2)
{
    tam = alfabetos.length();
    clave_a = c1;
    clave_b = c2;
    inversa_a=inversa(clave_a, tam);
}

string Affin::Affin_Encriptacion(string mensaje)
{
    string mensaje_cifrado;
    for(unsigned int i=0;i<mensaje.length();i++){
        int num=alfabetos.find(mensaje[i]);
        int temp1=modulo(modulo(clave_a*num,alfabetos.size())+clave_b,alfabetos.size());
        mensaje_cifrado+=alfabetos[temp1];
    }
    return mensaje_cifrado;
}
string Affin::Affin_Desencriptacion(string mensaje_Encriptado)
{
    string mensaje_D;
    for(unsigned int i=0;i<mensaje_Encriptado.length();i++){
        int num=alfabetos.find(mensaje_Encriptado[i]);
        int temp1=modulo(modulo(num-clave_b,alfabetos.size())*inversa_a,alfabetos.size());
        mensaje_D+=alfabetos[temp1];
    }
    return mensaje_D;
}

int Affin::get_clave_a()
{
    return clave_a;
}
int Affin::get_clave_b()
{
    return clave_b;
}
