#pragma once
#define SqStackMaxsize 5

typedef int ElemType;

typedef struct SqStack
{
    ElemType data[SqStackMaxsize];
    int top;
} SqStack;

void InitStack(SqStack& S)
{
    S.top = -1;    // indicate that stack is empty
}

bool StackIsEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;;
}

bool Push(SqStack& S, ElemType value)
{
    if (S.top < SqStackMaxsize - 1) {
        S.data[++S.top] = value; // equal to : `S.top=S.top+1;` `S.data[S.top]=value;`
        return true;
    }
    return false;
}

// get the top element of the stack
bool Peek(SqStack S, ElemType& top_value)
{
    if (StackIsEmpty(S)) {
        return false;
    }
    top_value = S.data[S.top];
    return true;
}

bool Pop(SqStack& S, ElemType& removed_value)
{
    if (StackIsEmpty(S)) {
        return false;
    }
    removed_value = S.data[S.top];
    S.top--;
    return true;
}
