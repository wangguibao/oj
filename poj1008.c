/*
 * Problem: 1008, Maya Calendar
 * User: LoiteringLeo
 * Memory: 392K     Time: 0MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int hash_bucket = 800;
const char *haab_months[] = {
    "pop",
    "no",
    "zip",
    "zotz",
    "tzec",
    "xul",
    "yoxkin",
    "mol",
    "chen",
    "yax",
    "zac",
    "ceh",
    "mac",
    "kankin",
    "muan",
    "pax",
    "koyab",
    "cumhu",
    "uayet"
};

const char *tzolkin_days[] = {
    "imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau",
};

int fill_hash(int *haab_number, int bucket_size)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = sizeof(haab_months) / sizeof(haab_months[0]);
    int str_len = 0;
    for (i = 0; i < len; ++i) {
        sum = 0;
        str_len = strlen(haab_months[i]);
        for (j = 0; j < str_len; ++j) {
            sum += haab_months[i][j] - ('a' - 'A');
        }
        if (haab_number[sum] != 0) {
            printf("hash collision: %u %u", sum, haab_number[sum]);
            return -1;
        }
        haab_number[sum] = i + 1;
    }

    return 0;
}

int main ()
{
    int i = 0;
    int j = 0;
    int len = 0;
    int hash = 0;
    int n;
    int day = 0;
    int m = 0;
    char month[10];
    int year = 0;
    int day_num = 0;
    int day_name = 0;

    int *haab_number = (int *)malloc(sizeof(int) * hash_bucket);
    for (i = 0; i < hash_bucket; ++i) {
        haab_number[i] = 0;
    }
    fill_hash(haab_number, hash_bucket);

    scanf("%d", &n);
    printf("%d\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d. %s %d", &day, month, &year);
        len = strlen(month);
        hash = 0;
        for(j = 0; j < len; ++j) {
            hash += month[j] - ('a' - 'A');
        }
        m = haab_number[hash];
        day = year * 365 + (m - 1) * 20 + day;

        year = day / (13 * 20);
        day = day % (13 * 20);
        day_num = day % 13 + 1;
        day_name = day % 20;
        printf("%d %s %d\n", day_num, tzolkin_days[day_name], year);
    }

    return 0;
}
