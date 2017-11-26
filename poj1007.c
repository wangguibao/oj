/*
 * POJ1007 - DNA Sorting
 * http://poj.org/problem?id=1007
 * Problem: 1007    User: LoiteringLeo
 * Memory: 388K     Time: 16MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 55
#define MAX_ELE 105

/**
 * Number of out-of-order pairs in a sequence
 * Inspired by http://poj.org/showmessage?message_id=77242
 */
int sortedness(const char *str, int len)
{
    int A = 0;
    int C = 0;
    int G = 0;
    int i = len - 1;
    int count = 0;

    for (; i >= 0; --i) {
        switch (str[i]) {
        case 'A':
            A++;
            break;
        case 'C':
            C++;
            count += A;
            break;
        case 'G':
            G++;
            count += A + C;
            break;
        case 'T':
            count += A + C + G;
        }
    }

    return count;
}

void insert_sort(int *a, int *b, int n) {
    int i = 0;
    int j = 0;
    if (a == NULL || b == NULL || n <= 1) {
        return;
    }

    for (i = 1; i < n; ++i) {
        int tmp = a[i];
        int tmp_b = b[i];
        for (j = i - 1; j >= 0; --j) {
            if (a[j] > tmp) {
                a[j + 1] = a[j];
                b[j + 1] = b[j];
            }
            else {
                break;
            }
        }
        a[j + 1] = tmp;
        b[j + 1] = tmp_b;
    }

    return;
}

int main()
{
    int n = 0;
    int m = 0;
    int i = 0;
    char buf[MAX_ELE][MAX_LEN];
    int diff[MAX_ELE];
    int id[MAX_ELE];

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; ++i) {
        scanf("%s", buf[i]);
        diff[i] = sortedness(buf[i], strlen(buf[i]));
        id[i] = i;
    }

    insert_sort(diff, id, m);

    for (i = 0; i < m; ++i) {
        printf("%s\n", buf[id[i]]);
    }
    return 0;
}
