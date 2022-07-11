#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
    element *data;
    int capacity;       //현재 크기
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

//연산자의 우선순위 반환
int prec(char op)
{
    switch(op)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
    return -1;
}

//중위를 후위로
void infix_to_postfix(char *exp)
{
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for(int i = 0; i < len; i++)
    {
        ch = exp[i];
        switch(ch)
        {
            case '+': case '-': case '*': case '/':
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))))        //스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                    printf("%c", pop(&s));
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op != '(')
                {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:        //연산자일 경우
                printf("%c", ch);
                break;
        }
    }
    while(!is_empty(&s))        //스택에 저장된 연산자들 출력
        printf("%c", pop(&s));
}

int main(void)
{
    char *s = "(2+3)*4+9";
    printf("중위 %s \n", s);
    printf("후위 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}
