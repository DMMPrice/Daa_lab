#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *array_1, int length_1)
{
    int i, j, temp;
    for (i = length_1 - 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (*(array_1 + j) > *(array_1 + j + 1))
            {
                temp = *(array_1 + j);
                *(array_1 + j) = *(array_1 + j + 1);
                *(array_1 + j + 1) = temp;
            }
        }
    }
}
void merge(int *c, int *array_1, int *array_2, int aLen, int bLen)
{
    int i = 0, j = 0;
    while (i < aLen && j < bLen)
    {
        if (array_1[i] < array_2[j])
        {
            c[i + j] = array_1[i];
            i++;
        }
        else
        {
            c[i + j] = array_2[j];
            j++;
        }
    }
    while (i < aLen)
    {
        c[i + j] = array_1[i];
        i++;
    }

    while (j < bLen)
    {
        c[i + j] = array_2[j];
        j++;
    }
}
void main()
{
    int *array_1, *array_2, *c, i, length_1, length_2, tot_length;
    printf("Enter the size of an array: ");
    scanf("%d", &length_1);
    array_1 = (int *)malloc(length_1 * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i <= length_1 - 1; i++)
    {
        scanf("%d", (array_1 + i));
    }
    bubble_sort(array_1, length_1);
    printf("Enter the size of an array: ");
    scanf("%d", &length_2);
    array_2 = (int *)malloc(length_2 * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i <= length_2 - 1; i++)
    {
        scanf("%d", (array_2 + i));
    }
    bubble_sort(array_2, length_2);
    tot_length = length_1 + length_2;
    c = (int *)malloc(tot_length * sizeof(int));
    merge(c, array_1, array_2, length_1, length_2);
    for (i = 0; i < tot_length; i++)
        printf("%d ", *(c + i));
}