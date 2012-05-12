/*
 * Problem: 1658, Eva's Problem
 * User: LoiteringLeo
 * Memory: 388K     Time: 0MS
 * Language: GCC    Result: Accepted
*/

#include <stdio.h>

int main()
{
    int n;

    int n1, n2, n3, n4;
    int n5;

    scanf("%d", &n);
    while (n > 0) {
        scanf ("%d %d %d %d", &n1, &n2, &n3, &n4);
        if (n2 - n1 == n3 - n2 && n3 - n2 == n4 -n3) {
           n5 = n4 + (n4 - n3);
        }
        else {
            n5 = n4 * (n4 / n3);
        }
        printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);
        n--;
    }

    return 0;
}

