#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
#define FILENAME "accounts.txt"
#define SECURITY_CODE "1234" // Replace with your desired security code

struct Account {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Function to read account information from file
int readAccounts(struct Account accounts[], int maxAccounts) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s", accounts[count].username, accounts[count].password) == 2) {
        count++;
        if (count >= maxAccounts) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to write account information to file
void writeAccounts(struct Account accounts[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", accounts[i].username, accounts[i].password);
    }

    fclose(file);
}

// Function to reset password by username with security code verification
void resetPassword(struct Account accounts[], int count, char username[], char newPassword[], char securityCode[]) {
    if (strcmp(securityCode, SECURITY_CODE) != 0) {
        printf("Security code is incorrect. Password reset failed.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            strcpy(accounts[i].password, newPassword);
            printf("Password reset successful for user %s.\n", username);
            return;
        }
    }

    printf("Username not found. Password reset failed.\n");
}

int main() {
    struct Account accounts[MAX_LENGTH];
    int numAccounts = readAccounts(accounts, MAX_LENGTH);

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char securityCode[MAX_LENGTH];
    char newPassword[MAX_LENGTH];

    printf("Login System\n");

    // Get username from the user
    printf("Enter username: ");
    scanf("%s", username);

    // Get password from the user
    printf("Enter password: ");
    scanf("%s", password);

    // Authenticate the user
    int authenticated = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
            authenticated = 1; // Authentication successful
            break;
        }
    }

    if (authenticated) {
        printf("Login successful. Welcome, %s!\n", username);
    } else {
        printf("Login failed. Invalid username or password.\n");

        // Option to reset password with security code
        printf("Do you want to reset your password? (y/n): ");
        char resetOption;
        scanf(" %c", &resetOption);

        if (resetOption == 'y' || resetOption == 'Y') {
            printf("Enter security code for password reset: ");
            scanf("%s", securityCode);

            // Get a new password
            printf("Enter a new password: ");
            scanf("%s", newPassword);

            // Reset password
            resetPassword(accounts, numAccounts, username, newPassword, securityCode);

            // Update accounts file
            writeAccounts(accounts, numAccounts);
        }
    }

    return 0;
}
