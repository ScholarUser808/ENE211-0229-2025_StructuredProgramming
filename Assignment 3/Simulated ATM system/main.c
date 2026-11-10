#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Requirement 1: Login / PIN verification function
int login()
{
    char pin[100];
    int attempts;
    int pinLength;
    int digitsOnly;
    int i;

    printf("=====================================\n");
    printf("      SIMULATED ATM SYSTEM\n");
    printf("=====================================\n\n");

    // PIN entry loop. Only valid four-digit PIN entries count towards the three attempts given to enter the correct PIN.
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
                return 1; // Returns True (1) if login is successful.
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

    // Three valid four-digit PIN attempts have been unsuccessful. Denies access to the system and exits.
    printf("\nSystem locked! Maximum attempts exceeded. Access denied.\n");
    return 0; // Returns False (0) if login fails.
}

// Requirement 3 (1): Balance Inquiry function
void checkBalance(float balance)
{
    printf("\nCurrent account balance: $%.2f\n", balance);
}

// Requirement 3 (2) & 5 (1): Deposit function with validation
void deposit(float *balance)
{
    float amount;
    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    // Ensure deposit amount is a positive number.
    if (amount <= 0)
    {
        printf("Error: Deposit amount must be a positive number.\n");
    }
    else
    {
        *balance += amount;
        printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, *balance);
    }
}

// Requirement 3 (3) & 5 (1, 2): Withdraw function with validation
void withdraw(float *balance)
{
    float amount;
    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);

    // Ensure withdrawal amount is a positive number.
    if (amount <= 0)
    {
        printf("Error: Withdrawal amount must be a positive number.\n");
    }

    // Ensure withdrawal does not exceed current balance.
    else if (amount > *balance)
    {
        printf("Error: Insufficient balance. Current balance is $%.2f\n", *balance);
    }
    else
    {
        *balance -= amount;
        printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, *balance);
    }
}

int main()
{
    float balance = 2000.00; // Starting account balance
    int choice;

    // Execute login function
    if (!login())
    {
        return 0; // Exit program if login fails.
    }

    // Requirement 2 & 4: Repeatedly display menu and loop until exit.
    while (1)
    {
        printf("\n=====================================\n");
        printf("           ATM MAIN MENU\n");
        printf("=====================================\n");
        printf("1. Balance Inquiry\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");

        printf("\nChoose an option: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Requirement 3: Handle user Choice.
        switch (choice)
        {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                deposit(&balance);
                break;

            case 3:
                withdraw(&balance);
                break;

            case 4:
                printf("\nThank you for using the ATM. Exiting system.\n");
                return 0;

            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}
