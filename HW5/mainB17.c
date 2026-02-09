#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned int Number = 0;

    scanf("%d",&Number);
    for(int i=10;i<=Number;i++)
    {
        unsigned int Num_10_Do_Number = i;
        unsigned int Sum = 0;
        unsigned int Prod = 1;
        unsigned int EndNumber = 0;

        while(Num_10_Do_Number>0)
        {
            EndNumber=Num_10_Do_Number%10;
            Sum+=EndNumber;
            Prod *= EndNumber;
            Num_10_Do_Number/=10;
        }
        if(Sum == Prod)
            printf("%d\n",i);
    }

    return 0;
}
