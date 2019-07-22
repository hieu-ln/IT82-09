//Chuong 2, Bai 3 : DANH SACH LIEN KET DON
#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 3.1: Khai bao cau truc ds
struct Node
{
	int info;
	Node *link;
};

Node *first;

//Cau 3.2: Khoi tao danh sach rong
void Init()
{
	first = NULL;
}

//Cau 3.3: Xuat cac phan tu trong ds
void Process_list()
{
	Node *p;
	p = first;
	while (p!= NULL)
	{
		cout << p -> info << "\t";
		p = p -> link;
	}
	cout << endl;
}

//Cau 3.4: Tim mot phan tu trong ds
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p -> info != x)
	{
		p = p -> link;
	}
	return p;
}

//Cau 3.5: Chen mot phan tu vao dau ds
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = first;
	first = p;
}

//Cau3.6: Xoa mot phan tu dau ds
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first -> link;
		delete p;
		return 1;
	}
	return 0;
}

//Cau 3.7: Them phan tu vao cuoi ds
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q -> link != NULL)
		{
			q = q -> link;
		}
		q -> link = p;
	}
}

//Cau 3.8: Xoa phan tu cuoi ds
int Delete_last()
{
	if( first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p -> link != NULL)
		{
			q = p;
			p = p -> link;
		}
		if (p != first)
		{
			q -> link = NULL;
		}
		else first = NULL;
		delete p;

		return 1;
	}
	return 0;
}

//Cau 3.9: Tim phan tu trong ds, xoa neu co
int SearchAndDelete(int x)
{
	if( first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p -> info != x && p -> link != NULL)
		{
			q = p;
			p = p -> link;
		}
		if (p != first && p != NULL)
		{
			if ( p -> link != NULL)
				q -> link = p -> link;
			else 
				q -> link = NULL;
			delete p;

			return 1;
		}
		else if (p == first)
		{
			first = p -> link;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

//Cau 3.10: Sap xep ds theo thu tu tang dan
void Sort()
{

}

//Cau 3.11: Sap xep ds theo thu tu giam dan
void SortDesc()
{

}


int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << " -------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON --------" << endl;
	cout << "1. Khoi tao DSLK DON rong" << endl;
	cout << "2. Them phan tu vao dau DSLKD" << endl;
	cout << "3. Them phan tu vao cuoi DSLKD" << endl;
	cout << "4. Xoa phan tu dau DSLKD" << endl;
	cout << "5. Xoa phan tu cuoi DSLKD" << endl;
	cout << "6. Xuat DSLKD" << endl;
	cout << "7. Tim phan tu voi gia tri x trong DSLKD" << endl;
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "9. Sap xep DSLKD tang dan" << endl;
	cout << "10. Sap xep DSLKD giam dan" << endl;
	cout << "11. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init();
				cout << "Ban vua khoi tao DSLKD thanh cong \n";
				break;

			case 2:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				Insert_first(x);
				cout << "Danh sach sau khi them la: ";
				Process_list();
				break;

			case 3:
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				Insert_last(x);
				cout << "Danh sach sau khi them la: ";
				Process_list();;
				break;

			case 4:
				i = Delete_first();
				if(i == 0)
					cout << "Danh sach rong, khong the xoa " << x << endl;
				else
				{
					cout << "Da xoa thanh cong phan tu cuoi cua DSLKD" << endl;
					cout << "Danh sach sau khi them la: ";
					Process_list();
				}
				break;

			case 5:
				i = Delete_last();
				if (i == 0)
				{
					cout << "Danh sach dang rong, khong co phan tu nao." << endl;
					
				}
				else
				{
					cout << "Xoa thanh cong. " << endl;
					cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
					Process_list();;
				}
					
				break;

			case 6:
				cout << "Danh sach hien tai la: ";
				Process_list();
				break;

			case 7:
				cout <<"Vui long nhap gia tri can tim x = ";
				cin >> x;
				p = Search(x);
				if(p != NULL)
				{
					cout << "Tim thay phan tu co gia tri x = " << x << endl;
				}
				else
					cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
				break;		

			case 8:
				cout <<"Vui long nhap gia tri can tim x = ";
				cin >> x;
				i = SearchAndDelete(x);
				if(i = 1)
				{
					cout << "Tim thay phan tu co gia tri x = " << x <<" va da xoa thanh cong" << endl;
					cout << "Danh sach sau khi xoa la: \n";
					Process_list();
				}
				else
					cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
				break;

			case 9:
				Sort();
				cout << "Danh sach sau khi sap xep tang dan la: ";
				Process_list();
				break;

			case 10:
				SortDesc();
				cout << "Danh sach sau khi sap xep giam dan la: ";
				Process_list();
				break;

			case 11: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}

	}while (choice != 11);
	system ("pause");
	return 0;
}