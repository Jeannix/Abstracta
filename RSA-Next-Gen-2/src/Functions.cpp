#include "Functions.h"

ZZ modulo(ZZ a, ZZ n)
{
    ZZ q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}
ZZ euclides(ZZ a, ZZ b)
{
     ZZ residuo = modulo(a,b);
     while(residuo!=0)
     {
         a = b;
         b = residuo;
         residuo = modulo(a,b);
     }
     return b;
}
ZZ mcd(ZZ a, ZZ b)
{
    ZZ resultado;
    resultado = 1;
    ZZ i;
    for(i=1;i<=a;i++)
    {
        if((modulo(a,i)==0)&&(modulo(b,i)==0))
        {
            resultado = i;
        }
    }
    return resultado;
}

vector <ZZ> extendido(ZZ a, ZZ b)
{
    vector <ZZ> resultados;
    ZZ r1,s1,t1,r2,s2,t2,q,r;
    r1 = a;
    r2 = b;
    s1 = 1;
    s2 = 0;
    t1 = 0;
    t2 = 1;
    while(r2>0)
    {
        q = r1/r2;

        ZZ r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ZZ s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        ZZ t = t1 - q * t2;
        t1 = t2;
        t2 = t;

    }
    resultados.push_back(r1);
    resultados.push_back(s1);
    resultados.push_back(t1);
    return resultados;
}

ZZ inversa(ZZ a, ZZ alfabeto)
{
    ZZ x = extendido(a,alfabeto)[1];
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}

ZZ potencia(ZZ a, ZZ b, ZZ modu)
{
    ZZ result = to_ZZ(1);
    ZZ n = to_ZZ(2);
    ZZ x = to_ZZ(a);
    while(b != 0){
        if(modulo(b,n)==1){
            result = modulo((result * x),modu);
        }
        x = modulo((x * x),modu);
        b = b/2;
    }
    return result;
}
string int_to_string(int s){
    stringstream ss;
    ss<<s;
    string aux=ss.str();
    return aux;
}

int string_to_int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
//ZZ potencia(ZZ x, ZZ y)
//{
//    ZZ res = ZZ(1);
//
//    while (y > 0)
//    {
//        if (y & 1)
//            res = res*x;
//        y = y>>1;
//        x = x*x;
//    }
//    return res;
//}

string zzToString(ZZ z) {
    std::stringstream ss;
    ss << z;
    return ss.str();
}

ZZ stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}

ZZ int_ZZ(int n){
    ZZ z;
    conv(z,n);
    return z;
}

int ZZ_int(ZZ z){
    int n;
    conv(n,z);
    return n;
}

ZZ phi_euler(ZZ p, ZZ q)
{
    return ((p-1)*(q-1));
}
string invertir(string b){
    string temp;
    for(int i=0;i<b.size();i++){
        temp+=b[b.size()-1-i];
    }
    return temp;
}
string bin(ZZ a){
    string tmp;
    while(a!=ZZ(0)){
        tmp+=zzToString(ZZ(a%2));
        a/=ZZ(2);
   }
   tmp=invertir(tmp);
   return tmp;
}
