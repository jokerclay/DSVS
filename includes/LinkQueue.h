typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct LinkQueue
{
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;


// 初始化队列，使用带头结点的链表
void InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    if (Q.front != NULL) Q.front->next = NULL;
}

void EnQueue(LinkQueue& Q, ElemType val)
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

bool DeQueue(LinkQueue& Q, ElemType& removed_val)
{
    if (Q.rear == Q.front) return false;

    LinkNode* removed_node = Q.front->next;
    Q.front->next = removed_node->next;

    // 链表只剩一个结点时，结点被删除后要改变 rear 的值
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

