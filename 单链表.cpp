#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

int main()
{
	LL*list = list_init();
	cout << "���������ݣ��ÿո�������س�������" << endl;
	ElemType val;
	do
	{
		cin >> val;
		list_insert_end(list, val);
	} while ((getchar()) != '\n');

	cout << "�����е�����:>" << endl;
	list_print(list);


	cout << "������Ԫ�ز���λ��:>";
	int location;
	cin >> location;
	cout << "����������Ԫ��:>";
	int elem;
	cin >> elem;
	list_insert(list, location, elem);
	cout << "�����е�����:>" << endl;
	list_print(list);


	cout << "��������Ҫɾ����Ԫ�ص�λ��:>" ;
	int location1;
	cin >> location1;
	list_delete(list, location1);
	cout << "�����е�����:>" << endl;
	list_print(list);

	
	cout << "��������Ҫ��ѯ��Ԫ�ص�λ��:>";
	int location2;
	cin >> location2;
	cout << "��ѯԪ��:>" << list_getdata(list, location2) << endl;

	cout << "���������޸ĵ����ݵ�λ��:>";
	int location3;
	cin >> location3;
	cout << "��������Ҫ�޸ĵ�������:>";
	int new_data;
	cin >> new_data;
	list_modify(list, location3, new_data);
	cout << "�����е�����:>" << endl;
	list_print(list);


	list_destroy(list);




	return 0;
}


