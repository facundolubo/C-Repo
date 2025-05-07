#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/* --- Helper Functions for String-based Large Number Arithmetic --- */

/*
 * Helper to remove leading zeros from a string number.
 * Returns a pointer to the first non-zero digit.
 */
char *
remove_leading_zeros(char *num)
{
    int     i = 0;

    while (num[i] == '0' && num[i+1] != '\0')
    {
        i++;
    }
    return num + i;
}

/*
 * Helper to pad a string number with leading zeros.
 * Returns a dynamically allocated string.
 */
char *
pad_left(char *num, int target_len)
{
    int     current_len = strlen(num);
    int     padding_len;
    char   *padded_num;

    if (current_len >= target_len)
    {
        return strdup(num); /* Return a duplicate if already long enough */
    }

    padding_len = target_len - current_len;
    padded_num = (char *) malloc(target_len + 1);
    if (padded_num == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    memset(padded_num, '0', padding_len);
    strcpy(padded_num + padding_len, num);
    padded_num[target_len] = '\0';

    return padded_num;
}

/*
 * Helper to add two non-negative large numbers represented as strings.
 * Returns a dynamically allocated string.
 */
char *
add_large_numbers(char *num1, char *num2)
{
    int     len1 = strlen(num1);
    int     len2 = strlen(num2);
    int     max_len = (len1 > len2) ? len1 : len2;
    int     result_len = max_len + 1; /* Potentially one extra digit for carry */
    char   *result;
    int     i, j, k;
    int     carry = 0;

    result = (char *) malloc(result_len + 1);
     if (result == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    result[result_len] = '\0';

    i = len1 - 1;
    j = len2 - 1;
    k = result_len - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';

        result[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    /* The result might have leading zeros if there was no final carry */
    /* The starting index will be k+1 */
    return strdup(result + k + 1); /* Duplicate the valid part */
}

/*
 * Helper to subtract two non-negative large numbers represented as strings (num1 - num2).
 * Assumes num1 >= num2. Returns a dynamically allocated string.
 */
char *
subtract_large_numbers(char *num1, char *num2)
{
    int     len1 = strlen(num1);
    int     len2 = strlen(num2);
    char   *result;
    int     i, j, k;
    int     borrow = 0;

    result = (char *) malloc(len1 + 1); /* Result won't be longer than num1 */
     if (result == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    result[len1] = '\0';

    i = len1 - 1;
    j = len2 - 1;
    k = len1 - 1;

    while (i >= 0)
    {
        int digit1 = num1[i--] - '0';
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result[k--] = diff + '0';
    }

    /* Remove leading zeros from the result */
    return strdup(remove_leading_zeros(result));
}

/*
 * Helper for simple multiplication of a string number by a power of 10.
 */
char *
multiply_by_power_of_10(char *num, int power)
{
    int     len = strlen(num);
    char   *result;

    result = (char *) malloc(len + power + 1);
     if (result == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    strcpy(result, num);
    memset(result + len, '0', power);
    result[len + power] = '\0';

    return result;
}

/*
 * Helper for standard multiplication of two small numbers (represented as strings).
 * Used as the base case for Karatsuba.
 */
char *
base_multiply(char *num1_str, char *num2_str)
{
    long long num1 = atoll(num1_str);
    long long num2 = atoll(num2_str);
    long long result_ll = num1 * num2;

    /* Convert the reult back to a string */
    char result_str[50]; /* Sufficiently large buffer for long long */
    sprintf(result_str, "%lld", result_ll);

    return strdup(result_str);
}


/* --- Karatsuba Multiplication --- */

/*
 * Implements the Karatsuba multiplication algorithm for two large numbers
 * represented as strings. Returns a dynamically allocated result string.
 */
char *
karatsuba_multiply(char *X_str, char *Y_str)
{
    /* 1. Base Case: If numbers are small, use standard multiplication */
    int     len_X, len_Y;
    char   *X_clean, *Y_clean;
    int     n;
    int     power_of_2;
    char   *X_padded, *Y_padded;
    int     half_n;
    char    a_str[1000], c_str[1000]; /* Using static buffers for parts */
    char    b_str[1000], d_str[1000];
    char   *P1, *P2, *P3;
    char   *a_plus_b, *c_plus_d;
    char   *P3_minus_P1, *ad_plus_bc;
    char   *term1, *term2;
    char   *sum1, *final_result;


    len_X = strlen(X_str);
    len_Y = strlen(Y_str);

    /* Remove leading zeros for base case comparison */
    X_clean = remove_leading_zeros(X_str);
    Y_clean = remove_leading_zeros(Y_str);
    len_X = strlen(X_clean);
    len_Y = strlen(Y_clean);

    /* Define a threshold for the base case */
    /* A value around 10-20 is typical, but can be tuned */
    int KARATSUBA_THRESHOLD = 10;

    if (len_X <= KARATSUBA_THRESHOLD || len_Y <= KARATSUBA_THRESHOLD)
    {
        return base_multiply(X_clean, Y_clean);
    }

    /* 2. Padding: Make lengths equal and a power of 2 */
    n = (len_X > len_Y) ? len_X : len_Y;
    /* Find the smallest power of 2 greater than or equal to n */
    power_of_2 = 1;
    while (power_of_2 < n)
    {
        power_of_2 *= 2;
    }
    n = power_of_2; /* Use this padded length for splitting */

    X_padded = pad_left(X_clean, n);
    Y_padded = pad_left(Y_clean, n);

    /* 3. Splitting: Divide X and Y into two halves */
    half_n = n / 2;

    /* a and c are the upper halves */
    /* Use strncpy carefully, ensure null termination */
    strncpy(a_str, X_padded, half_n);
    a_str[half_n] = '\0';

    strncpy(c_str, Y_padded, half_n);
    c_str[half_n] = '\0';

    /* b and d are the lower halves */
    strncpy(b_str, X_padded + half_n, half_n);
    b_str[half_n] = '\0';

    strncpy(d_str, Y_padded + half_n, half_n);
    d_str[half_n] = '\0';

    /* 4. Recursive Calls (The three multiplications) */
    P1 = karatsuba_multiply(a_str, c_str); /* ac */
    P2 = karatsuba_multiply(b_str, d_str); /* bd */

    /* Calculate a+b and c+d */
    a_plus_b = add_large_numbers(a_str, b_str);
    c_plus_d = add_large_numbers(c_str, d_str);

    P3 = karatsuba_multiply(a_plus_b, c_plus_d); /* (a+b)(c+d) */

    /* 5. Combine Results */
    /* Calculate P3 - P1 - P2 = (a+b)(c+d) - ac - bd = ad + bc */
    P3_minus_P1 = subtract_large_numbers(P3, P1);
    ad_plus_bc = subtract_large_numbers(P3_minus_P1, P2);

    /* Calculate the final result: P1 * 10^n + (ad+bc) * 10^(n/2) + P2 */
    term1 = multiply_by_power_of_10(P1, n);
    term2 = multiply_by_power_of_10(ad_plus_bc, half_n);

    sum1 = add_large_numbers(term1, term2);
    final_result = add_large_numbers(sum1, P2);

    /* --- Free allocated memory --- */
    free(X_padded);
    free(Y_padded);
    free(P1);
    free(P2);
    free(a_plus_b);
    free(c_plus_d);
    free(P3);
    free(P3_minus_P1);
    free(ad_plus_bc);
    free(term1);
    free(term2);
    free(sum1);
    /* Note: final_result is returned and must be freed by the caller */

    return final_result;
}

/* --- Main function for demonstration --- */
int
main(void) /* Use void if no arguments are expected */
{
    char num1[1000], num2[1000]; /* Buffers for input */
    char *result;

    printf("Enter the first large non-negative integer: ");
    scanf("%s", num1);

    printf("Enter the second large non-negative integer: ");
    scanf("%s", num2);

    result = karatsuba_multiply(num1, num2);

    printf("Result of multiplication: %s\n", result);

    free(result); /* Free the result allocated by karatsuba_multiply */

    return 0;
}
