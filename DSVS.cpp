// DSVS.cpp: 定义应用程序的入口点。
//

#include "DSVS.h"
#include "input/Inputs.c"



typedef int ElemType;





#if 1
#include "includes/SequentialList.h"
#include "includes/LinkList.h"
#include "includes/SqStack.h"
#include "includes/SqCircleQueue.h"
#endif // 0
#include "includes/BinaryTree.h"
#include "includes/LinkQueue.h"

#if 0
 // 调试二叉树层序遍历的时候打开
void level_order(BiTree root)
{
	LinkQueue Q;
	InitLinkQueue(Q);

	BiTree p;    // 存储出队的结点
	EnLinkQueue(Q, root); //把根入队

	while (!LinkQueueIsEmpty(Q))
	{
		DeLinkQueue(Q, p);
		putchar(p->c); // 等价 printf("%c", p->c);
		if (p->lchild)
		{
			EnLinkQueue(Q, p->lchild); // 左孩子不为空，就入队左孩子
		}

		if (p->rchild)
		{
			EnLinkQueue(Q, p->rchild); // 右孩子不为空，就入队右孩子
		}
	}
}


#endif // 0

int main()
{
#pragma region 你好，世界
#if 0
	/******************* 你好，世界开始 *******************/
	printf(IN_HELLO);
	/******************* 你好，世界结束 *******************/
#endif // 0
#pragma endregion


#pragma region 顺序表
#if 0
/******************* 顺序表开始 *******************/
//typedef int ElemType;  使用int 作为顺序表中的数据

	Sqlist sqlist;
	bool result = false;

	// 填充 10 个元素到顺序表 0,1,2,3,4,5,6,7,8,9
	for (int i = 0; i < 10; i++)
	{
		sqlist.data[i] = IN_10_INTS[i];
	}
	sqlist.length = 10;


	// 1. [插入操作]: 向位置 2 插入数字 69
	result = ListInsert(sqlist, 2, 69);

	if (result)
	{
		PrintSqList(sqlist);
	}
	else {
		printf("Insertion failed \n");
	}

	// 2. [移除操作]:移除在位置 1 的元素
	ElemType removed_el = 0;
	result = ListRemove(sqlist, 1, removed_el);
	if (result)
	{
		PrintSqList(sqlist);
	}
	else {
		printf("delete failed \n");
	}

	// 3. [按值查找操作]:找到元素 69 所在位置
	ElemType TryToFind = 69;
	int try_to_find_location = -1;
	try_to_find_location = LocateElement(sqlist, TryToFind);

	if (result)
	{
		printf("[INFO]>Locate element success \n");
		printf("[INFO]>Element %d at position %d \n", TryToFind, try_to_find_location);
		PrintSqList(sqlist);
	}
	else {
		printf("locate failed \n");
	}


	/******************* 顺序表结束 *******************/
#endif // 0
#pragma endregion


#pragma region 链表
#if 0
	/******************* 链表开始 *******************/
	LinkList L;

	// 1. [初始化链表](带头结点)
	LinkListInit(L);


	// 2. [尾插法] 插入元素 0,1,2,3,4,5,6,7,8,9 
	LNode* tail_ptr = L;
	for (int i = 0; i < 10; ++i)
	{
		LinkListTailInsert(tail_ptr, IN_10_INTS[i]);
	}
	PrintLinkList(L);


	// 3. [头插法] 插入元素 0,1,2,3,4,5,6,7,8,9 
	for (int i = 0; i < 10; ++i)
	{
		LinkListHeadInsert(L, IN_10_INTS[i]);
	}
	PrintLinkList(L);

	// 4. [按位查找] 查找第10 个元素 
	LNode* TryToFindAt = GetByPosition(L, 1);
	printf("[INFO]> Get Value %d at position %d\n", TryToFindAt->data, 1);


	// 5. [按值查找] 返回第一个为要找的值的结点
	LNode* TryToFindValue = GetByValue(L, 3);
	printf("[INFO]> Find Node %d, which next is %d\n", TryToFindValue->data, TryToFindValue->next->data);


	// 6. [按位置插入] 在第9个位置处插入 6699
	bool TryToInsertAt = InsertAt(L, 6699, 9);
	if (TryToInsertAt) 
	{
		PrintLinkList(L);
	}
	else
	{
		printf("[ERROR]>Failed Insert %d at position %d\n", 6699,9);
	}


	// 7. [按位置删除] 删除第10个位置的元素
	bool TryToRemoveAt = RemoveAt(L, 10);
	if (TryToRemoveAt)
	{
		PrintLinkList(L);
	}
	else
	{
		printf("[ERROR]>Failed to Rmove at position %d\n", 10);
	}


	/******************* 链表结束 *******************/
#endif // 0
#pragma endregion


#pragma region 栈
#if 0
	/******************* 栈开始 *******************/
	SqStack S;
	// 1. [初始化栈]
	InitStack(S);
	bool isEmpty;

	// 2. [判断栈空]
	isEmpty = StackIsEmpty(S);
	if (isEmpty) printf("[INFO]>Stack is empty\n");

	for (int i = 0; i < 10; i++)
	{
		// 3. [入栈]
		if (Push(S, IN_10_INTS[i]))
			printf("[INFO] Pushed data[%d]: %d\n", i, IN_10_INTS[i]);
		else
			printf("[FAILED] Push data[%d]: %d failed\n", i, IN_10_INTS[i]);
	}

	ElemType top_val = 0;

	// 4. [查看栈顶元素]
	if (Peek(S, top_val))
		printf("[INFO] peek successfully: got %d at the top of the stack.\n", top_val);
	else
		printf("[FAILED] peek failed: top_val stay with value: %d\n", top_val);

	// 5. [出栈]
	ElemType removed_val = 0;
	if (Pop(S, removed_val))
		printf("[INFO] pop successfully: removed %d at the top of the stack.\n", removed_val);
	else
		printf("[FAILED] pop failed: removed stay with value: %d\n", removed_val);

	/******************* 栈结束 *******************/
#endif // 0
#pragma endregion


#pragma region 循环顺序队列
#if 0

	/******************* 循环顺序队列开始 *******************/

	// 1. [初始化队列]
	SqQueue Q;
	SqInitQueue(Q);

	// 2. [判断队列空]
	if (SqQueueIsEmpty(Q))
	{
		printf("[INFO]: SqQueue is Empty\n");
	}
	else {
		printf("[INFO]: SqQueue is NOT Empty\n");
	}
	
	for (int i = 0; i < 10; i++)
	{
		// 3. [入队]
		if (SqEnQueue(Q, IN_10_INTS[i]))
		{
			printf("[INFO]: Inserted %d into Queue\n ", IN_10_INTS[i]);
		}
		else {
			printf("[INFO]: Insert  %d Failed into Queue\n ", IN_10_INTS[i]);
		}
	}

	int dequeue_count = 5;
	for (int i = 0; i < dequeue_count; i++)
	{
		ElemType removed_val;
		// 4. [出队]
		if (SqDeQueue(Q, removed_val))
		{
			printf("[INFO]: removed %d from Queue\n ", removed_val);
		}
		else {
			printf("[INFO]: remove  %d Failed from Queue\n ", removed_val);
		}
	}




	/******************* 循环顺序队列结束 *******************/
#endif // 0
#pragma endregion


#pragma region 循环链队列
#if 0
	/******************* 循环链队列开始 *******************/

		// 初始化队列 --> 入队 --> 出队
	LinkQueue Q;

	// 1. [初始化队列]，使用带头结点的链表
	InitLinkQueue(Q);

	// 2. [入队]
	for (int i = 0; i < 10; ++i)
	{
		EnLinkQueue(Q, IN_10_INTS[i]);
	}

	ElemType dequeued_val = 0;
	// 3. [出队]
	if (DeLinkQueue(Q, dequeued_val))
	{
		printf("Dequeue success! dequeued value %d \n", dequeued_val);
	}
	else
	{
		printf("Dequeue failed! remain %d\n", dequeued_val);
	}

	/******************* 循环链队列结束 *******************/
#endif // 0
#pragma endregion


#pragma region 二叉树
#if 1
	/******************* 二叉树开始 *******************/
	


	BiTree tree_root = NULL;
	BiElementType data[10] = {};
	for (int i = 0; i < 10; i++)
	{
		data[i] = IN_10_CHARS[i];
	}
	CreateTree(&tree_root, data, 10);

	pre_order(tree_root);
	printf("\n");

	in_order(tree_root);
	printf("\n");

	post_order(tree_root);
	printf("\n");

	// level_order(tree_root);
	

	/******************* 二叉树结束 *******************/
#endif // 0
#pragma endregion


	return 0;
}
