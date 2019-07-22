//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//# define MAX 100
//void init(int A[], int &sp)
//{
//	sp = -1;
//}
//int push(int A[], int &sp, int x)	// them phan tu vao stack (push)
//{
//	if (sp < MAX - 1)
//	{
//		A[++sp] = x;
//		return 1;
//	}
//	return 0;
//}
//int pop(int A[], int &sp, int &x)	// lay mot phan tu trong stack (pop)
//{
//	if (sp != 1)		// khi stack khac rong
//	{
//		x = A[sp--];
//		return 1;
//	}
//	return 0;
//}
//int isfull(int A[], int sp)			// kiem tra stack day (isfull)
//{
//	if (sp == MAX - 1)
//		return 1;
//	return 0;
//}
//int isEmpty(int A[], int sp)		// ham kiem tra stack rong (isEMpty)
//{
//	if (sp == -1)
//		return 1;
//	return 0;
//}
//void process_stack(int A[], int sp)
//{
//	for (int i = 0; i < sp + 1; i++)
//	{
//		cout << setw(4) << A[i];
//	}
//	cout << endl;
//}
//int main()
//{
//	int choice, x, kq, A[MAX], sp;
//	cout << "---------- BAI TAP 5, CHUONG 2, STACK (NGAN XEP - DS DAC) ----------	" << endl;
//	cout << "1.Khoi tao stack rong." << endl;
//	cout << "2.Them mot phan tu vao stack." << endl;
//	cout << "3.Lay mot phan tu trong stack." << endl;			// co the xem nhu xoa
//	cout << "4.Kiem tra stack day." << endl;
//	cout << "5.Kiem tra stack rong." << endl;
//	cout << "6.Xuat stack." << endl;
//	cout << "7.Tam biet!." << endl;
//	do {
//		cout << "Chon muc: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(A, sp);
//			cout << "ban da tao stack rong thanh cong!" << endl;
//			break;
//		case 2:
//			cout << "nhap gia tri ban muon them vao: ";
//			cin >> x;
//			push(A, sp, x);
//			cout << "Stack sau khi them la:" << endl;
//			process_stack(A, sp);
//			break;
//		case 3:
//			kq = pop(A, sp, x);
//			if (kq == 0)
//				cout << "khong co gia tri de lay ra!" << endl;
//			else
//				cout << "gia tri duoc lay ra: " << x << endl;
//			break;
//		case 4:
//			if (isfull(A, sp) == 1)
//				cout << "stack day" << endl;
//			else
//				cout << "stack chua day" << endl;
//			break;
//		case 5:
//			if (isEmpty(A, sp) == 1)
//				cout << "stack rong" << endl;
//			else
//				cout << "stack chua rong" << endl;
//			break;
//		case 6:
//			cout << "ds hien tai la: ";
//			process_stack(A,sp);
//			break;
//		case 7:
//			cout << "Tam biet!" << endl;
//			break;
//		default:
//			cout << "Nhap sai, nhap lai" << endl;
//			break;
//		}
//	} while (choice != 7);
//	_getch();
//	return 0;
//}