/*
 * Problem: 1258, Agri-Net, minimum spanning tree
 * User: LoiteringLeo
 * Memory: 512K     Time: 16MS
 * Language: GCC    Result: Accepted
*/

#include <stdio.h>
#include <string.h>

#define MAX_FARM    500
#define MAX_DIST    1000001
#define INF         (MAX_DIST + 1)

int dist[MAX_FARM][MAX_FARM];   /* Adjacent matrix */
int mincost[MAX_FARM];          /* Minimum cost to MST */
int flag[MAX_FARM];             /* Is the farm belong to MST? */

int prim(int (*dist)[MAX_FARM], int n)
{
    int sum = 0;
    int i;
    int j;
    int min_dist;
    int candidate;

    for (i = 0; i < n; i++) {
        mincost[i] = dist[0][i];
        flag[i] = 0;
    }

    for (i = 1; i < n; i++) {
        min_dist = MAX_DIST;
        candidate = -1;
        for (j = 1; j < n; j++) {
            if (flag[j] == 0 && min_dist > mincost[j]) {
                min_dist = mincost[j];
                candidate = j;
            }
        }

        sum += min_dist;
        flag[candidate] = 1;

        for (j = 1; j < n; j++) {
            if (flag[j] == 0 && dist[candidate][j] < mincost[j]) {
                mincost[j] = dist[candidate][j];
            }
        }
    }

    return sum;
}

int main()
{
    int farm_cnt;

    while (scanf("%d", &farm_cnt) != EOF) {
        int row = 0;
        int col = 0;

        for (row = 0; row < farm_cnt; row++) {
            for (col = 0; col < farm_cnt; col++) {
                scanf("%d", &dist[row][col]);
            }
        }
        printf("%d\n", prim(dist, farm_cnt));
    }

    return 0;
}
