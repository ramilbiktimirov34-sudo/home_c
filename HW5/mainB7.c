#include <stdio.h>
#include <stdbool.h>
#define N 10
 int main()
{
    unsigned int a, len;
    int cnt[N]={0};
    bool OK = false;

    scanf("%d",&a);
    if (a == 0)
        cnt[0] = 1;
    while(a > 0)
    {
        len = a%10;
        cnt[len]++;
        a /= 10;
    }
    for(int i=0; i<N;i++){
        if(cnt[i] > 1)
            OK = true;
    }
    if(OK)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
