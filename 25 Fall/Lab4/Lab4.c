#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2;
    int choice;
    
    // Step 1: Get two numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("\nEnter second number: ");
    scanf("%lf", &num2);

    // Step 2: Check logical operator rule
    if ((num1 > 0 && num2 > 0) || (num1 + num2 > 10)) {

        // Step 3: Show menu
        printf("\nChoose operation:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Modulus\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        // Step 4: Use switch for operation
        switch(choice) {
            case 1:
                printf("\n\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("\n\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("\n\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case 4:
                if (num2 != 0) {
                    printf("\n\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                } else {
                    printf("\n\nError: Cannot divide by zero.\n");
                }
                break;
            case 5:
                // Only valid if both numbers are integers and num2 != 0
                if ((floor(num1) == num1) && (floor(num2) == num2) && num2 != 0) {
                    int i1 = (int)num1;
                    int i2 = (int)num2;
                    printf("\n\nResult: %d %% %d = %d\n", i1, i2, i1 % i2);
                } else {
                    printf("\n\nError: Modulus only valid for nonzero integers.\n");
                }
                break;
            default:
                printf("\n\nInvalid choice. Please select 1–5.\n");
        }
    } else {
        printf("\n\nInvalid input: numbers must be positive or sum must be greater than 10.\n");
    }

    return 0;
}