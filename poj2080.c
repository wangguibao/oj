/*
 * Problem: 2080, Calendar
 * User: LoiteringLeo
 * Memory: 420K     Time: 92MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#define MAX_YEAR    (9999 + 1)

char *week_day[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};

int day_in_month[] = {
    0,
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31,
};

int day_in_year[MAX_YEAR];
int weekday_of_20000101 = 6;

int is_leapyear(int n)
{
    if (((n % 4) == 0 && (n % 100) != 0) ||
        (n % 400) == 0) {
        return 1;
    }
    return 0;
}


int main()
{
    int n;
    int year;
    int month;
    int day;
    int weekday;
    int i;

    for (i = 2000; i < MAX_YEAR; i++) {
        day_in_year[i] = is_leapyear(i) ? 366 : 365;
    }
#if 0
    for (i = 2000; i < 2006; i++) {
        printf("%d ", day_in_year[i]);
    }
#endif
    while (scanf("%d", &n) && n != -1) {
        weekday = (n % 7 + weekday_of_20000101) % 7;

        n++;
        year = 2000;
        while (n - day_in_year[year] > 0) {
            n -= day_in_year[year];
            year++;
        }

        month = 1;
        if (is_leapyear(year)) {
            day_in_month[2] = 29;
        }
        else {
            day_in_month[2] = 28;
        }
        while (n - day_in_month[month] > 0) {
            n -= day_in_month[month];
            month++;
            if (month > 12) {
                month = 1;
            }
        }
        day = n;

        printf("%d-%02d-%02d %s\n", year, month, day, week_day[weekday]);
    }

    return 0;
}

