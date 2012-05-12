/*
 * Problem: 1330, nearest common ancestors
 * User: LoiteringLeo
 * Memory: 432K     Time: 32MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <string.h>

#define MAX_ELE 10000

int tree[MAX_ELE] = {0, };
char a[MAX_ELE];

int main()
{
    int cases;
    int n;
    int i;
    int node1;
    int node2;
    int parent;
    int child;

    scanf("%d\n", &cases);

    while (cases > 0) {
        scanf("%d\n", &n);

        memset(tree, 0, sizeof(tree));

        for (i = 1; i < n; i++) {
            scanf("%d %d", &parent, &child);
            tree[child] = parent;
        }
        scanf("%d %d", &node1, &node2);

        for (i = 0; i < n; i++) {
            a[i] = 0;
        }

        while (node1 != 0) {
            a[node1] = 1;
            node1 = tree[node1];
        }
        while (node2 != 0) {
            if (a[node2] == 1) {
                printf("%d\n", node2);
                break;
            }
            node2 = tree[node2];
        }

        cases--;
    }

    return 0;
}

