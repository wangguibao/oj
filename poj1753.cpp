/*
 * Problem: 1753, Flip Game
 * User: LoiteringLeo
 * Memory: 812K     Time: 47MS
 * Language: G++    Result: Accepted
*/
#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
#include <cmath>

#define MAX_COMP    65535
using namespace std;

typedef struct _COMPOSITION {
    int comp;       /* Bit represention of the composition */
    int round;      /* Number of rounds until now */
    int i;          /* The piece which caused this composition */
} COMPOSITION;

bool traversed[MAX_COMP];

/* Returns a new composition after flipping piece i */
COMPOSITION flip(COMPOSITION p, int piece)
{
    COMPOSITION child;
    int comp;

    comp = p.comp;
    comp ^= 1 << piece;

    /* Upper neighbor */
    if (piece > 3) {
        comp ^= 1 << (piece - 4);
    }

    /* Lower neighbor */
    if (piece < 12) {
        comp ^= 1 << (piece + 4);
    }

    /* Left neighbor */

    if ((piece & 0x3) != 0) {
        comp ^= 1 << (piece - 1);
    }

    /* Right neighbor */
    if ((piece & 0x3) != 3) {
        comp ^= 1 << (piece + 1);
    }

    child.comp = comp;
    child.round = p.round + 1;
    child.i = piece;

    return child;
}

int main()
{
    char grid[4][4];
    int i;
    queue<COMPOSITION> q;
    COMPOSITION comp;

    for (i = 0; i < 4; i++) {
        cin >> grid[i][0] >> grid[i][1] >> grid[i][2] >> grid[i][3];
    }

    memset(traversed, 0, sizeof(traversed));

    comp.comp = 0;
    comp.round = 0;
    comp.i = 0;

    for (i = 0; i < 16; i++) {
        if (((char *)&grid)[i] == 'b') {       /* 1: black, 0: white */
            comp.comp |= 1 << i;
        }
    }
    q.push(comp);
    traversed[comp.comp] = true;

    while (!q.empty()) {
        COMPOSITION parent = q.front();

        q.pop();
#if 0
        cout << parent.round << " " << hex << setw(4) << setfill('0') << parent.comp << endl;
#endif
        if (parent.comp == 0xffff || parent.comp == 0x0000) {
            cout << parent.round << endl;
            return 0;
        }
        for (i = 0; i < 16; i++) {
            COMPOSITION child;
            child = flip(parent, i);
#if 0
            if (child.comp == 0xffff || child.comp == 0x0000) {
                cout << child.round << endl;
                return 0;
            }
#endif
            if (traversed[child.comp] == false) {
                q.push(child);
                traversed[child.comp] = true;
            }
            else {
                continue;
            }
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
