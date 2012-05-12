/*
 * Problem: 3169, Layout, system of difference constraints
 * User: LoiteringLeo
 * Memory: 512K     Time: 79MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>

#define MAX_COW     1001
#define MAX_CONS    10001
#define INF         1000001

typedef struct _CONSTRAINT {
    int a;
    int b;
    int c;
} CONSTRAINT;

CONSTRAINT cons[MAX_CONS * 2];
int d[MAX_COW];

int bellman_ford(CONSTRAINT *cons, int n, int m)
{
    int i;
    int j;

    for (i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[1] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (d[cons[j].b] > d[cons[j].a] + cons[j].c) {
                d[cons[j].b] = d[cons[j].a] + cons[j].c;
            }
        }
#if 0
        printf("===========Round %d============\n", i);
        for (j = 1; j <= n; j++) {
            printf("%d ", d[j]);
        }
        printf("\n===========Round %d end========\n", i);
#endif
    }

    for (j = 1; j <= m; j++) {
        if (d[cons[j].b] > d[cons[j].a] + cons[j].c) {
            return -1;
        }
    }

    return 0;
}

int main()
{
    int n, ml, md;
    int i;
    int a, b, c;
    int m = 1;

    scanf("%d %d %d", &n, &ml, &md);

    for (i = 0; i < ml; i++) {
        scanf("%d %d %d", &a, &b, &c);
        cons[m].a = a;
        cons[m].b = b;
        cons[m].c = c;
        m++;
    }

    for (i = 0; i < md; i++) {
        scanf("%d %d %d", &a, &b, &c);
        cons[m].a = b;
        cons[m].b = a;
        cons[m].c = -c;
        m++;
    }

    if (bellman_ford(cons, n, m - 1) == 0) {
        if (d[n] == INF) {
            printf("-2\n");
        }
        else {
            printf("%d\n", d[n]);
        }
    }
    else {
        printf("-1\n");
    }
    return 0;
}
