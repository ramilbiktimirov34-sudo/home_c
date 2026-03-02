#include <stdio.h>
#define N 10

void InputArr(int arr[N]);
void SdvigRight(int arr[N]);

int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    SdvigRight(arr);
    //printf("%.2f\n",SredneeArifElem(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

void SdvigRight(int arr[N])
{
    int arrNew[N] = {0};
    printf("%d ",arrNew[0] = arr[N-1]);
    for(int i=1,j=0;i<N,j<N-1;i++,j++){
        arrNew[i] = arr[j];
        printf("%d ",arrNew[i]);
    }
    printf("\n");
}

