#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void findmax(char *s, int k, char *maxnum)
{
    if (k == 0)
    {
        return;
    }

    int len = strlen(s);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[j] > s[i])
            {
                swap(&s[i], &s[j]);
                if (strcmp(s, maxnum) > 0)
                {
                    strcpy(maxnum, s);
                }
                findmax(s, k - 1, maxnum);
                swap(&s[i], &s[j]);
            }
        }
    }
}

int main()
{
    char s[11];
    int k;
    scanf("%s", s);
    scanf("%d", &k);

    char maxnum[11];
    strcpy(maxnum, s);
    findmax(s, k, maxnum);

    printf("%s\n", maxnum);
    return 0;
}