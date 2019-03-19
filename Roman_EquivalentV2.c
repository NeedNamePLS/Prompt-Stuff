/*
*Program: (Promt #4 Modified) Roman-Numeral Equivalent of Decimal Values
*Programmer: Jonathan A. Butler
*Date: 18 Mar 2019
*Description: Allows the user to enter a decimal or roman number to be converted
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int clear_input();
int convert(char Roman);

int main()
{
    // variables and stuff
    int i = 0, counter = 0, loop = 1;
    int converter;
    int decimalNum, temp = 0;
    char romanNum[100];
    char password[4];

    // Password Locked
    printf("Enter Password: ");
    scanf("%s", &password);
    if (strcmp(password, "IDF") == 0)
    {
        printf("ACCESS ACCEPTED\n");
    }
    else
    {
        printf("ACCESS DENIED\n");
        exit(0);
    }

    // Prompt to let user choose how to convert
    printf("\nWelcome to the Decimal/Roman Converter\n");
    printf("\nDo you wish to convert a Decimal number or a Roman number?\n");
    while (converter != 1 && converter != 2)
    {
        printf("[1] for Decimal | [2] for Roman | User Input: ");
        scanf("%d", &converter);
        clear_input();
    }
    
    // Numerical to Roman convert
    if (converter == 1)
    {
        while (decimalNum < 1 || decimalNum > 100)
        {
            printf("Enter a decimal number ranging from 1 to 100 | User Input: ");
            scanf("%d", &decimalNum);
            clear_input();
        }

        temp = decimalNum;
        printf("The Roman equivalent of %d is: ", decimalNum);

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
        printf("\n\n");
    }

    // Roman to Numerical convert
    if (converter == 2)
    {
        while (loop != 0)
        {
            counter = 0;

            printf("Enter a Roman value | User Input: ");
            scanf("%s", &romanNum);
            clear_input();

            // 
            if (convert(romanNum[i]) < 0)
            { counter++; }
            
            if((strlen(romanNum) - i ) > 2)
            {
                if(convert(romanNum[i]) < convert(romanNum[i + 2]))
                { counter++; }
            }
            
            for(i = 0; i < strlen(romanNum); i++)
            {
                // The ugliest statement ever but someone decided to change the requirements like 4 hours later then when we started
                if((romanNum[i] == 'I' && romanNum[i+1] == 'I' && romanNum[i-1] == 'I' && romanNum[i+2] == 'I')||
                    (romanNum[i] == 'X' && romanNum[i+1] == 'X' && romanNum[i-1] == 'X' && romanNum[i+2] == 'X')||
                    (romanNum[i] == 'V' && romanNum[i+1] == 'V')||
                    (romanNum[i] == 'L' && romanNum[i+1] == 'L')||
                    (romanNum[i] == 'C' && romanNum[i+1] == 'C' && romanNum[i-1] == 'C' && romanNum[i+2] == 'C'))
                { counter++; }
            }

            if (counter == 0)
            {
                loop = 0;
            }
        }// End of While Loop

        for (i = 0; i < strlen(romanNum); i++)
        {
            if(convert(romanNum[i]) >= convert(romanNum[i + 1]))
            {
                temp += convert(romanNum[i]);
            }
            else
            {
                temp += (convert(romanNum[i + 1]) - convert(romanNum[i]));
                i++;
            }
            i++;
        }// End of While Loop
        printf("\nThe Decimal equivalent of %s is: %d\n", romanNum, temp);

        return 0;
    }
    
    return 0;
}// End of main

// 
int convert(char Roman)
{
    int value = 0;

    switch(Roman)
    {
        case 'I': value = 1; break;
        case 'V': value = 5; break;
        case 'X': value = 10; break;
        case 'L': value = 50; break;
        case 'C': value = 100; break;
        case 'D': value = 500; break;
        case 'M': value = 1000; break;
        case '\0': value = 0; break;
        default: value = -1;
    }

    return value;
}

//Clears stdin
int clear_input()
{
   while(getchar() != '\n');
}