/*
 * Problem: 1562, Oil Depoits
 * User: LoiteringLeo
 * Memory: 404K     Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>

#define MAX_ROW 101
#define MAX_COL 101

/* Grid flags */
#define NOT_VISITED 0
#define VISITED     1
#define NOT_POCKET  2

char buf[MAX_ROW][MAX_COL];
char visited[MAX_ROW][MAX_COL];

typedef struct _GRID {
    int row;
    int col;
} GRID;

typedef struct _QUEUE {
    GRID grid[MAX_ROW * MAX_COL];
    int size;
    int cnt;
    int head;
    int tail;
} QUEUE;

/* Queue implementation */
void queue_init(QUEUE *q)
{
    q->cnt = q->head = q->tail = 0;
    q->size = MAX_ROW * MAX_COL;
}

int queue_is_empty(QUEUE *q)
{
    return (q->head == q->tail);
}

int queue_push_back(QUEUE *q, int row, int col)
{
    if (q->cnt > q->size) {
        return -1;
    }
    q->grid[q->tail].row = row;
    q->grid[q->tail].col = col;

    q->tail = (q->tail + 1) % q->size;
    q->cnt++;

    return 0;
}

GRID queue_pop_front(QUEUE *q)
{
    GRID grid;
    if (q->cnt <= 0) {
        grid.row = -1;
        grid.col = -1;
        return grid;
    }

    grid.row = q->grid[q->head].row;
    grid.col = q->grid[q->head].col;

    q->head = (q->head + 1) % q->size;
    q->cnt--;

    return grid;
}

int bfs(char (*buf)[MAX_COL], int m, int n)
{
    int i;
    int j;
    int deposite = 0;
    QUEUE q;
    GRID grid;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (buf[i][j] == '*') {
                visited[i][j] = NOT_POCKET;
            }
            else {
                visited[i][j] = NOT_VISITED;
            }
        }
    }

    queue_init(&q);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (visited[i][j] == NOT_VISITED) {
                deposite++;
                queue_push_back(&q, i, j);
                while (!queue_is_empty(&q)) {
                    grid = queue_pop_front(&q);
                    /* upper-left */
                    if (grid.row - 1 >= 0 && grid.col - 1 >= 0
                        && visited[grid.row - 1][grid.col - 1] == NOT_VISITED) {
                            visited[grid.row - 1][grid.col - 1] = VISITED;
                            queue_push_back(&q, grid.row - 1, grid.col - 1);
                    }

                    /* upper */
                    if (grid.row - 1 >= 0
                        && visited[grid.row - 1][grid.col] == NOT_VISITED) {
                            visited[grid.row - 1][grid.col] = VISITED;
                            queue_push_back(&q, grid.row - 1, grid.col);
                    }

                    /* upper-right */
                    if (grid.row - 1 >= 0 && grid.col + 1 < n
                        && visited[grid.row - 1][grid.col + 1] == NOT_VISITED) {
                            visited[grid.row - 1][grid.col + 1] = VISITED;
                            queue_push_back(&q, grid.row - 1, grid.col + 1);
                    }

                    /* right */
                    if (grid.col + 1 < n
                        && visited[grid.row][grid.col + 1] == NOT_VISITED) {
                            visited[grid.row][grid.col + 1] = VISITED;
                            queue_push_back(&q, grid.row, grid.col + 1);
                    }

                    /* lower-right */
                    if (grid.row + 1 < m && grid.col + 1 < n
                        && visited[grid.row + 1][grid.col + 1] == NOT_VISITED) {
                            visited[grid.row + 1][grid.col + 1] = VISITED;
                            queue_push_back(&q, grid.row + 1, grid.col + 1);
                    }

                    /* lower */
                    if (grid.row + 1 < m
                        && visited[grid.row + 1][grid.col] == NOT_VISITED) {
                            visited[grid.row + 1][grid.col] = VISITED;
                            queue_push_back(&q, grid.row + 1, grid.col);
                    }

                    /* lower-left */
                    if (grid.row + 1 < m && grid.col - 1 >= 0
                        && visited[grid.row + 1][grid.col - 1] == NOT_VISITED) {
                            visited[grid.row + 1][grid.col - 1] = VISITED;
                            queue_push_back(&q, grid.row + 1, grid.col - 1);
                    }

                    /* left */
                    if (grid.col - 1 >= 0
                        && visited[grid.row][grid.col - 1] == NOT_VISITED) {
                            visited[grid.row][grid.col - 1] = VISITED;
                            queue_push_back(&q, grid.row, grid.col - 1);
                    }
                }   /* end while */
            }   /* end if */
        }
    }

    return deposite;
}

int main()
{
    int m;
    int n;
    int i;

    while (scanf("%d %d", &m, &n) && m > 0) {
        for (i = 0; i < m; i++) {
            scanf("%s", buf[i]);
        }
        printf("%d\n", bfs(buf, m, n));
    }

    return 0;
}
