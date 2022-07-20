#define BUCKETS 10
#define DIGITS 4

void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    Queuetype queues[BUCKETS];

    for(b = 0; b < BUCKETS; b++)
        init_queue(&queue[b]);
    for(d = 0; d < DIGITS; d++)
    {
        for(i = 0; i < n; i++)      //데이터들을 자리수에 따라 큐에 삽입
            enqueue(&queues[(list[i] / factor) % 10], list[i]);
        for(b = i = 0; b < BUCKETS; b++)        //버킷에서 꺼내어 list로 합친다.
        {
            while(!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
            factor *= 10;       //그다음 자리수로 가버림
        }
    }
}