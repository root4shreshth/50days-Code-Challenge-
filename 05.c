#include <stdio.h>
int main()
{
    int n, i, j, k, count = 0;
    int arr[1000];
    int seen[1000][3];
    int triplets = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            int a = arr[i];
            int b = arr[j];

            if (a == b)
            {
                int countA = 0;
                for (int m = 0; m < n; m++)
                {
                    if (arr[m] == a)
                        countA++;
                }
                if (countA < 2)
                    continue;
            }

                int c = a + b;

                for (k = 0; k < n; k++)
                {
                    if (arr[k] == c)
                    {
                        int min = a < b ? a : b;
                        int max = a > b ? a : b;
                        int found = 0;
                        for (int t = 0; t < count; t++)
                        {
                            if (seen[t][0] == min && seen[t][1] == max && seen[t][2] == c)
                            {
                                found = 1;
                                break;
                            }
                        }

                        if (!found)
                        {
                            seen[triplets][0] = min;
                            seen[triplets][1] = max;
                            seen[triplets][2] = c;
                            triplets++;
                            count++;
                        }

                        break;
                    }
                }
            }
        }

        printf("%d\n", triplets);
        return 0;
    }