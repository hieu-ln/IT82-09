#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int sp;
int x;
int cot1[MAX], cot2[MAX], cot3[MAX], stack[MAX];
int n, b=1,c=2,d=3;
void init(int a[], int &sp){
	sp = -1;
	cout << "Stack da duoc khoi tao\n";
}
void push(int a[], int &sp){
	cout << "Nhap gia tri can them x=";
	cin >> x;
	if(sp < MAX-1){
		a[++sp]=x;
		cout << "Da them phan tu thanh cong\n";
	}
	else
		cout << "Stack da day! Khong the them phan tu\n";
}
void pop(int a[], int &sp, int &x){
	if(sp!=-1){
		x=a[sp--];
		cout << "Da lay phan tu thanh cong\n";
	}
	else
		cout << "Stack rong! Khong the lay phan tu\n";
}
void isFull(int a[], int &sp){
	if(sp == MAX - 1)
		cout << "Stack day!!!\n";
	else
		cout << "Stack chua day!!!\n";
}
void isEmpty(int a[], int &sp){
	if(sp == -1)
		cout << "Stack rong!!!\n";
	else
		cout << "Stack khong rong!!!\n";
}
void chuyendia(int a,int b,int c,int n,int &sp)
{
	sp++;
	stack[sp]=n-1;	
	cot1[sp]=c;
	cot2[sp]=b;
	cot3[sp]=a;
	sp++;
	stack[sp]=1;
	cot1[sp]=a;
	cot2[sp]=b;
	cot3[sp]=c;
	sp++;
	stack[sp]=n-1;
	cot1[sp]=a;
	cot2[sp]=c;
	cot3[sp]=b;
}
void thaphanoi(int a,int b, int c, int n)
{
	stack[0]=n;cot1[0]=a;cot2[0]=b;cot3[0]=c; 
	int sp=0;
	while (sp>=0)
	{
		sp--;
		if (stack[sp+1]==1)
			cout << "Cot " << cot1[sp+1] << " --> cot " << cot2[sp+1] << endl;
		else
			chuyendia(cot1[sp+1],cot2[sp+1],cot3[sp+1],stack[sp+1],sp);
	}
}
int main(){
	int chon;
	cout << "MENU\n";
	cout <<"1. Khoi tao Stack rong\n";
	cout <<"2. Kiem tra Stack rong\n";
	cout <<"3. Kiem tra Stack day\n";
	cout <<"4. Them 1 phan tu vao Stack\n";
	cout <<"5. Xoa 1 phan tu vao Stack\n";
	cout <<"6. Thap Ha Noi\n";
	cout <<"6. Thoat\n";
	do{
		cout <<"Chon: ";
		cin >> chon;
		switch(chon){
		case 1:
			init(a, sp);
			break;
		case 2:
			isEmpty(a,sp);
			break;
		case 3:
			isFull(a,sp);
			break;
		case 4:
			push(a, sp);
			break;
		case 5:
			pop(a, sp, x);
			break;
		case 6:
			cout << "nhap so dia: ";
			cin >> n;
			thaphanoi(b,c,d,n);
		default:
			break;
		}
	}while(chon!=7);
	system("pause");
	return 0;
}