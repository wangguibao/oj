/*
 * Problem: 2371, Questions and Answers
 * User: LoiteringLeo
 * Memory: 424K     Time: 47MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

#define MAX_ELE 5001

int a[MAX_ELE];
int b[MAX_ELE];

int main()
{
    int nd;
    int nq;
    int i;
    int d;
    int q;
    int sum = 0;
    int l;
    int r;
    int mid;
    int max = 0;

    scanf("%d\n", &nd);

    for (i = 0; i <= MAX_ELE; i++) {
        a[i] = 0;
    }

    for (i = 1; i <= nd; i++) {
        scanf("%d\n", &d);
        a[d]++;
        if (max < d) {
            max = d;
        }
    }
    scanf("###\n");
    scanf("%d\n", &nq);

    for (i = 1; i <= max; i++) {
        sum += a[i];
        b[i] = sum;
    }


    for (i = 1; i <= nq; i++) {
        scanf("%d", &q);
        l = 1, r = max;

        do {
            mid = l + ((r - l) >> 1);
            if (q <= b[mid] && q > b[mid - 1]) {
                printf("%d\n", mid);
                break;
            }
            else if (q > b[mid]) {
                l = mid + 1;
            }
            else if (q <= b[mid - 1]) {
                r = mid - 1;
            }
        } while (l <= r);
    }

    return 0;
}

