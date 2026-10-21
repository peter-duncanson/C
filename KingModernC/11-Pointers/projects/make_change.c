// =============================================================================
// Takes a USD amount and lets you know how to pay it with the least amount
// of bills. Takes variables for the bills by reference, and USD amount by
// value.
// =============================================================================
#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int amount, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf("For $%d you need:\n%d twenties\n%d tens\n%d fives\n%d ones\n",
            amount, twenties, tens, fives, ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    *tens = (dollars % 20) / 10;
    *fives = (dollars % 10) / 5;
    *ones = (dollars % 5);
}
