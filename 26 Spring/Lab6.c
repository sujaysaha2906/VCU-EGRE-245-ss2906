/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 6: Multiplying Square Matrices
 */

#include <stdio.h>

#define MAX_MATRIX_SIZE 5

int main(void)
{
    int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int product[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {{0}};
    int size;

    printf("Lab #6 - Solution\n\n");
    printf("Enter the number of rows, N, of a square matrix, (N <= 5): ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_MATRIX_SIZE) {
        printf("Matrix size must be between 1 and 5.\n");
        return 1;
    }

    printf("\nEnter the %d elements of Matrix-1:\n", size * size);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            scanf("%d", &matrix1[row][column]);
        }
    }

    printf("\nEnter the %d elements of Matrix-2:\n", size * size);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            scanf("%d", &matrix2[row][column]);
        }
    }

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            for (int index = 0; index < size; ++index) {
                product[row][column] += matrix1[row][index] * matrix2[index][column];
            }
        }
    }

    printf("\nThe product of the two matrices is:\n");
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            printf("%8d", product[row][column]);
        }
        printf("\n");
    }

    return 0;
}
