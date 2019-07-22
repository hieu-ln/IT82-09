// Bai 3, chuong 2: Danh sach lien ket don
#include <iostream>
#include <stdio.h>

using namespace std;

// 3.1
struct Node
{
	int info;
	Node *link;
};
Node *first;

//3.2
void Init()
{
	first = NULL;
}

//3.3
void processList()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//3.4
Node *search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//3.5
void insertFirst(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//3.6
int deleteFirst()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7
void insertLast(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
}

//3.8
int deleteLast()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
		{
			first = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

// 3.9
int searchAndDelete(int x)
{
	Node *p, *q;
	p = first;
	q = first;
		
	if (first != NULL)
	{
		while (p != NULL && p->info != x)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			q->link = p->link;
			delete p;
			return 1;
		}
		else
		{
			q->link = NULL;
			return 0;
		}
		
	}
	/*else
	{
		if (p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else
		{
			return 0;
		}
	}*/
	return 0;
}

int main()
{
	int choise = 0, x, i;
	Node *p;
	
	system("cls");
	cout << "**** Bai 3, chuong 2, Damh sach lien ket don ****\n";
	cout << "1.Khoi tao DSLK DON rong\n";
	cout << "2.Them phan tu vao dau DSLK DON\n";
	cout << "3.Them phan tu vao cuoi DSLK DON\n";
	cout << "4.Xoa phan tu o dau DSLK DON\n";
	cout << "5.Xoa phan tu o cuoi DSLK DON\n";
	cout << "6.Xuat DSLK DON\n";
	cout << "7.Tim mot phan tu gia tri x trong DSLK DON\n";
	cout << "8.Tim mot phan tu gia tri x va xoa no neu co trong DSLK DON\n";
	cout << "9.Thoat\n";
	do {
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao DSLK DON thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap giaq tri x = ";
			cin >> x;
			insertFirst(x);
			cout << "Danh sach sau khi them la: \n";
			processList();
			break;
		case 3:
			cout << "Vui long nhap giaq tri x = ";
			cin >> x;
			insertLast(x);
			cout << "Danh sach sau khi them la: \n";
			processList();
			break;
		case 4:
			i = deleteFirst();
			if (i == 0)
			{
				cout << "Danh sach rong, khong the xoa !!\n";
			}
			else
			{
				cout << "Da xoa thanh cong phan tu dau trong DSLK DON";
				cout << "Danh sach sau khi xoa la: \n";
				processList();
			}
			break;
		case 5:
			i = deleteLast();
			if (i == 0)
			{
				cout << "Danh sach rong, khong the xoa !!\n";
			}
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi trong DSLK DON";
				cout << "Danh sach sau khi xoa la: \n";
				processList();
			}
			break;
		case 6:
			cout << "Danh sach hien tai: ";
			processList();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			p = search(x);
			if (p != NULL)
			{
				cout << "Tim thay co gia tri x = " << x << endl;
			}
			else
			{
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			}
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			i = searchAndDelete(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong\n";
				cout << "Danh sach sau khi xoa la: \n";
				processList();
			}
			else
			{
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			}
			break;
		case 9:
			cout << "Goodbye !!! \n";
		default: 
			break;
		}
	} while (choise != 9);

	system("pause");
	return 0;
}