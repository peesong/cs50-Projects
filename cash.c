#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int);
int calculate_dimes(int);
int calculate_nickels(int);
int calculate_pennies(int);
int quarters;
int dimes;
int nickels;
int pennies;

int main(void)
{
    int change_owed = 0;
    do
    {
        change_owed = get_int("How much change is owed (in cents):\n");
    }
    while (change_owed < 0);

    do
    {
        quarters = calculate_quarters(change_owed);
        change_owed = change_owed - (quarters * 25);
        dimes = calculate_dimes(change_owed);
        change_owed = change_owed - (dimes * 10);
        nickels = calculate_nickels(change_owed);
        change_owed = change_owed - (nickels * 5);
        pennies = calculate_pennies(change_owed);
        change_owed = change_owed - (pennies);
    }
    while (change_owed > 0);
    int coin = (quarters + dimes + nickels + pennies);
    printf("%d coins.\n%d quarters, %d dimes, %d nickels, %d pennies\n", coin, quarters, dimes,
           nickels, pennies);
}

int calculate_quarters(int change_owed)
{
    quarters = 0;
    while (change_owed >= 25)
    {
        quarters++;
        change_owed = change_owed - 25;
    }
    return quarters;
}

int calculate_dimes(int change_owed)
{
    dimes = 0;
    while (change_owed >= 10)
    {
        dimes++;
        change_owed = change_owed - 10;
    }
    return dimes;
}

int calculate_nickels(int change_owed)
{
    nickels = 0;
    while (change_owed >= 5)
    {
        nickels++;
        change_owed = change_owed - 5;
    }
    return nickels;
}

int calculate_pennies(int change_owed)
{
    pennies = 0;
    while (change_owed >= 1)
    {
        pennies++;
        change_owed = change_owed - 1;
    }
    return pennies;
}
