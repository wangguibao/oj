#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

enum DIRECTION {START, END};
typedef struct _MOVE {
    int s;
    int t;
} MOVE;

typedef struct _POINT {
    int n;
    DIRECTION d;
} POINT;

typedef struct _CASE {
    int n;
    MOVE moves[200];
} CASE;

bool cmp(POINT a, POINT b)
{
    return a.n <= b.n;
}

int main()
{
    int cases;
    vector<CASE> casev;
    vector<CASE>::iterator casei;
    vector<MOVE>::iterator movei;
    CASE caase;

    cin >> cases;
    while (cases > 0) {
        int i;
        cin >> caase.n;

        for (i = 0; i < caase.n; i++) {
            caase.moves[i].s = 0;
            caase.moves[i].t = 0;
        }
        for (i = 0; i < caase.n; i++) {
            cin >> caase.moves[i].s >> caase.moves[i].t;
            if (caase.moves[i].s > caase.moves[i].t) {
                int temp = caase.moves[i].s;
                caase.moves[i].s = caase.moves[i].t;
                caase.moves[i].t = temp;
            }
            caase.moves[i].s = (caase.moves[i].s + 1) >> 1;
            caase.moves[i].t = (caase.moves[i].t + 1) >> 1;
        }
        casev.push_back(caase);
        cases--;
    };

    for (casei = casev.begin(); casei != casev.end(); casei++) {
        caase = *casei;
        int i = 0;
        int j = 0;
        POINT points[caase.n * 2];

        for (i = 0; i < caase.n; i++) {
            points[2 * i].n = caase.moves[i].s;
            points[2 * i].d = START;
            points[2 * i + 1].n = caase.moves[i].t;
            points[2 * i + 1].d = END;
        }

        sort(points, points + i * 2, cmp);
        int max = 0;
        int overlap = 0;
        for (j = 0; j < 2 * i; j++) {
            if (points[j].d == START) {
                overlap++;
                if (max < overlap) {
                    max = overlap;
                }
            }
            else if (points[j].d == END) {
                overlap--;
            }
        }

        cout << 10 * max << endl;
    }

    return 0;
}
