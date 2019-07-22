//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *first;
//void init()
//{
//	first = NULL;
//}
//void process_list()
//{
//	node *p = first;
//	while(p != NULL)
//	{
//		cout << setw(4) << p->info;
//		p = p->link;
//	}
//	cout << endl;
//}
//node *search(int x)
//{
//	node *p = first;
//	while(p != NULL && p->info != x)
//		p = p->link;
//	return p;
//}
//void insert_head(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
//void insert_tail(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (first == NULL)
//		first = p;
//	else
//	{
//		node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q->link = p;
//	}
//}
//int delete_head()
//{
//	if (first != NULL)
//	{
//		node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int delete_last()
//{
//	if (first != NULL)
//	{
//		node *p, *q;
//		p = first;
//		q = NULL;
//		if (p != NULL)
//			while (p->link != NULL)
//			{
//				q = p; p = p->link;
//			}
//		if (p != first)
//			q->link = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int delete_x(int y)
//{
//	node *p = NULL, *q = first;
//	while (q != NULL && q->info != y)
//	{
//		p = q;
//		q = q->link;
//	}
//	if (q != NULL)
//	{
//		if (q == first)
//			delete_head();
//		else
//		{
//			if (q->link == NULL)
//				delete_last();
//			else
//			{
//				p->link = q->link;
//				delete q;
//			}
//		}
//		return 1;
//	}
//	return 0;
//}
//void swap(int &a, int &b)
//{
//	int tam = a;
//	a = b;
//	b = tam;
//}
//void SelectionSort()
//{
//	node *min_pos;
//	for (node *p = first; p->link != NULL; p = p->link)
//	{
//		min_pos = p;
//		for (node *q = p->link; q != NULL; q = q->link)
//			if (q->info < min_pos->info)
//				min_pos = q;
//		swap(min_pos->info, p->info);
//	}
//	process_list();
//}
//void InterchangeSort()
//{
//	for (node *i = first; i->link != NULL; i = i->link)
//		for (node *j = i->link ; j != NULL; j = j->link)
//			if (j->info > i->info)
//				swap(i->info, j->info);
//	process_list();
//}
//int main()
//{
//	int choice;
//	int x, kq;
//	node *p;
//	cout << "---------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON ----------	" << endl;
//	cout << "1.Khoi tao danh sach rong." << endl;
//	cout << "2.Them phan tu vao dau danh sach." << endl;
//	cout << "3.Them phan tu vao cuoi danh sach." << endl;
//	cout << "4.xoa phan tu vao dau danh sach." << endl;
//	cout << "5.xoa phan tu vao cuoi danh sach." << endl;
//	cout << "6.xuat danh sach." << endl;
//	cout << "7.Tim mot phan tu gia tri x trong danh sach." << endl;
//	cout << "8.Tim phan tu gia tri x va xoa no neu co." << endl;
//	cout << "9.Sap xep danh DSLK don tang dan." << endl;
//	cout << "10.Sap xep danh DSLK don giam dan." << endl;
//	cout << "11.Thoat" << endl;
//	do{
//		cout << "chon muc: " << endl;
//		cin >> choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout << "ban da tao danh sach rong!" << endl;
//				break;
//			case 2:
//				/*cout << "nhap gia tri node can them vao: ";
//				cin >> x;*/
//				x = rand() % 10;
//				insert_head(x);
//				break;
//			case 3:
//				x = rand() % 10;
//				/*cout << "nhap gia tri node can them vao: ";
//				cin >> x;*/
//				insert_tail(x);
//				break;
//			case 4:
//				delete_head();
//				cout << "ds sau khi xoa: ";
//				process_list();
//				break;
//			case 5:
//				delete_last();
//				cout << "ds sau khi xoa: ";
//				process_list();
//				break;
//			case 6:
//				cout << "Cac phan tu co trong danh sach: ";
//				process_list();
//				break;
//			case 7:
//				cout << "nhap gia tri phan tu can tim: ";
//				cin >> x;
//				p = search(x);
//				if (p == NULL)
//					cout << "Khong tim thay!" << endl;
//				else
//					cout << "Tim thay!" << endl;
//				break;
//			case 8:
//				cout << "nhap node can xoa: ";
//				cin >> x;
//				kq = delete_x(x);
//				if (kq == 0)
//					cout << "khong tim thay!" << endl;
//				else
//				{
//					cout << "Danh sach sau khi xoa: ";
//					process_list();
//				}
//				break;
//			case 9:
//				cout << "danh sach sau khi duoc sap xep: " << endl;
//				SelectionSort();
//				break;
//			case 10:
//				cout << "danh sach sau khi duoc sap xep: " << endl;
//				InterchangeSort();
//				break;
//			case 11:
//				cout << "tam biet!" << endl;
//				break;
//			default:
//				cout << "nhap sai! " << endl;
//				break;
//		}	
//		//system("cls");
//	}while (choice != 11);
//	_getch();
//	return 0;
//}