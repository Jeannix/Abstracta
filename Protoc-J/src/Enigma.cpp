#include "../include/Enigma.h"

Enigma::Enigma(string clave, int a, int b, int c)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabetos.size();
    r1=elegir_rotores(a);
    r2=elegir_rotores(b);
    r3=elegir_rotores(c);
    int n_1 = generar_Aleatorio_Max(tam);
    int n_2 = generar_Aleatorio_Max(tam);
    while(n_2==n_1){
        n_2 = generar_Aleatorio_Max(alfabetos.size());
    }
    sk += alfabetos[n_1];
    sk += alfabetos[n_2];
    l1 = limite[a-1];
    l2 = limite[b-1];
    l3 = limite[c-1];
}
Enigma::Enigma(string clave,int a, int b, int c, string override, string n)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabetos.size();
    sk = n;
    r1=elegir_rotores(a);
    r2=elegir_rotores(b);
    r3=elegir_rotores(c);
    l1=override[0];
    l2=override[1];
    l3=override[2];
}
string Enigma::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;

    int desplaza1, desplaza2, desplaza3;
    desplaza1 = alfabetos.find(pos_inicial[0]);
    desplaza2 = alfabetos.find(pos_inicial[1]);
    desplaza3 = alfabetos.find(pos_inicial[2]);

    for(int i=0;i<mensaje_original.length();i++){
        if(mensaje_original[i]==sk[0]){
            mensaje_original[i]=sk[1];
        }
        if(mensaje_original[i]==sk[1]){
            mensaje_original[i]=sk[0];
        }
        string tmp;
        int tmp2;
        desplaza3=modulo(desplaza1+1,tam);
        if(desplaza3==alfabetos.find(l3)){
            desplaza2 = modulo(desplaza2+1,tam);
        }
        if(desplaza2==modulo(alfabetos.find(l2)-1,tam)){
            desplaza2 = modulo(desplaza2+1,tam);
            desplaza1 = modulo(desplaza1+1,tam);
        }
        tmp=r3[modulo(alfabetos.find(mensaje_original[i])+desplaza3,tam)];
        tmp=r2[modulo(alfabetos.find(tmp)-desplaza3+desplaza2,tam)];
        tmp=r1[modulo(alfabetos.find(tmp)-desplaza2+desplaza1,tam)];

        tmp=reflect[modulo(alfabetos.find(tmp)-desplaza1,tam)];

        tmp2=modulo(r1.find(alfabetos[modulo(alfabetos.find(tmp)+desplaza1,tam)])-desplaza1,tam);
        tmp2=modulo(r2.find(alfabetos[modulo(tmp2+desplaza2,tam)])-desplaza2,tam);
        tmp=alfabetos[modulo(r3.find(alfabetos[modulo(tmp2+desplaza3,tam)])-desplaza3,tam)];
        mensaje_encriptado+=tmp;
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[1];
        }
    }
    return mensaje_encriptado;
}
string Enigma::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    int desplaza1, desplaza2, desplaza3;
    desplaza1 = alfabetos.find(pos_inicial[0]);
    desplaza2 = alfabetos.find(pos_inicial[1]);
    desplaza3 = alfabetos.find(pos_inicial[2]);
    for(int i=0;i<mensaje_encriptado.length();i++){
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[0];
        }
        string tmp;
        int tmp2;
        desplaza3=modulo(desplaza1+1,tam);
        if(desplaza3==alfabetos.find(l3)){
            desplaza2 = modulo(desplaza2+1,tam);
        }
        if(desplaza2==modulo(alfabetos.find(l2)-1,tam)){
            desplaza2 = modulo(desplaza2+1,tam);
            desplaza1 = modulo(desplaza1+1,tam);
        }
        tmp=r3[modulo(alfabetos.find(mensaje_encriptado[i])+desplaza3,tam)];
        tmp=r2[modulo(alfabetos.find(tmp)-desplaza3+desplaza2,tam)];
        tmp=r1[modulo(alfabetos.find(tmp)-desplaza2+desplaza1,tam)];

        tmp=reflect[modulo(alfabetos.find(tmp)-desplaza1,tam)];

        tmp2=modulo(r1.find(alfabetos[modulo(alfabetos.find(tmp)+desplaza1,tam)])-desplaza1,tam);
        tmp2=modulo(r2.find(alfabetos[modulo(tmp2+desplaza2,tam)])-desplaza2,tam);
        tmp=alfabetos[modulo(r3.find(alfabetos[modulo(tmp2+desplaza3,tam)])-desplaza3,tam)];
        mensaje_desencriptado+=tmp;
        if(mensaje_desencriptado[i]==sk[0]){
            mensaje_desencriptado[i]=sk[1];
        }
        if(mensaje_desencriptado[i]==sk[1]){
            mensaje_desencriptado[i]=sk[1];
        }
    }
    return mensaje_desencriptado;
}
string Enigma::elegir_rotores(int a)
{
    switch(a){
    case 1:
        return rotor_i;
    case 2:
        return rotor_i2;
    case 3:
        return rotor_i3;
    case 4:
        return rotor_i4;
    case 5:
        return rotor_i5;
    case 6:
        return rotor_i6;
    case 7:
        return rotor_i7;
    case 8:
        return rotor_i8;
    }
}
