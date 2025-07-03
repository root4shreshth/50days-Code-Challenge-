#include <stdio.h>
int main()
{
    int n, a;
    char all[50];
    int count[10] = {0};
    scanf("%d", &n);
    sprintf(all, "%d%d%d", n, n * 2, n * 3);

    for (a = 0; all[a] != '\0'; a++)
    {
        int d = all[a] - '0';
        count[d]++;
    }

    int ok = 1;
    for (a = 1; a < 9; a++)
    {
        if (count[a] != 1)
        {
            ok = 0;
            break;
        }
    }

    if (ok)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}