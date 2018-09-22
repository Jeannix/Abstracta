#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

const string alfabetos="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int modulo(int,int);
int euclides(int, int);
int euclides_extendido(int,int);
int inversa(int,int);
int generar_Aleatorio();
void generar_claves_affin(int&,int&,int);

#endif // FUNC_H
