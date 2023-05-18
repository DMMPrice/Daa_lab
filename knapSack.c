#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item
{
    char name;
    int profit;
    int weight;
    float ratio;
} Item;

void print(Item *items, int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("ITEM %c -> profit- %d , weight- %d , ratio- %f \n", items[i].name, items[i].profit, items[i].weight, items[i].ratio);
    }
}

int merge(Item *items, int beg_index, int mid_index, int end_index)
{
    int left_array_size = mid_index - beg_index + 1;
    int right_array_size = end_index - mid_index;
    Item left_array[left_array_size], right_array[right_array_size];
    for (int i = 0; i < left_array_size; i++)
    {
        left_array[i] = items[beg_index + i];
    }
    for (int i = 0; i < right_array_size; i++)
    {
        right_array[i] = items[mid_index + 1 + i];
    }
    int a = 0, b = 0, c = beg_index;
    while (a < left_array_size && b < right_array_size)
    {
        if (left_array[a].ratio >= right_array[b].ratio)
        {
            items[c] = left_array[a];
            a++;
        }
        else
        {
            items[c] = right_array[b];
            b++;
        }
        c++;
    }
    while (a < left_array_size)
    {
        items[c] = left_array[a];
        a++;
        c++;
    }
    while (b < right_array_size)
    {
        items[c] = right_array[b];
        b++;
        c++;
    }
    return 0;
}

void merge_sort(Item *items, int beg_index, int end_index)
{
    if (beg_index < end_index)
    {
        int mid_index = (beg_index + (end_index - 1)) / 2;
        merge_sort(items, beg_index, mid_index);
        merge_sort(items, mid_index + 1, end_index);
        merge(items, beg_index, mid_index, end_index);
    }
}

float fractionalKnapsack(Item *items, int number_of_items, int bag_capacity)
{

    int cur_weight = 0;
    float final_profit = 0.0;
    char final_items = NULL;

    for (int i = 0; i < number_of_items; i++)
    {
        if (cur_weight == bag_capacity)
        {
            return final_profit;
        }
        else if (cur_weight + items[i].weight <= bag_capacity)
        {
            cur_weight += items[i].weight;
            final_profit += items[i].profit;

            printf("\nitem %c  is taken ", items[i].name);
        }
        else
        {
            int remain_weight = bag_capacity - cur_weight;
            final_profit += (items[i].profit / (float)items[i].weight) * remain_weight;
            printf("\n%f part of item %c  is taken \n", (remain_weight / (float)items[i].weight), items[i].name);
            break;
        }
    }

    return final_profit;
}

int main()
{

    system("clear");
    clock_t start_time, end_time;
    double cpu_time_used;

    int number_of_items, bag_capacity;
    printf("Enter the number of items: ");
    scanf("%d", &number_of_items);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &bag_capacity);
    printf("\n");

    Item *items = (Item *)malloc(sizeof(Item) * number_of_items);

    for (int i = 0; i < number_of_items; i++)
    {
        printf("Enter the weight of item %c: ", 'A' + i);
        scanf("%d", &items[i].weight);
        printf("Enter the profit of item %c: ", 'A' + i);
        scanf("%d", &items[i].profit);
        items[i].name = 'A' + i;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    start_time = clock();

    merge_sort(items, 0, number_of_items - 1);

    float max_profit = fractionalKnapsack(items, number_of_items, bag_capacity);
    printf("\n The maximum profit is: %f", max_profit);
    end_time = clock();

    cpu_time_used = (double)(end_time - start_time);
    printf("\n\n Time taken by the program = %f  \n", cpu_time_used);
    free(items);

    return 0;
}
