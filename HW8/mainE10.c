#include <stdio.h>
#define N 12

void InputArr(int arr[N]);
void SdvigRight(int arr[N]);

int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    SdvigRight(arr);
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
    for(int i=0;i<N;i++){
        arrNew[(i+4)%12] = arr[i];
    }
    for(int j=0;j<N;j++)
        printf("%d ",arrNew[j]);
    printf("\n");
}

