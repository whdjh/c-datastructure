#include <stdio.h>
#include <stdlib.h>

void heap_sort(element a[], int n)
{
    int i;
    heapType *h;

    h = create();
    init(h);
    for(i = 0; i < n; i++)
        insert_max_heap(h, a[i]);
    for(i = n - 1; i >= 0; i--)
        a[i] = delete_max_heap;
    free(h);
}