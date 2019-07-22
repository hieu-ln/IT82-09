//Chuong 2, Bai 1: DANH SACH DAC
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//Cau 1.1
int a[MAX];
int n;

//Cau 1.2
void input (int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: ";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Cau 1.3
void output (int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

}

//Cau 1.4: Tim mot phan tu trong ds
int search (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if(i == n)
			return -1;
	}
	return i;
}

//Cau 1.5: Chen mot phan tu vao cuoi ds
int insert_last (int a[], int &n, int x)
{
	if(n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;		
}

//Cau 1.6: Xoa mot phan tu cuoi ds
int Delete_last (int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;	
}

//Cau 1.7: Xoa mot phan tu tai vi tri thu i
int Delete (int a[], int &n, int i)
{
	if(i >= 0 && i < n)
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

//Cau 1.8: Tim 1 phan tu trong ds, xo phan tu do neu co
int searchAndDelete (int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if ( a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}

	}
	return 0;
			
}

int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << " -------- BAI TAP 1, CHUONG 2, DANH SACH DAC --------" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim phan tu co gia tri x trong danh sach" << endl;
	cout << "4. Them phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri i" << endl;
	cout << "7. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "8. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				input(a, n);
				cout << "Ban vua nhap danh sach thanh cong \n";
				break;
			case 2:
				cout << "Danh sach da dang nhap la: \n";
				output(a, n);
				break;
			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				i = search(a, n, x);
				if (i == -1)
					cout << "Tim khong thay phan tu co gia tri " << x << endl;
				else 
					cout << "Tim thay phan tu co gia tri x = " << x << " tai vi tri i = " << i << endl;
				break;
			case 4:
				cout << "Vui long nhap x can them vao cuoi DS: ";
				cin >> x;
				i = insert_last(a, n, x);
				if(i == 0)
					cout << "Danh sach da day, khong the them " << x << endl;
				else
				{
					cout << "Da them phan tu x = " << i << " vao cuoi danh sach." << endl;
					cout << "Danh sach sau khi them la: ";
					output(a,n);
				}
				break;
			case 5:
				i = Delete_last(a, n);
				if (i > 0)
				{
					cout << "Xoa thanh cong. " << endl;
					cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
					output(a,n);
				}
				else
					cout << "Danh sach dang rong, khong co phan tu nao." << endl;
				break;
			case 6:
				cout <<"Vui long nhap vi tri can xoa: ";
				cin >> i;
				i = Delete(a, n, i);
				if(i == 1)
				{
					cout << "Xoa thanh cong. " << endl;
					cout << "Danh sach sau khi xoa la: \n";
					output(a,n);
				}
				else
					cout << "Khong co phan tu nao de xoa." << endl;
				break;

			case 7:
				cout <<"Vui long nhap gia tri can xoa x = ";
				cin >> x;
				i = searchAndDelete(a, n, x);
				if(i == 1)
				{
					cout << "Xoa thanh cong phan tu co gia tri x = " << x << endl;
					cout << "Danh sach sau khi xoa la: \n";
					output(a,n);
				}
				else
					cout << "Khong co phan tu nao de xoa." << endl;
				break;
			case 8: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}

	}while (choice != 8);
	system ("pause");
	return 0;
}