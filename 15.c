#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{ // defining the structure
    int value;
    bool is_present;
} harshsetentry;

typedef struct
{ // defining the hash set structure
    harshsetentry *entries;
    int size;
} harshset;

harshset *create_hash_set(int size)
{ // creating a function to create a hash set
    harshset *set = (harshset *)malloc(sizeof(harshset));
    set->size = size * 2;
    set->entries = (harshsetentry *)calloc(set->size, sizeof(harshsetentry));
    return set;
}

void insert_into_set(harshset *set, int value)
{ // function to insert a value into the hash set
    int index = abs(value) % set->size;
    while (set->entries[index].is_present)
    {
        if (set->entries[index].value == value)
        {
            return;
        }
        index = (index + 1) % set->size;
    }
    set->entries[index].value = value;
    set->entries[index].is_present = true;
}

bool contains_in_set(harshset *set, int value)
{ // creating a function to check if a value exists
    int index = abs(value) % set->size;
    while (set->entries[index].is_present)
    {
        if (set->entries[index].value == value)
        {
            return true;
        }
        index = (index + 1) % set->size;
    }
    return false;
}

void free_hash_set(harshset *set)
{
    free(set->entries);
    free(set);
}

int longest_consecutive_sequence(int *nums, int numsize)
{ // finding the longest consecutive sequence
    if (numsize == 0)
    {
        return 0;
    }

    harshset *numset = create_hash_set(numsize);
    for (int i = 0; i < numsize; i++)
    {
        insert_into_set(numset, nums[i]);
    }

    int maxlength = 0;

    for (int i = 0; i < numsize; i++)
    {
        int currentnum = nums[i];

        if (!contains_in_set(numset, currentnum - 1))
        {
            int currentlength = 1;

            while (contains_in_set(numset, currentnum + currentlength))
            {
                currentlength++;
            }

            if (currentlength > maxlength)
            {
                maxlength = currentlength;
            }
        }
    }

    free_hash_set(numset);
    return maxlength;
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
    printf("%d\n", longest_consecutive_sequence(arr, n));
    free(arr);
    return 0;
}