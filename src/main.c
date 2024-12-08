#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"
#include <time.h>

int main()
{
    struct Array arr;
    int arrLength;

    // Initialize Array on HEAP
    printf("Enter size on HEAP for an array: ");
    scanf("%d", &arr.size);

    if (arr.size <= 0)
    {
        printConsoleMessage(0, "Array size must be positive");
        return 1;
    }

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter length of an array: ");
    scanf("%d", &arrLength);

    if (arrLength > arr.size)
    {
        printConsoleMessage(0, "Number of elements can not be greater than allocated array size");
        free(arr.A);
        return 1;
    }

    int isRandom = 1;
    printf("Do you want randomly filled array? 1: YES 0: NO -> ");
    scanf("%d", &isRandom);

    if (isRandom == 1)
    {
        fillRandomNumbers(arr.A, arrLength);
    }
    else if (isRandom == 0)
    {
        printf("Enter all elements: \n");
        for (int i = 0; i < arrLength; ++i)
        {
            printf("\tElement %d: ", i + 1);
            scanf("%d", &arr.A[i]);
        }
    }
    else
    {
        printConsoleMessage(0, "Invalid input passed");
        return -1;
    }

    arr.length = arrLength;
    Display(&arr);

    // Manipulatios on created Array from console
    while (1)
    {
        printf("\nChoose Options on %sArray%s:  \n", C_DATA, C_RESET);
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

            printConsoleMessage(1, "Deleted value: ");
            printf("%d\n", Delete(&arr, index));
            break;
        }
        case SEARCH:
        {
            int key;
            printf("\t\tEnter num to search: ");
            scanf("%d", &key);
            printConsoleMessage(1, "Found num at index: ");
            printf("%d\n", Search(&arr, key));
            break;
        }
        case GET:
        {
            int index;
            printf("\t\tEnter index to get: ");
            scanf("%d", &index);
            printConsoleMessage(1, "Found num: ");
            printf("%d\n", Get(&arr, index));
            break;
        }
        case SET:
        {
            int index, num;
            printf("\t\tEnter index to set: ");
            scanf("%d", &index);

            printf("\t\tEnter number to set: ");
            scanf("%d", &num);
            printConsoleMessage(1, "Number setted at index:");
            printf("Num: %d\n Index: %d\n", Set(&arr, index, num), index);
            break;
        }
        case MAX:
        {
            printConsoleMessage(1, "Max found number:");
            printf("%d\n", Max(&arr));
            break;
        }
        case MIN:
        {
            printConsoleMessage(1, "Min found number:");
            printf("%d\n", Min(&arr));
            break;
        }
        case SUM:
        {
            printConsoleMessage(1, "Sum of all elements:");
            printf("%d\n", Sum(&arr));
            break;
        }
        case AVG:
        {
            printConsoleMessage(1, "Average of all elements:");
            printf("%.2f\n", Avg(&arr));
            break;
        }
        case REVERSE:
        {
            Reverse(&arr);
            printConsoleMessage(1, "Elements reversed");
            Display(&arr);
            break;
        }
        case LEFT_SHIFT:
        {
            LeftShift(&arr);
            printConsoleMessage(1, "Elements left shifted");
            Display(&arr);
            break;
        }
        case RIGHT_SHIFT:
        {
            RightShift(&arr);
            printConsoleMessage(1, "Elements right shifted");
            Display(&arr);
            break;
        }
        case ROTATE:
        {
            int k;
            printf("\tEnter non-negative Rotate step: ");
            scanf("%d", &k);
            Rotate(&arr, k);
            printConsoleMessage(1, "Elements right rotated");
            Display(&arr);
            break;
        }
        case IS_SORTED:
        {

            if (IsSorted(&arr))
                printConsoleMessage(1, "Array is Sorted in non-descending order");
            else
                printConsoleMessage(1, "Array is NOT Sorted in non-descending order");
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