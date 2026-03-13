#include <stdio.h>
#define MAX 1000

void StrNum(char* str);

int main(void)
{
    char str[MAX];
    StrNum(str);
    //getchar();
    //getchar();
    return 0;
}

void StrNum(char* str)
{
    gets(str);
    for( int i = 0; str[i] != '\0'; i++)
    {
        int cnt = 1;
        while(str[i] == str[i+1])
        {
            cnt++;
            i++;
        }
        if(str[i] != '.')
            printf("%c%d",str[i],cnt);
    }
}
