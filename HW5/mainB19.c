#include <stdio.h>

int main()
{
    unsigned int Number = 0;
    unsigned int EndNumder = 0;
    unsigned int Sum = 0;
    scanf("%d",&Number);
    while(Number > 0)
    {
        EndNumder = Number%10;
        Sum+=EndNumder;
        Number/=10;

    }
    if(Sum == 10)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
