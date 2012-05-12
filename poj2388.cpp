/*
 * Problem: 2388, Who's in the Middle
 * User: LoiteringLeo
 * Memory: 768K     Time: 141MS
 * Language: G++    Result: Accepted
*/
#include <iostream>

using namespace std;

int find_mid2(int *a, int begin, int end, int k)
{
    int x;
    int i;
    int j;
    int temp;

retry:
    if (begin >= end) {
        return begin;
    }

    x = a[end];
    i = begin - 1;
    for (j = begin; j < end; j++) {
        if (a[j] < x) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    temp = a[i];
    a[i] = x;
    a[end] = temp;

    if (i - begin == k - 1) {
        return i;
    }
    else if (i - begin > k - 1) {
        end = i - 1;
    }
    else if (i - begin < k - 1) {
        k = k - (i - begin + 1);
        begin = i + 1;
    }
    goto retry;
}

int main()
{
    int n;
    int i;

    cin >> n;
    int *a = new int[n];
    
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << a[find_mid2(a, 0, n - 1, (n + 1) / 2)] << endl;
    delete[] a;
    return 0;
}

