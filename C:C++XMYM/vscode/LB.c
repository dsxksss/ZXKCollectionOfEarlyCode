#include <stdlib.h>
#include <stdio.h>
#define MOOC_NODE_H

typedef struct node
{                      //创建结点
    int value;         //每个结点的第一部分用于保存数值
    struct node *next; //第二部分是指向下一个结点的指针
} Node;

typedef struct list
{
    Node *head; //始终指向第一个结点的指针
    Node *tail; //始终指向最后一个结点的指针
} List;

void *add(List *plist, int number); //添加数值到结点
void print(List *plist);            //输出链表中的值
void found(List *fList);            //中查找指定数值
void pdelete (List *fList);          //删除指定数值

int main(void)
{
    printf("Please enter the data you need to store(-1 is to end):");
    //链表开始为空
    List list;
    list.head = NULL;
    list.tail = NULL;
    int number;
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);
        }
    } while (number != -1);
    print(&list);
    found(&list);
    pdelete (&list);
    return 0;
}
void *add(List *plist, int number)
{
    //add to linked-list
    Node *p = (Node *)(malloc(sizeof(Node))); //每读入一个数字就得制造一个结点来存储它
    p->value = number;                        //将读入的数值存储在value区
    p->next = NULL;                           //将next区置零(空指针)：链表的最后一个结点的next区必须是空指针
    //find the last number
    Node *last = plist->tail; //tail结点总是要指向最后一个结点(last结点)(在main函数开始时List的结点成员全为NULL)
    if (last)
    {
        // while (last->next){
        //     last = last->next;
        last->next = p;  //如果last存储了数值,那么将last的next就指向p，就是将p结点链接到last结点后面
        plist->tail = p; //此时tail结点就是(指向)新结点p
    }
    else
    {
        //如果last没有存储数值,那么此时只有一个结点p,那么链表的首尾结点肯定都是它了
        plist->head = p;
        plist->tail = p;
    }
}
void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    { //从头开始查找数值,只要p里面有数值，就一直找下一个结点
        printf("%d\t", p->value);
    }
    printf("\n");
}
void found(List *fList)
{
    int number;
    printf("What value do you want to find ?");
    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for (p = fList->head; p; p = p->next)
    {
        if (p->value == number)
        {
            printf("Found it!\n");
            system("pause");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("Not found it!\n");
    }
}
void pdelete (List *fList)
{
    int number;
    printf("What value do you want to delete ?");
    scanf("%d", &number);
    Node *p, *q;
    //如果要删除的结点p是第一个结点,那么q就指向了空指针(因为中间没有结点可绕)
    for (q = NULL, p = fList->head; p; q = p, p = p->next)
    {
        if (p->value == number)
        {
            if (q)
            {                      //如果q是非空指针
                q->next = p->next; //删除结点原理：要删除结点p的值.只需要让q的next指向p的next指向的结点(就是绕过结点p)
            }
            else
            {
                fList->head = p->next; //否则就让p的next指向头指针(它自己)
            }
            free(p); //绕过的结点p必须释放其内存(因为是malloc申请的)
            printf("It's been deleted !\n");
            break;
        }
    }
    //删除整个链表：因为链表malloc申请的内存块,用完必须释放
    for (p = fList->head; p; p = q)
    {                //让p指向首结点(从头开始删除),删除p之后将q复制给p：就是让p和q每次往下一个结点移动
        q = p->next; //让q指向p的下一个结点
        free(p);     //然后就可以删除p了
    }
    printf("For safety, The entire list is deleted after the program ends !");
}