/*
 * poj1004.cpp - Financial Management
 * Problem: 1004    User: LoiteringLeo
 * Memory: 760K     Time: 0MS
 * Language: G++    Result: Accepted
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double total;
    double balance;
    int i;

    for (i = 1; i <= 12; i++) {
        cin >> balance;
        total += balance;
    }

    fixed(cout);
    cout << "$" << setprecision(2) << total / 12 << endl;

    return 0;
}
