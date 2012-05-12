/*
 * Problem: 1519, Digital Roots
 * User: LoiteringLeo
 * Memory: 748K     Time: 0MS
 * Language: G++    Result: Accepted
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    while (getline(cin, s) && s != "0") {
        long long int sum = 0;
        long long int n;

        for (int i = 0; i < s.length(); i++) {
            sum += s.at(i) - '0';
        }

        do {
            n = sum;
            sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
        } while (sum >= 10);
        cout << sum << endl;
    }

    return 0;
}

