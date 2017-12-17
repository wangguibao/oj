/*
 * Problem: POJ1010, STAMPS
 * User: LoiteringLeo
 * Memory: 392K     Time: 94MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CANDIDATES  100
#define BUFF_SIZE       2048
#define MAX_STAMPS      4

int stamps[MAX_CANDIDATES];
int selected[MAX_CANDIDATES];
int temp_selected[MAX_CANDIDATES];
char buf[BUFF_SIZE];

void dfs(int *stamps,
        size_t total_types,
        int current_type_index,
        int sum,
        int types,
        int *max_types,
        int total_stamps,
        int *min_total_stamps,
        int *highest_value,
        int temp_high,
        int *selected,
        int *temp_selected,
        int *tie,
        int *solution_found)
{
    int i = 0;
    int j = 0;
    int current_sum = sum;
    int current_total_stamps = total_stamps;
    int high_value = temp_high;

    if (total_stamps >= 4) {
        return;
    }

    if (selected == NULL || temp_selected == NULL) {
        return;
    }

    if (stamps == NULL || total_types <= 0) {
        return;
    }

    for (i = current_type_index; i < total_types; ++i) {
        if (sum < stamps[i]) {
            continue;
        }

        while (sum >= stamps[i]) {
            sum -= stamps[i];
            total_stamps++;
            temp_selected[i]++;
            if (high_value < stamps[i]) {
                high_value = stamps[i];
            }
            if (sum == 0 && total_stamps <= 4) {
                if (*max_types < types + 1
                        || (*max_types == types + 1
                                && *min_total_stamps > total_stamps)
                        || (*max_types == types + 1
                                && *min_total_stamps == total_stamps
                                && *highest_value < high_value))
                {
                    *solution_found = 1;
                    *max_types = types + 1;
                    *min_total_stamps = total_stamps;
                    *highest_value = high_value;
                    for (j = 0; j < MAX_CANDIDATES; ++j) {
                        selected[j] = temp_selected[j];
                    }
                    *tie = 0;
                }
                else if (*max_types == types + 1
                        && *min_total_stamps == total_stamps
                        && *highest_value == high_value)
                {
                    *tie = 1;
                }
            }
            else {
                dfs(stamps,
                    total_types,
                    i + 1,
                    sum,
                    types + 1,
                    max_types,
                    total_stamps,
                    min_total_stamps,
                    highest_value,
                    high_value,
                    selected,
                    temp_selected,
                    tie,
                    solution_found);
            }
        }

        temp_selected[i] = 0;
        high_value = temp_high;
        sum = current_sum;
        total_stamps = current_total_stamps;
    }

    return;
}

void search(int *stamps, size_t total_types, int sum)
{
    int types = 0;
    int max_types = 0;
    int total_stamps = 0;
    int min_total_stamps = INT_MAX;
    int high_value = 0;
    int temp_high = -1;
    int tie = 0;
    int current_type_index = 0;
    int solution_found = 0;
    int i = 0;
    int j = 0;

    for (; i < MAX_CANDIDATES; ++i) {
        selected[i] = 0;
        temp_selected[i] = 0;
    }

    dfs(stamps,
        total_types,
        current_type_index,
        sum,
        types,
        &max_types,
        total_stamps,
        &min_total_stamps,
        &high_value,
        temp_high,
        selected,
        temp_selected,
        &tie,
        &solution_found);

    if (solution_found == 1) {
        printf("%u (%u):", sum, max_types);
        if (tie == 0) {
            for (i = 0; i < total_types; ++i) {
                if (selected[i] > 0) {
                    for (j = 0; j < selected[i]; ++j) {
                        printf(" %u", stamps[i]);
                    }
                }
            }
            printf("\n");
        }
        else {
            printf(" tie\n");
        }
    }
    else {
        printf("%u ---- none\n", sum);
    }
}

int main ()
{
    int i = 0;
    int stamp_type = 0;
    int value = 0;
    char *token = NULL;

    for (; i < MAX_CANDIDATES; ++i) {
        stamps[i] = 0;
    }

    while (gets(buf) != NULL) {
        stamp_type = 0;
        token = strtok(buf, " ");
        stamps[stamp_type++] = strtod(token, NULL);

        while ((token = strtok(NULL, " ")) != NULL) {
            value = strtod(token, NULL);
            if (value == 0) {
                break;
            }
            stamps[stamp_type++] = value;
        }

        gets(buf);
        token = strtok(buf, " ");
        search(stamps, stamp_type, strtod(token, NULL));

        while ((token = strtok(NULL, " ")) != NULL) {
            value = strtod(token, NULL);
            if (value == 0) {
                break;
            }
            search(stamps, stamp_type, value);
        }
    }

    return 0;
}
