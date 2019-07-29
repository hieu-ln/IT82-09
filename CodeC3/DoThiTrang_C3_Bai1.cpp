//BAI TAP 1 CHUONG 3: XEP THU TU, TIM KIEM 
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 3000
//CAU 1.1
int A [MAX];
int n;

//CAU 1.0: NHAP DANH SACH TU DONG 
void init (int a[], int &n)
{
	cout <<" Nhap vao so luong phan tu cua danh sach:";
	cin >>n;
	for (int i =0 ; i <n ; i++)
	{
		a[i]= rand() % 10000 +1;
	}
	cout <<" Danh sach da duoc nhap ngau nhien nhu sau :"<< endl;
	for (int i=0; i <n ; i++)
	{
		cout << a[i] <<" "; 
	}
	cout << endl;
}

//CAU 1.2: NHAP DANH SACH 
void input (int a[], int &n)
{
	cout <<" Nhap vao so luonh phan tu cua danh sach :";
	cin >>n;
	cout <<" nhap vao cac phan tu cua danh sach :" <<endl;
	for (int i = 0 ; i <n; i++)
	{
		cout << "a[" <<i << "]=";
		cin >> a[i];
	}    
}

//CAU 1.3 XUAT DANH SACH 
void output(int a[], int n)
{
	for (int i=0; i <n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
 
void CopyArray(int a[], int b[], int n)
{
	for (int i=0; i <n; i++)
	{
		b[i]= a[i];
	}
}

//CAU 1.4 Insertion Sort
void InsertionSort (int a[], int n
{
	int i , key , j ;
	for (i=1 ; i <n; i++)
	{
		key = a[i];
		j=i-1;

		/*Di chuyen cac phan tu co gia tri lon hon gia tri key ve sau mot vi tri so voi vi tri ban dau cua no */
		while (j >=0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

//Ham doi cho 2 so nguyen 
void swap (int &a, int &b)
{
	int t = a;
	a=b;
	b=t;
}

//CAU 1.5 SELECTION SORT
void selectionSort (int a[], int n)
{
	int i , j , min_idx;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep 
	for (i = 0; i <n; i++)
	{
		// Tim phan tu lon nhat trong mang chua sap xep 
		min_idx = i;
		for (j = i+1; j <n ; j++)
		if (a[j] < a[min_idx])
			min_idx =j ;
		// Doi cho phan tu nho nhat voi phan tu dau tien
		swap (a[min_idx], a[i]);
	}
}

//CAU 1.6 
void interchangeSort (int a[], int n)
{
	for (int i=0; i <n-1; i++)
		for (int j =i+1; j <n; j ++)
			if (a[i] > a[j])
				swap(a[i], a[j]); // doi cho a[i] va a[j]
}

//CAU 1.7 HAM SAP XEP BUBBLE SORT 
void BubbleSort (int arr[], int n)
{
	int i , j ; 
	bool haveSwap = false;
	for (int i=0; i <n-1; i++)
	{
		//i phan tu cuoi cung da duoc sap xep 
		haveSwap = false;
		for (int j =0; j <n-1; j ++)
		{
			if (arr[j] > arr[j+1])
			{
				swap (arr[j], arr[j+1]);
				haveSwap = true ; // Kiem tra lan lap nay co swap khong 
			}
		}
		// Neu khong co swap nao duoc thuc hien => Mang da sap xep ,khong can lap them
		if (haveSwap == false)
		{
			break;
		}
	}
}

//CAU 1.8
/*Ham thuc hien giai thuat quick sort */
void QuickSort (int a[], int left , int right)
{
	int x = a[(left + right )/2];
	int i = left ; 
	int j = right ; 
	while (i<j)
	{
		while (a[i] <x)
			i++;
		while (a[j] >=x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j] ; // doi cho a[i] va a[j])
			i++;
			j--;
		}
	}
	if (left <j )
		QuickSort (a, left , j );
	if (i< right)
		QuickSort (a,i, right);
}

// CAU 1.9
void shift(int a[], int i , int n)
{
	int j = 2* j +1;
	if (j>=n) // Neu vi tri j khong ton tai trong danh sach dang xet thi thoat 
		return ;
	if (j+1 <n) //Neu ton btai vi tri j +1 trong danh sach dang xet 
		if (a[j] < a[j+1]) // neu phan tu a[j] < a[j+1]
			j++; // Luu vi tri phan tu lon hon trong hai phan tu vi tri j 
	if (a[i] >= a[j]) // Xet a[i] la pahn tu lon nhat trong 3 phan tu a[i], a[2*i+1], a [2*i+2]
		return ; // thoat chuong trinh 
	else //a[i] khong la phan tu lon nhat trong 3 phan tu a[i], a[2*i+1], a [2*i+2]
	{
		int x = a[i];
		a[i]= a[j];
		a[j] = x; 
		shift(a, j , n ); // Xet tinh lan truyen tai vi tri phan tu vua hoan doi
	}
}

void HeapSort(int a[] , int n)
{
	int i = n/2 -1;
	while (i >= 0) // Tao heap ban dau 
	{
		shift (a, i , n);
		i--;
	}
	int right = n -1 ; // right la vi tri cuoi Heap dang xet 
	while (right >0)
	{
		swap (a[0], a[right]); // Hoan vi phan tu a[0] cho phan tu cuoi Heap dang xet 
		right--; //Gioi han phan tu cuoi day dang xet 
		if(right >0)//Kiem tra day dang xet con nhieu hon 1 phan tu 
			shift (a, 0 , right ); //Tao heap lai tai vi tri 0
	}
}

//CAU 1.10
int searchSequence (int a[], int n, int x)
{
	int i = 0; 
	while (i <n &&a[i] !=x)
	{
		i++;
	}
	/*if (i == n) {
	cout <<" khong tim thay ";
	}
	else{
	cout <<" tim thay tai vi tri " <<i;
	}*/
	if (i==n)
		return -1;
	else 
		return i;
}
// CAU 1.11
int searchBinary (int a[], int l, int r, int x)
{
	if (r >=1)
	{
		int mid = 1 +(r-1)/2; // tuong duong (1+r)/2 nhung uu diem tran so khi 1 , r lon 
		// Neu a[mid] = x , tra ve chi so ket thuc.
		if (a[mid] == x)
			return mid; 
		//Neu a[mid] >x , thuc hien tim kiem nua trai cua mang 
		if (a[mid] > x)
			return searchBinary (a, l , mid -1, x); 
		//Neu a[mid]< x, thuc hien tim kiem nua phai cua mang 
		if (a[mid] < x)
			return  searchBinary (a, l , mid +1, x); ; 
	}
	//Neu khong tim thay 
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice , x, i;
	system ("cls");
	cout <<"----------BAI TAP 1, CHUONG 3, XEP THU TU VA TIM KIEM----------------" <<endl;
	cout <<"0. Khoi tao danh sach ngau nhien " <<endl;
	cout <<"1. nhap danh sach" << endl ; 
	cout <<"2. xuat danh sach" << endl;
	cout <<"3. xep thu tu danh sach bang SELECTION SORT"<< endl;
	cout <<"4. xep thu tu danh sach bang INSERTION SORT"<< endl;
	cout <<"5. xep thu tu danh sach bang BUBBLE SORT"<< endl;
	cout <<"6. xep thu tu danh sach bang INTERCHANGE SORT"<< endl;
	cout <<"7. xep thu tu danh sach bang QUICK SORT"<< endl;
	cout <<"8. xep thu tu danh sach bang HEAP SORT"<< endl;
	cout <<"9. tim kiem phan tu x bang TIM KIEM TUAN TU"<< endl;
	cout <<"10. tim kiem phan tu x bang TIM KIEM NHI PHAN "<< endl;
	cout<<"11. thoat"<<endl;
	do
	{
		cout <<" \nVui long chon so de thuc hien :";
		cin >> choice ;
		switch(choice)
		{
		case 0: // khoi tao random
			init(a,n);
			break;
		case 1:
			input (a, n);
			break;
		case 2:
			cout <<" danh sach la :" << endl;
			output (a,n);
			break;
		case 3:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi SELECTION SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian SELECTION SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 4:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi INSERTION SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian INSERTION SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 5:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi BUBBLE SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian BUBBLE SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 6:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi INTERCHANGE SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian INTERCHANGE SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 7:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi QUICK SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian QUICK SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 8:
			CopyArray(a,b,n);
			start = clock();
			selectionSort(b,n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<" danh sach sau khi xep thu tu voi HEAP SORT la : " << endl;
				output(b,n);
			}
			if (duration >0)
				cout <<" Thoi gian HEAP SORT:" << duration * 1000000 <<" Microseconds" << endl;
			break;
		case 9:
			cout <<" vui long nhap gia tri x=";
			cin >>x;
			start = clock();
			i = searchSequence(a, n ,x);
			if (i==-1)
				cout <<" khong tim thay x=" <<x<< " trong mang !"<< endl;
			else 
				cout <<" tim thay x=" <<x<< " tai vi tri i="<<i<< endl;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (duration >0)
				cout <<"\n-thoi gian tim kiem TUAN TU la :" << duration * 10000000<<" Microsecons" << endl;
			break;
		case 10:
			cout << " vui long nhap gia tri x =";
			cin >>x;
			start = clock();
			i== searchBinary(b, 0, n, x);
			duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
			if (i==-1)
				cout <<" khong tim thay x=" <<x<< " trong day !"<< endl;
			else 
				cout <<" tim thay x=" <<x<< " tai vi tri i="<<i<< endl;
			if (duration >0)
				cout <<"\n-thoi gian tim kiem NHI PHAN la :" << duration * 10000000<<" Microsecons" << endl;
			break;
		case 11:
			cout <<" GOODBYE..... !" <<endl;
			break;
		default:
			break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}