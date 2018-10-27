#ifndef RSA_H
#define RSA_H

#include "Functions.h"

class RSA
{
    private:
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ phi_n;
        ZZ e;
        ZZ d;
    public:
        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        RSA();
        RSA(ZZ,ZZ);
        string cifrar(string);
        string rubrica();
        vector<ZZ> pre(ZZ);
        ZZ Resto_Chino(vector<ZZ> g,ZZ );
        string descifrar(string);
        void impr_claves(void);
        string orden1(int);
        string orden2(ZZ a,ZZ n);
        string orden3(ZZ a,ZZ n);

};

#endif // RSA_H
