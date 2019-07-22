// Bai 9, Chuong 2: Danh han che, STACK, Thap HN (Danh sach dac).
#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 100

// khoi tao
void init(int a[], int&sp)
{
	sp = -1;
}

// kt rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

// kt day
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

// them vao 1 phan tu
int push(int a[], int &sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

// lay ra 1 phan tu
int pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

// xuat stack
void processStack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}

/*
// chuyen STACK A qua STACK B
void movement(int a[], int &sp1, int b[], int &sp2, int c[], int &sp3)
{
	int x;
	for (int i = 0; i < sp1; i++) {
		x = 0;
		pop(a,sp1,x);
		push(c, sp3, x);
	}
	pop(a, sp1, x);
	push(b, sp2, x);
	for (int i = 0; i <= sp3 ; i++) {
		x = 0;
		pop(c, sp3, x);
		push(b, sp2, x);
	}
}*/

// Nhap mang
void inputArray(int a[], int &n) {
	cout << "Nhap so phan tu muon khoi tao: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}

// xuat mang 
void outputArray(int a[], int n) {
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			cout << setw(4) << a[i];
		}
		cout << endl;
	}
	else {
		cout << "\tKhong co phan tu.\t";
		cout << endl;
	}	
}

// Xap xep 
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void arrange(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++)
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
		}
	}
}

//  xoa phan tu cuoi cua mang va chuyen phan tu vao stack
void deleteLastArrayToStack(int a[], int &n, int &x, int stack[], int &sp) {
	for (int i = n - 1; i >= 0; i--) {
		x = a[i];
		n--;
		push(stack, sp, x);
	}
	
}

// them phan tu tu stack vao mang
void insertFirstArryFromStack(int a[], int &n, int x, int stack[], int &sp) {
	while(sp == 0){

		x = pop(stack, sp, x);
		n++;
		a[n] = x;
	}
}

int main()
{
	int a[MAX], n1 = 0, b[MAX], n2 = 0, c[MAX], n3 = 0, stack[MAX];
	int choise, x, i, sp ;
	system("cls");
	
	/*
	
	} while (n1 != 0);
	
	do {
		pop(stack, sp, x);
		cout << "Danh sach stack hien tai: \n";
		processStack(stack, sp);
		insert(c, n3, x);
		outputArray(c, n3);
	} while (isEmpty(stack,sp) != 1);*/

	cout << "**** Bai 9, chuong 2:                        ****\n";
	cout << "1.Khoi tao mang \n";
	cout << "2.Xuat mang vua khoi tao\n";
	cout << "3.Sap xep mang vua nhap\n";
	cout << "4.Khoi tao STACK rong\n"; // r
	cout << "5.Chuyen tu mang A (cot 1) qua mang B(cot 2) dung STACK\n";
	cout << "6.Chuyen tu mang A (cot 1) qua mang C(cot 3) dung STACK\n";
	cout << "7.Kiem tra STACK\n";// r
	cout << "8.Xuat STACK\n"; // r
	cout << "9.Xuat cac mang A, B, C\n"; // r
	cout << "10.Thoat/n"; // r
	do {
		cout << "\n Vui long chon so de thuc hien: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			inputArray(a, n1);
			break;

		case 2:
			cout << "Mang vua khoi tao: ";
			outputArray(a, n1);
			break;

		case 3:
			arrange(a, n1);
			cout << "Mang vua sap xep la: \n";
			outputArray(a, n1);
			break;

		case 4:
			init(a, sp);
			cout << "Ban vua khoi tao STACK rong thanh cong\n";
			break;
		
		case 5:
			cout << "Mang A: ";
			outputArray(a, n1);
			cout << "So phan tu n1 = " << n1 << endl;
			cout << "Mang B: ";
			outputArray(b, n2);
			cout << "So phan tu n2 = " << n2 << endl;
			deleteLastArrayToStack(a, n1, x, stack, sp);
			cout << ">>> .............  >>>";

			insertFirstArryFromStack(b, n2, x, stack, sp);
			cout << "Mang A: ";
			outputArray(a, n1);
			cout << "So phan tu n1 = " << n1 << endl;
			cout << endl;
			cout << "Mang B: ";
			outputArray(b, n2);
			cout << "So phan tu n2 = " << n2 << endl;
			cout << "STACK hien tai: ";
			processStack(stack, sp);
			break;
		case 6:
			break;
		
		case 7:
			i = isEmpty(stack, sp);
			if (i == 0)
			{
				cout << "STACK khong rong !!\n";
			}
			else
			{
				cout << "STACK rong !!\n";
			}

			i = isFull(stack, sp);
			if (i == 0)
			{
				cout << "STACK chua day !!\n";
			}
			else
			{
				cout << "STACK da day !!\n";
			}
			break;


		case 8:
			i = isEmpty(stack, sp);
			if (i == 0)
			{
				cout << "STACK hien tai: ";
				processStack(stack, sp);
			}
			else
			{
				cout << "STACK hien tai rong!!\n";
			}
			break;

		case 9:
			cout << "Mang A: ";
			outputArray(a, n1);
			cout << "So phan tu n1 = " << n1 << endl;
			cout << endl;
			cout << "Mang B: ";
			outputArray(b, n2);
			cout << "So phan tu n2 = " << n2 << endl;
			cout << endl;
			cout << "Mang C: ";
			outputArray(c, n3);
			cout << "So phan tu n3 = " << n3 << endl;
			cout << endl;
			break;

		case 10:
			cout << "Goodbye .............!!! \n";
		default:
			break;
		}
	} while (choise != 10);

	system("pause");
	return 0;
}