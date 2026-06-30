#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void backtrack(int n, int W, int weights[], int value[], int P[n + 1][W + 1]) {
    int w = W;
    printf("Items included in the knapsack:\n");
    for(int i = n; i >= 1; i--) { 
        if(P[i][w] > 0) { 
            if(P[i][w] != P[i - 1][w]) { 
                printf("Item %d with weight %d and value %d\n", i, weights[i], value[i]);
                w = w - weights[i];  
            }
        }
    }
}

void zeroOneKnapsack(int n, int W, int weights[], int value[]) {
    int P[n + 1][W + 1];
    for(int i = 0; i <= n; i++) { 
        for(int w = 0; w <= W; w++) { 
            if(i == 0 || w == 0) {
                P[i][w] = 0;
            } else if(weights[i] > w) {
                P[i][w] = P[i - 1][w];
            } else {          
                P[i][w] = max(value[i] + P[i - 1][w - weights[i]], P[i - 1][w]); 
            }
        }
    }
    printf("The maximum benefit is: %d\n", P[n][W]);
    backtrack(n, W, weights, value, P);
}

int main(){
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    int weights[n + 1], value[n + 1];
    for(int i = 1; i <= n; i++){
        printf("Enter weight and value of item %d: ", i);
        scanf("%d %d", &weights[i], &value[i]);
    }

    zeroOneKnapsack(n, W, weights, value);
    return 0;
}