#include <stdio.h>



int main(void) {
    int pin;
    const int CORRECT_PIN = 1234;
    int attempts = 0;
    int balance = 10000; /* starting balance */
    int choice;
    int amount;
    int c; /* for clearing input */

    printf("Welcome to the Simple ATM!\n");

    /* Login with up to 3 attempts */
    while (attempts < 3) {
        printf("Enter your PIN: ");
        if (scanf("%d", &pin) != 1) {
            /* clear invalid input */
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Please enter digits only.\n");
            continue;
        }
        if (pin == CORRECT_PIN) {
            printf("Login successful!\n");
            break;
        } else {
            attempts++;
            printf("Wrong PIN. Attempts left: %d\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("Too many wrong attempts. Exiting.\n");
        return 0;
    }

    /* Main menu loop */
    do {
        printf("\n--- ATM MENU ---\n");
        printf("1. Check balance\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Please enter a number 1-4.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Your balance is: %d\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                if (scanf("%d", &amount) != 1) {
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid amount.\n");
                    break;
                }
                if (amount <= 0) {
                    printf("Amount must be positive.\n");
                } else {
                    balance += amount;
                    printf("Deposit successful. New balance: %d\n", balance);
                }
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                if (scanf("%d", &amount) != 1) {
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid amount.\n");
                    break;
                }
                if (amount <= 0) {
                    printf("Amount must be positive.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds. Your balance: %d\n", balance);
                } else {
                    balance -= amount;
                    printf("Please take your cash: %d\n", amount);
                    printf("New balance: %d\n", balance);
                }
                break;
            case 4:
                printf("Thank you for using the Simple ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1-4.\n");
        }

        /* clear any leftover input before next loop */
        while ((c = getchar()) != '\n' && c != EOF) {}

    } while (choice != 4);

    return 0;
}
