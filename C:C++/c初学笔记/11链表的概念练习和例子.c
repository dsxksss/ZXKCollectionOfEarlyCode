#include<stdio.h>
#include<stdlib.h>
#include"dsxk3.h"
/*
typedef struct _node {
	int valude;
	struct _node* next;
}Node;
*/

typedef struct _list {
	Node* head;
	//Node* tail;//另外一种方法，自己可以去实现一下
}List;
void add1(Node* head, int number);//函数原型声明；
void print(List* PList);//函数原型声明；

int main68(int argc,char const *argv[])
{
	List list;
	int number;
	list.head = NULL;
	do {
		scanf_s("%d", &number);
		if (number != -1)
		{
			add(&list, number);
		}
	} while (number != -1);
	print(&list);
	scanf_s("%d", &number);
	Node* p;
	int isFound = 0;
	for(p=list.head;p;p=p->next)
	{
		if (p->valude == number) 
		{
			printf("找到了\n");
			isFound = 1;
			break;
	    }
	}
	if(!isFound)
	{
		printf("没找到\n");
	}
	Node* q;
	for (q=NULL,p = list.head;p;q=p,p = p->next)
	{
		if (p->valude == number)
		{
			if (q) {
				q->next = p->next;
			}
			else{
				list.head = p->next;
			}
			free(p);
			break;
		}
	}
	for (p =list.head; p; p = q) {
		q = p->next;
		free(p);
	}

	return 0;
}
void add1(List* PList, int number) {
	//加入进链表里去；
	Node* p = (Node*)malloc(sizeof(Node));
	p->valude = number;//初始化
	p->next = NULL;//初始化
	//找到最后那个:
	Node* last = PList->head;
	if (last)
	{
		while (last->next) {
			last = last->next;
		}
		//然后接上去；
		last->next = p;
	}
	else {
		PList->head = p;
	}
}
void print(List *PList)
{
	Node* p;
	for (p = PList->head; p; p = p->next)
	{
		printf("%d\t", p->valude);
	}
	printf("\n");
}