#include <stdio.h>
#include <string.h>

int main()
{
    int n, a;
    char name[100][101];
    int max = 0;

    scanf("%d", &n);

    for (a = 0; a < n; a++)
    {
        scanf("%s", name[a]);
        int len = strlen(name[a]);
        if (len > max)
        {
            max = len;
        }
    }

    for (a = 0; a < n; a++)
    {
        int len = strlen(name[a]);
        if (len == max)
        {
            printf(" Longest name is : %s\n", name[a]);
        }
    }

    return 0;
}
