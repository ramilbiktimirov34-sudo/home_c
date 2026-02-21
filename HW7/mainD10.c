#include <stdio.h>
//#include <inttypes.h>
//#include <stdlib.h>
//#include <math.h>

int RecursNumberProst(int n, int m);

int main()
{
    int NumberA = 0;
    scanf("%d",&NumberA);
    if(RecursNumberProst(NumberA,2))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

int RecursNumberProst(int n, int m)
{
    if(n<2)
        return 0;
    if(m*m > n)
        return 1;
    if(n%m == 0)
        return 0;
    return RecursNumberProst(n,m+1);
}
