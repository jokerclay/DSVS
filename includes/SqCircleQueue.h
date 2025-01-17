#pragma once

#define SqQueueMaxSize 5


typedef struct SqQueue
{
    ElemType data[SqQueueMaxSize]; // MaxSize 5 目前最多放 4 个
    int front, rear;
}SqQueue;

// 初始化队列，即让队列的头和尾都指向 0 号元素
void SqInitQueue(SqQueue& Q)
{
    Q.front = 0;
    Q.rear = 0;
}

bool SqQueueIsEmpty(SqQueue Q)
{
    if (Q.rear == Q.front) return true;
    return false;
}

bool isFull(SqQueue Q)
{
    if ((Q.rear + 1) % SqQueueMaxSize == Q.front) return true;
    return false;
}

bool SqEnQueue(SqQueue& Q, ElemType val)
{
    if (isFull(Q)) return false;

    Q.data[Q.rear] = val;

    // 大于数组最大下表，回到开头
    Q.rear = (Q.rear + 1) % SqQueueMaxSize;
    return true;
}

bool SqDeQueue(SqQueue& Q, ElemType& removed)
{
    if (SqQueueIsEmpty(Q)) return false;
    removed = Q.data[Q.front];
    Q.front = (Q.front + 1) % SqQueueMaxSize;
    return true;
}