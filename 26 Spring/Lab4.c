/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 4: Utility Tracker
 */

#include <stdio.h>

int main(void)
{
    double totalElectricity = 0.0;
    double totalWater = 0.0;
    double totalGas = 0.0;
    double usage;
    int entriesMade = 0;
    int choice = 0;

    printf("Lab #4 - Solution\n\n");

    while (choice != 5) {
        printf("1. Enter electricity usage (kWh)\n");
        printf("2. Enter water usage (gallons)\n");
        printf("3. Enter gas usage (therms)\n");
        printf("4. Display totals\n");
        printf("5. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter electricity usage: ");
                scanf("%lf", &usage);
                if (usage >= 0.0) {
                    totalElectricity += usage;
                    ++entriesMade;
                } else {
                    printf("Usage cannot be negative.\n");
                }
                break;
            case 2:
                printf("Enter water usage: ");
                scanf("%lf", &usage);
                if (usage >= 0.0) {
                    totalWater += usage;
                    ++entriesMade;
                } else {
                    printf("Usage cannot be negative.\n");
                }
                break;
            case 3:
                printf("Enter gas usage: ");
                scanf("%lf", &usage);
                if (usage >= 0.0) {
                    totalGas += usage;
                    ++entriesMade;
                } else {
                    printf("Usage cannot be negative.\n");
                }
                break;
            case 4:
                printf("\nTotals:\n");
                printf("Electricity: %.2f kWh\n", totalElectricity);
                printf("Water: %.2f gallons\n", totalWater);
                printf("Gas: %.2f therms\n", totalGas);
                printf("Entries made: %d\n", entriesMade);
                break;
            case 5:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid menu option.\n");
        }
        printf("\n");
    }

    return 0;
}
