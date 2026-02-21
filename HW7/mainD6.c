#include <stdio.h>
//#include <inttypes.h>
//#include <stdlib.h>
//#include <math.h>

void RecursChar(void);

int main()
{
    RecursChar();
    return 0;
}

void RecursChar(void)
{
    char str;
    scanf("%c",&str);
    if(str == '.')
        return;
    RecursChar();
    printf("%c",str);
}
