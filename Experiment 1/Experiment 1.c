#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100], string2[100];
    int choice, i, j, n, r = 6;

    printf("Enter String 1:\n");
    scanf("%s", string1);

    while (r == 6)
    {
        printf("\nEnter your choice:\n");
        printf("1. Find Substring\n");
        printf("2. Palindrome\n");
        printf("3. Compare\n");
        printf("4. Copy\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter String2:\n");
                scanf("%s", string2);

                if (strstr(string1, string2) != NULL)
                {
                    printf("Substring Found\n");
                }
                else
                {
                    printf("Substring Not Found\n");
                }
                break;


            case 2:
                n = strlen(string1);

                for (i = 0; i < n; i++)
                {
                    if (string1[i] != string1[n - i - 1])
                    {
                        printf("Not a Palindrome\n");
                        break;
                    }
                }

                if (i == n)
                {
                    printf("Palindrome\n");
                }

                break;


            case 3:
                printf("Enter String2:\n");
                scanf("%s", string2);

                if (strcmp(string1, string2) == 0)
                {
                    printf("Strings are equal\n");
                }
                else
                {
                    printf("Strings are not equal\n");
                }

                break;


            case 4:
                strcpy(string2, string1);

                printf("Copied String = %s\n", string2);

                break;


            case 5:
                n = strlen(string1);
                j = 0;

                for (i = n - 1; i >= 0; i--)
                {
                    string2[j] = string1[i];
                    j++;
                }

                string2[j] = '\0';

                printf("Reversed String = %s\n", string2);

                break;


            case 6:
                r = 5;
                printf("Exit Successful\n");
                break;


            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
