/**
 * Problem: POJ 1129, Channel Allocation
 * User: LoiteringLeo
 * Memory: 388K     Time: 0MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <string.h>

#define MAX_VERTEX  26

char graph[MAX_VERTEX][MAX_VERTEX];

/**
 * Coloring on a graph, returns the minimum colors needed
 * @param graph - the matrix represented graph
 * @param n - number of vertices
 * @return minimum number of colors needed to color the graph
 */
int color(char (*graph)[MAX_VERTEX], int n)
{
    int i;
    int j;
    int order = 0;
    int min_color = 0;
    char final_color[MAX_VERTEX];
    int adj_color_bits;

    /* Determine the order of the graph */
    for (i = 0; i < n; i++) {
        int order_i = 0;
        for (j = 0; j < n; j++) {
            if (i != j && graph[i][j] == 1) {
                order_i++;
            }
        }
        if (order < order_i) {
            order = order_i;
        }
    }

    memset(final_color, 0, MAX_VERTEX);

    /* Go through each vertex */
    final_color[0] = 0;

    for (i = 1; i < n; i++) {
        adj_color_bits = 0;
        for (j = 0; j < i; j++) {
            if (graph[i][j] == 1) {
                adj_color_bits |= 1 << final_color[j];
            }
        }

        for (j = 1; j <= order + 1; j++) {
            if ((adj_color_bits & (1 << (j - 1))) == 0) {
                final_color[i] = j - 1;
                break;
            }
        }
    }


    min_color = 0;
    for (j = 0; j < n; j++) {
        if (min_color < final_color[j]) {
            min_color = final_color[j];
        }
    }

    return min_color + 1;
}

int main()
{
    int n;
    char line[MAX_VERTEX + 2];

    while (scanf("%d", &n) && n != 0) {
        int i;
        int j;
        int colors;

        memset(graph, 0, MAX_VERTEX * MAX_VERTEX);

        for (i = 0; i < n; i++) {
            scanf("%s", line);

            for (j = 2; j < strlen(line); j++) {
                graph[i][line[j] - 'A'] = 1;
            }
        }

        colors = color(graph, n);
        printf("%d channel%s needed.\n", colors, colors > 1 ? "s": "");
    }

    return 0;
}
