#include <stdio.h>
#include <string.h>

int main() {
    int base; 
    char results[15]; 

   
    scanf("%d", &base);
    scanf("%s", results);

    int carlsen_points = 0; // total points for Carlsen
    int chef_points = 0;    // total points for Chef

    
    for (int i = 0; i < 14; i++) {
        if (results[i] == 'C') {
            carlsen_points += 2; // if carlsen wins, he gets 2 points
        } else if (results[i] == 'N') {
            chef_points += 2;    // if chef wins, he will gets 2 points
        } else if (results[i] == 'D') {
            carlsen_points += 1; // if draw b/w both then get 1 point
            chef_points += 1;
        }
    }

    int prize; // total prize of carlsen
    
    if (carlsen_points > chef_points) {
        prize = 60 * base; 
    } else if (carlsen_points < chef_points) {
        prize = 40 * base; 
    } else {
        prize = 55 * base; 
    }

    
    printf("%d\n", prize); //pirnt carlsen's prize

    return 0;
}