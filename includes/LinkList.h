#pragma once
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;

void LinkListInit(LinkList& L)
{
	// 初始化头结点
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

void LinkListHeadInsert(LinkList& L, ElemType value)
{
	// 根据数据创建一个新结点
	LNode* new_node_ptr = (LNode*)malloc(sizeof(LNode));
	new_node_ptr->data = value;

	// 将值从头部插入
	new_node_ptr->next = L->next;
	L->next = new_node_ptr;
}

void LinkListTailInsert(LNode*& tail_ptr, ElemType value)
{
	LNode* new_node_ptr = (LinkList)malloc(sizeof(LNode));
	new_node_ptr->data = value;

	tail_ptr->next = new_node_ptr;

	// 更新尾结点指针
	tail_ptr = new_node_ptr;
	tail_ptr->next = NULL;
}

void PrintLinkList(LinkList L)
{
	L = L->next;
	while (L) {
		printf("%4d ", L->data);
		L = L->next;
	}
	printf("\n");
}

LNode* GetByPosition(LinkList L, int position)
{
	if (position < 0) return NULL;
	if (position == 0) return L;

	int current_pos = 1;
	LNode* current_pos_ptr = L->next;

	while (current_pos != position) {
		current_pos++;
		current_pos_ptr = current_pos_ptr->next;
		if (current_pos_ptr == NULL) {
			return NULL;
		}
	}
	return current_pos_ptr;
}

LNode* GetByValue(LinkList L, ElemType value)
{
	while (L) {
		if (L->data == value) return L;

		L = L->next;
	}
	return NULL;
}

bool InsertAt(LinkList& L, int value, int position)
{
	/*int current_pos = 1;*/
	/*LNode *current_pos_ptr = L->next;*/
	/**/
	/*while (current_pos != position-1) {*/
	/*    current_pos++;*/
	/*    current_pos_ptr = current_pos_ptr->next;*/
	/*    if (current_pos_ptr) return false;*/
	/*}*/
	/*LNode * new_node_ptr = (LNode *)malloc(sizeof(LNode));*/
	/*new_node_ptr->next = current_pos_ptr->next;*/
	/*new_node_ptr->data = value;*/
	/*current_pos_ptr = new_node_ptr;*/

	LNode* prv_node = GetByPosition(L, position - 1);
	if (prv_node != NULL)
	{
		LNode* new_node_ptr = (LNode*)malloc(sizeof(LNode));
		new_node_ptr->data = value;
		new_node_ptr->next = prv_node->next;
		prv_node->next = new_node_ptr;
		return true;
	}
	return false;
}

bool RemoveAt(LinkList& L, int pos)
{
	LNode* removed_prv_node = GetByPosition(L, pos - 1);

	if (removed_prv_node != NULL)
	{
		LNode* removed_node = removed_prv_node->next;
		removed_prv_node->next = removed_node->next;
		free(removed_node);
		return true;
	}
	return false;
}