#include <stdio.h>

 int main()
{
    unsigned int a;
    unsigned int b;
    scanf("%d%d",&a,&b);
    if(a>0 && a<100 && a<=b)
        if(b>0 && b<100)
        {
            for(int c=a; c<b+1;c++)
            {
                printf("%d\t",c*c);
            }
        }
}
