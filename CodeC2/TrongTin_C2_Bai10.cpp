//Project: C2_Bai10.cpp
#include <iostream>
using namespace std;

struct node
{
	int info;
	node *link;
};
node *sp;
void init()
{
	sp = NULL;
}
void push(int x)
{
	node *p;
	p = new node;
	p -> info = x;
	p -> link = sp;
	sp = p;
}
int pop( int &x)
{
	if(sp != NULL)
	{
		node *p = sp;
		x = p -> info;
		sp = p -> link;
		delete p;
		return 1;
	}
	return 0;
}
int isempty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void xuat()
{
	node *p;
	p = sp;
	while (p != NULL)
	{
		cout << p -> info << endl;
		p = p -> link;
	}
}
int nhiphan(int so)
{
	init ();
	int np = 0;
	while (so != 0)
	{
		int du = so % 2;
		push(du);
			so /= 2;
	}
	while (!isempty())
	{
		int x;
		if (pop(x))
			np = np * 10 + x;
		else
			break;
	}
	return np;
}
int main()
{
	int x, t, chon, n;
	char tt;
	do {
		cout << "\nNhap chon:\n"
			 << "1. Khoi tao\n"
			 << "2. Kiem tra rong\n"
			 << "3. Them 1 phan tu\n"
			 << "4. Xoa 1 phan tu\n"
			 << "5. Doi 1 so thap phan sang nhi phan\n"
			 << "6. Xuat danh sach\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
			case 1:
				init();
				cout << "Khoi tao danh sach thanh cong\n";
				break;
			case 2:
				if (isempty()!=0)
					cout << "Danh sach rong\n";
				else
					cout << "Danh sach khong rong\n";
				break;
			case 3:
				cout << "Nhap gia tri muon them: ";
				cin >> x;
				push(x);
					cout << "Them thanh cong!\n";
				break;
			case 4:
				t = pop(x);
				if (t != 0)
					cout << "Phan tu lay ra co gia tri la "<<x<<"\n";
				else
					cout << "Stack rong!\n";
				break;
			case 5:
				cout << "Nhap gia tri can doi nhi phan: ";
				cin >> n;
				cout << "So sau khi chuyen sang nhi phan la: ";
				cout << nhiphan(n) << endl;
				break;
			case 6:
				cout << "Danh sach cua stack:\n";
				xuat();
				break;
			default:
				cout << "Gia tri chon khong hop le!\n";
				break;
		}
		cout << "Ban muon tiep tuc khong(Yes/No):";
		cin >> tt;
	} while(tt == 'y'|| tt == 'Y');
	return 0;
}