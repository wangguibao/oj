/*
 * Problem: 3913, Gnome Sequencing
 * User: LoiteringLeo
 * Memory: 384K     Time: 0MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

int main()
{
    int n;
    int i;
    int j;
    int k;

    scanf("%d", &n);

    printf("Gnomes:\n");
    while (n > 0) {
        scanf("%d %d %d", &i, &j, &k);

        if ((i > j && j > k) || (i < j && j < k)) {
            printf("Ordered\n");
        }
        else {
            printf("Unordered\n");
        }
        n--;
    }

    return 0;
}
