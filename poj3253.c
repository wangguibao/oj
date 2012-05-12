/*
 * Problem: 3253, Fence Repair
 * User: LoiteringLeo
 * Memory: 560K     Time: 0MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

#define MAX_ELE 20001
#define MAX_LEN 50001

int len[MAX_ELE + 1];
long long int b[MAX_ELE + 1];

int partition(int *a, int l, int r)
{
    int x = a[r];
    int tmp;
    int i = l - 1;
    int j;

    for (j = l; j < r; j++) {
        if (a[j] < x) {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i + 1];
    a[i + 1] = x;
    a[r] = tmp;

    return i + 1;
}

void quicksort(int *a, int l, int r)
{
    int part;

    if (l >= r) {
        return;
    }

    part = partition(a, l, r);
    quicksort(a, l, part - 1);
    quicksort(a, part + 1, r);
}

long long int min_cost(int *a, int l, int r)
{
    int i;
    int j;      /* Points to the head of the second array */
    int k;      /* Points to the tail of the second array */
    long long int cost = 0;

    if (l > r) {
        return 0;
    }
    else if (l == r) {
        b[1] = a[l];
        return b[1];
    }

    b[1] = a[l] + a[l + 1];

    i = l + 2, j = 2, k = 1;

    while (i <= r) {
        if ((i + 1 <= r) && a[i] <= b[k] && a[i + 1] <= b[k]) {
            b[j] = a[i] + a[i + 1];
            i += 2;
            j++;
        }
        else if ((k + 1 < j) && b[k] <= a[i] && b[k + 1] <= a[i]) {
            b[j] = b[k] + b[k + 1];
            k += 2;
            j++;
        }
        else  {
            b[j] = a[i] + b[k];
            i++;
            k++;
            j++;
        }
    }

    while (k + 1 < j) {
        b[j] = b[k] + b[k + 1];
        j++;
        k += 2;
    }

    for (k = 1; k < j; k++) {
        cost += b[k];
    }

    return cost;
}

int main()
{
    int n;
    int i;
    int sum = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &len[i]);
        sum += len[i];
    }

    quicksort(len, 1, n); 

    printf("%lld\n", min_cost(len, 1, n));
    return 0;
}

