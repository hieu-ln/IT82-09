// bai 7, chuong 2 : Danh sach han che, hnag doi , queue
#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 100


//7.2 khoi tao queue rong 
void init(int a[], int &front, int &rear) {
	front = -1;
	rear = -1;
}

//7.3 kiem tra queue rong
int isEmpty(int a[], int &front, int &rear) {
	if (front == rear)
		return 1;
	else
		return 0;
}

// 7.4 kt queue day
int isFull(int a[], int &front, int &rear) {
	if (front == 0 && rear == MAX - 1 || front - rear == 1) 
		return 1;
	else
		return 0;	
}


// 7.5 them phan tu vao queue
int push(int a[], int &front, int &rear, int x) {
	if (rear - front == MAX - 1)
		return 0;
	else {
		if (front == -1)
			front = 0;
		if (rear == MAX - 1) {
			for (int i = front; i <= rear; i++) {
				a[i - front] = a[i];
			}
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}

//7.6 lay 1 phan tu ra khoi queue
int pop(int a[], int &front, int &rear, int &x) {
	if (front == -1) {
		return 0;
	}
	else {
		x = a[front++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}


// Xuat queue
void processQueue(int a[], int f, int r) {
	cout << "f = " << f << "\t r = " << r << endl;
	if (f <= r && f != -1) {
		cout << "<--   ";
		for (int i = f; i < r + 1; i++) {
			cout << setw(4) << a[i];
		}
		cout << "   <--" << endl;
	}
}

int main()
{
	int a[MAX];
	int choise, f, r, x, i;
	system("cls");
	cout << "**** Bai 7, chuong 2: Damh sach han che, hang doi, queue ****\n";
	cout << "1.Khoi tao QUEUE rong\n";
	cout << "2.Them phan tu vao QUEUE\n";
	cout << "3.Lay phan tu ra khoi QUEUE\n";
	cout << "4.Kiem tra QUEUE co rong hay khong\n";
	cout << "5.Kiem tra QUEUE co day hay khong\n";
	cout << "6.Xuat QUEUE \n";
	cout << "7.Thoat\n";
	do {
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			init(a, f, r);
			cout << "Ban vua khoi tao QUEUE rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap giaq tri x = ";
			cin >> x;
			i = push(a, f, r, x);
			cout << "QUEUE sau khi them la: \n";
			processQueue(a, f, r);
			break;
		case 3:
			i = pop(a, f, r, x);
			cout << "Phan tu lay ra tu QUEUE la x = " << x << endl;
			cout << "QUEUE sau khi lay ra la: \n";
			processQueue(a, f, r);
			break;
		case 4:
			i = isFull(a, f, r);
			if (i == 0)
			{
				cout << "QUEUE chua day !!\n";
			}
			else
			{
				cout << "QUEUE da day !!\n";
			}
			break;
		case 5:
			i = isEmpty(a, f, r);
			if (i == 0)
			{
				cout << "QUEUE khong rong !!\n";
			}
			else
			{
				cout << "QUEUE rong !!\n";
			}
			break;
		case 6:
			cout << "QUEUE hien tai: ";
			processQueue(a, f, r);
			break;
		case 7:
			cout << "Goodbye .............!!! \n";
		default:
			break;
		}
	} while (choise != 7);
	system("pause");
	return 0;
}