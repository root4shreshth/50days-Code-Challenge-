#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void rearrange(int arr[], int n)
{

    qsort(arr, n, sizeof(int), compare);

    int max = n - 1;
    int min = 0;

    int maxelem = arr[n - 1] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[max] % maxelem) * maxelem;
            max--;
        }
        else
        {
            arr[i] += (arr[min] % maxelem) * maxelem;
            min++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / maxelem;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    rearrange(arr, n);

    return 0;
}

