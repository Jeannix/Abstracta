#include "Cesar.h"

using namespace std;

int main()
{
    int clave;
    string mensaje_;
    cout<<"Ingresa una clave: ";
    cin>>clave;
    cout<<"Ingresa el mensaje: ";
    cin>>mensaje_;
    cout<<" "<<endl;
    Cesar Emisor(clave);
    string mensaje_e= Emisor.encriptado(mensaje_);
    cout<<mensaje_e<<endl;
    Cesar Receptor(clave);
    string mensaje_d = Receptor.desencriptar(mensaje_e);
    cout<<mensaje_d<<endl;
    return 0;
}
