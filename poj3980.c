/*
 * Problem: 3980, Modulo Operation
 * User: LoiteringLeo
 * Memory: 384K     Time: 375MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

#define MAX_LINE    32

char input[MAX_LINE];

int mod(int a, int b)
{
    int i;

    if (a < b) {
        return a;
    }
    else if (a == b) {
        return 0;
    }

    i = a / b;
    return a - i * b;
}

int main()
{
    int i;
    int j;
    while (gets(input) != NULL) {
        sscanf(input, "%d %d", &i, &j);
        printf("%d\n", mod(i, j));
    }

    return 0;
}
