//CHUONG 2 - BAI 16: DS LK DON
#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;

struct Node {
	int info;
	Node *link;
};


void init(Node *a) {
	a = NULL;
}

void insertFirst(Node *&a, int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = a;
	a = p;
}

void insertLast(Node *&a, int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (a == NULL)
	{
		a = p;
	}
	else
	{
		Node *q = a;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
}

int deleteFirst(Node *&a)
{
	if (a != NULL)
	{
		Node *p = a;
		a = a->link;
		delete p;
		return 1;
	}
	return 0;
}

int deleteLast(Node *&a)
{
	if (a != NULL)
	{
		Node *p, *q;
		p = a;
		q = a;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != a)
		{
			q->link = NULL;
		}
		else
		{
			a = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void processList(Node *a)
{
	//Node *p = a;
	while (a != NULL)
	{
		cout << setw(4) << a->info;
		a = a->link;
	}
	cout << endl;
}


//CAU 16.2: Xuat cac phan tu thuoc tap hop giao cua hai danh sach
void phepGiao(Node *&a1, Node *&b1)
{
	Node *at, *bt;
	at = a1;
	bt = b1;

	bool flag = false;

	while (bt != NULL)
	{
		while (at != NULL)
		{
			if (at->info == bt->info) {
				flag = true;
				cout << at->info << " ";
				at = at->link;
				break;
			}
			at = at->link;
		}
		bt = bt->link;
	}
	if (flag == false) {
		cout << "Khong co phan tu thuoc tap hop giao cua hai ds.\n";
	}
}

//16.3 
void phepBu(Node *&a1, Node *&b1)
{
	Node *at, *bt;
	at = a1;
	bt = b1;
	bool flag = false;

	while (at != NULL)
	{
		while (bt != NULL) {
			if (bt->info == at->info) /* Chi can co mot phan tu bi trung thi break */
			{
				flag = true;
				bt = bt->link;
				break;
			}
			bt = bt->link;
		}
		if (flag == false) {
			cout << at->info;
		}
		else {
			flag = false;
		}
		at = at->link;
		bt = b1;
	}
}

int main()
{
	Node *a = NULL, *b = NULL;
	int choice, i, n;
	char x;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 15: DAnh SACH LIEN KET DON ----------" << endl;
	cout << "1. Nhap danh sach A va B" << endl;
	cout << "2. Xuat cac phan tu thuoc TAP HOP cua A va B" << endl;
	cout << "3. Xuat cac phan tu thuoc TAP GIAO cua A va B" << endl;
	cout << "4. Xuat cac phan tu thuoc PHAN BU cua A va B" << endl;
	cout << "5. Thoat" << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			// Danh sach 1
			init(a);
			cout << "Ban vua khoi tao DSLK DON A thanh cong\n";
			cout << "Chon chuc nang them/xoa phan tu vao/trong danh sach.\n";
			cout << "a. Them dau ds.\n";
			cout << "b. Them cuoi ds.\n";
			cout << "c. Xoa dau ds.\n";
			cout << "d. Xoa cuoi ds.\n";
			cout << "e. Xong.\n";
			do {
				cout << "Moi chon chuc nang: ";
				cin >> x;
				switch (x)
				{
				case 'a': case 'A':
					cout << "Vui long nhap gia tri x = ";
					cin >> n;
					insertFirst(a, n);
					cout << "Danh sach sau khi them la: \n";
					processList(a);
					break;
				case 'b': case 'B':
					cout << "Vui long nhap gia tri x = ";
					cin >> n;
					insertLast(a, n);
					cout << "Danh sach sau khi them la: \n";
					processList(a);
					break;
				case 'c': case 'C':
					i = deleteFirst(a);
					if (i == 0)
					{
						cout << "Danh sach rong, khong the xoa !!\n";
					}
					else
					{
						cout << "Da xoa thanh cong phan tu dau trong DSLK DON";
						cout << "Danh sach sau khi xoa la: \n";
						processList(a);
					}
					break;
				case 'd': case 'D':
					i = deleteLast(a);
					if (i == 0)
					{
						cout << "Danh sach rong, khong the xoa !!\n";
					}
					else
					{
						cout << "Da xoa thanh cong phan tu cuoi trong DSLK DON";
						cout << "Danh sach sau khi xoa la: \n";
						processList(a);
					}
					break;
				case 'e': case 'E':
					cout << "Hoan thanh viec nhap du lieu ds A !!!" << endl;
					cout << endl;
					break;
				default:
					break;
				}
			} while (x != 'e' && x != 'E');


			cout << endl;

			// Danh sach 2
			init(b);
			cout << "Ban vua khoi tao DSLK DON B thanh cong\n";
			cout << "Chon chuc nang them/xoa phan tu vao/trong danh sach.\n";
			cout << "a. Them dau ds.\n";
			cout << "b. Them cuoi ds.\n";
			cout << "c. Xoa dau ds.\n";
			cout << "d. Xoa cuoi ds.\n";
			cout << "e. Xong.\n";
			do {
				cout << "Moi chon chuc nang: ";
				cin >> x;
				switch (x)
				{
				case 'a': case 'A':
					cout << "Vui long nhap gia tri x = ";
					cin >> n;
					insertFirst(b, n);
					cout << "Danh sach sau khi them la: \n";
					processList(b);
					break;
				case 'b': case 'B':
					cout << "Vui long nhap gia tri x = ";
					cin >> n;
					insertLast(b, n);
					cout << "Danh sach sau khi them la: \n";
					processList(b);
					break;
				case 'c': case 'C':
					i = deleteFirst(b);
					if (i == 0)
					{
						cout << "Danh sach rong, khong the xoa !!\n";
					}
					else
					{
						cout << "Da xoa thanh cong phan tu dau trong DSLK DON";
						cout << "Danh sach sau khi xoa la: \n";
						processList(b);
					}
					break;
				case 'd': case 'D':
					i = deleteLast(b);
					if (i == 0)
					{
						cout << "Danh sach rong, khong the xoa !!\n";
					}
					else
					{
						cout << "Da xoa thanh cong phan tu cuoi trong DSLK DON";
						cout << "Danh sach sau khi xoa la: \n";
						processList(b);
					}
					break;
				case 'e': case 'E':
					cout << "Hoan thanh viec nhap du lieu ds B !!!" << endl;
					cout << endl;
					break;
				default:
					break;
				}
			} while (x != 'e' && x != 'E');
			break;


		case 2:
			cout << "Xuat phan tu tap hop cua hai danh sach: \n";
			cout << "Danh sach A: ";
			processList(a);
			cout << "Danh sach B: ";
			processList(b);
			break;

		case 3:
			cout << "Danh sach cac phan tu thuoc TAP HOP GIAO cua A va B la:" << endl;
			phepGiao(a, b);
			cout << endl;
			break;

		case 4:
			cout << "a. Phan bu cua B trong A (A\B)" << endl;
			cout << "b. Phan bu cua A trong B (B\A)" << endl;
			cout << endl;

			cout << "Chon a hoac b de thuc hien: ";
			cin >> x;
			if (x == 'a')
			{
				cout << "Danh sach cac phan tu thuoc phan bu cua A va B (A\\B) la:" << endl;
				phepBu(a, b);
				cout << endl;
			}
			if (x == 'b')
			{
				cout << "Danh sach cac phan tu thuoc phan bu cua B va A (B\\A) la:" << endl;
				phepBu(b, a);
				cout << endl;
			}

			cout << endl;
			break;
		case 5:
			cout << "Goodbye...!" << endl;

			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 5);

	system("pause");

	return 0;
}