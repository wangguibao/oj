/*
 * poj1002.cpp - 487-3279
 * Problem: 1002    User: LoiteringLeo
 * Memory: 1100K     Time: 500MS
 * Language: G++    Result: Accepted
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>

int mapping[] = {
    2, 2, 2,    // A-C
    3, 3, 3,    // D-F
    4, 4, 4,    // G-I
    5, 5, 5,    // J-L
    6, 6, 6,    // M-O
    7, -1, 7, 7,// P-S
    8, 8, 8,    // T-V
    9, 9, 9,    // W-Y
    -1,         // Z
};

int main()
{
    int n;
    int x;
    int size;
    int i = 0;
    char s[1000];
    int total = 0;

    scanf("%d", &n);
    int phone[n];

    while (n > 0) {
        scanf("%s", s);
        --n;

        x = 0;
        size = strlen(s);
        for (i = 0; i < size; ++i) {
            if (s[i] == '-') {
                continue;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                x = x * 10 + mapping[s[i] - 'A'];
            }
            else if (s[i] >= '0' && s[i] <= '9'){
                x = x * 10 + s[i] - '0';
            }
        }
        phone[total++] = x;
    }

    std::sort(phone, phone + total);

    int dup = 1;
    int has_dup = 0;
    for (i = 0; i < total; i++, dup = 1) {
        while (phone[i] == phone[i + 1]) {
            dup++;
            i++;
        }
        if (dup > 1) {
            printf("%03d-%04d %u\n", phone[i] / 10000, phone[i] % 10000, dup);
            has_dup = 1;
        }
    }

    if (has_dup == 0) {
        printf("No duplicates.\n");
    }

    return 0;
}
