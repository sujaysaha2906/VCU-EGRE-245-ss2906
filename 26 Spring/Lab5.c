/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 5: Olympic Scoring
 */

#include <stdio.h>

int main(void)
{
    double scores[10];
    int numberOfJudges;
    double highest;
    double lowest;
    double total = 0.0;
    double officialScore;

    printf("Lab #5 - Solution\n\n");
    printf("Enter number of judges (5 to 10): ");
    scanf("%d", &numberOfJudges);

    while (numberOfJudges < 5 || numberOfJudges > 10) {
        printf("The number of judges must be between 5 and 10. Try again: ");
        scanf("%d", &numberOfJudges);
    }

    for (int index = 0; index < numberOfJudges; ++index) {
        printf("Enter score for judge %d: ", index + 1);
        scanf("%lf", &scores[index]);

        while (scores[index] < 0.0 || scores[index] > 10.0) {
            printf("Scores must be between 0.0 and 10.0. Try again: ");
            scanf("%lf", &scores[index]);
        }
    }

    highest = scores[0];
    lowest = scores[0];
    for (int index = 0; index < numberOfJudges; ++index) {
        total += scores[index];
        if (scores[index] > highest) {
            highest = scores[index];
        }
        if (scores[index] < lowest) {
            lowest = scores[index];
        }
    }

    officialScore = (total - highest - lowest) / (numberOfJudges - 2);

    printf("\nScores entered: ");
    for (int index = 0; index < numberOfJudges; ++index) {
        printf("%.1f", scores[index]);
        if (index < numberOfJudges - 1) {
            printf(" ");
        }
    }
    printf("\nHighest score: %.1f\n", highest);
    printf("Lowest score: %.1f\n", lowest);
    printf("Official score (drop high/low): %.2f\n", officialScore);

    return 0;
}
