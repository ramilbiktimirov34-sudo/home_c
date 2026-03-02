#include <stdio.h>
#define N 12

void InputArr(int arr[N]);
float SredneeArifElem(int arr[N]);


int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%.2f\n",SredneeArifElem(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

float SredneeArifElem(int arr[N])
{
    int Summ = 0;
    for(int i=0;i<N;i++)
        Summ += arr[i];
    return (float)Summ/N;
}

