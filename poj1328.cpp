/*
 * Problem: 1328, Radar Installation
 * User: LoiteringLeo
 * Memory: 1104K     Time: 94MS
 * Language: G++    Result: Accepted
*/
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_POINTS  1000

using namespace std;

typedef struct _POINT {
    int x;
    int y;
} POINT;

typedef struct _TEST_CASE {
    int p;
    int d;
    POINT points[MAX_POINTS];
} TEST_CASE;

typedef struct _REGION {
    double left;
    double right;
} REGION;

bool cmp(REGION a, REGION b)
{
    return a.right < b.right;
}

int min_radar(POINT *points, int n, int radius)
{
    int min = 1;
    int begin = 0;
    int i;
    REGION region[MAX_POINTS];

    for (i = 0; i < n; i++) {
        if (points[i].y > radius || points[i].y < (0 - radius)) {
            return -1;
        }
        region[i].left =
            points[i].x - sqrt(radius * radius - points[i].y * points[i].y);
        region[i].right =
            points[i].x + sqrt(radius * radius - points[i].y * points[i].y);
    }

    sort(region, region + n, cmp);

    i = 0;
    begin = i;
    while (begin < n) {
        int j;

        // cout << "max_x: " << max_x;
        for (j = begin + 1; j < n; j++) {
            if (region[j].left > region[begin].right) {
                min++;
                begin = j;
            }
        }
        if (j >= n) {
            break;
        }
    }
    return min;
}

int main()
{
    vector<TEST_CASE> cvec;
    vector<TEST_CASE>::iterator titer;
    TEST_CASE test_case;

    while (true) {
        int points;
        int d;
        
        cin >> points >> d;
        if (points == 0 && d == 0) {
            break;
        }
        test_case.p = points;
        test_case.d = d;

        for (int i = 0; i < points; i++) {
            cin >> test_case.points[i].x >> test_case.points[i].y;
        }
        cvec.push_back(test_case);
    }

    int j = 1;
    for (titer = cvec.begin(); titer != cvec.end(); titer++) {
        test_case = *titer;

        cout << "Case " << j << ": "
             << min_radar(test_case.points, test_case.p, test_case.d) << endl;
        j++;
    }

    return 0;
}