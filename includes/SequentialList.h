

#define Maxsize 50

typedef struct {
    ElemType data[Maxsize];
    int length; // 顺序表长度
} Sqlist;

bool ListInsert(Sqlist& l, int pos, ElemType element)
{

    // santity check
    if (pos < 1 || pos > l.length + 1 || l.length == Maxsize)
        return false;
    for (int j = l.length; j >= pos; j--)
    {
        l.data[j] = l.data[j - 1];
    }

    l.data[pos - 1] = element;
    l.length++;

    return true;
}


bool ListRemove(Sqlist& l, int pos, ElemType& removed_element)
{
    // sanity check
    if (pos < 1 || pos > l.length + 1 || l.length == Maxsize)
        return false;

    // 保存要删除的值
    removed_element = l.data[pos - 1];

    for (int j = pos; j < l.length; j++) {
        l.data[j - 1] = l.data[j];
    }
    l.length--;
    return true;
}


int LocateElement(Sqlist& l, ElemType value)
{
    for (int i = 0; i < l.length; i++)
    {
        if (l.data[i] == value)
        {
            return i + 1;
        }
    }
    return 0;
}


void PrintSqList(Sqlist l)
{
    for (int i = 0; i < l.length; i++)
    {
        printf("%3d", l.data[i]);
    }
    printf("\n");
}

