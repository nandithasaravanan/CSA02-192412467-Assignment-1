#include <stdio.h>

#define RUPEES_TO_PAISE(x) ((x) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline int square_function(int x)
{
    return x * x;
}

static inline int max_function(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 4, b = 7;

    printf("Rupees to paise: %d\n", RUPEES_TO_PAISE(25));
    printf("Square of a + 1: %d\n", SQUARE(a + 1));
    printf("Maximum value: %d\n", MAX(a, b));

    printf("Square using inline function: %d\n",
           square_function(a + 1));
    printf("Maximum using inline function: %d\n",
           max_function(a, b));

    return 0;
}
