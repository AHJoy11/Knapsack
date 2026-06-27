#include <stdio.h>

#define MAX_ITEMS 100

void fractionalKnapsack(double benefit[], double weight[], double amount[], double value[], int n, double W) {
    int taken[MAX_ITEMS]; 

    for (int i = 0; i < n; i++) {
        amount[i] = 0;
        taken[i] = 0;
        value[i] = benefit[i] / weight[i];  
    }

    double totalWeight = 0;  

    while (totalWeight < W) {

        int bestIndex = -1;
        double bestValue = -1;

        for (int i = 0; i < n; i++) {
            if (taken[i] == 0) {
                if (value[i] > bestValue) {
                    bestValue = value[i];
                    bestIndex = i;
                }
            }
        }

        if (bestIndex == -1) {
            break;
        }

        double spaceLeft = W - totalWeight;
        double amountToTake;

        if (weight[bestIndex] < spaceLeft) {
            amountToTake = weight[bestIndex];
        } else {
            amountToTake = spaceLeft;
        }

        amount[bestIndex] = amountToTake;
        totalWeight = totalWeight + amountToTake;
        taken[bestIndex] = 1;  
    }
}

int main(void) {
    int n;
    double benefit[MAX_ITEMS];
    double weight[MAX_ITEMS];
    double amount[MAX_ITEMS];
    double value[MAX_ITEMS];
    double W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter benefit and weight of item %d: ", i + 1);
        scanf("%lf %lf", &benefit[i], &weight[i]);
    }

    printf("Enter max weight W: ");
    scanf("%lf", &W);

    fractionalKnapsack(benefit, weight, amount, value, n, W);

    printf("\nResults:\n");
    double totalBenefit = 0;

    for (int i = 0; i < n; i++) {
        printf("Item %d: took %.2f out of %.2f (benefit = %.2f, ratio = %.2f)\n",
               i + 1, amount[i], weight[i], benefit[i], value[i]);
        totalBenefit = totalBenefit + amount[i] * value[i];
    }

    printf("Total benefit: %.2f\n", totalBenefit);

    return 0;
}