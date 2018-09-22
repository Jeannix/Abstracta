#include <iostream>
#include "Protocolo.h"
using namespace std;

int main()
{
    cout << "Protocolo" << endl;
    Protocolo test("463","JCC","COR","HQ");
    string mensaje = "TEESTOYBUSCANDOPARAEXPLOTARCONTIGOPARAEXPLOTARCONTIGOPARAEXPLOTARNOSTEESTOYLLAMANDOPARAVOLARCONTIGOZ";
    string encriptado = test.Encriptado(mensaje);
    cout <<encriptado<<endl;
    ///string desencriptado = test.Desencriptado();
    ///cout <<desencriptado<<endl;
    return 0;
}
