#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int* count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Cannot add more products. Maximum limit reached.\n");
        return;
    }
  
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
  
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
  
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);

    (*count)++;
  
    printf("Product added successfully.\n");
}

void displayProducts(Product products[], int count) {
    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    printf("Product List:\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
  
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("---------------------------\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}