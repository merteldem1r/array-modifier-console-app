#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

int main()
{
    struct Array arr;
    int elemCount;

    // Initialize Array on HEAP
    printf("Enter size of an array: ");
    scanf("%d", &arr.size);

    if (arr.size <= 0)
    {
        printf("\t\t** Error: Array size must be positive\n");
        return 1;
    }

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of elements: ");
    scanf("%d", &elemCount);

    if (elemCount > arr.size)
    {
        printf("\t\t** Error: Number of elements can not be greater than allocated array size\n");
        free(arr.A);
        return 1;
    }

    printf("Enter all elements: \n");
    for (int i = 0; i < elemCount; ++i)
    {
        printf("\tElement %d: ", i + 1);
        scanf("%d", &arr.A[i]);
    }

    arr.length = elemCount;
    Display(&arr);

    // Manipulatios on created Array from console
    while (1)
    {
        printf("Choose Options on Array:  \n");
        displayOptions();

        int option;
        printf("-> ");
        scanf("%d", &option);

        switch (option)
        {
        case DISPLAY:
            Display(&arr);
            break;

        case APPEND:
        {
            printf("\t\tEnter number: ");
            int num;
            scanf("%d", &num);
            Append(&arr, num);
            break;
        }
        case INSERT:
        {
            int index, num;
            printf("\t\tEnter insert index: ");
            scanf("%d", &index);

            printf("\t\tEnter number to insert: ");
            scanf("%d", &num);

            Insert(&arr, index, num);
            break;
        }
        case DELETE:
        {
            int index;
            printf("\t\tEnter delete index: ");
            scanf("%d", &index);

            printf("-> Deleted value: %d\n", Delete(&arr, index));
            break;
        }
        case SEARCH:
        {
            int key;
            printf("\t\tEnter num to search: ");
            scanf("%d", &key);
            printf("-> Found num at index: %d\n", Search(&arr, key));
            break;
        }
        case GET:
        {
            int index;
            printf("\t\tEnter index to get: ");
            scanf("%d", &index);
            printf("-> Found num: %d\n", Get(&arr, index));
            break;
        }
        case SET:
        {
            int index, num;
            printf("\t\tEnter index to set: ");
            scanf("%d", &index);

            printf("\t\tEnter number to set: ");
            scanf("%d", &num);
            printf("-> Setted num: %d\n at index: %d\n", Set(&arr, index, num), index);
            break;
        }
        case MAX:
        {
            printf("-> Max found number: %d\n", Max(&arr));
            break;
        }
        case MIN:
        {
            printf("-> Min found number: %d\n", Min(&arr));
            break;
        }
        case SUM:
        {
            printf("-> Sum of all elements: %d\n", Sum(&arr));
            break;
        }
        case AVG:
        {
            printf("-> Average of all elements: %.2f\n", Avg(&arr));
            break;
        }
        case REVERSE:
        {
            Reverse(&arr);
            printf("-> Elements reversed: ");
            Display(&arr);
            break;
        }
        case LEFT_SHIFT:
        {
            LeftShift(&arr);
            printf("-> Elements left shifted: ");
            Display(&arr);
            break;
        }
        case RIGHT_SHIFT:
        {
            RightShift(&arr);
            printf("-> Elements right shifted: ");
            Display(&arr);
            break;
        }
        case ROTATE:
        {
            int k;
            printf("\tEnter non-negative Rotate step: ");
            scanf("%d", &k);
            Rotate(&arr, k);
            printf("-> Elements right roted for %d steps: ", k);
            Display(&arr);
            break;
        }
        case IS_SORTED:
        {

            if (IsSorted(&arr))
                printf("-> Array is Sorted in non-descending order!\n");
            else
                printf("-> Array is NOT Sorted in non-descending order!\n");

            break;
        }

        case EXIT:
            free(arr.A);
            arr.A = NULL;
            return 0;
        }
    }

    // Deallocate memory
    free(arr.A);
    arr.A = NULL;

    return 0;
}