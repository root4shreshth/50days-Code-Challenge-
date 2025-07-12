#include <stdio.h>

int jump(int *num, int numsize)
{
    if (numsize == 1)
        return 0;
    int jumps = 0;
    int max_reach = 0;
    int end = 0;
    for (int i = 0; i < numsize - 1; ++i)
    {
        if (i + num[i] > max_reach)
        {
            max_reach = i + num[i];
        }
        if (i == end)
        {
            jumps++;
            end = max_reach;
            if (end >= numsize - 1)
            {
                break;
            }
        }
    }
    return jumps;
}
int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
    }
    int result = jump(num, n);
    printf("%d\n", result);
    return 0;
}