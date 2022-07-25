#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity; //현재 크기
    int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType *s)
{
    s -> top = -1;
    s -> capacity = 1;
    s -> data = (element *)malloc(s -> capacity * sizeof(element));
}

//공백
int is_empty(StackType *s)
{
    return (s -> top == -1);
}

//포화
int is_full(StackType *s)
{
    return (s -> top == (s -> capacity - 1));
}

//삽입
void push(StackType *s, element item)
{
    if(is_full(s))
    {
        s -> capacity *= 2;
        s -> data = (element *)realloc(s -> data, s -> capacity * sizeof(element));
    }
    s -> data[++(s -> top)] = item;
}

//삭제
element pop(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return (s -> data[(s -> top)--]);
}

//확인용
element peek(StackType *s)
{
    if(is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return (s -> data[s -> top]);
}

int check_matching(const char *in)
{
    StackType s;
    char ch, open_ch;
    int n = strlen(in);
    init_stack(&s);

    for(int i = 0; i < n; i++)
    {
        ch = in[i];     //ch는 다음 문자
        switch(ch)
        {
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if(is_empty(&s))
                    return 0;
                else
                {
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') ||
                       (open_ch == '[' && ch != ']') || 
                       (open_ch == '{' && ch != '}'))
                        return 0;
                    break;  
                }
        }
    }
    if(!is_empty(&s))
        return 0;       //stack에 남아있다면 오류!
    return 1;
}

int main(void)
{
    char *p = "{ A[(i + 1)] = 0; }";
    if(check_matching(p) == 1)
        printf("%s 괄호검사성공\n", p);
    else 
        printf("%s 괄호검사실패\n", p);
    return 0;
}