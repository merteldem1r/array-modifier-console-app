#ifndef ARRAY_H
#define ARRAY_H

struct Array
{
    int *A;
    int size;
    int length;
};

#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define SEARCH 5
#define GET 6
#define SET 7
#define MAX 8
#define MIN 9
#define SUM 10
#define AVG 11
#define REVERSE 12
#define LEFT_SHIFT 13
#define RIGHT_SHIFT 14
#define ROTATE 16
#define IS_SORTED 17
#define EXIT 0

// METHODS

// Core Operations
void Resize(struct Array *arr);
void Display(struct Array *arr);
void Append(struct Array *arr, int num);
void Insert(struct Array *arr, int index, int num);
int Delete(struct Array *arr, int index);
int Search(struct Array *arr, int key);
int Get(struct Array *arr, int index);
int Set(struct Array *arr, int index, int num);

// Search Operations
int Max(struct Array *arr);
int Min(struct Array *arr);
int IsSorted(struct Array *arr);

// Statistics Operations
float Avg(struct Array *arr);
int Sum(struct Array *arr);

// Transformations
void Reverse(struct Array *arr);
void LeftShift(struct Array *arr);
void RightShift(struct Array *arr);
void Rotate(struct Array *arr, int k);

// UTILS
void swap(int *x, int *y);
void displayOptions();

#endif
