#include <stdio.h>
#define N 10

void InputArr(int arr[N]);
//int MinimumArr(int arr[N]);
int MaximumArr(int arr[N]);
//int NumMinimumArr(int arr[N]);
//int NumMaximumArr(int arr[N]);
//float SredneeArr(int arr[N]);


int main(void)
{
    int arr[N] = {0};
    InputArr(arr);
    printf("%d\n",MaximumArr(arr));
    return 0;
}

void InputArr(int arr[N])
{
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
}

/*int MinimumArr(int arr[N])
{
    int MinElem = arr[0];
    for(int i=0;i<N;i++)
    {
        if(arr[i]<MinElem){
            MinElem = arr[i];
        }
    }
    return MinElem;
}*/

int MaximumArr(int arr[N])
{
    int MaxElem1 = arr[0];
    int MaxElem2 = arr[1];
    for(int i=2;i<N;i++)
    {
        if(arr[i]>MaxElem1){
            MaxElem2 = MaxElem1;
            MaxElem1 = arr[i];
        }
        else if(arr[i]>MaxElem2)
            MaxElem2 = arr[i];
    }
    return MaxElem1+MaxElem2;
}

/*int NumMinimumArr(int arr[N])
{
    int MinElem = arr[0];
    int PosMinElem = 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]<MinElem){
            MinElem = arr[i];
            PosMinElem = i+1;
        }
    }
    return PosMinElem;
}*/

/*int NumMaximumArr(int arr[N])
{
    int MaxElem = arr[0];
    int PosMaxElem = 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>MaxElem){
            MaxElem = arr[i];
            PosMaxElem = i+1;
        }
    }
    return PosMaxElem;
}*/

/*float SredneeArr(int arr[N])
{
    float Summ = 0;
    for(int i=0;i<N;i++)
        Summ += arr[i];
    return Summ/N;
}*/
