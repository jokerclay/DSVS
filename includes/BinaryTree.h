#pragma once


typedef char BiElementType;

typedef struct BiNode
{
	BiElementType c;
	struct BiNode* lchild;
	struct BiNode* rchild;
} BiNode, * BiTree;

// ����
typedef struct tag
{
	BiTree p;               /* ����ĳһ�����ĵ�ַ*/
	struct tag* pnext;
} tag_t, * ptag_t;

// ����������
void CreateTree(BiTree* tree_root, BiElementType* data, int count)
{
	BiTree pnew;  /* ��������һ���½�� */
	ptag_t phead = NULL;
	ptag_t ptail = NULL;
	ptag_t list_pnew = NULL;
	ptag_t pcurrent = NULL;

	for (int i = 0; i < count; i++)
	{
		// calloc ����Ĵ�С����������ֱ�����,���Կռ��ʼ��Ϊ 0
		/*
        	mem = calloc(_Count * _Size)
        */
		pnew = (BiTree)calloc(1, sizeof(BiNode));
		pnew->c = data[i]; // �����ݴ��ȥ

		list_pnew = (ptag_t)calloc(1, sizeof(tag_t)); // �����н������ռ�

		list_pnew->p = pnew; // ���е������򣬰��½��Ľ��浽���е�������

		// ��������ĵ�һ�����
		if (*tree_root == NULL)
		{
			*tree_root = pnew;  // ����ָ���һ�����
			phead = list_pnew; // ��һ����㼴�Ƕ���ͷ��Ҳ�Ƕ���β
			ptail = list_pnew;
			pcurrent = list_pnew; // pcurrent Ҫָ�����������һ��������Ϊ���ĸ���Ԫ��

		}
		else {
			// ��Ԫ���������
			ptail->pnext = list_pnew;
			ptail = list_pnew;

			// �� �� ������������
			// �����п�λ�����½����������ӵ�λ��
			if (pcurrent->p->lchild == NULL)
			{
				pcurrent->p->lchild = pnew;

			}
			else if (pcurrent->p->rchild == NULL) {
				// �Һ����п�λ�����½��������Һ��ӵ�λ��
				pcurrent->p->rchild = pnew;
				// update parent node
				pcurrent = pcurrent->pnext; // ��ǰ���Һ��Ӷ����ˣ�parent node Ӧָ����һ���п�λ�Ľ��

			}

		}
	}

}

/*
abcdefghij

ǰ�����: �������ٴ�ӡ���������ٴ�ӡ������
abdhiejcfg

�������: �ȴ�ӡ���������������ٴ�ӡ������
hdibjeafcg

�������: �ȴ�ӡ���������ٴ�ӡ���������ٴ�ӡ����
hidjebfgca

���������
*/


// ǰ�����/�������/������ȱ���
void pre_order(BiTree root)
{
	if (root != NULL)
	{
		printf("%c", root->c);
		pre_order(root->lchild);
		pre_order(root->rchild);
	}
}

// �������
void in_order(BiTree root)
{
	if (root != NULL)
	{
		in_order(root->lchild);
		printf("%c", root->c);
		in_order(root->rchild);
	}
}


// �������
void post_order(BiTree root)
{
	if (root != NULL)
	{
		post_order(root->lchild);
		post_order(root->rchild);
		printf("%c", root->c);
	}
}

// �������
#if 1



#endif