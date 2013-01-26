/*
 * poj2636.c - Electrical Outlets
 * Problem: 2636    User: LoiteringLeo
 * Memory: 388K     Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>

int main()
{
    int cases;
    int outlet;
    int stripe;
    int total;
    int i;
    int j;

    scanf("%d", &cases);

    for (i = 1; i <= cases; i++) {
        total = 0;
        scanf("%d", &stripe);

        for (j = 1; j <= stripe; j++) {
            scanf("%d", &outlet);
            total += outlet - 1;
        }
        total++;
        printf("%d\n", total);
    }

    return 0;
}
