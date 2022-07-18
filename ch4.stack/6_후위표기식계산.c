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

int eval(char *exp)
{
    int op1, op2, value;
    int len = strlen(exp);
    char ch;

    StackType s;

    init_stack(&s);
    for(int i = 0; i < len; i++)
    {
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/')        //피연산자
        {
            value = ch - '0';                                       //아스키코드 이용
            push(&s, value);
        }
        else                                                        //연산자
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
                case '+': push(&s, op1 + op2);
                    break;
                case '-': push(&s, op1 - op2);
                    break;
                case '*': push(&s, op1 * op2);
                    break;
                case '/': push(&s, op1 / op2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main(void)
{
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}