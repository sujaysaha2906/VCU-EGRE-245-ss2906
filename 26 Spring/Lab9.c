/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 9: Introduction to Pointers
 */

#include <stdio.h>

int main(void)
{
    int firstValue;
    int secondValue;
    int temporaryValue;
    int *firstPointer;
    int *secondPointer;

    printf("Lab #9 - Solution\n");
    printf("Enter value for a: ");
    scanf("%d", &firstValue);
    printf("Enter value for b: ");
    scanf("%d", &secondValue);

    firstPointer = &firstValue;
    secondPointer = &secondValue;

    printf("\nInitial values:\n");
    printf("a = %d\n", firstValue);
    printf("b = %d\n", secondValue);

    printf("\nAddresses:\n");
    printf("&a = %p\n", (void *)&firstValue);
    printf("&b = %p\n", (void *)&secondValue);

    printf("\nPointer values:\n");
    printf("p1 = %p\n", (void *)firstPointer);
    printf("p2 = %p\n", (void *)secondPointer);

    printf("\nDereferenced values:\n");
    printf("*p1 = %d\n", *firstPointer);
    printf("*p2 = %d\n", *secondPointer);

    *firstPointer += 10;
    *secondPointer *= 2;

    printf("\nAfter pointer modifications:\n");
    printf("a = %d\n", firstValue);
    printf("b = %d\n", secondValue);

    temporaryValue = *firstPointer;
    *firstPointer = *secondPointer;
    *secondPointer = temporaryValue;

    printf("\nAfter swap:\n");
    printf("a = %d\n", firstValue);
    printf("b = %d\n", secondValue);

    return 0;
}
