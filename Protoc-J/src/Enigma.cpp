#include "Enigma.h"

Enigma::Enigma(string x,int b, int c, int d, string override, string n){
    temp = alfabeto.length();
    clave=x;
    r1=elegir_rotores(b);
    r2=elegir_rotores(c);
    r3=elegir_rotores(d);
    l1=override[0];
    l2=override[1];
    l3=override[2];
    sk = n;
}
string Enigma::Cifrado(string mensaje_original){
    ///int desplaza3, desplaza2, desplaza1;
    int desplaza1, desplaza2, desplaza3;
    string mensaje_encriptado;
    desplaza1=alfabeto.find(clave[0]);
    desplaza2=alfabeto.find(clave[1]);
    desplaza3=alfabeto.find(clave[2]);
    for(int i=0;i<mensaje_original.length();i++){
        if(mensaje_original[i]==sk[0]){
            mensaje_original[i]=sk[1];
        }
        else if(mensaje_original[i]==sk[1]){
            mensaje_original[i]=sk[0];
        }
        string temp1;
        int temp2;
        desplaza3=modulo(desplaza3+1,temp);
        if(desplaza3==(alfabeto.find(l3))){
            desplaza2++;
        }
        if(desplaza2==(alfabeto.find(l2)-1)){
            desplaza2++;
            desplaza1++;
        }
        temp1=r3[modulo(alfabeto.find(mensaje_original[i])+desplaza3,temp)];
        temp1=r2[modulo(alfabeto.find(temp1)-desplaza3+desplaza2,temp)];
        temp1=r1[modulo (alfabeto.find(temp1)+desplaza1-desplaza2,temp)];

        temp1=reflector[modulo(alfabeto.find(temp1)-desplaza1,temp)];

        temp2=modulo(r1.find(alfabeto[modulo((alfabeto.find(temp1)+desplaza1),(temp))])-desplaza1,temp);
        temp2=modulo(r2.find(alfabeto[modulo(temp2+desplaza2,temp)])-desplaza2,temp);
        temp1=alfabeto[modulo(r3.find(alfabeto[modulo(temp2+desplaza3,temp)])-desplaza3,temp)];
        mensaje_encriptado+=temp1;
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        else if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[0];
        }
    }
    cout<<desplaza1<<" "<<desplaza2<<" "<<desplaza3<<" "<<endl;
    return mensaje_encriptado;

}
string Enigma::Descifrado(string mensaje_encriptado){
    int desplaza3, desplaza2, desplaza1;
    string mensaje_desencriptado;
    desplaza1=alfabeto.find(clave[0]);
    desplaza2=alfabeto.find(clave[1]);
    desplaza3=alfabeto.find(clave[2]);
    for(int i=0;i<mensaje_encriptado.length();i++){
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        else if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[0];
        }
        string temp1;
        int temp2;
        desplaza3=modulo(desplaza3+1,temp);
        if(desplaza3==(alfabeto.find(l3))){
            desplaza2++;
        }
        if(desplaza2==(alfabeto.find(l2)-1)){
            desplaza2++;
            desplaza1++;
        }
        temp1=r3[modulo(alfabeto.find(mensaje_encriptado[i])+desplaza3,temp)];
        temp1=r2[modulo(alfabeto.find(temp1)-desplaza3+desplaza2,temp)];
        temp1=r1[modulo (alfabeto.find(temp1)+desplaza1-desplaza2,temp)];

        temp1=reflector[modulo(alfabeto.find(temp1)-desplaza1,temp)];

        temp2=modulo(r1.find(alfabeto[modulo((alfabeto.find(temp1)+desplaza1),(temp))])-desplaza1,temp);
        temp2=modulo(r2.find(alfabeto[modulo(temp2+desplaza2,temp)])-desplaza2,temp);
        temp1=alfabeto[modulo(r3.find(alfabeto[modulo(temp2+desplaza3,temp)])-desplaza3,temp)];
        mensaje_desencriptado+=temp1;
        if(mensaje_desencriptado[i]==sk[0]){
            mensaje_desencriptado[i]=sk[1];
        }
        else if(mensaje_desencriptado[i]==sk[1]){
            mensaje_desencriptado[i]=sk[0];
        }
    }
    return mensaje_desencriptado;
}
string Enigma::elegir_rotores(int a){
    switch (a){
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
