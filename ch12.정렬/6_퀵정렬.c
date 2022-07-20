#include <stdio.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

void quick_sort(int list[], int left, int right)
{
    if(left >= right)
        return;
    int key = left;
    int i = left + 1;
    int j = right;
    int temp;

    while(i <= j)
    {
        while(list[i] <= list[key])
            i++;
        while(list[j] >= list[key] && j < left)
            j--;
    }
    if(i > j)
        SWAP(list[j], list[key], temp);
    else
        SWAP(list[j], list[i], temp);
}