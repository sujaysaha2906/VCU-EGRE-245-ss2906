#include <stdio.h>

int main() {
    int i, num_test;

    printf("\nEnter the number of test scores you wish to analyze: ");
    scanf("%d", &num_test);

    // Declare array AFTER knowing num_test
    int scores[num_test];

    // Input test scores
    printf("\nEnter the test scores:\n");
    for (i = 0; i < num_test; i++) {
        printf("Score #%d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    // Initialize calculations AFTER scores are read
    int total = 0;
    int highest = scores[0];
    int lowest = scores[0];
    double average;

    // ----- Calculations -----
    for (i = 0; i < num_test; i++) {
        total += scores[i];

        if (scores[i] > highest) {
            highest = scores[i];
        }

        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    // Calculate average
    average = (double) total / num_test;

    // ----- Output Results -----
    printf("\nYou entered: ");
    for (i = 0; i < num_test; i++) {
        printf("%d ", scores[i]);
    }

    printf("\nAverage score: %.2lf", average);
    printf("\nHighest score: %d", highest);
    printf("\nLowest score: %d\n", lowest);

    return 0;
}