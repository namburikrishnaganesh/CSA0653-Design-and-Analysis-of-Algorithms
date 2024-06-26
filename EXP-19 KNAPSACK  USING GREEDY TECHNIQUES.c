#include <stdio.h>
struct Item {
    int value;
    int weight;
};
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItemsByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double)items[i].value / items[i].weight;
            double ratio2 = (double)items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
                swap(&items[i], &items[j]);
            }
        }
    }
}
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItemsByRatio(items, n);
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    return 0;
}