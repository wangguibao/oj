/*
 * POJ1003 - Hongover
 * http://poj.org/problem?id=1003
 * Problem: 1003    User: LoiteringLeo
 * Memory: 436K     Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>
int main()
{
    double d;
    int n = 2;
    double sum = 0.0;

    while (scanf("%lf", &d) > 0) {
        if (d - 0.00 < 1e-5) {
            break;
        }
        n = 0;
        sum = 0.0;
        do {
            ++n;
            sum += (double) 1 / (1 + n);
        } while (d - sum > 1e-5);

        printf("%u card(s)\n", n);
    }
    return 0;
}

