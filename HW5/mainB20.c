#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int Number = 0;
    bool Prost = true;
    scanf("%d",&Number);
    if(Number <= 1)
        Prost = false;
    else
        for(int i=2; i<Number; i++)
        {
            if(Number%i == 0)
            {
                Prost = false;
                break;
            }
        }
    if(Prost)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
