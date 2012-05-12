/*
 * Problem: 2262, Goldbach's Conjecture
 * User: LoiteringLeo
 * Memory: 2104K     Time: 454MS
 * Language: G++    Result: Accepted
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX 1000000
using namespace std;

bool prime[MAX];

void gen_prime_table()
{
    int i;

    memset(prime, 0, sizeof(prime));

    for (i = 2; i < MAX; i++) {
        prime[i] = true;
    }

    for (i = 2; i <= sqrt(MAX); i++) {
        if (prime[i] == true) {
            for (int j = 2 * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }

    prime[2] = false;  /* to make all primes odd */
}

int main()
{
    int i;
    vector<int> ivec;
    vector<int>::iterator iter;

    gen_prime_table();

    cin >> i;
    while (i != 0) {
        ivec.push_back(i);
        cin >> i;
    }

    for (iter = ivec.begin(); iter != ivec.end(); iter++) {
        int a = 3;
        int b = *iter - 3;

        while (a <= b) {
            while (prime[a] == false) {
                a++;
            }
            while (prime[b] == false) {
                b--;
            }
            if (a + b == *iter) {
                cout << *iter << " = " << a << " + " << b << endl;
                break;
            }
            else if (a + b > *iter) {
                b--;
            }
            else {
                a++;
            }

        }
        if (a > b) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
}
