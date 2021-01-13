#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

//������Ľ��ṹ������
struct Node
{
	ElemType data;//����������
	Node *next;//����ָ����
};

//����������ṹ������
typedef struct LinkList
{
	Node *head;//�����ͷ���ָ��
	Node *end;//�����β���ָ��
	int length;//����ĳ���
}LL;



//������Ĵ���
LL* list_init();

//���ӵ�����Ľ��
Node* node_init(ElemType val);

//������Ĵ�ӡ���
void list_print(LL* list);

//������Ĳ���Ԫ��
void list_insert_end(LL* list, ElemType val);//β�巨

void list_insert(LL*list,int index ,ElemType val );//ָ��λ�ò���

//�������ɾ��Ԫ��
void list_delete(LL*list, int index);


//��ȡ��������ָ��λ���ϵ�����
ElemType list_getdata(LL*list, int index);

//�޸�������ָ��λ�õ�����
void list_modify(LL*list, int index, ElemType val);

//�����������
void list_destroy(LL*list);




