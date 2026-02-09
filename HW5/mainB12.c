#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int number1 = 0;
    unsigned int number2 = 0;
    unsigned int EndNumber = 0;
    unsigned int MaxNumber = 0;
    unsigned int MinNumber = 0;

    scanf("%d",&number1);
    number2 = number1;
    if(number1 == 0 || number1 < 10){
        printf("%d %d\n",number1,number2);
    }
    else
    {
        while(number1 > 0)
        {
            EndNumber = number1%10;
            MinNumber = EndNumber;
            if(EndNumber > MaxNumber)
                MaxNumber = EndNumber;
            number1/=10;
        }
        while(number2 > 0)
        {
            EndNumber = number2%10;
            if(EndNumber < MinNumber)
                MinNumber = EndNumber;
            number2/=10;
        }
        printf("%d %d",MinNumber,MaxNumber);
        printf("\n");
    }
    return 0;
}
