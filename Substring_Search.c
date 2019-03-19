/*
*Program: (Promt #1) Searching for Substrings
*Programmer: Jonathan A. Butler
*Date: 18 Mar 2019
*Description: 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substringSearch(char *field, char *search);
int clear_input();

int main()
{
    char fieldInput[255];
    char searchInput[255];
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

    // Prompts user to input a "field" string
    printf("Input a string of whatever you want.\n");
    fgets(fieldInput, 255, stdin);
    clear_input();
    if ((strlen(fieldInput) > 0) && (fieldInput[strlen (fieldInput) - 1] == '\n'))
    {
        fieldInput[strlen (fieldInput) - 1] = '\0';
    }

    // Prompts the user to input a "search" string which will be looked for within the "field" string
    printf("Input a string to search within the previous string.\n");
    fgets(searchInput, 255, stdin);
    clear_input();
    if ((strlen(searchInput) > 0) && (searchInput[strlen (searchInput) - 1] == '\n'))
    {
        searchInput[strlen (searchInput) - 1] = '\0';
    }

    substringSearch(fieldInput, searchInput);
}

// Searches the "field" for the designated string
void substringSearch(char *field, char *search)
{
    char *searchPtr;
    searchPtr = strstr(field, search);

    // Prints out the first appearance of the search string onwards
    if (searchPtr != NULL)
    {
        printf("%s first appears here: %s\n", search, searchPtr);

        searchPtr = strstr((searchPtr + 1), search);

        // If there is a second occurence, prints out the second appearance onwards
        if (searchPtr != NULL)
        {
            printf("%s second appears here: %s\n", search, searchPtr);
        }
    }
    else
    {
        printf("Cannot find %s in %s\n", search, field);
        printf("This is Travis's fault\n"); // It really is
    }
}

//Clears stdin
int clear_input()
{
   while(getchar() != '\n');
}