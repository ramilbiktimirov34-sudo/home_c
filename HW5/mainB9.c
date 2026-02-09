#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int a, len;
    bool OK = true;
    scanf("%d",&a);
    while(a > 0)
    {
        len = a%10;
        if(len%2 != 0)
            OK = false;
        a /= 10;
    }
    if(OK)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
