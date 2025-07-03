#include <stdio.h>

int num(int arr[], int n) {
    int total = n * (n + 1) / 2; 
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];  
    }

    return total - sum; 
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = num(arr, n);
    printf("%d\n", missing);

    return 0;
}
