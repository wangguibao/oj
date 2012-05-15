/**
 * Problem: 2190, ISBN
 * User: LoiteringLeo
 * Memory: 368K     Time: 32MS
 * Language: GCC    Result: Accepted
 */
#include <stdio.h>
#define ISBN_LEN    10

int main()
{
    char isbn[ISBN_LEN + 2];
    int i;
    int br = 0;
    int sum = 0;
    int upper;

    gets(isbn);

    for (i = 0; i < ISBN_LEN; i++) {
        if (isbn[i] >= '0' && isbn[i] <= '9') {
            sum += (10 - i) * (isbn[i] - '0');
        }
        else if (isbn[i] == 'X') {
            sum += 10;
        }
        else if (isbn[i] == '?') {
            br = i;
        }
    }

    if (br == ISBN_LEN - 1) {
        upper = 10;
    }
    else {
        upper = 9;
    }
    for (i = 0; i <= upper; i++) {
        if ((sum + (10 - br) * i) % 11 == 0) {
            printf("%c\n", (i == 10) ? 'X' : i + '0');
            break;
        }
    }
    if (i > upper) {
        printf("-1\n");
    }

    return 0;
}
