/**
 * Problem: 2533, Longest Ordered Subsequence
 * User: LoiteringLeo
 * Ref: http://blog.bluebore.cn/?p=350
 * Memory: 396K     Time: 32MS
 * Language: GCC    Result:
 */
#include <stdio.h>
#define MAX_ELE 1000
int a[MAX_ELE + 1];
int max[MAX_ELE + 1];

/**
 * Find the Longest Ordered Subsequence in a given number sequence
 */
int los(int *a, int n)
{
    int i;
    int j;
    int longest;

    for (i = 1; i <= n; i++) {
        max[i] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                max[i] = (max[i] > max[j] + 1) ? max[i] : max[j] + 1;
            }
        }
    }

    longest = 1;
    for (i = 1; i <= n; i++) {
        if (longest < max[i]) {
            longest = max[i];
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
