#ifndef CESAR_H
#define CESAR_H
#include "Func.h"

class Cesar
{
    public:
        Cesar(int);
        string encriptado(string);
        string desencriptado(string);

        string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    private:
        int clave;
};

#endif // CESAR_H
