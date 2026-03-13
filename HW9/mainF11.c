#include <stdio.h>
#include <limits.h>
#define MAX 30

void InputArray(int a[]);
void FindMinSumArr(int a[]);

int main(void)
{
    int arr[MAX] = {0};
    InputArray(arr);
    FindMinSumArr(arr);
    //getchar();
    //getchar();
    return 0;
}

void InputArray(int a[])
{
    for(int i = 0; i < MAX; i++)
        scanf("%d",&a[i]);
}

void FindMinSumArr(int a[])
{
    int minSum = INT_MAX;
    int Sum = 0;
    int index1 = 0;
    int index2 = 0;

    for(int i = 0; i < MAX; i++)
    {
        for(int j = i+1; j < MAX; j++)
        {
            Sum = a[i] + a[j];
            if(Sum < minSum)
            {
                minSum = Sum;
                index1 = i;
                index2 = j;
            }
        }
    }
    if(index1 < index2)
        printf("%d %d\n",index1,index2);
    else
        printf("%d %d\n",index2,index1);
}
