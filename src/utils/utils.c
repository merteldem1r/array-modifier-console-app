#include <stdio.h>
#include <stdlib.h>
#include "../include/array.h"

void displayOptions()
{
    printf("\t1: Display\t6: Get\t\t11: Avg\t\t17: Is Sorted\n");
    printf("\t2: Append\t7: Set\t\t12: Reverse\n");
    printf("\t3: Insert\t8: Max\t\t13: Left Shift\n");
    printf("\t4: Delete\t9: Min\t\t14: Right Shift\n");
    printf("\t5: Search\t10: Sum\t\t16: Rotate\n");

    printf("0: Exit");
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}