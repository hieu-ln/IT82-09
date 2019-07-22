// Bai 10, chuong 2: DS han che , hang doi, stack (Dung DS lien ket don)

#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

// 10.1 khai bao cau truc stack
struct Node {
	int info;
	Node *link;
};

Node *sp;

// 10.2 khoi tao stack rong
void init() {
	sp = NULL;
}

// 10.3 kt stack rong
int isEmpty() {
	if (sp == NULL) {
		return 1;
	}
	return 0;
}

// 10.4 them 1 phan tu vao stack
void push(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//10.5 xoa 1 phan tu trong stack
int pop(int &x) {
	if (sp == NULL) {
		return 0;
	}
	else {
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}

}


// XUAT STACK
void processStack() {
	Node *p = sp;
	while (p != NULL) {
		cout << setw(4) << p->info;
		p = p->link;
	}
	cout << endl;
}

int main()
{
	//Node *p;
	int choise, x, i;
	system("cls");
	cout << "**** Bai 5, chuong 2: Damh sach han che ****\n";
	cout << "1.Khoi tao STACK rong\n";
	cout << "2.Them phan tu vao STACK\n";
	cout << "3.Lay phan tu ra khoi STACK\n";
	cout << "4.Kiem tra STACK co rong hay khong\n";
	cout << "5.Xuat STACK\n";
	cout << "6.Thoat\n";
	do {
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap giaq tri x = ";
			cin >> x;
			push(x);
			cout << "STACK sau khi them la: \n";
			processStack();
			break;
		case 3:
			i = pop(x);
			if (i == 0) {
				cout << "Ds da rong, khong the xoa !!";
			}
			else {
				cout << "Phan tu lay ra tu STACK la x = " << x << endl;
				cout << "STACK sau khi lay ra la: \n";
				processStack();
			}

			break;
		case 4:
			i = isEmpty();
			if (i == 0)
			{
				cout << "STACK khong rong !!\n";
			}
			else
			{
				cout << "STACK rong !!\n";
			}
			break;
		case 5:
			i = isEmpty();
			if (i == 0)
			{
				cout << "STACK hien tai: ";
				processStack();
			}
			else
			{
				cout << "STACK rong !!\n";
			}

			break;
		case 6:
			cout << "Goodbye .............!!! \n";
		default:
			break;
		}
	} while (choise != 6);

	system("pause");
	return 0;
}