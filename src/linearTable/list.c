#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct list
{
  int size;
  struct node *head;
} list;

// 初始化节点
node *getNewNode(val)
{
  node *p = (node *)malloc(sizeof(node));
  p->data = val;
  p->next = NULL;
  return p;
}

// 初始化链表
list *init()
{
  list *p = (list *)malloc(sizeof(list));
  p->head = getNewNode(0);
  p->size = 0;
  return p;
}

// 删除列表
void deleteList(list *p)
{
  node *q = p->head;
  // 先释放节点，注意还有一个额外的头,从第一个节点依次删除
  for (int i = 0; i <= p->size; i++)
  {
    node *temp = q->next;
    free(q);
    q = temp;
  }
  // 再释放列表
  free(p);
}

// 插入
int insertEle(list *l, int index, int value)
{
  if (index > l->size)
  {
    printf("当前插入的节点下标不存在");
    return 0;
  }

  node *p = l->head;

  // 查找待插入的前一个节点
  for (int i = 0; i < index; i++)
  {
    p = p->next;
  }

  // 构建新节点
  node *newNode = getNewNode(value);

  // 调换指针，注意先将next确认，否则会丢失
  newNode->next = p->next;
  p->next = newNode;
  // 数量+1
  l->size++;

  return 1;
}

// 删除
int deleteEle(list *l, int index)
{

  if (l->size <= index)
  {
    printf("\n您输入的下标超过当前链表的size, 删除的元素不存在! \n");
    return 0;
  }

  node *p = l->head;

  // 查找待删除的前一个节点
  for (int i = 0; i < index; i++)
  {
    p = p->next;
  }

  // 确认删除节点
  node *deleteNode = p->next;
  // 将上一个节点的next指向删除节点的next
  p->next = deleteNode->next;
  // 释放deleteNode
  free(deleteNode);
  l->size--;
  return 1;
}

// 打印
void showList(list *l)
{
  printf("\n当前顺序表的消息内容 ============ \n");
  printf("\n----- size = %d------ \n", l->size);

  for (node *p = l->head->next; p != NULL; p = p->next)
  {
    printf("%d->", p->data);
  }
  printf("NULL\n--------------------- \n");
}

int main()
{
  // 操作次数，容量上限
  int n;
  printf("请输入要操作的次数 =====: ");
  scanf("%d", &n);
  list *l = init();

  for (int i = 0; i < n; i++)
  {
    int order, index;
    printf("请输入要操作的命令：0 ---- 插入， 1 ---- 删除 =====: ");
    scanf("%d", &order);
    // 0 index val  插入
    if (order == 0)
    {
      int val;
      printf("请输入要插入的位置及值，用空格分隔 =====: ");
      scanf("%d %d", &index, &val);
      if (index < 0)
      {
        printf("请输入合法的下标值\n");
        return 0;
      }
      insertEle(l, index, val);
    }
    // 1 index 删除
    else if (order == 1)
    {
      printf("请输入要删除的位置 =====: ");
      scanf("%d", &index);
      if (index < 0)
      {
        printf("请输入合法的下标值\n");
        return 0;
      }
      deleteEle(l, index);
    }
    showList(l);
  }

  deleteList(l);
  l = NULL;
  return 0;
}