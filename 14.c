#include <stdio.h>

int zeroes(int n)
{
    int count = 0;
    while (n >= 5)
    {
        n /= 5;
        count += n;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", zeroes(n));
    return 0;
}