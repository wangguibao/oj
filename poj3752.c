/*
 * Problem: 3752, Character Rotation
 * User: LoiteringLeo
 * Memory: 400K     Time: 16MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <string.h>
#define MAX_N   1024

char matrix[MAX_N + 1][ MAX_N + 1];

void draw_circle(char start, int low, int high, int left, int right)
{
    int i;

#if 0
    printf("left = %d, right = %d, low = %d, high = %d, start = %c\n",
           left, right, low, high, start);
#endif

    if (left > right || low > high) {
#if 0
        printf("stop\n");
#endif
        return;
    }
    for (i = left; i <= right; i++) {
        matrix[low][i] = (start - 'A') % 26 + 'A';
        start++;
    }
    for (i = low + 1; i <= high; i++) {
        matrix[i][right] = (start - 'A') % 26 + 'A';
        start++;
    }
    if (high > low) {
        for (i = right - 1; i >= left; i--) {
            matrix[high][i] = (start - 'A') % 26 + 'A';
            start++;
        }
    }

    if (right > left) {
        for (i = high - 1; i > low; i--) {
            matrix[i][left] = (start - 'A') % 26 + 'A';
            start++;
        }
    }

    if (left + 1 <= right - 1 && low + 1 <= right - 1 ) {
        draw_circle((start - 'A') % 26 + 'A', low + 1, high - 1, left + 1, right - 1);
    }

    return;
}

int main()
{
    int m;
    int n;
    int i;
    int j;

    scanf("%d %d", &m, &n);

    draw_circle('A', 1, m, 1, n);

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            printf("   %c", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

