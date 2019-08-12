// chuong 6 bai 6
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;

//khai bao ma tran bang mang hai chieu
# define MAX 20
int a[MAX][MAX];
int n;// so dinh cua do thi
char vertex[MAX];  // ten dinh

void InitGraph()
{
	n=0;
}

void inputGraphFromText()
{
	string line;
	ifstream mylife("mtts.txt");
	if(mylife.is_open())
	{
		mylife >>n;
		for(int i=0; i<n;i++)
			mylife>>vertex[i];
		for(int i=0; i<n; i++)
		{
			for (int j=0;j<n; j++)
				mylife>>a[i][j];
		}
	}
}

// nhap ma tran ke cua do thi
void intGraph()
{
	cout<<"Nhap so dinh cua do thi n:";
	cin>>n;
	cout<<"Nhap ten dinh : ";
	for(int i=0; i<n;i++)
		cin>>vertex[i];
	for (int i=0;i<n; i++)
	{
		cout<<"Nhap vao dong thu"<<i+1<<" : ";
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
}

// xuat ma tran ke cua do thi
void outGraph()
{
	cout<<setw(5)<<left;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<setw(5)<<left;
		cout<<endl;
	}
}

// khoi tao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE=0;  // so phan tu tap E

//khoi bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; // so phan tu tap T

int TonTai(int d, int D[], int nD)
{
	for(int i=0;i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}


void TaoE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void Swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void SapXep()
{
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				Swap(wE[i],wE[j]);
				Swap(E1[i],E1[j]);
				Swap(E2[i],E2[j]);
			}
}

void Kruskal()
{
	for(int i = 0; i < nE; i++)
	{
		if(TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if(TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n-1)
			break;
	}
}

void output(bool VertexName)
{
	int tong=0;
	for(int i=0;i<nT;i++)
	{
		if(VertexName)
			cout<<endl<<"("<<vertex[T1[i]]<<","<<vertex[T2[i]]<<")="<<wT[i];
		else
			cout<<endl<<"("<<T1[i]<<","<<T2[i]<<")="<<wT[i];
		tong+=wT[i];
	}
	cout<<"\n Tong="<<tong;
}

int main()
{
	int choice,i;
	system("cls");
	cout<<" ----- Bai tap 6, Chuong 6------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong "<< endl;
	cout<<"2. Nhap MA TRAN KE tu file text "<< endl;
	cout<<"3. Nhap Ma Tran Ke"<< endl;
	cout<<"4. Xuat Ma Tran Ke"<< endl;
	cout<<"5. Tim Cay Khung Toi Thieu bang Kruskal cai tien: "<< endl;
	cout<<"6. Thoat"<< endl;
	do 
	{
		cout<<"\nVui long chon so de thuc hien:";
		cin >> choice; 
		switch(choice)
		{
		case 1:
			InitGraph();
				cout << "Ban vua khoi tao MA TAN KE rong thanh cong!\n";
			break ; 
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TAN KE tu file: \n";
			outGraph();
			break ; 
		case 3:
			intGraph();
			break ; 
		case 4:
			outGraph();
			break ; 
		case 5:
			TaoE();
			SapXep();
			//TaoE();
			Kruskal();
			cout <<" Cay khung toi thieu voi Kruskal cai tien: "<<endl; 
			output(true );
			break ; 
		case 6: 
			cout << "Goodbye..........!" <<endl; 
			break; 
		default:
			break ; 
		}
	} while (choice!=6);
	system("pause");
	return 0;
}
