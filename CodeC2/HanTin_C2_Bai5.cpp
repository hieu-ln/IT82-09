// Bai 5, Chuong 2: Danh han che , ngan xep , STACK.
#include<iostream>
#include<iomanip>
using namespace std;

#define MAX 100

// 5.2
void init(int a[], int&sp)
{
	sp = -1;
}

//5.3
int isEmty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//5.4
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

// 5.5
int push(int a[], int &sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//5.6
int pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// xuat stack
void processStack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}


int main()
{
	int a[MAX];
	int choise, x, i, sp;
	system("cls");
	cout << "**** Bai 5, chuong 2: Damh sach han che ****\n";
	cout << "1.Khoi tao STACK rong\n";
	cout << "2.Them phan tu vao STACK\n";
	cout << "3.Lay phan tu ra khoi STACK\n";
	cout << "4.Kiem tra STACK co rong hay khong\n";
	cout << "5.Kiem tra STACK co day hay chua\n";
	cout << "6.Xuat DSLK DON\n";
	cout << "7.Thoat\n";
	do {
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			init(a, sp);
			cout << "Ban vua khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap giaq tri x = ";
			cin >> x;
			i = push(a,sp,x);
			cout << "STACK sau khi them la: \n";
			processStack(a,sp);
			break;
		case 3:
			i = pop(a, sp, x);
			cout << "Phan tu lay ra tu STACK la x = " << x << endl;
			cout << "STACK sau khi lay ra la: \n";
			processStack(a, sp);
			break;
		case 4:
			i = isFull(a, sp);
			if (i == 0)
			{
				cout << "STACK chua day !!\n";
			}
			else
			{
				cout << "STACK da day !!\n";
			}
			break;
		case 5:
			i = isEmty(a, sp);
			if (i == 0)
			{
				cout << "STACK khong rong !!\n";
			}
			else
			{
				cout << "STACK rong !!\n";
			}
			break;
		case 6:
			cout << "STACK hien tai: ";
			processStack(a, sp);
			break;
		case 7:
			cout << "Goodbye .............!!! \n";
		default:
			break;
		}
	} while (choise != 7);

	system("pause");
	return 0;
}