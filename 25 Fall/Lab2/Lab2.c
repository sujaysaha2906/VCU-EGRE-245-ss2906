/*
 * EGRE 245 Engineering Programming
 * Fall 2025 - Lab 2: Total Cost to Paint a Wall
 */

#include <math.h>
#include <stdio.h>

int main(void)
{
    const double COVERAGE_PER_GALLON = 350.0;
    const double SALES_TAX_RATE = 0.045;
    double wallHeight;
    int wallWidth;
    double paintCostPerGallon;
    double wallArea;
    double paintNeeded;
    int cansNeeded;
    double paintCost;
    double salesTax;
    double totalCost;

    printf("Lab #2 - Solution\n");
    printf("EGRE 245 Engineering Programming Using C Lab #2 Cost to Paint a Wall\n\n");

    printf("Input Wall Height: ");
    scanf("%lf", &wallHeight);
    printf("Input Wall Width: ");
    scanf("%d", &wallWidth);
    printf("Input Paint Cost per Gallon: ");
    scanf("%lf", &paintCostPerGallon);

    wallArea = wallHeight * wallWidth;
    paintNeeded = wallArea / COVERAGE_PER_GALLON;
    cansNeeded = (int)ceil(paintNeeded);
    paintCost = cansNeeded * paintCostPerGallon;
    salesTax = paintCost * SALES_TAX_RATE;
    totalCost = paintCost + salesTax;

    printf("\nWall area: %.1f sq ft\n", wallArea);
    printf("Paint needed: %.3f gallons\n", paintNeeded);
    printf("Cans needed: %d can(s)\n", cansNeeded);
    printf("Paint cost: $%.2f\n", paintCost);
    printf("Sales tax: $%.2f\n", salesTax);
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}
