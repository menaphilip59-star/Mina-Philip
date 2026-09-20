#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long temp = number;
    int length = 0;

    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    int sum = 0, position = 0;
    temp = number;
    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;
        if (position % 2 == 1)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
            sum += digit;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long first_two = number;
    while (first_two >= 100)
        first_two /= 10;
    int first_digit = first_two / 10;

    if (length == 15 && (first_two == 34 || first_two == 37))
        printf("AMEX\n");
    else if (length == 16 && first_two >= 51 && first_two <= 55)
        printf("MASTERCARD\n");
    else if ((length == 13 || length == 16) && first_digit == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");
}
