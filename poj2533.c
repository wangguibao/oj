/**
 * Problem: 2533, Longest Ordered Subsequence
 * User: LoiteringLeo
 * Memory: 4316K     Time: 938MS
 * Language: GCC    Result:
 */
#include <stdio.h>
#define MAX_ELE 1000
int a[MAX_ELE + 1];
int c[MAX_ELE + 1][MAX_ELE + 1];

/**
 * Find the Longest Ordered Subsequence in a given number sequence
 */
int los(int *a, int n)
{
    int i;
    int j;
    int k;
    int longest;
    int curr_longest;

    for (i = 1; i <= n; i++) {
        c[1][i] = 1;
        c[i][i] = 1;
    }

    for (j = 2; j <= n; j++) {
        curr_longest = 1;
        for (i = 1; i < j; i++) {
            for (k = i; k < j; k++) {
                if (a[j] > a[k] && curr_longest < c[i][k] + 1) {
                    curr_longest = c[i][k] + 1;
                }
            }
            c[i][j] = curr_longest;
        }
    }

#if 0
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

#endif

    longest = c[1][1];
    for (i = 2; i <= n; i++) {
        if (longest < c[1][i]) {
            longest = c[1][i];
        }
    }
    return longest;
}

int main()
{
    int n;
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", los(a, n));

    return 0;
}
