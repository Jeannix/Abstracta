#ifndef ENIGMA_H
#define ENIGMA_H
#include <string>
#include <iostream>
using namespace std;


class Enigma
{
    public:
        Enigma();
        string alfabeto_o="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rotori3="EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string rotori5="AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotori7="BDFHJLCPRTXVZNYEIWGAKMUSQO";
        string intent_reflc="YRUHQSLDPXNGOKMIEBFCWVJAT";
        string cifrar(string);
        string descifrar(string);

    private:

};

#endif // ENIGMA_H
