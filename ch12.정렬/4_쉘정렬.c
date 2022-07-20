inc_insertion_sort(int list[], int first, int last, int gap)        //gap만큼 떨어진 요소들을 삽입 정렬, 정렬의 범위는 first에서 last
{
    int i, j ,key;
    for(int i = first + last; i <= last; i += gap)
    {
        key = list[i];
        for(int j = i - gap; j >= first && key < list[j]; j -= gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for(int gap = n / 2; gap > 0; gap = gap / 2)
    {
        if((gap % 2) == 0)
            gap++;
        for(int i = 0; i < gap; i++)                //부분리스트의 갯수는 gap
            inc_insertion_sort(list, i, n - 1, gap);
    }
}