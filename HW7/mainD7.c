#include <stdio.h>
//#include <inttypes.h>
//#include <stdlib.h>
//#include <math.h>

void RecursNumber(int n);

int main()
{
    int Number = 0;
    scanf("%d",&Number);
    RecursNumber(Number);
    return 0;
}

void RecursNumber(int n)
{
    printf("%d ",n);
    if(n != 1)
        RecursNumber(n-1);
}
