#include <stdio.h>
#include <stdlib.h>
int i = 0, j = 0;
void text(char *p,char *q)
{
    while (*p)
    {
        *p++;
    }
    while (*p++=*q++);
}
int main()
{
    char a[30];
    char b[20];
    scanf("%s", a);
    scanf("%s", b);
    printf("a=%s\n\n", a);
    printf("b=%s\n\n\n", b);
    text(a, b);
    printf("结合起来=%s\n", a);
    system("pause");
    return 0;
}