/*
 * poj2739.c - PKU Online Judge Problem 2739 solution
 * POJ2739: Sum of Consecutive Prime Numbers
 * Run ID  User         Problem Result   Memory Time Language Code Length Submit Time
 * 6293637 LoiteringLeo 2739    Accepted 364K   63MS GCC      3185B       2010-01-01 22:24:30
 */
#include <stdio.h>

/*
 * is_prime: determines if a positive number is primer number.
 * Returns: 0 - non prime number
 *          1 - prime number
 *         -1 - out of range
 */
int is_prime(unsigned int num)
{
    unsigned int divisior = 3;
    unsigned int limit = num;
	
    if (num > 10000 || num < 2) {			/* Limit range */
        return -1;
    }

    if (0 == (num & 0x1) && num != 2) {
        return 0;
    }

    while (limit > divisior) {
        if (0 == (num % divisior)) {
            return 0;
        }
        limit = num / divisior;
        divisior += 2;
    }
    return 1;
}

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    unsigned int sum = 0;
    unsigned int first_prime_idx = 0;
    unsigned int seqs = 0;
    unsigned int input[100];
    /*
     * The array temps[] stores run time prime numbers calculated in
     * last run. For example, 41 can be represented as 2 + 3 + 5 + 7 + 11 + 13
     * and 11 + 13 + 17 and 41. As the first time the program checks for a legal
     * sequence of prime numbers, it stores 2, 3, 5, 7, 11 and 13 into temps[],
     * so that the next time program can calculate from 14, and starts summing
     * from 3. This would save some time.
     */
    unsigned int temps[100];
    unsigned int temps_monitor = 0;
    
    for (i = 0; i < 100; i++) {
        scanf("%d", &input[i]);
        if (0 == input[i]) {
            break;
        }
    }

    for (j = 0; j < i; j++) {
        if (input[j] < 2 || input[j] > 10000) {
            printf("0\n");
            continue;
        }

        sum = 0;
        first_prime_idx = 0;
        seqs = 0;
        k = 2;

        for (l = 0; l < 100; l++) {
            temps[l] = 0;
        }
        l = 0;
        temps_monitor = 0;

retry:
        /*
         * First, if the array temps[] is stored prime numbers, we can use
         * it to save some time. Shift left these number for one slot, and
         * sums them up. if an equality is met, bumps the presentation number;
         * other wise, if summary is larger than destination, then repeats
         * the above process.
         */
        for (l = 0; l < temps_monitor; l++) {
            sum += temps[l];
            if (sum >= input[j]) {
                for (l = 0; l < temps_monitor; l++){
                    temps[l] = temps[l + 1];
                }
                temps_monitor--;
                if (sum == input[j]) {      /* An equality met */
                    seqs++;
                }
                sum = 0;
                goto retry;
            }
        }

        /*
         * Also, if the array temps[] is stored prime numbers, then continue
         * calculating the next prime number with (the last one stored + 1)
         */
        if (temps_monitor > 0) {
            k = temps[temps_monitor - 1] + 1;
        }
        else {
            k = 2;
        }
        
        while (k < input[j]) {
            if (1 == is_prime(k)) {
                sum += k;
                temps[temps_monitor++] = k;

                if (sum >= input[j]) {
                    if (sum == input[j]) {
                        seqs++;
                    }
                    sum = 0;
                    for (l = 0; l < temps_monitor; l++) {
                        temps[l] = temps[l + 1];
                    }
                    temps_monitor--;

                    goto retry;
                }
                else {
                    k++;
                }
            }
            else {
                k++;
            }
        }
        if (1 == (is_prime(input[j]))) {
            seqs++;
        }
        printf("%d\n", seqs);
    }

    return 0;
}
