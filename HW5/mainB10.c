#include <stdio.h>
#include <stdbool.h>
int main()
{
    unsigned int a, len, end, oldlen;
    bool OK = true;
    scanf("%d",&a);
    end = a%10;
    len = a/10;
    while(len > 0)
    {
        oldlen = len%10;
        if(oldlen >= end)
            OK = false;
        end = oldlen;
        len/=10;
    }
    if(OK)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
