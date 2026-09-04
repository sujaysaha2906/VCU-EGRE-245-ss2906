/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 1: Simple Menu
 */

#include <stdio.h>

int main(void)
{
    char selection;

    printf("Lab #1 Simple Menu - Solution\n");
    printf("February 2, 2026\n\n");
    printf("Select An Option:\n\n");
    printf("A:\tAdd\n");
    printf("B:\tEdit Name\n");
    printf("C:\tEdit Quantity\n");
    printf("D:\tDelete\n");
    printf("Q:\tQuit\n\n");
    printf("Enter your selection: ");
    scanf(" %c", &selection);
    printf("\nYour selection is option %c\n", selection);

    return 0;
}
