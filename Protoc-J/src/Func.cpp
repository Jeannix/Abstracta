#include "../include/Func.h"

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int euclides(int a, int b)
{
    int res=modulo(a,b);
    while(res!=0)
    {
        a=b;
        b=res;
        res=modulo(a,b);
    }
    return b;
}

int euclides_extendido(int a,int b)
{
    int result;
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    result=x;
    return result;
}
int inversa(int a, int b)
{
    int temp;
    temp = euclides_extendido(a,b);
    if(temp<0){
        return modulo(temp,b);
    }
    else{
        return temp;
    }
}
int generar_Aleatorio(){
    srand(time(NULL));
    int numero_aleatorio=rand();  ///Numeros entre 1-1000
    return numero_aleatorio;
}
int generar_Aleatorio_Max(int max){
    srand(time(NULL));
    int numero_aleatorio=rand()%(max);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
void generar_claves_affin(int &a,int &b, int mod)
{
    a = generar_Aleatorio();
    while(euclides(a,mod)!=1){
        a=generar_Aleatorio();
    }
    b=generar_Aleatorio_Max(mod-1);
}
