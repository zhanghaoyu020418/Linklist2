#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkList.h"

int main()
{
	LL*list = list_init();
	cout << "请输入数据（用空格隔开，回车结束）" << endl;
	ElemType val;
	do
	{
		cin >> val;
		list_insert_end(list, val);
	} while ((getchar()) != '\n');

	cout << "链表中的数据:>" << endl;
	list_print(list);


	cout << "请输入元素插入位置:>";
	int location;
	cin >> location;
	cout << "请输入插入的元素:>";
	int elem;
	cin >> elem;
	list_insert(list, location, elem);
	cout << "链表中的数据:>" << endl;
	list_print(list);


	cout << "请输入你要删除的元素的位置:>" ;
	int location1;
	cin >> location1;
	list_delete(list, location1);
	cout << "链表中的数据:>" << endl;
	list_print(list);

	
	cout << "请输入你要查询的元素的位置:>";
	int location2;
	cin >> location2;
	cout << "查询元素:>" << list_getdata(list, location2) << endl;

	cout << "请输入你修改的数据的位置:>";
	int location3;
	cin >> location3;
	cout << "请输入你要修改的新数据:>";
	int new_data;
	cin >> new_data;
	list_modify(list, location3, new_data);
	cout << "链表中的数据:>" << endl;
	list_print(list);


	list_destroy(list);




	return 0;
}


