/*
 * Problem: 1001, Exponentiation
 * User: LoiteringLeo
 * Memory: 396K     Time: 0MS
 * Language: GCC    Result: Accepted
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 6
#define RET_LEN 256

int main()
{
    char str_base[MAX_LEN + 1];
    int base_len;
    char str_ret[RET_LEN];
    int ret_len;
    int base;
    int exp;
    int point_pos = 0;
    int i;
    int product;
    int carry;
    int end;

    while (scanf("%s %d", str_base, &exp) == 2) {
        base_len = strlen(str_base);
        i = 0;
        while (str_base[i] != '.' && str_base[i] != '\0') {
            i++;
        }
        point_pos = base_len - i - 1;
        if (point_pos < 0) {
            point_pos = 0;
        }
        point_pos *= exp;

        while (i < base_len && str_base[i] != '\0') {
            str_base[i] = str_base[i + 1];
            i++;
        }
        base = atoi(str_base);
#if 0
        printf("%d\n", base);
#endif
        memset(str_ret, 0, RET_LEN);
        str_ret[1] = 1;
        ret_len = 1;
        while (exp > 0) {
            carry = 0;
            for (i = 1; i <= ret_len; i++) {
                product = base * str_ret[i] + carry;
                carry = product / 10;
                product = product - 10 * carry;
                str_ret[i] = product;
            }
            while (carry != 0) {
                product = carry;
                carry = product / 10;
                str_ret[i] =  product - carry * 10;
                i++;
            }
            ret_len = --i;
            exp--;
        }

        i = (ret_len < point_pos) ? point_pos : ret_len;
        end = 1;
        if (point_pos != 0) {
            while (str_ret[end] == 0 && end <= point_pos) {
                end++;
            }
        }
        for (; i >= end; i--) {
            if (i == point_pos) {
                printf(".");
            }
            printf("%d", str_ret[i]);
        }
        printf("\n");
    }

    return 0;
}
