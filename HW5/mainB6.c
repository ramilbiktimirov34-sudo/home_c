#include <stdio.h>

 int main()
{
    unsigned int a, oldLen, len;
    int b = 0;
    scanf("%d",&a);
    while(a != 0)
    {
        len = a%10;
        a /= 10;
        if(oldLen == len)
        {
            b = 1;
        }
        //printf("A=%d, Len=%d Old=%d\n",a,len,oldLen);
        oldLen = len;
    }
    if(b == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
