#include <iostream>
//#include <stack>
#include <queue>
using namespace std;
#define maxnum 100

typedef struct node
{
    char val;
    node *link;
}node,*pnode;

typedef struct stack
{
    pnode top;
}stack,*pstack;

pstack create_nullstack()
{
    pstack plstack = (pstack)malloc(sizeof(stack));
    
    if(plstack != nullptr)
    {
        plstack->top = nullptr;
    }
    return plstack;
}

int is_emptystack(pstack plstack)
{
    return plstack->top == nullptr;
}

void push(pstack plstack, char x)
{
    pnode p = (pnode)malloc(sizeof(node));
    if(p)
    {
        p->val = x;
        p->link = plstack->top;
        plstack->top = p;
    }
}

void pop(pstack plstack)
{
    pnode p;
    if(!is_emptystack(plstack))
    {
        p = plstack->top;
        plstack->top = p->link;
        free(p);
    }
}

char top_link(pstack plstack)
{
    if(!is_emptystack(plstack))
    {
        return plstack->top->val;
    }
}



int main()
{   stack openings;
    pstack plstack = create_nullstack();

    char symbol; //
    bool is_matched = true;
    while(is_matched && cin>>symbol)
    {
        if(symbol == '{' || symbol == '(' || symbol == '[')
        push(plstack,symbol);

        if(symbol == ')' || symbol == ')' || symbol == ']')
            if(is_emptystack(plstack))
            {
                cout<<"no"<<endl;
                is_matched = false;
                break;
            }
            else
            {
                char match;
                match = top_link(plstack); //栈顶元素检查是否匹配
                pop(plstack);
                is_matched = (symbol == '}'&& match == '{')
                            ||(symbol == ')'&& match == '(')
                            ||(symbol == ']'&& match == '[');
                if(!is_matched)
                cout<<"no"<<endl;
            }
            if(cin.peek() == '\n') // 自动识别换行符，结束输入
            break;
    }
    if(!is_emptystack(plstack))
        cout<<"no"<<endl;
    else if(is_matched)
    {
        cout<<"yes"<<endl;
    }

    return 0;
}