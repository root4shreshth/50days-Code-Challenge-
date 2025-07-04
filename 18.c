#include <stdio.h>
#include <stdlib.h>

typedef struct // creating structure to hold the value and its frequency
{
    int value;
    int frequency;
} element;

int com_elem(const void *a, const void *b) // Comparison function
{
    element *elemA = (element *)a;
    element *elemB = (element *)b;

    if (elemA->frequency != elemB->frequency)
    {
        return elemB->frequency - elemA->frequency;
    }
    else
    {

        return elemB->value - elemA->value;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    element *elements = (element *)malloc(n * sizeof(element));
    int uniqueCount = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++)
        {
            if (elements[j].value == arr[i])
            {
                elements[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            elements[uniqueCount].value = arr[i];
            elements[uniqueCount].frequency = 1;
            uniqueCount++;
        }
    }

    qsort(elements, uniqueCount, sizeof(element), com_elem); // sorting the elements based on frequency and value

    int index = 0; // construct the sorted array
    for (int i = 0; i < uniqueCount; i++)
    {
        for (int j = 0; j < elements[i].frequency; j++)
        {
            arr[index++] = elements[i].value;
        }
    }

    for (int i = 0; i < n; i++) // print the sorted array
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(elements);

    return 0;
}