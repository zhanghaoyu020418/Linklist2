#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

//单链表的结点结构的声明
struct Node
{
	ElemType data;//结点的数据域
	Node *next;//结点的指针域
};

//整个单链表结构的声明
typedef struct LinkList
{
	Node *head;//链表的头结点指针
	Node *end;//链表的尾结点指针
	int length;//链表的长度
}LL;



//单链表的创建
LL* list_init();

//连接单链表的结点
Node* node_init(ElemType val);

//单链表的打印输出
void list_print(LL* list);

//单链表的插入元素
void list_insert_end(LL* list, ElemType val);//尾插法

void list_insert(LL*list,int index ,ElemType val );//指定位置插入

//单链表的删除元素
void list_delete(LL*list, int index);


//获取单链表上指定位置上的数据
ElemType list_getdata(LL*list, int index);

//修改链表上指定位置的数据
void list_modify(LL*list, int index, ElemType val);

//单链表的销毁
void list_destroy(LL*list);




