/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
void change_max_min(int size, int a[]);

int main(void)
{
    int N = 0;
    scanf("%d",&N);
    int a[N];
    InputArr(N,a);
    change_max_min(N,a);
    OutputArr(N,a);
    getchar();
    getchar();
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
void change_max_min(int size, int a[])
{
    int tmp = 0;;
    int max = a[0];
    int iMax = 0;
    int min = a[0];
    int iMin = 0;
    for(int i = 0; i < size; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            iMax = i;
        }
        if(a[i] < min)
        {
            min = a[i];
            iMin = i;
        }
    }
    tmp = a[iMax];
    a[iMax] = a[iMin];
    a[iMin] = tmp;
}
