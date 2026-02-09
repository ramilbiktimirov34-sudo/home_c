#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int NumberOne = 0;
    unsigned int NumberTwo = 0;
    unsigned int Ostatok = 0;
    scanf("%d %d",&NumberOne,&NumberTwo);
    if(NumberOne > NumberTwo)
    {
        Ostatok = NumberOne%NumberTwo;
        while(Ostatok != 0)
        {
            NumberOne = NumberTwo;
            NumberTwo = Ostatok;
            Ostatok = NumberOne%NumberTwo;
        }
        printf("%d\n",NumberTwo);
    }
    else if(NumberOne < NumberTwo)
    {
        Ostatok = NumberTwo%NumberOne;
        while(Ostatok != 0)
        {
            NumberTwo = NumberOne;
            NumberOne = Ostatok;
            Ostatok = NumberTwo%NumberOne;
        }
        printf("%d\n",NumberOne);
    }
    return 0;
}
