/*
 * Problem: POJ1182, food chain (Disjoint Sets)
 * User: LoiteringLeo
 * Memory: 776K		Time: 266MS
 *Language: GCC		Result: Accepted
 */
#include <stdio.h>

#define MAX_ANIMAL  50000
#define UNDETERMINED_TYPE   3

int parent[MAX_ANIMAL + 1]; // Parent node id
int type[MAX_ANIMAL + 1];   // Node type
int lies = 0;
int n = 0;
int k = 0;

void make_set(int k)
{
    parent[k] = k;
    type[k] = 0;
}

int finds(int k)
{
    if (parent[k] == k) {
        return k;
    }
    else {
        parent[k] = finds(parent[k]);
    }

    return parent[k];
}

int find_set(int k)
{
    int p;

    if (parent[k] == k) {
        return k;
    }

    p = find_set(parent[k]);

    type[k] = (type[k] + type[parent[k]]) % 3;
    parent[k] = p;

    return p;
}

void check(int d, int x, int y)
{
    int p_x = find_set(x);
    int p_y = find_set(y);

    if (x > n || y > n) {
        lies++;
        return;
    }

    if (p_x == p_y) {
        if (((type[y] - type[x] + 3) % 3) != d - 1) {
            lies++;
        }
        return;
    }

    parent[p_y] = p_x;
    if (d == 1) {
        type[p_y] = (type[x] - type[y] + 3) % 3;
    }
    else if (d == 2) {
        type[p_y] = (type[x] - type[y] + 7) % 3;
    }
    return;
}

int main()
{
    int i;
    int d;
    int x;
    int y;

    scanf("%d %d", &n, &k);

    for (i = 1; i <= n; i++) {
        make_set(i);
    }

    for (i = 1; i <= k; i++) {
        scanf("%d %d %d", &d, &x, &y);
        check(d, x, y);
    }

    printf("%d\n", lies);

    return 0;
}
