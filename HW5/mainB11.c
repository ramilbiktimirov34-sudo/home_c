#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int number = 0;
    unsigned int EndNumber = 0;
    scanf("%d",&number);
    if(number == 0)
        printf("%d",EndNumber);
    while(number > 0)
    {
        EndNumber = number%10;
        number/=10;
        printf("%d",EndNumber);
    }
    printf("\n");
    return 0;
}
