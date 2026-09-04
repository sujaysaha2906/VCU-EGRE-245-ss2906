/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 3: Calculating Fare
 */

#include <stdio.h>

int main(void)
{
    const double BASE_FARE = 3.00;
    const double OFF_PEAK_RATE = 1.80;
    const double PEAK_RATE = 2.40;
    const double STUDENT_DISCOUNT = 0.10;
    const double SENIOR_DISCOUNT = 0.15;
    const double PROMO_VALUE = 5.00;
    double miles;
    int timeCategory;
    int riderType;
    int promoCode;
    double mileageRate;
    double discountRate;
    double subtotal;
    double discountAmount;
    double afterDiscount;
    double promoApplied;
    double finalTotal;

    printf("Lab #3 - Solution\n\n");
    printf("Enter miles traveled: ");
    scanf("%lf", &miles);
    printf("Enter time category (1=off-peak, 2=peak): ");
    scanf("%d", &timeCategory);
    printf("Enter rider type (1=standard, 2=student, 3=senior): ");
    scanf("%d", &riderType);
    printf("Enter promo code (0=none, 1=SAVE5): ");
    scanf("%d", &promoCode);

    if (miles < 0.0) {
        printf("Error: Miles traveled cannot be negative.\n");
        return 1;
    } else if (timeCategory != 1 && timeCategory != 2) {
        printf("Error: Time category must be 1 or 2.\n");
        return 1;
    } else if (riderType < 1 || riderType > 3) {
        printf("Error: Rider type must be 1, 2, or 3.\n");
        return 1;
    } else if (promoCode != 0 && promoCode != 1) {
        printf("Error: Promo code must be 0 or 1.\n");
        return 1;
    }

    mileageRate = timeCategory == 1 ? OFF_PEAK_RATE : PEAK_RATE;
    if (riderType == 2) {
        discountRate = STUDENT_DISCOUNT;
    } else if (riderType == 3) {
        discountRate = SENIOR_DISCOUNT;
    } else {
        discountRate = 0.0;
    }

    subtotal = BASE_FARE + miles * mileageRate;
    discountAmount = subtotal * discountRate;
    afterDiscount = subtotal - discountAmount;
    promoApplied = promoCode == 1 ? PROMO_VALUE : 0.0;
    finalTotal = afterDiscount - promoApplied;
    if (finalTotal < 0.0) {
        finalTotal = 0.0;
    }

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Discount: $%.2f\n", discountAmount);
    printf("After discount: $%.2f\n", afterDiscount);
    if (promoCode == 1) {
        printf("Promo applied: -$%.2f\n", promoApplied);
    } else {
        printf("Promo applied: None\n");
    }
    printf("Final total: $%.2f\n", finalTotal);

    return 0;
}
