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
    printf("\n");
    return 0;
}

void RecursNumber(int n)
{
    if(n<10)
        printf("%d ",n);
    else
    {
        printf("%d ",n%10);
        RecursNumber(n/10);
    }
}
