/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
void swap_negmax_last(int size, int a[]);
int main(void)
{
    int sizeA = 0;
    scanf("%d",&sizeA);
    int a[sizeA];
    InputArr(sizeA,a);
    swap_negmax_last(sizeA,a);
    OutputArr(sizeA,a);
    //getchar();
    //getchar();
    return 0;
}

void InputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        scanf("%d", &a[i]);
}

void OutputArr(int size, int a[])
{
    for(int i = 0; i < size; i++)
        printf("%d ",a[i]);
}
*/
void swap_negmax_last(int size, int a[])
{
    int indexMaxNeg = -1;
    for(int i = 0; i < size; i++)
        if(a[i] < 0)
            if(indexMaxNeg == -1 || a[i] > a[indexMaxNeg])
                indexMaxNeg = i;

    if(indexMaxNeg != -1)
    {
        int tmp = a[indexMaxNeg];
        a[indexMaxNeg] = a[size-1];
        a[size-1] = tmp;
    }
}
