#include <stdio.h>
#define N 3
int main()
{
    int i = 0;
    int b = 0;
    int max = 0;
    int a[N];
    scanf("%d",&b);
    a[0] = b%10;
    a[1] = (b/10)%10;
    a[2] = (b/100)%10;
    for(i=0;i<N;i++)
        if(a[i]>max)
            max = a[i];
    printf("%d\n",max);
    return 0;
}
