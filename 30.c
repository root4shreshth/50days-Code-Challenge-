#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < y) {
        printf("REPAIR\n");
    } else if (x > y) {
        printf("NEW PHONE\n");
    } else {
        printf("ANY\n");
    }
    return 0;
}
