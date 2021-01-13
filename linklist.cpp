#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"


//单链表的创建
LL* list_init()
{
	LL*temp = (LL*)malloc(sizeof(LL));
	if (temp == NULL)
	{
		return NULL;
	}
	temp->end = NULL;
	temp->head = NULL;
	temp->length = 0;
	return temp;
}

//连接单链表的结点
Node* node_init(ElemType val)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return NULL;
	}
	temp->data = val;
	temp->next = NULL;
	return temp;
}

//单链表的打印输出
void list_print(LL* list)
{

	for (Node *temp = list->head; temp != NULL; temp = temp->next)
	{
		cout << temp->data << "-->";
	}
	cout << "NULL" << endl;
}

//单链表的插入元素
void list_insert_end(LL* list, ElemType val)//尾插法
{
	if (list == NULL)//未创建链表
	{
		cout << "不存在链表，插入失败！" << endl;
	}
	if (list->head == NULL)//链表中没有元素
	{
		list->end = list->head = node_init(val);//链表的头指针和尾指针同时指向新开辟的结点
		list->length++;//链表的长度+1
	}
	else//链表中有元素
	{
		list->end->next = node_init(val);//链表中最后一个元素指向新开辟的结点
		list->end = list->end->next;//链表的尾指针指向新开辟的结点
		list->length++;//链表的长度+1
	}
}

void list_insert(LL*list, int index, ElemType val)//指定位置插入
{
	if (list == NULL)
	{
		cout << "不存在链表，插入失败！" << endl;
	}
	if (list->length + 1 < index || index < 1)
	{
		cout << "插入错误！" << endl;
	}
	if (list->head == NULL)//链表中没有元素
	{
		list->end = list->head = node_init(val);//链表的头指针和尾指针同时指向新开辟的结点
		list->length++;//链表的长度+1
	}
	if (index == 1)
	{
		Node*New = node_init(val);
		New->next = list->head;
		list->head = New;
		list->length++;
	}
	if (index == list->length + 1)
	{
		list_insert_end(list, val);
	}
	else
	{
		Node*temp = list->head;//用一个指针遍历到待插元素位置的前一个位置
		int i = 0;
		for (i = 1; i < index - 1; i++)
		{
			temp = temp->next;
		}
		Node*New = node_init(val);//创建待插入的新节点

		New->next = temp->next;//待插元素先指向插入元素后一个元素
		temp->next = New;//再让待插元素前一个元素指向待插元素

		list->length++;
	}
}
//单链表的删除元素
void list_delete(LL*list, int index)
{
	if (list == NULL)
	{
		cout << "不存在链表，删除失败" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "不存在该位置，删除失败" << endl;
	}
	if (index == 1)
	{
		Node*temp;
		temp = list->head;
		list->head = list->head->next;
		free(temp);
		list->length--;
	}
	if (index == list->length)
	{
		Node*temp1 = list->head;
		int i = 0;
		for (i = 1; i < index - 1; i++)
		{
			temp1 = temp1->next;
		}
		free(temp1->next);
		list->end = temp1;
		temp1->next = NULL;
		list->length--;
	}
	else
	{
		Node*temp1 = list->head;
		int i = 0;
		for (i = 1; i < index - 1; i++)
		{
			temp1 = temp1->next;
		}
		Node*temp2;
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		free(temp2);
		list->length--;
	}
}


//获取单链表上指定位置上的数据
ElemType list_getdata(LL*list, int index)
{
	if (list == NULL)
	{
		cout << "不存在链表，删除失败" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "不存在该位置，删除失败" << endl;
	}
	Node*temp = list->head;//用一个指针遍历到待插元素位置的前一个位置
	int i = 0;
	for (i = 1; i < index-1; i++)
	{
		temp = temp->next;
	}
	return temp->next->data;
}

//修改链表上指定位置的数据
void list_modify(LL*list, int index, ElemType val)
{
	if (list == NULL)
	{
		cout << "不存在链表，删除失败" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "不存在该位置，修改失败" << endl;
	}
	Node *temp = list->head;
	int i = 0;
	for (i = 1; i < index; i++)
	{
		temp = temp->next;
	}
	temp->data = val;

}

//单链表的销毁
void list_destroy(LL*list)
{
	if (list == NULL)
	{
		cout << "链表为空，销毁失败！" << endl;
	}
	int i = 0;
	for (i = 0; i < list->length - 1; i++)
	{
		Node*temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	free(list->end);
	list->head = NULL;
	list->length = 0;
}



