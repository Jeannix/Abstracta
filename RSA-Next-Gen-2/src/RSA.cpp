#include "RSA.h"

RSA::RSA(){
    long bits=8;
    p=RandomBits_ZZ(bits);
    while((ProbPrime(p))!=1){
        p=RandomBits_ZZ(bits);
    }
    cout<<p<<endl;
    q=RandomBits_ZZ(bits);
    while((ProbPrime(q))!=1){
        q=RandomBits_ZZ(bits);
    }
    cout<<q<<endl;
    n=p*q;

    cout <<"N : "<<n<<endl;
    phi_n = phi_euler(p, q);
    cout<<"Phi : "<<phi_n<<endl;

    e = RandomBits_ZZ(bits);
    while(euclides(e,phi_n)!=1){
        e = RandomBits_ZZ(bits);
    }

    cout <<"E : "<<e<<endl;
    d = inversa(e, phi_n);
    cout <<"D : "<<d<<endl;
    cout <<"Clave publica : <"<<e<<" , "<<n<<">"<<endl;
    cout <<"Clave privado : <"<<d<<" , "<<n<<">"<<endl;
}

RSA::RSA(ZZ clave1, ZZ clave2)
{
    e = clave1;
    n = clave2;
}
vector<ZZ> RSA::pre(ZZ d){
    vector<ZZ> auxiliar;
    ZZ d1 = modulo(d,p-1);
    ZZ d2 = modulo(d,q-1);
    auxiliar.push_back(d1);
    auxiliar.push_back(d2);
    return auxiliar;
}
ZZ RSA::Resto_Chino(vector<ZZ> g,ZZ num){
    ZZ D1 = modulo(num,p);
    D1 = potencia(D1,g[0],p);
    ZZ D2 = modulo(num,q);
    D2 = potencia(D2,g[1],q);
    ZZ P = p*q;
    ZZ P1 = P/p;
    ZZ P2 = P/q;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ resultado = modulo(D1 * P1 * Q1,P);
    resultado += modulo(D2 * P2 * Q2,P);
    resultado = modulo(resultado,P);
    return resultado;
}
string RSA::orden1(int a){
    string tmp=int_to_string(a);
    string tmp_1=int_to_string(alfabeto.size());
    while(tmp.size()<tmp_1.size()){
        tmp='0'+tmp;
    }
    return tmp;
}
string RSA::orden2(ZZ a,ZZ n){
    string tmp=zzToString(a);
    string tmp_1=zzToString(n);
    while(tmp.size()<tmp_1.size()){
        tmp='0'+tmp;
    }
    return tmp;
}
string RSA::orden3(ZZ a,ZZ n){
    string tmp=zzToString(a);
    string tmp_1=zzToString(n);
    while(tmp.size()<(tmp_1.size()-1)){
        tmp='0'+tmp;
    }
    return tmp;
}
string RSA::cifrar(string mensaje)
{
    cout<<"Cifrado..."<<endl;
    string result;
    string tmp_1;
    string tmp_2;
    string tmp_3;
    vector <string> aux_1;
    vector <ZZ> aux_2;
    ZZ auxiliar;
    tmp_2=zzToString(n);
    for(int i=0;i<mensaje.size();i++){
        tmp_1+=orden1(alfabeto.find(mensaje[i]));
    }
    while(modulo(ZZ(tmp_1.size()),ZZ(tmp_2.size()-1))!=0){
        tmp_1+=zzToString(ZZ(alfabeto.find('W')));
    }
    int bloques=tmp_2.size()-1;
    for(int i=0;i<tmp_1.size();i++){
        tmp_3+=tmp_1[i];
        if(tmp_3.size()==bloques){
            aux_1.push_back(tmp_3);
            tmp_3="";
        }
    }
    cout<<e<<endl;
    for(unsigned int i=0;i<aux_1.size();i++){
        auxiliar=potencia(stringTozz(aux_1[i]),e,n);
        result+=orden2(auxiliar,n);
    }
    cout<<result<<endl;
    return result;
}
//string RSA::descifrar(string a)
//{
//    string result;
//    string tmp_1=zzToString(n);
//    string tmp_2;
//    string tmp_3;
//    string aux_2;
//    string aux_3;
//    ZZ auxiliar;
//    vector <string> aux_1;
//    int bloques=tmp_1.size();
//    for(int i=0;i<a.size();i++){
//        tmp_2+=a[i];
//        if(tmp_2.size()==bloques){
//            aux_1.push_back(tmp_2);
//            tmp_2="";
//        }
//    }
//    for(int i=0;i<aux_1.size();i++){
//       auxiliar=potencia(zzToString(aux_1[i]),d,n);
//       aux_2+=orden3(auxiliar,n);
//    }
//    for(int i=0;i<aux_2.size();i++){
//        aux_3+=aux_2[i];
//        string alf=int_to_string(alfabeto.size());
//        if(aux_3.size()==alf.size()){
//            cout<<aux_3<<" ";
//            result+=alfabeto[string_to_int(aux_3)];
//            aux_3="";
//        }
//    }
//    return result;
//}



