/*
 * POJ1006 - Biorhythms
 * http://poj.org/problem?id=1006
 * Problem: 1006    User: LoiteringLeo
 * Memory: 428K     Time: 63MS
 * Language: GCC    Result: Accepted
 *
 * See Chinese Remainder Theorem
 * https://en.wikipedia.org/wiki/Chinese_remainder_theorem
 */
#include <stdio.h>

int main()
{
    int n = 0;
    int p = 0;
    int i = 0;
    int e = 0;
    int d = 0;
    int p_period = 23;
    int e_period = 28;
    int i_period = 33;

    while (1) {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if (p == -1 && e == -1 && i == -1 && d == -1) {
            break;
        }
        ++n;

        p = p % p_period;
        e = e % e_period;
        i = i % i_period;

        while (p % e_period != e) {
            p += p_period;
        }

        while (p % i_period != i
               || p <= d) {
            p += p_period * e_period;
        }

        p -= d;
        printf("Case %u: the next triple peak occurs in %u days.\n",
               n,
               p);
    }

    return 0;
}

