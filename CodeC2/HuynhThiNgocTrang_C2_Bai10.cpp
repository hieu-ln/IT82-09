//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *sp;
//void init()
//{
//	sp = NULL;
//}
//void Push(int x)					// them pt
//{
//	node *p = new node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//int Pop(int &x)
//{
//	if (sp != NULL)
//	{
//		node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int isEmpty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//void process_stack()
//{
//	node *p = sp;
//	while (p != NULL) 
//	{
//		cout << setw(4) << p->info;
//		p = p->link;
//	}
//	cout << endl;
//}
//int main()
//{
//	int choice, x, kq;
//	cout << "---------- BAI TAP 10, CHUONG 2, STACK (NGAN XEP - DSLK) ----------	" << endl;
//	cout << "1.Khoi tao stack rong." << endl;
//	cout << "2.Them mot phan tu vao stack." << endl;
//	cout << "3.Lay mot phan tu trong stack." << endl;			// co the xem nhu xoa
//	cout << "4.Kiem tra stack rong." << endl;
//	cout << "5.Xuat stack." << endl;
//	cout << "6.Tam biet!." << endl;
//	do {
//		cout << "nhap muc: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Tao stack rong thanh cong!" << endl;
//			init();
//			break;
//		case 2:
//			cout << "Nhap gia tri muon them vao: ";
//			cin >> x;
//			Push(x);
//			cout << "Stack sau khi duoc them vao:" << endl;
//			process_stack();
//			break;
//		case 3:
//			kq = Pop(x);
//			if (kq == 1)
//				cout << "Gia tri duoc lay ra la x = " << x << endl;
//			else
//				cout << "Stack rong, khong co ptu de lay gia tri" << endl;
//			break;
//		case 4:
//			if (isEmpty() == 1)
//				cout << "Stack rong" << endl;
//			else
//				cout << "Stack con gia tri" << endl;
//			process_stack();
//			break;
//		case 5:
//			if (isEmpty() == 1)
//				cout << "Stack rong!" << endl;
//			else
//			{
//				cout << "Cac ptu trong stack la: ";
//				process_stack();
//			}
//			break;
//		case 6:
//			cout << "Tam biet!" << endl;
//			break;
//		default:
//			cout << "Nhap sai, nhap lai!" << endl;
//			break;
//		}
//	} while (choice != 6);
//	_getch();
//	return 0;
//}