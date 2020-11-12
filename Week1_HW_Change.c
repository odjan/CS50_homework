#include <stdio.h>
#include <math.h>
#include <cs50.h>
int change_calculator(float change);

// determine the lowest amount of coins necessary for correct change

int main(void){
    float change = 0;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);


    int coins = change_calculator(change);

    printf("%i \n", coins);

    return 0;
}

int change_calculator(float change){
    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int cents = round(change*100);

    // passing through quarters
    dollars += (cents/100);
    quarters += (cents / 25);
    dimes += ((cents-quarters*25)/10);
    nickels += ((cents-quarters*25-dimes*10)/5);
    pennies += ((cents-quarters*25-dimes*10-nickels*5)/1);

    return quarters + dimes + nickels + pennies;

}