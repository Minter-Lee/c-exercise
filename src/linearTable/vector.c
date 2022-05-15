#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
  int *data;
  int size, cap;
} vector;

// 返回值类型是 vector * 名字是 init 参数是int型 cnt
vector *init(int cnt)
{
  vector *p = (vector *)malloc(sizeof(vector));
  p->data = (int *)malloc(sizeof(int) * cnt);
  p->size = 0;
  p->cap = cnt;
  return p;
}

// 销毁
void delete_vector(vector *p)
{
  // 从末端开始销毁，先销毁 data，在销毁p
  free(p->data);
  free(p);
}

// 插入
int insert_ele(vector *v, int index, int val)
{
  // 先判定插入位置是否合理，插入位置大于V中元素数量
  if(index > v->size) {
    printf("\n当前插入位置大于顺序表size, 不可插入 \n");
    return 0;
  }

  // 已有与当前容量一致了，扩容两倍
  if(v->size == v->cap){
    v->cap *= 2;
    // 重新申请空间，并且元素内容不变，重新将指针赋值给data
    v->data = (int *)realloc(v->data, sizeof(int) * v->cap);
    printf("\n当前顺序表已满，将自动扩容两倍，扩容后上限为: %d\n", v->cap);
  }

  // 重后往前移动
  for(int i = v->size; i > index; i--) {
    v->data[i] = v->data[i-1];
  }

  // 插入值
  v->data[index] = val;

  // 数量+1
  v->size++;

  // 插入成功
  return 1;
}

// 删除
int delete_ele(vector *v, int index)
{
  if(v->size <= index) {
    printf("\n您输入的下标超过当前顺序表的size, 删除的元素不存在! \n");
    return 0;
  }

  for(int i = index; i < v->size; i++) {
    v->data[i] = v->data[i+1];
  }
  
  v->size--;
  return 1;
}

// 打印
void show_vector(vector *v)
{
  printf("\n当前顺序表的消息内容 ============ \n");
  printf("\n----- size = %d, cap = %d------ \n", v->size, v->cap);
  for (int i = 0; i < v->size; i++)
  {
    printf("%d ", v->data[i]);
  }
  printf("\n--------------------- \n");
}

// 动态顺序表，可以调整容量
int main()
{
  // 操作次数，容量上限
  int n, cnt;
  printf("请输入要操作的次数 =====: ");
  scanf("%d", &n);
  printf("请输入顺序表的上限 =====: ");
  scanf("%d", &cnt);
  vector *v = init(cnt);

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
      if(index < 0) {
        printf("请输入合法的下标值\n");
        return 0;
      }
      insert_ele(v, index, val);
    }
    // 1 index 删除
    else if (order == 1)
    {
      printf("请输入要删除的位置 =====: ");
      scanf("%d", &index);
      if(index < 0) {
        printf("请输入合法的下标值\n");
        return 0;
      }
      delete_ele(v, index);
    }
    show_vector(v);
  }

  delete_vector(v);
  v = NULL;

  return 0;
}