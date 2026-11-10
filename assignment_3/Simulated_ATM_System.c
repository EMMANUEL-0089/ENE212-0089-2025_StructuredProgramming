// Global variables: balance = 6000, correct_pin = "1281"

// 1. LOGIN FUNCTION
//    - Loop up to 3 times to ask user for PIN.
//    - If PIN matches correct_pin, return true (success).
//    - Else, decrease attempt count and retry; exit if 0 attempts left.

// 2. CHECK BALANCE FUNCTION
//    - Ask user for PIN.
//    - If PIN is correct, display current balance.
//    - Else, show error message.

// 3. DEPOSIT FUNCTION
//    - Check if deposit amount is valid (greater than 0).
//    - Ask for PIN to confirm.
//    - If PIN is correct, add amount to balance and notify user.

// 4. WITHDRAW FUNCTION
//    - Check if amount is valid and less than or equal to balance.
//    - Ask for PIN to confirm.
//    - If PIN is correct, subtract amount from balance and notify user.

// 5. MAIN PROGRAM
//    - Run login() function first.
//    - If login succeeds, enter a running loop:
//        - Display menu options (1: Balance, 2: Withdraw, 3: Deposit, 4: Exit).
//        - Read user choice.
//        - Execute corresponding function based on choice.
//        - Loop continues until user chooses to exit.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int balance = 6000;

const char correct_pin[10] = "1281";

void clear_buffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool login() {
    const char pin[10];
    int count = 2;
    while (count <= 2 && count >= 0) {
        printf("Enter PIN: ");
        if(scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            printf("Correct PIN.\n");
            printf("Successful login.\n");
            return true;
        } else {
            printf("Wrong PIN.\n");
            if (count >= 1) {
                printf("Try again. Attempts remaining %d\n", count--);
                    continue;
            } else {
                printf("No attempts remaining.\n\tExiting System.\n");
                    return false;
            }
        }
    }
    }

void checkBalance() {
    char pin[10];
    printf("Enter PIN: \n");

    if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
        printf("Dear customer, your account balance is %d.\n", balance);
    } else {
        printf("You have entered the wrong PIN.\n");
    }
}



void display_menu(void) {
    printf("\n1. Balance Inquiry.\n");
    printf("2. Withdraw.\n");
    printf("3. Deposit.\n");
    printf("4. Exit.\n");

    printf("Choose an option above.\n");
}

bool deposit(int amount) {
    char pin[10];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        printf("\nEnter PIN to confirm deposit of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance += amount;
            printf("You have successfully deposited %d in your account.\n", amount);
            return true;
        } else {
            printf("You have entered the wrong PIN.\n");
            return false;
        }
    }
}

bool withdraw(int amount) {
    char pin[10];
    if (amount < 1) {
        printf("Invalid amount.\n");
    } else {
        if (amount > balance) {
            printf("You have insufficient funds.\n");
            return false;
        }
        printf("\nEnter PIN to confirm withdrawal of %d: \n", amount);
        if (scanf(" %s", pin) == 1 && strcmp(correct_pin, pin) == 0) {
            balance -= amount;
            printf("You have successfully withdrawn %d in your account.\n", amount);
            return true;
        } else {
            printf("You have entered the wrong PIN.\n");
            return false;
        }
    }
}

int main()
{
    if (login() == true) {
        bool running = true;
        int amount;
        while (running) {
            int choice;
            display_menu();
            if (scanf("%d", &choice) != 1) {
                printf("That option contain letters or symbols. Try again.\n");
                clear_buffer();
                continue;
            }

            switch (choice) {
                case 1 : checkBalance();
                         break;
                case 2 : printf("Enter amount you would like to withdraw: ");
                         if (scanf("%d", &amount) == 1) {
                            withdraw(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 3 : printf("Enter amount you would like to withdraw: ");
                         if (scanf("%d", &amount) == 1) {
                            deposit(amount);
                         } else {
                            printf("Invalid amount.\n");
                            clear_buffer();
                         }
                         break;
                case 4 : printf("Exiting system.\n");
                         running = false;
                         return 0;
                default : printf("\nInvalid option. Please try again.\n");
                          clear_buffer();
                          break;
            }

        }
    }
    return 0;

}
