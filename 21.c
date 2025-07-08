#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *num, int start, int end) {
    while (start < end) {
        swap(&num[start], &num[end]);
        start++;
        end--;
    }
}

void nxtPerm(int *num, int numSize) {
    int pivot = -1;
    
    for (int i = numSize - 2; i >= 0; i--) {//  finding the pivot
        if (num[i] < num[i + 1]) {
            pivot = i;
            break;
        }
    }
    
    if (pivot == -1) {// array is in descending order, reverse to getting the first permutation
        
        reverse(num, 0, numSize - 1);
        return;
    }
    
    
    int swapCandidate;
    for (int i = numSize - 1; i > pivot; i--) {// finding the swap candidate
        if (num[i] > num[pivot]) {
            swapCandidate = i;
            break;
        }
    }
    
    
    swap(&num[pivot], &num[swapCandidate]);// Swaping and reverse 
    reverse(num, pivot + 1, numSize - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    nxtPerm(num, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]); //print the next permutation
    }
    printf("\n"); //print a new line after the output
    
    return 0;
}