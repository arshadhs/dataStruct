#include <iostream>

int main()
{
    int a[40];  // declare

    printf("SIZE = %d", sizeof(a));

    printf("\n");
    for (int i = 0; i < 40; i++)
        printf("\t%u", *a);
    printf("\n");
    for (int i = 0; i < 40; i++)
        a[i] = i;
    printf("\n");
    for (int i = 0; i < 40; i++)
        printf("\t a[%d] =%u", i, *(a+i));
    printf("\n");
    printf("SIZE = %d", sizeof(a));        
}