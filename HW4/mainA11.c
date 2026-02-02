#include <stdio.h>
#define N 5
int main()
{
    int i = 0;
    int max = 0;
    int min = 0;
    int a[N];
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    min = max = a[N-1];
    for(i=0;i<N;i++)
    {
        if(a[i]>max)
            max = a[i];
        if(a[i]<min)
            min = a[i];
    }
    printf("%d\n",max+min);
    return 0;
}
