//Bai 12, chuong 2: Danh sach lien ket kép
#include<stdio.h>
#include<iostream>
using namespace std;

//12.1 khai báo cấu trúc danh sách
struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;
//12.2 khởi tạo danh sách rỗng
void init()
{
	first = NULL;
	last = NULL;
}
// 12.3 xuất các phần tử trong danh sách(đầu về cuối) 
void Process_list()
{
	Node *p;
	p = first;
	while(p!=NULL)
	{
		cout << p->info << " ";
		p= p->next;
	}
	cout <<endl;
}
// 12.4 thêm phần tử vào đầu danh sách
void Insert_first(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if(first != NULL)
		first->previous = p;
	else // danh sách rỗng trước khi thêm p
		last = p; // sau khi thêm p danh sách có 1 phần tử
	first = p;
}
// 12.5 thêm phần tử vào cuói danh sách
void Insert_Last(int x)
{
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if(last != NULL) // danh sách có phần tử
		last->next = p;
	else // danh sách rỗng trước khi thêm p
		first = p; // sau khi thêm p, danh sách có 1 phần tử là p
	last = p;
}
//12.6 xóa phần tử đầu  của danh sách
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if(first != NULL) // danh sách có phần tử
			first->previous = NULL;
		else
			last = NULL;// danh sách k có phần tử nào
		return 1;
	}
	return 0;
}
//12.6 xóa phần tử cuối của danh sách
int Delete_Last()
{
	if(last != NULL)
	{
		Node *p = last;
	    last = last->previous;
		if(last!=NULL)//  danh sách có phần tử
			last->next = NULL;
		else
			first = NULL; // danh sách k có phần tử nào
		delete p;
		return 1;
	}
	return 0;
}
//tìm phần tử x
Node *Search(int x)
{
	Node *p = first;
	while((p!=NULL) && (p->info!=x))
		p = p->next;
	return p;
}
int SearchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *q, *e;
		Node *p = Search(x);
		q =first;
		e = first;
		if(p==first)
		{
			Delete_first();
		return 1;
		}
		else if(p==last)
		{
			Delete_Last();
			return 1;
		}
		else if(p!=first && p->next!=NULL)
		{
			if(p->next!=NULL)
			{
					q->next=p->next;
					e->previous=q;
			}
			else
			{
				q->next = NULL;
				return 1;
			}
		}
		else
			return 0;
	}
	return 0;	
}
//12.9 tìm phần tử có giá trị x, thêm 1 phàn tử đứng trước x
int SearchAndInsert(int x, int y)
{
	if(first != NULL)
	{
		Node *q,  *e;
		e = first;
		Node *p = Search(x);
		if(p==first)
		{
			Insert_first(y);
		return 1;
		}
		else if(p==last)
		{
			Insert_Last(y);
			return 1;
		}
		else 
		{ 
			Node *q = new Node;
			q->info = y;
			p->previous = q->previous ;
			e->next = q;
			return 1;
		}
		return 0;
	}
}
int main()
{
	int choice = 0;
	 int x, i, y;
	 Node* p;
	 system("cls");
	 cout << " -------- BAI TAP 12, CHUONG 2, DANH SACH LIEN KET KEP -------- " << endl;
	 cout << " 1. Khoi tao danh sach!" << endl;
	 cout << " 2. Xuat danh sach!" << endl;
	 cout << " 3. Them vao dau danh sach!" << endl;
	 cout << " 4. Them vao cuoi danh sach!" << endl;
	 cout << " 5. Xoa dau danh sach!" << endl;
	 cout << " 6. Xoa cuoi danh sach!" << endl;
	 cout << " 7. Tim X va xoa neu co" << endl;
	 cout << " 8. Tim X va them 1 phan tu vao truoc X" << endl;
	 cout << " 9. thoat " << endl;
	do
	{
		cout <<"Vui long chon so de thuc hien:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao DSLK kep thanh cong\n";
			break;
		case 2:
			cout << " danh sach hien tai la:\n";
			Process_list();
			break;
		case 3:
			cout <<"\nVui long nhap gia tri x = \n";
			cin >> x;
			Insert_first(x);
			cout <<"\nDanh sach sau khi them la :";
			Process_list();
			break;
		case 4:
			cout <<"\nVui long nhap gia tri x = ";
			cin >> x;
			Insert_Last(x);
			cout <<"\nDanh sach sau khi them la :";
			Process_list();
			break;
		case 5:
			i = Delete_first();
			if(i == 0)
				cout <<"Danh sach rong k the xoa!"<< x <<endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua DSLK kep !"<<endl;
				cout << "Danh sach sau khi xoa la :";
				Process_list();
			}
			break;
		case 6:
			i = Delete_Last();
			if(i == 0)
				cout <<"Danh sach rong k the xoa duoc!"<< x <<endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua DSLK kep !"<<endl;
				cout << "Danh sach sau khi xoa la :";
				Process_list();
			}
			break;
		case 7:
			cout<<"Vui long nhap gia tri ca tim x";
			cin >> x;
			i = SearchAndDelete(x);
			if(i==1)
			{
				cout << "tim thay x=" << x << "va da xoa thanh cong "<< endl;
				cout << "Danh sach sau khi xoa la:";
				Process_list();
			}
			else
				cout <<"khong tim thay phan tu co gia tri x = " << x <<"!!"<<endl;
			break;
		case 8:
			cout<<"Vui long nhap gia tri can tim x";
			cin >> x;
			cout<<"nhap gia tri y them vao truoc x";
			cin >> y;
			SearchAndInsert(x, y);
			Process_list();
			break;
		case 9:
			cout <<"Goodbye\n";
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}
