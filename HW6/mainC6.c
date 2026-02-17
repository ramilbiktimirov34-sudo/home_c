#include <stdio.h>
#include <inttypes.h>

#define Kletka 64

//#include <stdlib.h>
//#include <math.h>
//int absNumber(int a);
//int powerNumber(int a, int b);
//int Srednee(int a,int b);
//int FuncCalc(int a);
//int FuncCalcSum(int a);
uint64_t FuncCalcZerno(int a);

int main() {
    uint32_t NumberN;
    scanf("%d",&NumberN);
    printf("%"PRIu64"\n",FuncCalcZerno(NumberN));
    return 0;
}

uint64_t FuncCalcZerno(int a)
{
    uint64_t Zerno[Kletka];
    Zerno[0] = 0;
    Zerno[1] = 1;
    for(int i=2;i<Kletka+1;i++)
        Zerno[i] = Zerno[i-1] * 2;
    return Zerno[a];
}

/*int FuncCalcSum(int a)
{
    unsigned int Sum = 0;
    for(int i=1;i<a+1;i++)
        Sum+=i;
    return Sum;
}*/

/*int FuncCalc(int a)
{
    if(a<2 && a>=-2)
        return a*a;
    else if(a>=2)
        return (a*a+4*a+5);
    else if(a<-2)
        return 4;
}*/

/*int Srednee(int a,int b)
{
    return ((a+b)/2);
}*/

/*int absNumber(int a)
{
    int b = 0;
    b = abs(a);
    return b;
}*/

/*int powerNumber(int a, int b)
{
    return pow(a,b);
}*/
