#include <string.h>
#include <stdio.h>

#define MAX_SIZE 4

int combinations(int coinPosition, int rest);

int coins[] = {25, 10, 5, 1};
int comb[MAX_SIZE];

int main(void){
    int rest;
    printf("Inform the value: ");
    scanf("%d", &rest);
    printf("All possible combinations:\n");
    combinations(0, rest);
    return 0;
}

int combinations(int coinPosition, int rest){
    if(coinPosition == MAX_SIZE - 1){
        comb[coinPosition] = rest / coins[coinPosition];
        combinations(coinPosition + 1, 0);
        return 0;
    } 
    if(coinPosition >= MAX_SIZE){
        for(int i = 0; i < MAX_SIZE; i++){
            printf("%d ", comb[i]);
        }
        printf("\n");
    } else {
        for(int i = 0; i <= rest/coins[coinPosition]; i++){
            comb[coinPosition] = i;
            combinations(coinPosition + 1, rest - (coins[coinPosition] * i));
        }
    }
}