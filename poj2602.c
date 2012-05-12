/*
 * Problem: 2602, Superlong sums
 * User: LoiteringLeo
 * Memory: 3328     Time: 63MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

#define MAX_PAIR   1000005

typedef struct _PAIR {
    char d1;
    char d2;
} PAIR;

PAIR pairs[MAX_PAIR];
char sum[MAX_PAIR] = {'\0', };

int main()
{
    int n;
    int i;
    int result;
    int carry;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        pairs[i].d1 = getchar() - '0';
        getchar();
        pairs[i].d2 = getchar() - '0';
        getchar();
    }

    for (i = n - 1, carry = 0; i >= 0; i--) {
        result = pairs[i].d1 + pairs[i].d2 + carry;
        carry = result / 10;
        sum[i] = (result % 10) + '0';
    }

    puts(sum);
    return 0;
}

