#include <stdio.h>
#define N 12

void InputArr(int arr[N]);
void InversArrPolovin(int arr[N]);

int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    InversArrPolovin(arr);
    //printf("%.2f\n",SredneeArifElem(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

void InversArrPolovin(int arr[N])
{
    int arrInvers[N] = {0};

    for(int i=0,j=3;i<3,j>=0;i++,j--){
        arrInvers[i] = arr[j];
        printf("%d ",arrInvers[i]);
    }

    for(int i=4,j=7;i<7,j>=4;i++,j--){
        arrInvers[i] = arr[j];
        printf("%d ",arrInvers[i]);
    }

    for(int i=8,j=11;i<11,j>=8;i++,j--){
        arrInvers[i] = arr[j];
        printf("%d ",arrInvers[i]);
    }
    printf("\n");
}

