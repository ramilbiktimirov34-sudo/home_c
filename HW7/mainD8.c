#include <stdio.h>
//#include <inttypes.h>
//#include <stdlib.h>
//#include <math.h>

void RecursNumber(int n, int m);

int main()
{
    int NumberA = 0;
    int NumberB = 0;
    scanf("%d%d",&NumberA,&NumberB);
    RecursNumber(NumberA,NumberB);
    return 0;
}

void RecursNumber(int n,int m)
{
    printf("%d ",n);
    if(n == m)
        return;
    if(n < m)
        RecursNumber(n+1,m);
    else
        RecursNumber(n-1,m);
}
