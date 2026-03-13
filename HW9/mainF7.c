/*#include <stdio.h>
void InputArr(int size, int a[]);
void OutputArr(int size, int a[]);
int compression(int a[], int b[], int N);
int main(void)
{
    int N = 0;
    scanf("%d",&N);
    int a[N];
    int b[] = {0};
    InputArr(N,a);
    compression(a,b,N);
    OutputArr(compression(a,b,N),b);
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
    printf("[");
    for(int i = 0; i < size; i++)
        printf("%d,",a[i]);
    printf("]");
}
*/
int compression(int a[], int b[], int N)
{
    int j = 0, count = 1;

    if (N == 0) return 0;
    if (a[0] == 1) b[j++] = 0;

    for (int i = 1; i < N; i++) {
        if (a[i] == a[i-1]) count++;
        else {
            b[j++] = count;
            count = 1;
        }
    }
    b[j++] = count;

    return j;
}
