#include <stdio.h>
#include <stdlib.h>
struct Item {
    int id;
    int weight;
    int volume;
};
struct Container {
    int id;
    int remaining_capacity;
    int remaining_volume;
};
int compareItemsByWeight(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    return item2->weight - item1->weight; 
}
int compareItemsByVolume(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    return item2->volume - item1->volume;
}
void loadContainers(struct Item items[], int n, struct Container containers[], int num_containers) {
    qsort(items, n, sizeof(struct Item), compareItemsByWeight);
    for (int i = 0; i < num_containers; i++) {
        containers[i].id = i + 1;
        containers[i].remaining_capacity = 100; 
        containers[i].remaining_volume = 50;
    }
    for (int i = 0; i < n; i++) {
        struct Item item = items[i];
        int j;
        for (j = 0; j < num_containers; j++) {
            if (containers[j].remaining_capacity >= item.weight && containers[j].remaining_volume >= item.volume) {
                printf("Item %d (Weight: %d, Volume: %d) loaded into Container %d\n", item.id, item.weight, item.volume, containers[j].id);
                containers[j].remaining_capacity -= item.weight;
                containers[j].remaining_volume -= item.volume;
                break;}}
        if (j == num_containers) {
            printf("Item %d (Weight: %d, Volume: %d) cannot be loaded into any container\n", item.id, item.weight, item.volume);}}}
int main() {
    struct Item items[] = {
        {1, 20, 10},
        {2, 10, 5},
        {3, 15, 8},
        {4, 30, 20}
    };
    int n = sizeof(items) / sizeof(items[0]); 
    int num_containers = 3; 
    struct Container containers[num_containers];
    printf("Loading items into containers:\n");
    loadContainers(items, n, containers, num_containers);
    return 0;
}