#include <stdio.h>
//#include <inttypes.h>
//#include <stdlib.h>
//#include <math.h>

int RecursNumber(int n);

int main()
{
    int NumberA = 0;
    scanf("%d",&NumberA);
    int ResSum = RecursNumber(NumberA);
    printf("%d\n",ResSum);
    return 0;
}

int RecursNumber(int n)
{
    if(n < 10)
        return n;
    return (n%10)+RecursNumber(n/10);
}
