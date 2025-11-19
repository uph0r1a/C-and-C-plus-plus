#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int accountNumber;
    char holderName[50];
    float balance;
} Account;

void menu()
{
    printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Accounts\n5. Search Account\n6. Exit\n");
}

void create_account(Account *account, int *count)
{
    int account_number_input, flag = 1;
    if (*count >= 5)
    {
        printf("Account is full");
        return;
    }

    printf("Enter the account number: ");
    while (flag)
    {
        scanf("%d", &account_number_input);
        flag = 0;
        for (int i = 0; i < *count; i++)
        {
            if (account_number_input == account[i].accountNumber)
            {
                printf("Account number already exist\nRe-enter the account number: ");
                flag = 1;
                break;
            }
        }
    }

    account[*count].accountNumber = account_number_input;

    printf("Enter the holder name: ");
    scanf(" %[^\n]", account[*count].holderName);

    printf("Enter the balance: ");
    while (1)
    {
        scanf("%f", &account[*count].balance);
        if (account[*count].balance >= 0)
        {
            break;
        }
        printf("Account initial balance cannot be negative\nRe-enter the balance: ");
    }

    (*count)++;
}

void display_account(Account account[], int count)
{
    printf("%-10s|%-15s|%-10s\n", "Account number", "Holder Name", "Balance");
    for (int i = 0; i < count; i++)
    {
        printf("%-10d|%-15s|%-10.2f\n", account[i].accountNumber, account[i].holderName, account[i].balance);
    }
}

Account *findAccount(Account account[], int count, int account_number_input)
{
    for (int i = 0; i < count; i++)
    {
        if (account[i].accountNumber == account_number_input)
        {
            return &account[i];
        }
    }
    return NULL;
}

void deposit(Account account[], int count)
{
    float deposit;
    int account_number_input;

    printf("Enter your account number: ");
    scanf("%d", &account_number_input);

    Account *acc = findAccount(account, count, account_number_input);
    if (acc == NULL)
    {
        printf("Account didn't exist\n");
        return;
    }

    printf("Enter the deposit amount: ");
    while (1)
    {
        scanf("%f", &deposit);
        if (deposit > 0)
            break;
        printf("Deposit amount must be positive\nRe-enter the deposit amount: ");
    }

    acc->balance += deposit;
    printf("Deposit successful! New balance: %.2f\n", acc->balance);
}

void withdraw(Account account[], int count)
{
    float withdraw;
    int account_number_input;

    printf("Enter your account number: ");
    scanf("%d", &account_number_input);

    Account *acc = findAccount(account, count, account_number_input);
    if (acc == NULL)
    {
        printf("Account didn't exist\n");
        return;
    }

    printf("Enter the withdraw amount: ");
    while (1)
    {
        scanf("%f", &withdraw);
        if (withdraw > 0)
            break;
        printf("Withdraw amount must be positive\nRe-enter amount: ");
    }

    if (withdraw > acc->balance)
    {
        printf("Insufficient balance\n");
        return;
    }

    acc->balance -= withdraw;
    printf("Withdraw successful! New balance: %.2f\n", acc->balance);
}

int main(int argc, char const *argv[])
{
    int choice, flag = 1, count = 0, account_number_input;
    Account account[5];

    while (flag)
    {
        menu();
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_account(account, &count);
            break;
        case 2:
            deposit(account, count);
            break;
        case 3:
            withdraw(account, count);
            break;
        case 4:
            display_account(account, count);
            break;
        case 5:
            printf("Enter account number to search: ");
            scanf("%d", &account_number_input);

            Account *found = findAccount(account, count, account_number_input);
            if (found != NULL)
            {
                printf("Account Found: %d | %s | %.2f\n", found->accountNumber, found->holderName, found->balance);
            }
            else
            {
                printf("Account not found.\n");
            }
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        system("cls");
    }

    return 0;
}
