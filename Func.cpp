#include "Func.h"

int mod(int a, int b)
{
    int q=a/b;
    int r=a-(q*b);
    if(r<0)
        r+=b;
    return r;
}
