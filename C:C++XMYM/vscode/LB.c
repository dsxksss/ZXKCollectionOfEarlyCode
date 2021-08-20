#include <stdlib.h>
#include <stdio.h>
#define MOOC_NODE_H

typedef struct node
{                      //�������
    int value;         //ÿ�����ĵ�һ�������ڱ�����ֵ
    struct node *next; //�ڶ�������ָ����һ������ָ��
} Node;

typedef struct list
{
    Node *head; //ʼ��ָ���һ������ָ��
    Node *tail; //ʼ��ָ�����һ������ָ��
} List;

void *add(List *plist, int number); //�����ֵ�����
void print(List *plist);            //��������е�ֵ
void found(List *fList);            //�в���ָ����ֵ
void pdelete (List *fList);          //ɾ��ָ����ֵ

int main(void)
{
    printf("Please enter the data you need to store(-1 is to end):");
    //����ʼΪ��
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
    Node *p = (Node *)(malloc(sizeof(Node))); //ÿ����һ�����־͵�����һ��������洢��
    p->value = number;                        //���������ֵ�洢��value��
    p->next = NULL;                           //��next������(��ָ��)����������һ������next�������ǿ�ָ��
    //find the last number
    Node *last = plist->tail; //tail�������Ҫָ�����һ�����(last���)(��main������ʼʱList�Ľ���ԱȫΪNULL)
    if (last)
    {
        // while (last->next){
        //     last = last->next;
        last->next = p;  //���last�洢����ֵ,��ô��last��next��ָ��p�����ǽ�p������ӵ�last������
        plist->tail = p; //��ʱtail������(ָ��)�½��p
    }
    else
    {
        //���lastû�д洢��ֵ,��ô��ʱֻ��һ�����p,��ô�������β���϶���������
        plist->head = p;
        plist->tail = p;
    }
}
void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    { //��ͷ��ʼ������ֵ,ֻҪp��������ֵ����һֱ����һ�����
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
    //���Ҫɾ���Ľ��p�ǵ�һ�����,��ôq��ָ���˿�ָ��(��Ϊ�м�û�н�����)
    for (q = NULL, p = fList->head; p; q = p, p = p->next)
    {
        if (p->value == number)
        {
            if (q)
            {                      //���q�Ƿǿ�ָ��
                q->next = p->next; //ɾ�����ԭ��Ҫɾ�����p��ֵ.ֻ��Ҫ��q��nextָ��p��nextָ��Ľ��(�����ƹ����p)
            }
            else
            {
                fList->head = p->next; //�������p��nextָ��ͷָ��(���Լ�)
            }
            free(p); //�ƹ��Ľ��p�����ͷ����ڴ�(��Ϊ��malloc�����)
            printf("It's been deleted !\n");
            break;
        }
    }
    //ɾ������������Ϊ����malloc������ڴ��,��������ͷ�
    for (p = fList->head; p; p = q)
    {                //��pָ���׽��(��ͷ��ʼɾ��),ɾ��p֮��q���Ƹ�p��������p��qÿ������һ������ƶ�
        q = p->next; //��qָ��p����һ�����
        free(p);     //Ȼ��Ϳ���ɾ��p��
    }
    printf("For safety, The entire list is deleted after the program ends !");
}