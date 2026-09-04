/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 2: Total Cost to Carpet Three Rooms
 */

#include <stdio.h>

int main(void)
{
    const double WASTE_RATE = 0.20;
    const double LABOR_RATE = 0.75;
    const double SALES_TAX_RATE = 0.045;
    double carpetPrice;
    int roomWidth;
    int roomLength;
    int roomArea;
    double carpetCost;
    double laborCost;
    double salesTax;
    double roomCost;
    double totalCost = 0.0;

    printf("Lab #2 - Solution\n\n");

    printf("Please input the carpet price per square foot, room width, and room length for room 1: ");
    scanf("%lf %d %d", &carpetPrice, &roomWidth, &roomLength);
    roomArea = roomWidth * roomLength;
    carpetCost = roomArea * (1.0 + WASTE_RATE) * carpetPrice;
    laborCost = roomArea * LABOR_RATE;
    salesTax = (carpetCost + laborCost) * SALES_TAX_RATE;
    roomCost = carpetCost + laborCost + salesTax;
    totalCost += roomCost;
    printf("Order #1\n");
    printf("Room: %d sq ft\n", roomArea);
    printf("Carpet: $%.2f\n", carpetCost);
    printf("Labor: $%.2f\n", laborCost);
    printf("Tax: $%.2f\n", salesTax);
    printf("Cost: $%.2f\n\n", roomCost);

    printf("Please input the carpet price per square foot, room width, and room length for room 2: ");
    scanf("%lf %d %d", &carpetPrice, &roomWidth, &roomLength);
    roomArea = roomWidth * roomLength;
    carpetCost = roomArea * (1.0 + WASTE_RATE) * carpetPrice;
    laborCost = roomArea * LABOR_RATE;
    salesTax = (carpetCost + laborCost) * SALES_TAX_RATE;
    roomCost = carpetCost + laborCost + salesTax;
    totalCost += roomCost;
    printf("Order #2\n");
    printf("Room: %d sq ft\n", roomArea);
    printf("Carpet: $%.2f\n", carpetCost);
    printf("Labor: $%.2f\n", laborCost);
    printf("Tax: $%.2f\n", salesTax);
    printf("Cost: $%.2f\n\n", roomCost);

    printf("Please input the carpet price per square foot, room width, and room length for room 3: ");
    scanf("%lf %d %d", &carpetPrice, &roomWidth, &roomLength);
    roomArea = roomWidth * roomLength;
    carpetCost = roomArea * (1.0 + WASTE_RATE) * carpetPrice;
    laborCost = roomArea * LABOR_RATE;
    salesTax = (carpetCost + laborCost) * SALES_TAX_RATE;
    roomCost = carpetCost + laborCost + salesTax;
    totalCost += roomCost;
    printf("Order #3\n");
    printf("Room: %d sq ft\n", roomArea);
    printf("Carpet: $%.2f\n", carpetCost);
    printf("Labor: $%.2f\n", laborCost);
    printf("Tax: $%.2f\n", salesTax);
    printf("Cost: $%.2f\n\n", roomCost);

    printf("Total Sales: $%.2f\n", totalCost);

    return 0;
}
