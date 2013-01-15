/*
 * poj2656.c Unhappy Jinjin
 * Problem: 2656    User: LoiteringLeo
 * Memory: 408K	    Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>

int main()
{
    int n;
    int day;
    int i;
    int a;
    int b;
    int max;

    while (scanf("%d", &n) != EOF && n != 0) {
        day = 0;
        max = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &a, &b);
            if (a + b > 8) {
                if (max < a + b) {
                    max = a + b;
                    day = i;
                }
            }
        }

        printf("%d\n", day);
    }

    return 0;
}

