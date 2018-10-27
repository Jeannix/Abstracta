#include "RSA.h"
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
    vector<ZZ> precalc=pre(d);
    cout <<"Clave publica : <"<<e<<" , "<<n<<">"<<endl;
    cout <<"Clave privado : <"<<d<<" , "<<n<<">"<<endl;
}

RSA::RSA(ZZ clave1, ZZ clave2, ZZ clave2_n2, ZZ clave3_d)
{
    e_ext = clave1;
    n_ext = clave2;
    n = clave2_n2;
    d = clave3_d;
}

string RSA::cifrar(string mensaje)
{
    cout<<"Cifrado..."<<endl;
    string result;
    string tex;
    string tex2;
    string tex3;
    vector <string> aimp;
    vector <ZZ> aimp_2;
    ZZ auxiliar;
    tex2=zzToString(n);

    string nn;
    nn=zzToString(n);
    string save1,save3,save4,save6;
    ZZ save2,save5;
    int blocks_n=nn.size();

    for(int i=0;i<mensaje.size();i++){
        tex+=orden1(alfabeto.find(mensaje[i]));
    }
    while(modulo(ZZ(tex.size()),ZZ(tex2.size()-1))!=0){
        tex+=zzToString(ZZ(alfabeto.find('W')));
    }
    int bloques=tex2.size()-1;
    for(int i=0;i<tex.size();i++){
        tex3+=tex[i];
        if(tex3.size()==bloques){
            aimp.push_back(tex3);
            tex3="";
        }
    }
    cout<<e<<endl;
    for(unsigned int i=0;i<aimp.size();i++){
        auxiliar=potencia(stringTozz(aimp[i]),e,n);
        result+=orden2(auxiliar,n);
    }
    //cout<< result<<endl;

    for(int i=0;i<result.size();i++){
        save1+=result[i];
        if(save1.size()==blocks_n){
            save2=potencia(stringTozz(save1),d,n);
            save3+=orden2(save2,n);
        }
        if((i+1)==result.size()){
            save2=potencia(stringTozz(save1),d,n);
            save3+=orden2(save2,n);
        }
    }

    for(int i=0;i<save3.size();i++){
        save4+=save3[i];
        if(save4.size()==blocks_n){
            save5=potencia(stringTozz(save4),e_ext,n_ext);
            save6+=orden2(save5,n_ext);
        }
        if((i+1)==save3.size()){
            save5=potencia(stringTozz(save4),e_ext,n_ext);
            save6+=orden2(save5,n_ext);
        }
    }
    return save6;
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
//       aux_2+=(auxiliar,n);
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



