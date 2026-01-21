#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;

} DynArr;

int main()
{
    DynArr a;
    printf("%d", a.size);
    return 0;
}