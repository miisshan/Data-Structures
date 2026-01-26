#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} Stack;

void init(Stack *stk, int capacity)
{
    stk->capacity = capacity;
    stk->size = 0;
    stk->data = malloc(capacity * sizeof(int));
}
void push(Stack *stk, int element)
{
    if (stk->size == stk->capacity)
    {
        int new_capacity;
        new_capacity = stk->capacity * 2;
        int *new_data;
        new_data = malloc(new_capacity * sizeof(int));
        for (int i = 0; i < stk->size; ++i)
        {
            new_data[i] = stk->data[i];
        }
        free(stk->data);

        stk->data = new_data;
        stk->capacity = new_capacity;
    }
    stk->data[stk->size] = element;
    stk->size++;
}
int pop(Stack *stk)
{
    if (stk->size == 0)
    {
        printf("The stack is empty");
    }
    else
    {
        stk->size--;
        return stk->data[stk->size];
        }
}
int getAt(Stack *stk, int index)
{
    if (index < 0 || index >= stk->size)
    {
        printf("Index out of bounds\n");
        return -1; //
    }
    return stk->data[index];
}

int main()
{
    Stack stk;
    init(&stk, 4);
    push(&stk, 10);
    push(&stk, 20);
    printf("%d", getAt(&stk, 1));
    free(stk.data);
    getch();
    return 0;
}