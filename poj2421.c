/*
 * poj2421 - Constructing Roads
 * Problem: 2421    User: LoiteringLeo
 * Memory: 448K     Time: 63MS
 * Language: GCC    Result: Accepted
 *
 * Tke key is to use disjoint-set + Kruskal algorithm to grow a minimum spanning tree
 */
#include <stdio.h>

#define MAX_VILLAGE 100

typedef struct _VILLAGE VILLAGE;
struct _VILLAGE {
    int n;
    int k;
    int head;
};

typedef struct _DIST {
    int d;
    int a;
    int b;
} DIST;

VILLAGE village[MAX_VILLAGE + 1];
DIST dist[MAX_VILLAGE * (MAX_VILLAGE - 1) + 1];

void make_set(int n)
{
    village[n].n = n;
    village[n].k = 0;
    village[n].head = n;
}

int find_set(int n)
{
    if (village[n].head != n) {
        village[n].head = find_set(village[n].head);
    }
    return village[n].head;
}

void union_set(int m, int n)
{
    int pm = find_set(m);
    int pn = find_set(n);

    if (village[pm].k < village[pn].k) {
        village[pm].head = pn;
    }
    else {
        village[pn].head = pm;
        if (village[pm].k == village[pn].k) {
            village[pm].k++;
        }
    }
}

int partition(DIST *dist, int begin, int end)
{
    int i = begin - 1;
    int j;
    DIST pivot = dist[end];
    DIST temp;

    for (j = begin; j < end; j++) {
        if (dist[j].d <= pivot.d) {
            i++;

            temp.d = dist[j].d;
            temp.a = dist[j].a;
            temp.b = dist[j].b;

            dist[j].d = dist[i].d;
            dist[j].a = dist[i].a;
            dist[j].b = dist[i].b;

            dist[i].d = temp.d;
            dist[i].a = temp.a;
            dist[i].b = temp.b;
        }
    }

    temp.d = dist[j].d;
    temp.a = dist[j].a;
    temp.b = dist[j].b;

    dist[j].d = dist[i+1].d;
    dist[j].a = dist[i+1].a;
    dist[j].b = dist[i+1].b;

    dist[i+1].d = temp.d;
    dist[i+1].a = temp.a;
    dist[i+1].b = temp.b;

    return i+1;
}

void quicksort(DIST *dist, int begin, int end)
{
    int p;

    if (begin > end) {
        return;
    }

    p = partition(dist, begin, end);
    quicksort(dist, begin, p - 1);
    quicksort(dist, p + 1, end);
}

int main()
{
    int i;
    int j;
    int k;
    int d;
    int n;
    int q;
    int a;
    int b;
    int total = 0;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        make_set(i);
    }

    k = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &d);
            if (j > i ) {
                dist[k].d = d;
                dist[k].a = i;
                dist[k].b = j;
                k++;
            }
        }
    }

    /**
     * Sort distances in ascending order. This helps Kruskal alrogitm pick safe edge quickly
     */
    quicksort(dist, 0, k - 1);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        union_set(a, b);
    }

    /**
     * Repeatedly pick a safe edge and add to minimum spanning tree, adding the weight of the edge to total
     */
    for (i = 0; i < k; i++) {
        if (find_set(dist[i].a) != find_set(dist[i].b)) {
            union_set(dist[i].a, dist[i].b);
            total += dist[i].d;
        }
    }

    printf("%d\n", total);

    return 0;
}
