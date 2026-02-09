#include <stdio.h>

int main() {
    char ch;

    ch = getchar();


    while (ch != '.') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;  // или ch = ch + ('a' - 'A')
        }

        putchar(ch);

        ch = getchar();
    }

    printf("\n");

    return 0;
}
