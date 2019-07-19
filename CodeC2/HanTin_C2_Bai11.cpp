// Bai 11, chuong 2: DS han che ,hang doi, QUEUE (su dung ds lien ket don)
#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

// 11.1 khai bao cau truc queue
struct Node{
	int info;
	Node *link;
};

Node *front, *rear;

// 11.2 khoi tao queue
void init() {
	front = NULL;
	rear = NULL;
}

//11.3 kt queue
int isEmpty() {
	if (front == NULL) {
		return 1;
	}
	return 0;
}

// 11.4 them 1 pt vao queue
void push(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL) {
		front = p;
	}
	else {
		rear->link = p;
	}
	rear = p;
}

//11.5 xoa 1 pt trong queue
int pop(int &x) {
	if (front != NULL) {
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}


// XUAT QUEUE
void processQueue() {
	if (front != NULL) {
		Node *p = front;
		cout << "<--";
		do {
			cout << setw(4) << p->info;
			p = p->link;
		} while (p != NULL);
		cout << setw(4) << "<--\n";
	}
}

int main() {
	int choise, x, i;
	system("cls");
	cout << "_________ Bai 7, chuong 2: QUEUE (Hang doi - DSLKD) ___________\n";
	cout << "1. khoi tao queue rong.\n";
	cout << "2. them phan tu vao queue.\n";
	cout << "3. Lay phan tu ra khoi queue.\n";
	cout << "4. kiem tra queue rong hay khong.\n";
	cout << "5. xuat queue.\n";
	cout << "6. thoat.\n";
	do {
		cout << "vui long chon chuc nang de thuc hien: ";
		cin >> choise;
		switch (choise) {
		case 1:
			init();
			cout << "Ban vua khoi tao queue rong thanh cong.\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			push(x);
			processQueue();
			break;
		case 3:
			i = pop(x);
			if (i == 0) {
				cout << "Queue rong khong co phan tu de lay.\n";
			}
			else {
				cout << "phan tu moi lay ra khoi queue la x = " << x << endl;
				processQueue();
			}
			break;
		case 4:
			i = isEmpty();
			if (i == 0) {
				cout << "Queue khong rong.\n";
			}
			else {
				cout << "Queue rong.\n";
			}
			break;
		case 5:
			cout << "Queue hien tai la: ";
			processQueue();
			break;
		case 6:
			cout << "Goodbye ..........!\n";
		default:
			break;
		}
	} while (choise != 6);
	system("pause");
	return 0;
}

