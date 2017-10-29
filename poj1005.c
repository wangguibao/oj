/*
 * POJ1005 - I Think I Need a Houseboat
 * http://poj.org/problem?id=1005
 * Problem: 1005    User: LoiteringLeo
 * Memory: 436K     Time: 0MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>

#define PI 3.1415926

int main()
{
    int n = 0;
    double x = 0.0;
    double y = 0.0;
    double area = 0.0;
    int year = 0;

    scanf("%u", &n);

    int i = 0;
    for (i = 0; i < n; ++i) {
        scanf("%lf %lf", &x, &y);
        area = (x * x + y * y) * PI / 2;
        year = area / 50 + 1;
        printf("Property %d: This property will begin eroding in year %u.\n",
               i + 1,
               year);
    }

    printf("END OF OUTPUT.\n");
    return 0;
}

