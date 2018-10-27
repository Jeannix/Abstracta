#include "RSA.h"

int main()
{
    RSA a;
    //ZZ e=ZZ(25387);
    //ZZ n=ZZ(1521864343);
//    RSA test(e,n);
    string g =a.cifrar("COMEHERE");
    string d =a.cifrar("ELLA");
    //a.descifrar(g);
    //a.descifrar(d);
    //cout<<inversa(ZZ(5),ZZ(2))<<endl;
    return 0;
}

