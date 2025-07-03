#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int count;
    int first_index;
} NumberInfo;

#define hash_size 100003

int get_hash(int num)
{
    return abs(num) % hash_size;
}

int main()
{
    int n;
    printf("");
    scanf("%d", &n);

    int *numbers = (int *)malloc(n * sizeof(int));
    printf("");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    NumberInfo *hash_table = (NumberInfo *)calloc(hash_size, sizeof(NumberInfo));

    for (int i = 0; i < n; i++)
    {
        int current = numbers[i];
        int h = get_hash(current);

        while (hash_table[h].count != 0 && hash_table[h].value != current)
        {
            h = (h + 1) % hash_size;
        }

        if (hash_table[h].count == 0)
        {
            hash_table[h].value = current;
            hash_table[h].first_index = i;
        }
        hash_table[h].count++;
    }

    int answer = -1;
    int earliest_position = n;

    for (int i = 0; i < hash_size; i++)
    {
        if (hash_table[i].count == 1 && hash_table[i].first_index < earliest_position)
        {
            earliest_position = hash_table[i].first_index;
            answer = hash_table[i].value;
        }
    }

    printf("%d\n",answer);

    free(numbers);
    free(hash_table);

    return 0;
}