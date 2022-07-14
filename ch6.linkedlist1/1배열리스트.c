#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;        //리스트안의 요소들의 형태
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

//오류처리함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 초기화 함수
void init(ArrayListType *l)
{
    l -> size = 0;
}

//리스트가 비어있으면 1을 반환 그렇지 않으면 0을 반환
int is_empty(ArrayListType *l)
{
    return (l -> size == 0);
}

//리스트가 포화면 1을 반환 그렇지 않으면 0을 반환
int is_full(ArrayListType *l)
{
    return (l -> size == MAX_LIST_SIZE);
}

element get_entry(ArrayListType *l, int pos)
{
    if(pos < 0 || pos >= l -> size)
        error("위치 오류");
    return (l -> array[pos]);
}

//리스트 출력
void print_list(ArrayListType *l)
{
    for(int i = 0; i < l -> size; i++)
        printf("%d ->", l -> array[i]);
    printf("\n");
}

void insert_last(ArrayListType *l, element item)
{
    if(l -> size >= MAX_LIST_SIZE)
        error("리스트 오버플로우");
    l -> array[l -> size++] = item;
}

void insert(ArrayListType *l, int pos, element item)
{
    if(!is_full(l) && (pos >= 0) && (pos <= l -> size))
    {
        for (int i = (l -> size - 1); i >= pos; i--)
            l -> array[i + 1] = l -> array[i];
        l -> array[pos] = item;
        l -> size++;
    }
}

element delete(ArrayListType *l, int pos)
{
    element item;

    if(pos < 0 || pos >= l -> size)
        error("위치 오류");
    item = l -> array[pos];
    for(int i = pos; i < (l -> size - 1); i++)
        l -> array[i] = l -> array[i + 1];
    l -> size--;
    return item;
}

int main()
{
    ArrayListType l;

    init(&l);
    insert(&l, 0, 10); print_list(&l);
    insert(&l, 0, 20); print_list(&l);
    insert(&l, 0, 30); print_list(&l);
    insert_last(&l, 40); print_list(&l);
    delete(&l, 0); print_list(&l);
    return 0;
}