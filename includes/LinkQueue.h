#pragma once
 // typedef BiTree ElemType; // ���Զ��������������ʱ���

typedef struct LinkNode {
     ElemType data;
    struct LinkNode* next;
} LinkNode;

typedef struct LinkQueue
{
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;


// ��ʼ�����У�ʹ�ô�ͷ��������
void InitLinkQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    if (Q.front != NULL) Q.front->next = NULL;
}

// ���
void EnLinkQueue(LinkQueue& Q, ElemType val)
{
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    if (new_node != NULL) {
        new_node->data = val;
        new_node->next = NULL;
    };

    // append the new_node after the queue
    Q.rear->next = new_node;
    // rear point to the new tail
    Q.rear = new_node;

}

// ����
bool DeLinkQueue(LinkQueue& Q, ElemType& removed_val)
{
    if (Q.rear == Q.front) return false;

    LinkNode* removed_node = Q.front->next;
    Q.front->next = removed_node->next;

    // ����ֻʣһ�����ʱ����㱻ɾ����Ҫ�ı� rear ��ֵ
    if (Q.rear == removed_node)
    {
        Q.rear = Q.front;
    }

    if (removed_node != NULL) {
        removed_val = removed_node->data;
    }
    free(removed_node);
    return true;
}

// �ж϶ӿ�
bool LinkQueueIsEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}


