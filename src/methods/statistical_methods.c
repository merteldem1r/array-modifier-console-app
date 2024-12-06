#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int Sum(struct Array *arr) // Time: O(n)
{
    int sum = 0;

    for (int i = 0; i < arr->length; ++i)
        sum += arr->A[i];

    return sum;
}

float Avg(struct Array *arr) // Time: O(n)
{
    return (float)Sum(arr) / arr->length;
}
