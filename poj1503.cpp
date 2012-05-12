/*
 * Problem: 1503, Integer Inquiry
 * User: LoiteringLeo
 * Memory: 756k     Time: 0MS
 * Language: G++    Result: Accepted
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_CHAR    100
#define MAX_LINE    100

int main()
{
    string s;
    vector<char> cvec[MAX_LINE];
    vector<char>::iterator citer[MAX_LINE];
    int line = 0;
    int max_len = 0;
    int i = 0;

    while (getline(cin, s) && s != "0") {
        if (max_len < s.length()) {
            max_len = s.length();
        }
        for (i = s.length() - 1; i >= 0; i--) {
            cvec[line].push_back(s.at(i));
        }

        for (i = s.length(); i < max_len; i++) {
            cvec[line].push_back('0');
        }
        line++;
        s.clear();
    }

#if 0
    for (i = 0; i < line; i++) {
        for (vector<char>::reverse_iterator ri = cvec[i].rbegin();
             ri != cvec[i].rend(); ri++) {
            cout << *ri;
        }
        cout << endl;
    }
#endif

    for (i = 0; i < line; i++) {
        citer[i] = cvec[i].begin();
    }

    int sum;
    int carry = 0;
    int j;
    vector<int> retv;

    for (j = 0; j < max_len; j++) {
        sum = 0;
        for (i = 0; i < line; i++) {
            sum += *(citer[i]) - '0';
            (citer[i])++;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        retv.push_back(sum);
    }

    while (carry > 0) {
        sum = carry % 10;
        retv.push_back(sum);
        carry /= 10;
    }

    for (vector<int>::reverse_iterator riter = retv.rbegin();
         riter != retv.rend(); riter++) {
        cout << *riter;
    }
    cout << endl;

    return 0;
}

