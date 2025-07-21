#include <stdio.h>
#include <stdlib.h>

char x[] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
int x_size = 9;
int priority(char c) {
    for (int i = 0; i < x_size; i++) {
        if (x[i] == c) {
            return i;
        }
    }
    return -1; 
}
int compare(const void *a, const void *b) {
    char c1 = *(const char *)a;
    char c2 = *(const char *)b;
    return priority(c1) - priority(c2);
}
int main() {
    int n;
    scanf("%d", &n);    
    char *nuts = (char *)malloc(n * sizeof(char));
    char *bolts = (char *)malloc(n * sizeof(char));   
    for (int i = 0; i < n; i++) {
        scanf(" %c", &nuts[i]);
    }    
    for (int i = 0; i < n; i++) {
        scanf(" %c", &bolts[i]);
    }   
    qsort(nuts, n, sizeof(char), compare);
    qsort(bolts, n, sizeof(char), compare);    
    for (int i = 0; i < n; i++) {
        printf("%c ", nuts[i]);
    }
    printf("\n");   
    for (int i = 0; i < n; i++) {
        printf("%c ", bolts[i]);
    }
    printf("\n");   
    free(nuts);
    free(bolts);   
    return 0;
}