#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

const int MAX = 100;
int a[MAX], n;

//1
void inPut(int a[], int &n)
{
	cout << "Nhap so phan tu ma ban muon nhap : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap du lieu vao phan tu a[" << i << "]: ";
		cin >> a[i];
	}

}

//2
void outPut(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}

//3
int seacher(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		if (i == n)
		{
			return -1;
		}
		i++;
	}
	return i;
}

//4
int insertLast(int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}

//5
int deleteLast(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

// 7
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}

//6
int insert(int a[], int &n, int i, int x)
{
	if (i >= 0 && i < n)
	{
		n++;
		for (int j = n - 1; j >= 0; j--)
		{
			if (j == i - 1)
			{
				a[j] = a[j - 1];
				a[j - 1] = x;
				break;
			}
			else
			{
				a[j] = a[j - 1];
			}

		}
		return 1;
	}
	return 0;
}

//8
int seacherAnhDelete(int a[], int &n, int x)
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
	int x, choise, i;
	system("cls");
	cout << " **** BAI TAP, CHUONG 1, DANH SACH DAC **** \n";
	cout << "1. Nhap danh sach.\n";
	cout << "2. Xuat danh sach.\n";
	cout << "3. Tim mot phan tu trong danh sach.\n";
	cout << "4. Them mot phan tu vao cuoi danh sach.\n";
	cout << "5. Xoa mot phan tu o cuoi danh sach.\n";
	cout << "6. Them mot phan tu o vi tri i.\n";
	cout << "7. Xoa mot phan tu o vi tri i.\n";
	cout << "8. Tim va xoa phan tu neu co ton tai trong danh sach";
	cout << "9. Thoai.\n";

	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			inPut(a, n);
			cout << "Ban da nhap thanh cong\n";
			break;

		case 2:
			cout << "Danh sach da nhap la: \n";
			outPut(a, n);
			break;

		case 3:
			cout << "Nhap phan tu muon tim: ";
			cin >> x;
			i = seacher(a, n, x);
			if (i == -1)
			{
				cout << "Khong tim thay phan tu " << x << endl;
			}
			else
			{
				cout << "Tim thay phan tu " << x << " tai vi tri thu " << i + 1 << endl;
			}
			break;

		case 4:
			cout << "Vui long nhap gia tri muon them vao cuoi danh sach: ";
			cin >> x;
			i = insertLast(a, n, x);
			if (i == 0)
			{
				cout << "Danh sach da day khong the them !\n";
			}
			else
			{
				cout << "Da them phan tu x = " << x << " vao cuoi danh sach.\n";
				cout << "Danh sach sau khi them la: \n";
				outPut(a, n);
			}
			break;

		case 5:
			i = deleteLast(a, n);
			if (i > 0)
			{
				cout << "Xoa thanh cong! \n";
				cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
				outPut(a, n);
			}
			else
			{
				cout << "Danh sach dang rong, khoong co phan tu nao!\n";
			}
			break;

		case 6:
			cout << "Vui long nhap vi tri can them: ";
			cin >> i;
			cout << "Vui long nhap gia tri muon them: ";
			cin >> x;
			i = insert(a, n, i, x);
			if (i == 1)
			{
				cout << "Them thanh cong phan tu x = " << x << endl;
				cout << "Danh sach sau khi them la: \n";
				outPut(a, n);
			}
			else
			{
				cout << "Khong tim duoc vi tri! \n";
			}
			break;

		case 7:
			cout << "Vui long nhap vi tri can xoa: ";
			cin >> i;
			i = Delete(a, n, i);
			if (i == 1)
			{
				cout << "Xoa thanh cong! \n";
				cout << "Danh sach sau khi xoa la: \n";
				outPut(a, n);
			}
			else
			{
				cout << "Khong co phan tu nao de xoa! \n";
			}
			break;

		case 8:
			cout << "Vui long nhap gia tri can xoa trong danh sach: ";
			cin >> x;
			i = seacherAnhDelete(a, n, x);
			if (i == 1)
			{
				cout << "Xoa thanh cong phan tu x = " << x << endl;
				cout << "Danh sach sau khi xoa phan tu la: \n";
				outPut(a, n);
			}
			else
			{
				cout << "Khong co phan tu nao de xoa! \n";
			}
			break;

		case 9:
			cout << "Goodbye !\n";
			break;

		default:
			break;
		}

	} while (choise != 9);


	system("pause");
	return 0;
}
