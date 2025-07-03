#include <stdio.h>
#include <string.h>

int check(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[1000];
    char evenchtr[1000];
    char oddchtr[1000];
    int evenindex = 0;
    int oddindex = 0;

    scanf("%s", str);


    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i % 2 == 0)
        {
            evenchtr[evenindex] = str[i];
            evenindex++;
        }
        else
        {
            oddchtr[oddindex] = str[i];
            oddindex++;
        }
    }

    if (check(evenchtr) && check(oddchtr))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
