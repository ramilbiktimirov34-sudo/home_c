#include <stdio.h>
#include <stdlib.h>
int absNumber(int a);

int main() {
    int Number = 0;
    scanf("%d",&Number);
    printf("%d\n",absNumber(Number));
    return 0;
}

int absNumber(int a)
{
    int b = 0;
    b = abs(a);
    return b;
}
