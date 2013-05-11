/*
 * POJ1528 - Perfection
 * Note: 1 is deficient
 *
 * Problem: 1528    User: LoiteringLeo
 * Memory: 388K     Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>
int main()
{
    int n;

    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n) != EOF && n != 0) {
        int begin;
        int end;
        int total;

        printf("%5d  ", n);

        begin = 0;
        end = n;
        total = 0;
        while (begin < n && begin <= end) {
            while ((n % (++begin)) != 0);
            end = n / begin;
            if (begin == 1 && end != 1) {
                total += 1;
            }
            else if (begin > end) {
                break;
            }
            else if (begin == end) {
                if (begin != 1) {
                    total += begin;
                }
            }
            else {
                total += begin + end;
            }
        }

        if (total < n) {
            printf("DEFICIENT\n");
        }
        else if (total == n) {
            printf("PERFECT\n");
        }
        else {
            printf("ABUNDANT\n");
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
