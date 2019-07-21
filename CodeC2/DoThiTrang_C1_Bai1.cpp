//Bai 1, chuong 2
#include <stdio.h>
#include <iostream>
using namespace std;

//1.1 khai bao ds
#define MAX 100
int a[MAX];
int n;

//1.2 Nhap DS
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu:";
	cin >> n;
	cout << "Nhap cac phan tu:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]";
		cin >> a[i];
	}
}

//1.3 Xuat DS
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)\
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//1.4 tim phan tu
int search(int a[], int x, int n)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			return 1;
	}
	return i;
}

//1.5 Them phan tu vao cuoi DS
int insert_last(int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else return 0;
}

//1.6 Xoa phan tu cuoi DS
int Delete_last(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

//1.7 Xoa phan tu tai vi tri thu i
int Delete(int a[], int& n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}

//1.8 tim va xoa phan tu do
int SearchAndDelete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int x, i;
	int choice = 0;
	// Menu
	system("cls");
	cout << "-------------BAI TAP 1, CHUONG 2: DS DAC---------------";
	cout << "1. Nhap DS:" << endl;
	cout << "2. Xuat DS:" << endl;
	cout << "3. Tim phan tu x :" << endl;
	cout << "4. them phan tu vao cuoi DS:" << endl;
	cout << "5. Xoa phan tu cuoi DS:" << endl;
	cout << "6. Xoa phan tu vi tri i:" << endl;
	cout << "7. Tim va xoa phan tu x:" << endl;
	cout << "8. Thoat" << endl;

	do
	{
		cout << "Vui long chon so:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			input(a, n);
			cout << "Nhap DS thanh cong" << endl;
			break;
		case 2:
			cout << "DS:" << endl;
			output(a, n);
			break;
		case 3:
			cout << "vui longf nhap so can tim";
			cin >> x;

			i = search(a, n, x);
			if (i == -1)
				cout << "Khong tim thay " << x << endl;
			else
				cout << "Tim thay tai vi tri: " << i << endl;
			break;
		case 4:
			cout << "vui longf nhap so can them";
			cin >> x;

			i = insert_last(a, n, x);
			if (i == 0)
				cout << "DS da day, Khong the them " << x << endl;
			else
			{
				cout << "Da them phan tu: " << i << "vao cuoi DS" << endl;
				cout << "Ds sau khi them: ";
				output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a, n);

			if (i > 0)
			{
				cout << "xoa thanh cong" << endl;
				cout << "Ds sau khi xoa phan tu cuoi:";
				output(a, n);
			}
			else cout << "Ds rong, khong the xoa";
			break;
		case 6:
			cout << "Nhap vi tri can xoa: ";
			cin >> i;

			i = Delete(a, n, i);

			if (i == 1)
			{
				cout << "xoa thanh cong" << endl;
				cout << "Ds sau khi xoa: ";
				output(a, n);
			}
			else cout << "khong co phan tu nao de xoa";
			break;
		case 7:
			cout << "Nhap gia tri can tim: ";
			cin >> x;

			i = SearchAndDelete(a, n, x);

			if (i == 1)
			{
				cout << "xoa thanh cong phan tu " << x << endl;
				cout << "Ds sau khi xoa: ";
				output(a, n);
			}
			else cout << "khong co phan tu nao de xoa";
			break;
		case 8:
			cout << "Goodbye";
			break;
		default: break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}