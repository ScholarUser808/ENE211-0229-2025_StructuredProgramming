#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char pin[100];
    int attempts;
    int choice;
    int accessGranted = 0;
    int pinLength;
    int digitsOnly;
    int i;

    printf("=====================================\n");
    printf("      PIN-BASED DOOR LOCK SYSTEM\n");
    printf("=====================================\n\n");

    // Main system loop. The system allows the user to try again after the 5-second lockout.
    while (1)
    {
        accessGranted = 0;

        // PIN entry loop. Only valid four-digit PIN entries count towards the three attempts.
        for (attempts = 1; attempts <= 3;)
        {
            printf("Enter PIN: ");
            scanf("%99s", pin);

            pinLength = strlen(pin);
            digitsOnly = 1;

            // Check whether the PIN contains digits only.
            for (i = 0; i < pinLength; i++)
            {
                if (pin[i] < '0' || pin[i] > '9')
                {
                    digitsOnly = 0;
                    break;
                }
            }

            if (digitsOnly == 0)
            {
                printf("PIN contains digits only\n");
                printf("This entry does not count as an attempt.\n\n");
                continue;
            }
            else if (pinLength < 4)
            {
                printf("PIN is too short (must be 4 digits)\n");
                printf("This entry does not count as an attempt.\n\n");
                continue;
            }
            else if (pinLength > 4)
            {
                printf("PIN is too long (must be 4 digits)\n");
                printf("This entry does not count as an attempt.\n\n");
                continue;
            }
            else
            {
                printf("PIN is exactly 4 digits\n");

                // Only a valid four-digit numerical PIN counts as an attempt.
                if (strcmp(pin, "1256") == 0)
                {
                    printf("\nAccess granted.\n");
                    accessGranted = 1;
                    break;
                }
                else
                {
                    printf("Incorrect PIN.\n");

                    // Count the valid four-digit PIN attempt.
                    attempts++;

                    if (attempts <= 3)
                    {
                        printf("Remaining attempts: %d\n\n", 3 - attempts + 1);
                    }
                }
            }
        }

        // If the correct PIN was entered, display the device menu.
        if (accessGranted == 1)
        {
            while (1)
            {
                printf("\n");
                printf("=== Device Menu ===\n");
                printf("1. Open Door\n");
                printf("2. Change Username\n");
                printf("3. Change PIN\n");
                printf("4. Exit\n");

                printf("\nChoose an option: ");
                scanf("%d", &choice);

                // Switch statement for handling the selected menu option.
                switch (choice)
                {
                    case 1:
                        printf("\nAccess granted. Door unlocked.\n");
                        break;

                    case 2:
                        printf("\nChange username feature coming soon.\n");
                        break;

                    case 3:
                        printf("\nChange PIN feature coming soon.\n");
                        break;

                    case 4:
                        printf("\nExiting system.\n");
                        return 0;

                    default:
                        printf("\nInvalid option! Please try again.\n");
                }
            }
        }
        else
        {
            // Three valid four-digit PIN attempts have been unsuccessful.
            printf("\nSystem locked! Wait for 5 seconds...\n");

            // For loop with 1-second real-time delay per iteration.
            for (int seconds = 5; seconds >= 1; seconds--)
            {
                printf("%d...\n", seconds);
                fflush(stdout);
                sleep(1);
            }

            printf("You can try again now.\n\n");
        }
    }

    return 0;
}
