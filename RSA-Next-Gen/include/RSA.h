#ifndef RSA_H
#define RSA_H
#include <NTL/ZZ.h>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using namespace NTL;

class RSA
{
    private:
        ZZ d;
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
    public:
        RSA(int bits);
        RSA(ZZ,ZZ);
        string cifrar(string);
        string descifrar(string);
        void generar_claves(int);
        //ZZ chino_RSA(ZZ);
        void impr_claves();
        ZZ modulo(ZZ a, ZZ n);
        ZZ euclides(ZZ a, ZZ b);
        ZZ mcd(ZZ a, ZZ b);
        ZZ extendido(ZZ a, ZZ b);
        ZZ inversa(ZZ a, ZZ alfabeto);
        ZZ potencia(ZZ a, ZZ b, ZZ modu);
        string zzToString(ZZ z);
        ZZ stringTozz(string str);
        //vector<bool> ZZtoBinary(ZZ num);
        ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);
};

#endif // RSA_H
