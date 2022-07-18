int seq_search(int list[], int key)
{
    for(int i = 0; i < key; i++)
    {
        if(list[i] == key)
            return i;
    }
    return -1;
}