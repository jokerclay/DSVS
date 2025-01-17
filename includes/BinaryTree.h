#pragma once


typedef char BiElementType;

typedef struct BiNode
{
	BiElementType c;
	struct BiNode* lchild;
	struct BiNode* rchild;
} BiNode, * BiTree;

// 队列
typedef struct tag
{
	BiTree p;               /* 树的某一个结点的地址*/
	struct tag* pnext;
} tag_t, * ptag_t;

// 创建二叉树
void CreateTree(BiTree* tree_root, BiElementType* data, int count)
{
	BiTree pnew;  /* 申请树的一个新结点 */
	ptag_t phead = NULL;
	ptag_t ptail = NULL;
	ptag_t list_pnew = NULL;
	ptag_t pcurrent = NULL;

	for (int i = 0; i < count; i++)
	{
		// calloc 申请的大小是两个参数直接相乘,并对空间初始化为 0
		/*
        	mem = calloc(_Count * _Size)
        */
		pnew = (BiTree)calloc(1, sizeof(BiNode));
		pnew->c = data[i]; // 把数据存进去

		list_pnew = (ptag_t)calloc(1, sizeof(tag_t)); // 给队列结点申请空间

		list_pnew->p = pnew; // 队列的数据域，把新建的结点存到队列的数据域

		// 如果是树的第一个结点
		if (*tree_root == NULL)
		{
			*tree_root = pnew;  // 树根指向第一个结点
			phead = list_pnew; // 第一个结点即是队列头，也是队列尾
			ptail = list_pnew;
			pcurrent = list_pnew; // pcurrent 要指向进入树的哪一个孩子作为它的父亲元素

		}
		else {
			// 让元素先入队列
			ptail->pnext = list_pnew;
			ptail = list_pnew;

			// 把 非 根结点放入树中
			// 左孩子有空位，将新建结点放入左孩子的位置
			if (pcurrent->p->lchild == NULL)
			{
				pcurrent->p->lchild = pnew;

			}
			else if (pcurrent->p->rchild == NULL) {
				// 右孩子有空位，将新建结点放入右孩子的位置
				pcurrent->p->rchild = pnew;
				// update parent node
				pcurrent = pcurrent->pnext; // 当前左右孩子都满了，parent node 应指向下一个有空位的结点

			}

		}
	}

}

/*
abcdefghij

前序遍历: 先自身，再打印左子树，再打印右子树
abdhiejcfg

中序遍历: 先打印左子树，再自身，再打印右子树
hdibjeafcg

后序遍历: 先打印左子树，再打印右子树，再打印自身
hidjebfgca

层序遍历：
*/


// 前序遍历/先序遍历/深度优先遍历
void pre_order(BiTree root)
{
	if (root != NULL)
	{
		printf("%c", root->c);
		pre_order(root->lchild);
		pre_order(root->rchild);
	}
}

// 中序遍历
void in_order(BiTree root)
{
	if (root != NULL)
	{
		in_order(root->lchild);
		printf("%c", root->c);
		in_order(root->rchild);
	}
}


// 后序遍历
void post_order(BiTree root)
{
	if (root != NULL)
	{
		post_order(root->lchild);
		post_order(root->rchild);
		printf("%c", root->c);
	}
}

// 层序遍历
#if 1



#endif