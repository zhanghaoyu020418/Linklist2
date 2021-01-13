#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"


//������Ĵ���
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

//���ӵ�����Ľ��
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

//������Ĵ�ӡ���
void list_print(LL* list)
{

	for (Node *temp = list->head; temp != NULL; temp = temp->next)
	{
		cout << temp->data << "-->";
	}
	cout << "NULL" << endl;
}

//������Ĳ���Ԫ��
void list_insert_end(LL* list, ElemType val)//β�巨
{
	if (list == NULL)//δ��������
	{
		cout << "��������������ʧ�ܣ�" << endl;
	}
	if (list->head == NULL)//������û��Ԫ��
	{
		list->end = list->head = node_init(val);//�����ͷָ���βָ��ͬʱָ���¿��ٵĽ��
		list->length++;//����ĳ���+1
	}
	else//��������Ԫ��
	{
		list->end->next = node_init(val);//���������һ��Ԫ��ָ���¿��ٵĽ��
		list->end = list->end->next;//�����βָ��ָ���¿��ٵĽ��
		list->length++;//����ĳ���+1
	}
}

void list_insert(LL*list, int index, ElemType val)//ָ��λ�ò���
{
	if (list == NULL)
	{
		cout << "��������������ʧ�ܣ�" << endl;
	}
	if (list->length + 1 < index || index < 1)
	{
		cout << "�������" << endl;
	}
	if (list->head == NULL)//������û��Ԫ��
	{
		list->end = list->head = node_init(val);//�����ͷָ���βָ��ͬʱָ���¿��ٵĽ��
		list->length++;//����ĳ���+1
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
		Node*temp = list->head;//��һ��ָ�����������Ԫ��λ�õ�ǰһ��λ��
		int i = 0;
		for (i = 1; i < index - 1; i++)
		{
			temp = temp->next;
		}
		Node*New = node_init(val);//������������½ڵ�

		New->next = temp->next;//����Ԫ����ָ�����Ԫ�غ�һ��Ԫ��
		temp->next = New;//���ô���Ԫ��ǰһ��Ԫ��ָ�����Ԫ��

		list->length++;
	}
}
//�������ɾ��Ԫ��
void list_delete(LL*list, int index)
{
	if (list == NULL)
	{
		cout << "����������ɾ��ʧ��" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "�����ڸ�λ�ã�ɾ��ʧ��" << endl;
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


//��ȡ��������ָ��λ���ϵ�����
ElemType list_getdata(LL*list, int index)
{
	if (list == NULL)
	{
		cout << "����������ɾ��ʧ��" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "�����ڸ�λ�ã�ɾ��ʧ��" << endl;
	}
	Node*temp = list->head;//��һ��ָ�����������Ԫ��λ�õ�ǰһ��λ��
	int i = 0;
	for (i = 1; i < index-1; i++)
	{
		temp = temp->next;
	}
	return temp->next->data;
}

//�޸�������ָ��λ�õ�����
void list_modify(LL*list, int index, ElemType val)
{
	if (list == NULL)
	{
		cout << "����������ɾ��ʧ��" << endl;
	}
	if (index > list->length || index < 1)
	{
		cout << "�����ڸ�λ�ã��޸�ʧ��" << endl;
	}
	Node *temp = list->head;
	int i = 0;
	for (i = 1; i < index; i++)
	{
		temp = temp->next;
	}
	temp->data = val;

}

//�����������
void list_destroy(LL*list)
{
	if (list == NULL)
	{
		cout << "����Ϊ�գ�����ʧ�ܣ�" << endl;
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



