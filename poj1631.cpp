/*
 * Problem: 1631, Bridging Signals
 * User: LoiteringLeo
 * Memory: 1144K     Time: 125MS
 * Language: G++    Result: Accepted
*/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_PORT    40000

int port[MAX_PORT] = {0, };

/*
 * Returns maximum number of signal lines that don't cross each other
 */
int mns(int *a, int len)
{
    int b[MAX_PORT + 1];
    int max_value[MAX_PORT + 1];
    int max_len = 1;
    int i;
    int min;

    if (len == 0) {
        return 0;
    }

    b[0] = 0;
    for (i = 1; i <= len; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    max_value[0] = min - 1;

    for (i = 1; i <= len; i++) {
        b[i] = 1;
        max_value[i] = a[i];
    }

    for (i = 2; i <= len; i++) {
        int l = 1;
        int r = max_len;
        int mid;

        do {
            mid = l + ((r - l) >> 1);
#if 0 
            printf("l = %d, r = %d, mid = %d\n", l, r, mid);
#endif
            if (a[i] > max_value[mid]) {
                l = mid + 1;
            }
            else if (a[i] < max_value[mid]) {
                r = mid - 1;
            }
        } while (l <= r);

#if 0
        
        printf("l = %d, max_value[l - 1] = %d, a[i] = %d\n",
               l, max_value[l - 1], a[i]);
#endif

        if (a[i] > max_value[l - 1]) {
#if 0
            printf("b[l - 1] = %d\n", b[l - 1]);
#endif
            b[i] = (l - 1) + 1;
        }

        if (b[i] > max_len) {
            max_len = b[i];
            max_value[b[i]] = a[i];
        }
        else if (max_value[l - 1] < a[i] && a[i] < max_value[l]) {
            max_value[l] = a[i];
        }
    }

    return max_len;
}

int main()
{
    int n;
    int p;

    scanf("%d\n", &n);

    while (n > 0) {
        scanf("%d\n", &p);
        for (int i = 1; i <= p; i++) {
            scanf("%d", &port[i]);
            getchar();
        }
        cout << mns(port, p) << endl;
        n--;
    }

    return 0;
}

