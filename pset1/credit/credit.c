#include <stdio.h>
#include <cs50.h>

// Returns digit at specified placement(n);
// 123 n = 3; returns 1.
int get_single_digit(long num, int n)
{
    while (--n)
    {
        num /= 10;
    }
    return num % 10;
}

// Returns the digit length of a given num.
int get_num_length(long num)
{
    int count = 0;
    do
    {
        num /= 10;
        count++;
    }
    while (num > 0);
    return count;
}

// Returns first (2) starting numbers
int get_pair(long num, int length)
{
    for (int i = 0; i < length - 2; i++)
    {
        num /= 10;
    }
    return num;
}

// Identifies Credit Card Maker returns the
// CC Company name, returns INVALID if it doesn't meet requirements.
string validate_company(long cc_num)
{
    int length = get_num_length(cc_num);
    int pair = get_pair(cc_num, length);


    if (length == 16 && (pair >= 51 && pair <= 55))  // MC 16 digits long, start with 51 - 55
    {
        return "MASTERCARD";
    }
    else if (length == 15 && (pair == 34 || pair == 37))  // AMEX 15 digits long, start with 34 or 37
    {
        return "AMEX";
    }
    else if ((length == 13 || length == 16) && (get_single_digit(pair, 2) == 4))  //  VISA 13/16 digits long, with 4 as 1st number.
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

// Returns 1 if valid CC#, or 0 if invalid.
int validate_num(long cc_num)
{
    int sum = 0;
    int odd_sum = 0;
    int length = get_num_length(cc_num);

    // Multiple each even number by 2.
    // Add the products digits, NOT the products.
    for (int i = 2; i <= length; i += 2)
    {
        long digit = get_single_digit(cc_num, i) * 2;
        // If the Sum(digit) is more than a single digit, loop over
        // adding the digits, if not, just add to total sum.
        if (digit > 9)
        {
            int digit_length = get_num_length(digit);
            for (int j = 1; j <= digit_length; j++)
            {
                sum += get_single_digit(digit, j);
            }

        }
        else
        {
            sum += digit;
        }
    }

    // Sum all odd numbers
    for (int k = 1; k <= length; k += 2)
    {
        odd_sum += get_single_digit(cc_num, k);
    }

    sum += odd_sum;
    return ((sum % 10) != 0) ? 0 : 1;
}

// Validates and returns credit card company name
// returns INVALID if number fails check.
int main(void)
{
    long cc_num = get_long("Number: ");

    string msg = (validate_num(cc_num)) ? validate_company(cc_num) : "INVALID";
    printf("%s\n", msg);
}
