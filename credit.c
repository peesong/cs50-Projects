#include <cs50.h>
#include <stdio.h>

int every_other_digit(long credit_card);
int every_other_digit2(long credit_card);
int validate_card(int check_sum);
int validate_amex(long credit_card);
int validate_visa(long credit_card);
int validate_mc(long credit_card);
int card_type;

int main(void)
{
    long credit_card = get_long("enter card number:\n"); // prompts user for CC number
    int sum_every_other_digit =
        every_other_digit(credit_card); // gets the sum of every other digit in the credit_card,
                                        // starting second to last and implements luhns algorithm on
                                        // every other digit starting from last.
    int sum_every_other_digit2 =
        every_other_digit2(credit_card); // gets the sum of every other digit
                                         // in the credit_card, starting from last
    int check_sum =
        sum_every_other_digit + sum_every_other_digit2; // adds the two digit sums together
    int is_valid_card = validate_card(check_sum);
    if (is_valid_card == 1)
    {
        card_type = 0;
        card_type = validate_amex(credit_card);
        if (card_type == 1)
        {
            printf("AMEX\n");
        }
        if (card_type == 0)
        {
            card_type = validate_visa(credit_card);
            if (card_type == 2)
            {
                printf("VISA\n");
            }
        }
        if (card_type == 0)
        {
            card_type = validate_mc(credit_card);
            if (card_type == 3)
            {
                printf("MASTERCARD\n");
            }
        }
        if (card_type == 0)
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int every_other_digit(long credit_card)
{
    int sum = 0;
    bool isalternatedigit = false;
    while (credit_card > 0)
    {
        if (isalternatedigit == true) // takes everyother digit, starting from 2nd to last and
                                      // extracts and mulitplies by 2
        {
            int last_digit = credit_card % 10;
            last_digit = last_digit * 2;
            if (last_digit > 9) // if the last digit * 2 is two digits, extracts the digits and sums
                                // them together
            {
                int digit_1 = last_digit % 10;
                last_digit = last_digit / 10;
                int digit_2 = last_digit % 10;
                last_digit = digit_1 + digit_2;
            }
            sum = sum + last_digit; // updates running sum of digits extracted above
        }
        isalternatedigit = !isalternatedigit;
        credit_card = credit_card / 10; // removes final digit from card number to repeat extraction
    }
    return sum;
}

int every_other_digit2(long credit_card)
{
    int sum = 0;
    bool isalternatedigit = true;
    while (credit_card > 0)
    {
        if (isalternatedigit == true)
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
        }
        isalternatedigit = !isalternatedigit;
        credit_card = credit_card / 10;
    }
    return sum;
}

int validate_card(int check_sum)
{
    int is_valid_card = 0;
    bool isvalidnumber = false;
    if (check_sum % 10 == 0)
    {
        isvalidnumber = true;
        is_valid_card = 1;
    }
    return is_valid_card;
}

int validate_amex(long credit_card)
{
    long valid_amex = credit_card;
    if (valid_amex >= 100000000000000 && valid_amex < 1000000000000000)
    // check if 15 digit number
    {
        valid_amex = valid_amex / 10000000000000; // remove 13 digits
        if (valid_amex == 34 || valid_amex == 37) // and check if remaining digit is 34 or 37
        {
            card_type = 1; // set card_type to amex
        }
    }
    else
        card_type = 0;
    return card_type;
}

int validate_visa(long credit_card)
{
    long valid_visa = credit_card;
    if (valid_visa >= 1000000000000 && valid_visa < 10000000000000) // check if 13 digit number
    {
        valid_visa = valid_visa / 1000000000000; // remove 12 digits
        if (valid_visa == 4)                     // check if valid visa
        {
            card_type = 2; // set card_type to visa
        }
    }
    else if (valid_visa >= 1000000000000000 && valid_visa < 10000000000000000)
    {
        valid_visa = valid_visa / 1000000000000000; // remove 15 digits
        if (valid_visa == 4)                        // check if valid visa
        {
            card_type = 2; // set card_type to visa
        }
    }
    else
        card_type = 0;
    return card_type;
}

int validate_mc(long credit_card)
{
    long valid_mc = credit_card;
    if (valid_mc >= 100000000000000 && valid_mc < 10000000000000000)
    {
        valid_mc = valid_mc / 100000000000000; // remove 14 digts
        if (valid_mc >= 51 && valid_mc <= 55)
        {
            card_type = 3; // set card_type to mc
        }
    }

    else
        card_type = 0;
    return card_type;
}
