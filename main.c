#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account accounts[100];
    int totalAccounts = 0;
    int choice;
    int i, searchNo, found;
    float amount;

    while (1) {
        printf("\nBANK MANAGEMENT SYSTEM\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Account Number: ");
            scanf("%d", &accounts[totalAccounts].accNo);
            
            printf("Enter Holder Name: ");
            scanf("%s", accounts[totalAccounts].name);
            
            printf("Enter Initial Balance: ");
            scanf("%f", &accounts[totalAccounts].balance);

            totalAccounts++;
            printf("Account created successfully!\n");

        } else if (choice == 2) {
            if (totalAccounts == 0) {
                printf("\nNo accounts found.\n");
            } else {
                printf("\nAccount List:\n");
                for (i = 0; i < totalAccounts; i++) {
                    printf("Acc No: %d, Name: %s, Balance: $%.2f\n", 
                           accounts[i].accNo, accounts[i].name, accounts[i].balance);
                }
            }

        } else if (choice == 3) {
            printf("\nEnter Account Number: ");
            scanf("%d", &searchNo);
            found = 0;

            for (i = 0; i < totalAccounts; i++) {
                if (accounts[i].accNo == searchNo) {
                    printf("Enter Deposit Amount: ");
                    scanf("%f", &amount);
                    accounts[i].balance += amount;
                    printf("Deposit successful! New Balance: $%.2f\n", accounts[i].balance);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account not found!\n");
            }

        } else if (choice == 4) {
            printf("\nEnter Account Number: ");
            scanf("%d", &searchNo);
            found = 0;

            for (i = 0; i < totalAccounts; i++) {
                if (accounts[i].accNo == searchNo) {
                    printf("Enter Withdrawal Amount: ");
                    scanf("%f", &amount);
                    
                    if (amount <= accounts[i].balance) {
                        accounts[i].balance -= amount;
                        printf("Withdrawal successful! Remaining Balance: $%.2f\n", accounts[i].balance);
                    } else {
                        printf("Insufficient balance!\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account not found!\n");
            }

        } else if (choice == 5) {
            printf("\nEnter Account Number to Search: ");
            scanf("%d", &searchNo);
            found = 0;

            for (i = 0; i < totalAccounts; i++) {
                if (accounts[i].accNo == searchNo) {
                    printf("\nAccount Found:\n");
                    printf("Account No: %d\n", accounts[i].accNo);
                    printf("Name: %s\n", accounts[i].name);
                    printf("Balance: $%.2f\n", accounts[i].balance);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Account not found!\n");
            }

        } else if (choice == 6) {
            printf("\nExiting program. Goodbye!\n");
            break;

        } else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
