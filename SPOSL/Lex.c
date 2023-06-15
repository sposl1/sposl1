#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int isKeyword(char* token) 
{
    // List of keywords
    char keywords[][MAX_LENGTH] = {"if", "else", "while","int"};

    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) 
    {
        if (strcmp(token, keywords[i]) == 0) 
        {
            return 1; // It's a keyword
        }
    }
    return 0; // It's not a keyword
}

int main() 
{
    char input[MAX_LENGTH];
    int k=0,i=0,c=0,o=0;
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " \t\n");

    while (token != NULL) {
        if (isalpha(token[0])) {
            // Identifier or keyword
            if (isKeyword(token))
            {
                printf("Keyword: %s\n", token);
                k++;
            } 
            else 
            {
                printf("Identifier: %s\n", token);
                i++;
            }
        } 
        else if (isdigit(token[0])) 
        {
            // Integer constant
            printf("Constant: %s\n", token);
            c++;
        } 
        else 
        {
            // Operator or punctuation
            printf("Operator/Punctuation: %s\n", token);
            o++;
        }

        token = strtok(NULL, " \t\n");

    }
        printf("Total keywordss : %d\n",k);
        printf("Total identifiers : %d\n",i);
        printf("Total number : %d\n",c);
        printf("Total operator : %d\n",o);
        printf("Total tokens : %d\n", (k+i+c+o));

    return 0;
}
