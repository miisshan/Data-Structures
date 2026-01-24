#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynArr;

// Dynamic array : size == capacity, the whole array gets deleted and the new array of double size is created and the elements within the array is copied to it.

void init(DynArr *arr, int initialCapacity)
{
    arr->capacity = initialCapacity;
    arr->size = 0;
    arr->data = malloc(arr->capacity * sizeof(int));
}

void append(DynArr *arr, int element)
{

    if (arr->size == arr->capacity)
    {
        int new_capacity = arr->capacity * 2;
        int *new_data = malloc(new_capacity * sizeof(int));

        for (int i = 0; i < arr->size; i++)
        {
            new_data[i] = arr->data[i];
        }
        free(arr->data);
        arr->capacity = new_capacity;
        arr->data = new_data;
    }
    arr->data[arr->size] = element;
    arr->size++;
}

void pop(DynArr *arr)
{
    if (arr->size > 0)
    {
        arr->size--;
    }
}
// Array at index
int get(DynArr *arr, int index)
{
    if (index >= 0 && index < arr->size)
        return arr->data[index];
    else
        return -1; // or handle error
}

void set(DynArr *arr, int index, int element)
{
    if (index >= 0 && index < arr->size)
    {
        arr->data[index] = element;
    }
    else
    {
        printf("Error trying to insert an element");
    }
}

int main()
{
    DynArr arr;
    init(&arr, 2);
    append(&arr, 1);
    append(&arr, 2);
    append(&arr, 3);
    append(&arr, 4);

    for (int i = 0; i < arr.size; i++)
    {
        printf("%d", get(&arr, i));
    }
    free(arr.data);
    getch();
}
