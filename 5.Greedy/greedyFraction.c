#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    double ratio; // This will be calculated based on profit and weight
};
int main()
{
    int n,total_weight=0;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of items.\n");
        return 1;
    }
    struct Item items[n]; // Array of items

    int total_profit = 0;
    int capacity;

    // Input profits and weights for each item
    
    for (int i = 0; i < n; i++)
    {  
    printf("Enter the weight for item %d :",(i+1) );
        // printf("Enter the weight for item :");
        scanf("%d", &items[i].weight);
         printf("Enter the profit for item %d :",(i+1));
        scanf("%d", &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
     /*  for (int i = 0; i < n; i++)
    {
     items[i].ratio = (double)items[i].profit / items[i].weight; // Calculate ratio
     }*/
    // Input capacity of knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Output the sorted order of items
    printf("Sorted order of items based on profit-to-weight ratio:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d (Profit: %d, Weight: %d, Ratio: %.2lf)\n", i + 1, items[i].profit, items[i].weight, items[i].ratio);
    }
    printf("\n");

    // Greedy knapsack algorithm
    for (int i = 0; i < n; i++)
    {
        if (capacity > items[i].weight)
        {
            total_profit += items[i].profit;
            total_weight+=items[i].weight;
            capacity -= items[i].weight;
        }
        else
        {
            total_profit += (capacity * items[i].profit) / items[i].weight;
            total_weight+=capacity;
            break;
        }
    }
    printf("Total profit obtained: %d\n", total_profit);
     printf("total weight : %d ",total_weight);
    return 0;
}
