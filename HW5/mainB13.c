#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int number = 0;
    unsigned int EndNumber = 0;
    unsigned int CntEven = 0;
    unsigned int CntOdd = 0;
    scanf("%d",&number);
    while(number > 0)
    {
        EndNumber = number%10;
        if(EndNumber%2==0)
            CntEven++;
        else
            CntOdd++;
        number /= 10;
    }
    printf("%d %d\n",CntEven,CntOdd);
    return 0;
}
