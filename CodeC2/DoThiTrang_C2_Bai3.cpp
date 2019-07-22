// Bai 3, chuong 2: DSLK don
#include <stdio.h> 
#include <iostream>
using namespace std;

//3.1 Khai bao DS
struct Node
{
	int info;
	Node* link;
};
Node* first;

//3.2 Khoi tao DS
void Init()
{
	first = NULL;
}

//3.3 Xuat DS
void Process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//3.4 Tim phan tu
Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//3.5 Them phan tu vao dau DS
void Insert_first(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//3.6 Xoa phan tu dau DS
int Delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7 Them phan tu vao cuoi DS
void Insert_last(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

//3.8 Xoa phan tu cuoi DS
int Delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;

		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}

		if (p != first)
			q->link = NULL;
		else first = NULL;
		delete p;
		return 1;
	}

	return 0;
}

//3.9 Tim va Xoa phan tu
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;

		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}

		if (p != first && p->link != NULL)
		{
			//phan tu giua DS
			if (p->link != NULL)
				q->link = p->link;
			else q->link = NULL;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			//phan tu dau DS
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			//phan tu cuoi Ds
			q->link = NULL;
			delete p;
			return 1;
		}
		else return 0;
	}
	return 0;
}

// ham doi gia tri cua 2 phan tu
void swap(Node* a, Node* b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

//3.10 Sap xep tang dan
// Selection sort
void Sort()
{
	Node* p, * q, * min;
	// Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while (p != NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}

		//Doi cho phan tu nho nhat voi phan tu dau tien
		swap(min, p);
		p = p->link;
	}
}

//3.10 Sap xep giam dan
// Selection sort
void Sort_Desc()
{
	Node* p, * q, * min;
	// Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while (p != NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info > min->info)
				min = q;
			q = q->link;
		}

		//Doi cho phan tu nho nhat voi phan tu dau tien
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int choice = 0;
	int i, x;
	Node* p;
	system("cls");
	// Menu
	cout << "-------------BAI TAP 3, CHUONG 2: DSLK---------------" << endl;
	cout << "1. Khoi tao DSLK Don rong" << endl;
	cout << "2. Them phan tu vao dau DSLK" << endl;
	cout << "3. Them phan tu vao cuoi DSLK" << endl;
	cout << "4. Xoa phan tu vao dau DSLK" << endl;
	cout << "5. Xoa phan tu cuoi DSLK" << endl;
	cout << "6. Xuat DSLK" << endl;
	cout << "7. Tim phan tu x trong DSLK" << endl;
	cout << "8. Tim va Xoa phan tu" << endl;
	cout << "9. Sap xep tang dan" << endl;
	cout << "10. Sap xep giam dan" << endl;
	cout << "11. Thoat" << endl;

	do
	{
		cout << "Vui long chon so:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init();
			cout << "Khoi tao DS thanh cong" << endl;
			break;
		case 2:
			cout << "vui long nhap so can them";
			cin >> x;
			Insert_first(x);
			cout << "Ds sau khi them: ";
			Process_list();
			break;
		case 3:
			cout << "vui long nhap so can them";
			cin >> x;
			Insert_last(x);
			cout << "Ds sau khi them: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "Ds rong, khong the xoa" << endl;
			else
			{
				cout << "xoa thanh cong" << endl;
				cout << "Ds sau khi xoa phan tu dau:";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
				cout << "Ds rong, khong the xoa" << endl;
			else
			{
				cout << "xoa thanh cong" << endl;
				cout << "Ds sau khi xoa phan tu dau:";
				Process_list();
			}
			break;
		case 6:
			cout << "DS:" << endl;
			Process_list();
			break;
		case 7:
			cout << "vui long nhap so can tim";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << "Tim thay phan tu cos gia tri x: " << x << endl;
			else
				cout << "Khong tim thay " << x << endl;
			break;
		case 8:
			cout << "Nhap gia tri can tim: ";
			cin >> x;

			i = SearchAndDelete(x);

			if (i == 1)
			{
				cout << "Tim thay " << x << "va xoa thanh cong phan tu " << x << endl;
				cout << "Ds sau khi xoa: ";
				Process_list();
			}
			else cout << "khong tim thay phan tu " << x << "de xoa";
			break;
		case 9:
			Sort();
			cout << "Ds sau khi sap xep: ";
			Process_list();
			break;
		case 10:
			Sort_Desc();
			cout << "Ds sau khi sap xep: ";
			Process_list();
			break;
		case 11:
			cout << "Goodbye";
			break;
		default: break;
		}
	} while (choice != 11);
	system("pause");
	return 0;
}