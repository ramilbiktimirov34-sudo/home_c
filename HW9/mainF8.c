#include <stdio.h>
//#include <inttypes.h>
//#include <stdint.h>
#define MAX 1000
int InputArray(int a[]);
void OutputArray(int a[], int size);
int Max_Elem_Array(int a[], int size);
int Min_Elem_Array(int a[], int size);
int Sum_Elem_Array(int a[], int size);
int Found_Expect(unsigned int M,
                 unsigned int N,
                 unsigned int Sum);

int main(void)
{
    unsigned int cnt = 0;
    unsigned int M = 0, N = 0;
    int arr[MAX] = {0};
    //InputArray(arr);
    cnt = InputArray(arr);

    //OutputArray(arr, cnt);
    printf("%d\n",
           Found_Expect(Min_Elem_Array(arr,cnt),
                        Max_Elem_Array(arr,cnt),
                        Sum_Elem_Array(arr,cnt))
        );
    //getchar();
    //getchar();
    return 0;
}

int InputArray(int a[])
{
    unsigned int count = 0;
    unsigned int Num = 0;
    unsigned int Sum = 0;
    while(count < MAX)
    {
        scanf("%d", &Num);
        if(Num == 0)
            break;
        a[count] = Num;
        count++;
    }
    return count;
}

void OutputArray(int a[],int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ",a[i]);
}

int Max_Elem_Array(int a[], int size)
{
    unsigned int Max = a[0];
    for(int i = 0; i < size; i++)
        if(a[i] > Max)
            Max = a[i];
    return Max;
}

int Min_Elem_Array(int a[], int size)
{
    unsigned int Min = a[0];
    for(int i = 0; i < size; i++)
        if(a[i] < Min)
            Min = a[i];
    return Min;
}

int Sum_Elem_Array(int a[], int size)
{
    unsigned int Sum = 0;
    for(int i = 0; i < size; i++)
        Sum += a[i];
    return Sum;
}

int Found_Expect(unsigned int M,
                 unsigned int N,
                 unsigned int Sum)
{
    unsigned int Num = 0, Expect = 0;
    Expect = (M+N)*(N-M+1)/2;
    Sum += Num;
    return Expect - Sum;
}
