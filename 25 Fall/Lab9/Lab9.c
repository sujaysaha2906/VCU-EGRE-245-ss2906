/*
 * EGRE 245 Engineering Programming
 * Fall 2025 - Lab 9: Simple Contact Manager
 */

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10
#define MAX_NAME_LENGTH 50

void clearInputLine(void);
void addContact(char contacts[][MAX_NAME_LENGTH], int *contactCount);
void displayContacts(char contacts[][MAX_NAME_LENGTH], int contactCount);
void searchContact(char contacts[][MAX_NAME_LENGTH], int contactCount);

int main(void)
{
    char contacts[MAX_CONTACTS][MAX_NAME_LENGTH] = {{0}};
    int contactCount = 0;
    int choice = 0;

    printf("Lab #9 - Solution\n\n");

    while (choice != 4) {
        printf("Simple Contact Manager\n");
        printf("----------------------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            clearInputLine();
            choice = 0;
        } else {
            clearInputLine();
        }

        printf("\n");
        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                displayContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please choose 1 through 4.\n");
        }
        printf("\n");
    }

    return 0;
}

void clearInputLine(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
    }
}

void addContact(char contacts[][MAX_NAME_LENGTH], int *contactCount)
{
    if (*contactCount >= MAX_CONTACTS) {
        printf("The contact list is full.\n");
        return;
    }

    printf("Enter contact name: ");
    if (fgets(contacts[*contactCount], MAX_NAME_LENGTH, stdin) == NULL) {
        printf("Unable to read the contact name.\n");
        return;
    }

    contacts[*contactCount][strcspn(contacts[*contactCount], "\n")] = '\0';
    ++(*contactCount);
    printf("Contact added!\n");
}

void displayContacts(char contacts[][MAX_NAME_LENGTH], int contactCount)
{
    if (contactCount == 0) {
        printf("No contacts saved.\n");
        return;
    }

    printf("Contacts:\n");
    for (int index = 0; index < contactCount; ++index) {
        printf("%d. %s\n", index + 1, contacts[index]);
    }
}

void searchContact(char contacts[][MAX_NAME_LENGTH], int contactCount)
{
    char searchName[MAX_NAME_LENGTH];

    printf("Enter contact name to search for: ");
    if (fgets(searchName, sizeof(searchName), stdin) == NULL) {
        printf("Unable to read the contact name.\n");
        return;
    }
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int index = 0; index < contactCount; ++index) {
        if (strcmp(contacts[index], searchName) == 0) {
            printf("Contact found at position %d.\n", index + 1);
            return;
        }
    }

    printf("Contact not found.\n");
}
