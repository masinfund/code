#include <iostream>
using namespace std;
#define N 1000

class Solution
{
  public:
    int getline(char *line, int max);
    int strindex(char *source, char *searchfor);
    //找到所有与模式匹配的行然后打印出来
    // const char pattern[] = "ould" ; /*待查找的模式*/
};

// getline
int Solution::getline(char *line, int max)
{
    // 将行保存到s中，并返回该行的长度
    int c, i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i] = '\0';
    return i;
}

int Solution::strindex(char *s, char *t)
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

class A
{
  public:
    A() : i(10) {}
    virtual void f() { cout << "A::f() " << i << endl; };
    int i;
};

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} LiStack;

void InitStack(LiStack *s)
{
    s->data = 0;
    s->next = NULL;
}

void Push(LiStack *s, ElemType item)
{
    LiStack *tmp;
    tmp = (LiStack *)malloc(sizeof(LiStack));
    if (!tmp)
        return;
    tmp->data = item;
    tmp->next = s->next;
    s->next = tmp;
    s->data++;
    tmp = NULL;
}

ElemType Pop(LiStack *s)
{
    if (!s)
        exit(EXIT_FAILURE);
    if (!s->next)
    {
        printf("underflow");
        exit(EXIT_FAILURE);
    }
    LiStack *tmp = s->next;
    ElemType num = tmp->data;
    s->next = tmp->next;
    free(tmp);
    s->data--;

    return num;
}

int Isempty(LiStack *s)
{
    if (!s)
        return 0;
    return s->next == NULL;
}

void Destroy(LiStack *s)
{
    if (!s)
        return;
    LiStack *tmp = s->next;
    while (tmp)
    {
        s->next = tmp->next;
        free(tmp);
        if (!s->next)
            break;
        tmp = s->next;
    }
    s->data = 0;
    tmp = s = NULL;
}

ElemType *top(LiStack *s)
{
    if (!s || !s->next)
        return NULL;
    return &s->next->data;
}

int priority(LiStack *s, int ch)
{
    int *tmp = top(s);
    if (!tmp)
    {
        return -1;
    }
    switch (ch)
    {
    case '+':
    case '-':
        if (*tmp == '+' || *tmp == '-')
            return 0;
        else
            return 1;
        break;
    case '*':
    case '/':
    case '%':
        if (*tmp == '*' || *tmp == '/' || *tmp == '%')
            return 1;
        else
            return -1;
        break;
    case '(':
        return -1;
        break;
    case ')':
        return 2;
        break;
    default:
        return -1;
        //sprintf(stderr, "character match wrong ! ") ;
        break;
    }
}
int main(int argc, char const *argv[])
{
    // char line[N] ;
    // Solution find ;
    // int found = 0 ;
    // while(find.getline(line , N) > 0)
    //     if(find.strindex(line ,find.pattern) >= 0) {
    //         cout << line << '\n' ;
    //         ++found ;
    //     }
    // cout << endl ;
    LiStack s, s1;
    //stack test
    InitStack(&s);
    InitStack(&s1);
    for (int i = 1; i <= 4; ++i)
    {
        Push(&s, i);
    }
    while (!Isempty(&s))
    {
        printf("%d ", Pop(&s));
    }
    puts("");

    //中转后
    char ch;
    while (scanf(" %c", &ch) != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            Push(&s1, ch);
            continue;
        }
        else
        {
            Push(&s1, ' ');
            switch (priority(&s, ch))
            {
            case -1:
                Push(&s, ch);
                break;
            case 0:
                Push(&s1, Pop(&s));
                Push(&s1, ' ');
                Push(&s, ch);
                break;
            case 1:
                Push(&s1, Pop(&s));
                while (priority(&s, ch) == 0)
                {
                    Push(&s1, ' ');
                    Push(&s1, Pop(&s));
                }
                Push(&s1, ' ');
                Push(&s, ch);
                break;
            case 2:
                while (*top(&s) != '(')
                {
                    Push(&s1, Pop(&s));
                }
                Pop(&s);
                break;
            default:
                break;
            }
        }
    }
    while (!Isempty(&s))
    {
        Push(&s1, Pop(&s));
    }
    while (!Isempty(&s1))
    {
        Push(&s, Pop(&s1));
    }

    // calculator
    int tmp = 0, sum = 0, a = 0, flag = 0;
    if (*top(&s) == ' ')
        Pop(&s);
    while (!Isempty(&s))
    {
        printf("%c", tmp = Pop(&s));
        while (tmp >= '0' && tmp <= '9')
        {
            if (!flag)
            {
                sum *= 10;
                sum += tmp - '0';
            }
            else
            {
                a *= 10;
                a += tmp - '0';
                flag = 2;
            }
            printf("%c", tmp = Pop(&s));
        }
        if (flag == 2)
        {
            flag = 1;
            Push(&s1, a);
            a = 0;
        }
        if (tmp == ' ' && !flag)
        {
            flag = 1;
            Push(&s1, sum);
            sum = 0;
        }
        if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/')
        {
            a = Pop(&s1);
            sum = Pop(&s1);
            switch (tmp)
            {
            case '+':
                sum += a;
                a = 0;
                break;
            case '-':
                sum -= a;
                a = 0;
                break;
            case '*':
                sum *= a;
                a = 0;
                break;
            case '/':
                sum /= a;
                a = 0;
                break;
            }
            Push(&s1, sum);
        }
    }
    sum = Pop(&s1);
    printf("\nthe operation is %d.\n", sum);

    Destroy(&s);
    Destroy(&s1);

    getchar();
    return 0;
}
