#include <stdio.h>
struct
{
    int name;
};

int main()
{
    int a = 10;
    int b = 20;
    int result = a + b;

    printf("Sum of %d and %d is: %d\n", a, b, result);

    return 0;
}