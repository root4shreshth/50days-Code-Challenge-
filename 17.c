#include <stdio.h>
#include <string.h>

void encode(int N, char *S)
{ // function to encode the binary string

    for (int i = 0; i < N; i += 2)
    {

        char pair[3]; // extract the current pair of binary digits
        pair[0] = S[i];
        pair[1] = S[i + 1];
        pair[2] = '\0';

        if (strcmp(pair, "00") == 0)
        {
            printf("A");
        }
        else if (strcmp(pair, "01") == 0)
        {
            printf("T");
        }
        else if (strcmp(pair, "10") == 0)
        {
            printf("C");
        }
        else if (strcmp(pair, "11") == 0)
        {
            printf("G");
        }
    }
    printf("\n"); // print newline
}

int main()
{
    int N;
    char S[1001];

    // read input values
    scanf("%d", &N);
    scanf("%s", S);

    // call the encoding function
    encode(N, S);

    return 0;
}