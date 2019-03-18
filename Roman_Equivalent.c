/*
*Program: (Promt #4) Roman-Numeral Equivalent of Decimal Values
*Programmer: Jonathan A. Butler
*Date: 18 Mar 2019
*Description: Prints a table of numeral values 1 through 100 and then prints the Roman-Numeral equivalent
*/

#include <stdio.h>

int main()
{
    // Temporary used to represent the Roman version and compared with
    int temp;

    printf("\n");
    printf("[Numeral to Roman]\n");

    // To go through the values 1 to 100
    for (int numeral = 1; numeral < 101; numeral++)
    {
        // Set temp value with the current numerical value
        temp = numeral;

        // Purely cosmetic so the printed table is evenly aligned
        if (numeral < 10)
        {
            printf("[  %d]: ", numeral);
        }
        else if (numeral > 9 && numeral < 100)
        {
            printf("[ %d]: ", numeral);
        }
        else
        {
            printf("[%d]: ", numeral);
        }

        // While Loop to constantly compare the temp value until it is 0
        while (temp > 0)
        {
            // Checks to see if value equals 100 then prints the Roman version of 100
            if (temp == 100)
            {
                printf("C");
                temp -= 100;
            }
            // Checks to see if value is 90 or greater but less than 100 then prints Roman version of 90
            if (temp > 89 && temp < 100)
            {
                printf("XC");
                temp -= 90;
            }
            // Checks to see if value is 50 or greater but less than 90 then prints the Roman version of 50
            if (temp > 49 && temp < 90)
            {
                printf("L");
                temp -= 50;
            }
            // Checks to see if value is 40 or greater but less than 50 then prints the Roman version of 40
            if (temp > 39 && temp < 50)
            {
                printf("XL");
                temp -= 40;
            }
            // Checks to see if value is 10 or greater but less than 40 then prints the Roman version of 10
            if (temp > 9 && temp < 40)
            {
                printf("X");
                temp -= 10;
            }
            // Checks to see if value is 9 then prints the Roman version of 9
            if (temp == 9)
            {
                printf("IX");
                temp -= 9;
            }
            // Checks to see if value is 5 or greater but less than 10 then prints the Roman version of 5
            if (temp > 4 && temp < 10)
            {
                printf("V");
                temp -= 5;
            }
            // Checks to see if value is 4 then prints the Roman version of 4
            if (temp == 4)
            {
                printf("IV");
                temp -= 4;
            }
            // Checks to see if value is 1 or greater and less than 4 then prints the Roman version of 1
            if (temp > 0 && temp < 4)
            {
                printf("I");
                temp -= 1;
            }
        }// End of While Loop

        printf("\n");
    }// End of For Loop

    return 0;
}// End of main