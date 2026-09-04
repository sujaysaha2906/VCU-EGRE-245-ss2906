/*
 * EGRE 245 Engineering Programming
 * Spring 2026 - Lab 8: Update Stock Item and Price
 */

#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NAME 50

typedef struct {
    char name[MAX_ITEM_NAME];
    double price;
    int quantity;
} StockItem;

StockItem updateItem(const char name[], double price, int quantity,
                     double priceChange, int quantityChange);

int main(void)
{
    StockItem item;
    StockItem updatedItem;
    double priceChange;
    int quantityChange;

    printf("Lab #8 - Solution\n\n");
    printf("Input the item name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = '\0';
    printf("Input the item price: ");
    scanf("%lf", &item.price);
    printf("Input the item quantity: ");
    scanf("%d", &item.quantity);

    printf("\nInput price increment value: ");
    scanf("%lf", &priceChange);
    printf("Input quantity increment value: ");
    scanf("%d", &quantityChange);

    updatedItem = updateItem(item.name, item.price, item.quantity,
                             priceChange, quantityChange);

    printf("\nUpdated values of item\n\n");
    printf("Name: %s\n", updatedItem.name);
    printf("Price: %.2f\n", updatedItem.price);
    printf("Quantity: %d\n", updatedItem.quantity);
    printf("\nValue of the item = %.2f\n",
           updatedItem.price * updatedItem.quantity);

    return 0;
}

StockItem updateItem(const char name[], double price, int quantity,
                     double priceChange, int quantityChange)
{
    StockItem updatedItem;

    snprintf(updatedItem.name, sizeof(updatedItem.name), "%s", name);
    updatedItem.price = price + priceChange;
    updatedItem.quantity = quantity + quantityChange;

    return updatedItem;
}
