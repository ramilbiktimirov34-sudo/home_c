#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int number = 0;
    unsigned int CntNumber = 0;
    scanf("%d",&number);
    while(number != 0)
    {
        CntNumber++;
        scanf("%d",&number);
    }
    printf("%d\n",CntNumber);
    return 0;
}
