#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned int First = 0;
    unsigned int Second = 1;
    unsigned int Next = 0;
    unsigned int Num = 0;
    scanf("%d",&Num);
    printf("%d\n",Second);
    for(int i = 2; i<=Num ;i++)
    {
        Next = First + Second;
        printf("%d\n",Next);
        First = Second;
        Second = Next;
    }
    return 0;
}
