/*
 * poj1020.cpp - Anniversary Cake
 * Problem: 1020    User: LoiteringLeo
 * Memory: 732K     Time: 32MS
 * Language: G++    Result: Accepted
 */
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_PIECES      16          /* Max num of cake pieces */
#define MAX_EDGE        10          /* Max edge len of a cake piece */
#define MAX_CAKE_EDGE   40          /* Max edge len of the cake */

int side;                           /* Cake size */
int npiece;                         /* Number of pieces */
int pieces[MAX_EDGE + 1];           /* Number of pieces having edge i */
int rows[MAX_CAKE_EDGE + 1];        /* Unused row for each column */
int used;

void reset_state()
{
    side = 0;
    npiece = 0;
    memset(pieces, 0, sizeof(pieces));
    for (int i = 0; i <= MAX_CAKE_EDGE; i++) {
        rows[i] = 1;
    }
    used = 0;
}

int judge(int used, int *rows)
{
    if (used == npiece)
    {
        return 0;
    }

    int row_start = MAX_CAKE_EDGE;
    int col_start;
    int i;

    for (i = 1; i <= side; i++) {
        if (rows[i] < row_start) {
            row_start = rows[i];
            col_start = i;
        }
    }

    for (i = MAX_EDGE; i >= 1; i--) {
        if (pieces[i] > 0
            && i + row_start <= side + 1
            && i + col_start <= side + 1) {
            // Can we put this piece?
            bool found = true;
            int j;

            // Check the next continuous columns
            for (j = col_start + 1; j < col_start + i; j++) {
                if (rows[j] > row_start) {
                    found = false;
                    break;
                }
            }

            if (found == true) {
                for (j = col_start; j < col_start + i; j++) {
                    rows[j] += i;
                }
                pieces[i]--;

                if (judge(used + 1, rows) == 0) {
                    return 0;
                }

                // This path fails,
                for (j = col_start; j < col_start + i; j++) {
                    rows[j] -= i;
                }
                pieces[i]++;
            }
        }
    }   // end for (...)

    return -1;
}

int main()
{
    int n;
    int i;
    int piece;

    cin >> n;
    for (i = 0; i < n; i++) {
        reset_state();
        cin >> side >> npiece;
        for (int j = 0; j < npiece; j++) {
            cin >> piece;
            pieces[piece]++;
        }

        cout << (judge(used, rows) == 0 ? "KHOOOOB!" : "HUTUTU!")
             << endl;
    }

    return 0;
}

