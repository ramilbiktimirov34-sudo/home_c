#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int number = 0;
    unsigned int CntEvenNumber = 0;
    scanf("%d",&number);
    while(number != 0)
    {
        if(number%2==0)
            CntEvenNumber++;
        scanf("%d",&number);
    }
    printf("%d\n",CntEvenNumber);
    return 0;
}
