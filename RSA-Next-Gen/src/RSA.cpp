#include "RSA.h"
ZZ RSA::modulo(ZZ a, ZZ n)
{
    ZZ q, r;
	q = a / n;
	r = a - (q*n);
	if (r < 0)
		r += n;
	return r;
}
ZZ RSA::euclides(ZZ a, ZZ b)
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
ZZ RSA::mcd(ZZ a, ZZ b)
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

ZZ RSA::extendido(ZZ a, ZZ b)
{
    ZZ resultados;
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
    resultados=r1;
    return resultados;
}

ZZ RSA::inversa(ZZ a, ZZ alfabeto)
{
    ZZ x = extendido(a,alfabeto);
    if(x<0)
    {
        return modulo(x,alfabeto);
    }
    return x;
}

ZZ RSA::potencia(ZZ a, ZZ b, ZZ modu)
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

/*string RSA::zzToString(ZZ z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ RSA::stringTozz(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}

vector<bool> RSA::ZZtoBinary(ZZ num){
    vector<bool> binario;
    while(num>0){
        binario.push_back(to_int(modulo(num,to_ZZ(2))));
        num=num>>1;
    }
    return binario;
}
*/
/*ZZ RSA::potenciaMod(ZZ n, ZZ m, ZZ mod){
    if(n>mod)
        n=modulo(n,mod);
    vector<bool> b=ZZtoBinary(m);
    ZZ d=to_ZZ(1);
	for(int i=b.size();i>0;i--){
        d=modulo(d*d,mod);
        if(b[i-1]==1)
            d=modulo(d*n,mod);
	}
	return d;
}
*/
