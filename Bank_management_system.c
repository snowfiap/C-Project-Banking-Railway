#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100  // Define the maximum number of accounts

// Define a structure to represent a bank account
typedef struct {
    int accountNumber;         // Account number
    char accountHolder[50];    // Account holder's name
    float balance;             // Account balance
} Account;

Account bank[MAX_ACCOUNTS];    // Array to store accounts in the bank
int accountCount = 0;          // Number of accounts created

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Bank is full! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1;  // Assign account number sequentially
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.accountHolder);        // Get account holder's name
    newAccount.balance = 0.0;                     // Initialize balance to 0
    bank[accountCount++] = newAccount;            // Add account to the bank array
    
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) { // Validate account number
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {  // Validate amount
        printf("Invalid deposit amount!\n");
        return;
    }

    bank[accountNumber - 1].balance += amount;    // Add amount to account balance
    printf("Amount deposited successfully! New Balance: %.2f\n", bank[accountNumber - 1].balance);
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) { // Validate account number
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {  // Validate amount
        printf("Invalid withdrawal amount!\n");
        return;
    }

    if (bank[accountNumber - 1].balance < amount) { // Check if sufficient balance is available
        printf("Insufficient balance!\n");
        return;
    }

    bank[accountNumber - 1].balance -= amount;    // Deduct amount from balance
    printf("Amount withdrawn successfully! New Balance: %.2f\n", bank[accountNumber - 1].balance);
}

// Function to check the balance of an account
void checkBalance() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) { // Validate account number
        printf("Invalid account number!\n");
        return;
    }

    printf("Account Balance: %.2f\n", bank[accountNumber - 1].balance); // Display balance
}

// Function to display account details
void displayAccountDetails() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) { // Validate account number
        printf("Invalid account number!\n");
        return;
    }
    
    Account acc = bank[accountNumber - 1];  // Fetch account details
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.accountHolder);
    printf("Balance: %.2f\n", acc.balance);
}

// Main function with a menu-driven interface
int main() {
    int choice;
    
    while (1) { // Continuous loop for menu options
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();         // Create a new account
                break;
            case 2:
                depositMoney();          // Deposit money into an account
                break;
            case 3:
                withdrawMoney();         // Withdraw money from an account
                break;
            case 4:
                checkBalance();          // Check account balance
                break;
            case 5:
                displayAccountDetails(); // Display account details
                break;
            case 6:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
