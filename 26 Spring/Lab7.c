/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 7: Remove Odd Numbers from an Array
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100

int RemoveOdds(int arraySize, const int originalArray[], int evenArray[]);

int main(void)
{
    int originalArray[MAX_ARRAY_SIZE];
    int evenArray[MAX_ARRAY_SIZE];
    int arraySize;
    int numberOfEvens;

    printf("Lab #7 - Solution\n\n");
    printf("Enter the size of your array: ");
    scanf("%d", &arraySize);

    if (arraySize < 1 || arraySize > MAX_ARRAY_SIZE) {
        printf("Array size must be between 1 and %d.\n", MAX_ARRAY_SIZE);
        return 1;
    }

    printf("Input your array: ");
    for (int index = 0; index < arraySize; ++index) {
        scanf("%d", &originalArray[index]);
    }

    numberOfEvens = RemoveOdds(arraySize, originalArray, evenArray);

    printf("The number of evens is %d\n\n", numberOfEvens);
    for (int index = 0; index < numberOfEvens; ++index) {
        printf("%d", evenArray[index]);
        if (index < numberOfEvens - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

int RemoveOdds(int arraySize, const int originalArray[], int evenArray[])
{
    int numberOfEvens = 0;

    for (int index = 0; index < arraySize; ++index) {
        if (originalArray[index] % 2 == 0) {
            evenArray[numberOfEvens] = originalArray[index];
            ++numberOfEvens;
        }
    }

    return numberOfEvens;
}
