//Chuong 2, Bai 5 : DANH SACH HANH CHE, NGAN XEP, STACK
#include <stdio.h>
#include <iostream>
using namespace std;

//5.1: Khai bao cau truc Stack
#define MAX 100

//5.2: Khoi tao Stack rong
void init(int a[], int &sp)
{
	sp = -1;
}

//5.3: Kiem tra Stack rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//5.4: Kiem tra Stack day
int isFull(int a[], int sp)
{
	if (sp == MAX -1)
		return 1;
	return 0;
}

//5.5: Them mot phan tu vao Stack
int Push(int a[], int &sp, int x)
{
	if (sp < MAX -1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//5.6: Xoa mot phan tu
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//Xuat Stack 
void Process_stack(int a[], int sp)
{
	for(int i=0; i<sp+1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "---------------BAI TAP 5 , CHUONG 2-------------" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Them phan tu vao STACK" << endl;
	cout << "3. Lay phan tu ra khoi STACK" << endl;
	cout << "4. Kiem tra STACK co rong hay khong" << endl;
	cout << "5. Kiem tra STACK co day hay khong" << endl;
	cout << "6. Xuat STACK" << endl;
	cout << "7. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien:";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout << "Ban vua khoi tao STACK rong" << endl;
			break;
		case 2: 
			cout << "Vui long nhap gia tri x="; cin >> x;
			i = Push(a, sp, x);
			cout << "STACK sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 3: 
			i = Pop(a, sp, x);
			cout << "Phan tu lay ra tu STACK la x=" << x << endl;
			cout << "STACK sau khi lay ra la: ";
			Process_stack(a, sp);
			break;
		case 4:
			i = isFull(a, sp);
			if(i == 0)
				cout << "STACK chua day! " << x << endl;
			else
				cout << "STACK da day!" << endl;
			break;
		case 5: 
			i = isEmpty(a, sp);
			if(i == 0)
				cout <<"STACK khong rong" << endl;
			else 
				cout <<"STACK rong!" << endl;
			break;
		case 6: 
			cout << "STACK hien tai la: ";
			Process_stack(a, sp);
			break;
		case 7:
			cout << "GOODBYE ......!" << endl;
			break;
		default:
			break;
		}
	}while (choice != 7);
	system ("pause");
	return 0;
}