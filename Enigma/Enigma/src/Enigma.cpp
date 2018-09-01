#include "Enigma.h"

Enigma::Enigma()
{

}
string Enigma::cifrar(string mensaje) {
    string resultado;
    for(int i=0; i<alfabeto_o.size(); i++){
        string n1;
        n1 = alfabeto_o[rotori7.find(mensaje[i])];
        string n2;
        n2 = alfabeto_o[rotori5.find(n1)];
        string n3;
        n3 = alfabeto_o[rotori3.find(n2)];
        string n4;
        n4 = alfabeto_o[intent_reflc.find(n3)];
        string n5;
        n5 = rotori3[alfabeto_o.find(n4)];
        string n6;
        n6 = rotori5[alfabeto_o.find(n5)];
        string n7;
        n7 = rotori7[alfabeto_o.find(n6)];
        resultado+=n7;
}
//a4=alfabeto[rotor.find(a3)]
return resultado;
}
