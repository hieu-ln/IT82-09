//Chuong 5 Bai 5: Do Thi
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

// DSLK su dung cho Stack va Queue va DS ke
struct Node
{
	int info;
	Node *link;
};

Node *First[MAX]; // DS cac DSK
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

Node *sp; // su dung cho Stack
Node *front, *rear; // su dung cho queue

// Stack
void InitStack() // ham khoi tao Stack
{
	sp = NULL;
}

int IsEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//////////////////

// Queue
void InitQueue() // khoi tao Queue
{
	front = NULL;
	rear = NULL;
}

int IsEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p->info;
		front = p->link;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
///////////////////

void InitGraph() // khoi tao do thi
{
	n = 0;
}

void InsertLast(Node *&First, Node *p)
{
	if(First == NULL)
		First = p;
	else
	{
		Node *q = First;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

// Cau 5.1: Nhap ma tan ke vao do thi
void InputGraphFromText() //Nhap mtran ke bang file text
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile>>n;
		for (int i = 0; i <n; i++)
			myfile >>vertex[i];
		
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				// dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1],p);
			}
			i++;
		}
		// cout << i;
	}
}

void InputGraph() // nhap ma tran ke bang tay
{
	cout << "Nhap so dinh do thi: ";
	cin >> n;
	cout << "Nhap ten dinh:" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> vertex[i];
	}

	for(int i = 0; i < n; i++)
	{
		cout << "Nhap DSK cua dinh thu " << i << "("<< vertex[i] <<")" << endl;
		int u;
		while(cin >> u)
		{
			Node *p = new Node;
			p->info = u;
			p->link = NULL;
			InsertLast(First[i-1],p);
		}
	}
}

// Cau 5.2: Xuat Ma tran ke
void OutputGraph()
{
	for (int i = 0 ; i <n; i++)
	{
		cout << "Dinh " << i << "("<< vertex[i] <<") : " << endl;
		Node *p = First[i];
		while(p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}                                                
void Output(int a[], int n) // Xuat ma tran ke
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << ": " << endl;            
}

// Cau 5.3: Duyet do thi theo chieu rong BFS (dung Queue va DSLK don)
int C[100], bfs[100];
int nbfs = 0;

void InitC()
{
	for(int i = 0; i < n; i++) // n la so dinh cua do thi
		C[i] = 1;
}
void BFS(int v) // v la dinh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;

	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;

		while(w != NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

// Cau 5.4: Duyet do thi theo chieu sau DFS (dung Stack va DSLK don)
int dfs[100];
int ndfs = 0;

void DFS(int s) 
{
	PushQ(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node *v = NULL;

	while(IsEmptyS() == 0)
	{
		if(v == NULL)
			PopS(u);

		v = First[u];
		while(v != NULL)
		{
			if(C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u=v->info;
				break;
			}
			v = v->link;
		}
	}
}

// Cau 5.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v) // v la dnh bat dau
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;

	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		w = First[p];
		while(w != NULL)
		{
			if(C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
		}
	}
}

int main ()
{
	int a [MAX];
	int b [MAX]; 
	int choice, x, i ; 
	system("cls"); 
	cout<<" -------------BAI TAP 4 , CHUONG 5, DO THI ---------" <<endl; 
	cout<<"1. Khoi tao DANH SACH KE rong "<< endl ; 
	cout<<"2. Nhap DANH SACH KE tu file text "<< endl ;
	cout<<"3. Nhap DANH SACH KE "<< endl ; 
	cout<<"4. XUAT DANH SACH KE "<< endl ; 
	cout<<"5. Duyet do thi theo chieu rong BFS "<< endl ; 
	cout<<"6. Duyet do thi theo chieu sau DFS "<< endl ; 
	cout<<"7. Tim dinh co gia tri x theo BFS "<< endl ; 
	cout<<"8. Thoat "<< endl ; 
	do
	{
		cout <<"\nVui long chon so de thuc hien :";
		cin >> choice; 
		switch(choice)
		{
		case 1:
			InitGraph();
				cout <<" Ban vua khoi tao DANH SACH KE rong thanh cong!\n";
				break;
		case 2:
			InputGraphFromText();
			cout <<" Ban vua nhap DANH SACH KE tu file: \n";
			OutputGraph();
			break;
				
		case 3:
			InputGraph();
			break; 
		case 4:
			OutputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout <<" Vui long nhap dinh xuat phat:";
			cin >>x;
			nbfs = 0 ; 
			BFS(x);
			cout <<" Thu tu dinh sau khi duyet BFS :" << endl; 
			Output (bfs, n); 
			break ; 
		case 6:
			InitStack();
			InitC();
			cout <<" Vui long nhap dinh xuat phat:";
			cin >>x;
			nbfs = 0 ; 
			DFS(x);
			cout <<" Thu tu dinh sau khi duyet DFS :" << endl; 
			Output (dfs, n); 
			break ; 
		case 7:
			InitQueue();
			InitC();
			nbfs = 0 ; 
			cout <<" Vui long nhap gia tri x can tim :"; 
			cin >>x; 
			Search_by_BFS(x, 0);
			break ; 
		case 8:
			cout <<" GOODBYE........... !" << endl; 
			break ; 
		default:
			break ;
		}
	}while (choice!=8);
	system("pause");
	return 0;
}