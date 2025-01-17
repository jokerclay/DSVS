#pragma once

#define SqQueueMaxSize 5


typedef struct SqQueue
{
    ElemType data[SqQueueMaxSize]; // MaxSize 5 Ŀǰ���� 4 ��
    int front, rear;
}SqQueue;

// ��ʼ�����У����ö��е�ͷ��β��ָ�� 0 ��Ԫ��
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

    // ������������±��ص���ͷ
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