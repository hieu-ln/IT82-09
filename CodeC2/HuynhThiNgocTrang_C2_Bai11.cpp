//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//struct node
//{
//	int info;
//	node *link;
//};
//node *front, *rear;
//void init()
//{
//	front = rear = NULL;
//}
//void Push(int x)
//{
//	node *p = new node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int Pop(int &x)
//{
//	if (front != NULL)
//	{
//		node *p = front;
//		x = p->info;
//		front = front->link;
//		if (front == NULL)
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//void process_queue()
//{
//	node *p = front;
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
//	cout << "---------- BAI TAP 11, CHUONG 2, QUEUE (HANG DOI - DSLK) ----------	" << endl;
//	cout << "1.Khoi tao QUEUE rong." << endl;
//	cout << "2.Them mot phan tu vao QUEUE." << endl;
//	cout << "3.Lay mot phan tu trong QUEUE." << endl;			// co the xem nhu xoa
//	cout << "4.Kiem tra QUEUE rong." << endl;
//	cout << "5.Xuat QUEUE." << endl;
//	cout << "6.Tam biet!." << endl;
//	do {
//		cout << "nhap muc: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << "Tao QUEUE rong thanh cong!" << endl;
//			init();
//			break;
//		case 2:
//			cout << "Nhap gia tri muon them vao: ";
//			cin >> x;
//			Push(x);
//			cout << "Queue sau khi duoc them vao:" << endl;
//			process_queue();
//			break;
//		case 3:
//			kq = Pop(x);
//			if (kq == 1)
//				cout << "Gia tri duoc lay ra la x = " << x << endl;
//			else
//				cout << "QUEUE rong, khong co ptu de lay gia tri" << endl;
//			break;
//		case 4:
//			if (isEmpty() == 1)
//				cout << "QUEUE rong" << endl;
//			else
//				cout << "QUEUE con gia tri" << endl;
//			process_queue();
//			break;
//		case 5:
//			if (isEmpty() == 1)
//				cout << "QUEUE rong" << endl;
//			else
//			{
//				cout << "Cac ptu trong QUEUE la: ";
//				process_queue();
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
