//Bai 1, Chuong 3: XEP THU TU, TIM KIEM
#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;

#define MAX 5000
// CAU 1.1
int a[MAX];
int n;

// caau 1.2 : nhap danh sach
void init(int a[], int &b)
{
	cout <<"nhap vao so luong phan tu cua danh sach:";
	cin >> n;
	for(int i =0; i<n; i++)
	{
		a[i] = rand() % 10000 +1;
	}
	cout <<"danh sach da duocj nhap ngau nhien nhu sau:"<<endl;
	for(int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
}
// cau 1.2 : nhap danh sach
void input(int a[], int &n)
{
	cout <<"nhap vao so luong phan tu cua danh sach:";
	cin >> n;
	cout <<"Nhap vao cac phan tu cua danh sach:" <<endl;
	for(int i =0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
//cau 1.3 XUAT DANH SACH
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << a[i] <<" ";
	}
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
		b[i] = a[i];
}
// 1.4 InsertionSort
void InsertionSort(int a[], int n)
{
	int i, key, j;
	for( i=1; i<n; i++)
	{
		key = a[i];
		j = i-1;
		/*di chuyen cac phan tu co gia tri lon hon gia tri key ve sau 1 vi tri so voi vi tri ban dau
		*/
		while(j >= 0  && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j -1;
		}
		a[j+1] = key;
	}
}
// ham hoan vi
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
// cau 1.5 SelectionSort
void SelectionSort(int a[], int n)
{
	int i, j, min_idx;
	// di chuyen ranh gio cua mang da sap xep va chua sap xep
	for(i = 0; i< n-1; i--)
	{ 
		// tim phan tu nho nhat trong mang chua sap xep
		min_idx = i;
		for(j = i+1; j<n; j++)
			if(a[j] < a[min_idx])
				min_idx = j;
		// doi cho phan tu nho nhat voi pah tu dau tien
		swap(a[min_idx], a[i]);
	}
}
// cau 1.6
void InterchangeSort(int a[], int n)
{
	for(int i =0; i<n - 1; i++)

		for(int j = i +1; j<n; j++)
			if(a[i] >a[j])
				swap(a[i], a[j]);
}
 // cau 1.7 ham sap xep Bubble Sort
void BubbleSort(int a[], int n)
{
	int i, j;
	bool haveSwap = false;
	for(i =0; i< n-1; i++)
	{
		// I PHAN TU CUOI CUNG DA DUOC SAP XEP
		haveSwap =  false;
		for(j =0; j < n-i-1; j ++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true; // kiem tra lan lap nay co swap hay k
			}
		}
		// neu k co swap nao duocj thuc hien-> amng da duoc sap xep
		if(haveSwap ==  false)
		{
			break;
		}
	}
}
//1.8 quick sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while(a[i] < x)
			i++;
		while(a[i] < x)
			j--;
		if(i<= j)
		{
			swap(a[i], a[j]); // doi cho  cho a[i] va a[j]
			i++;
			j--;
		}
	}
	if(left < j)
		QuickSort(a, left, j);
	if(i < right)
		QuickSort(a, i, right);
}
//1.9 heapSort
void shift(int a[], int i, int n)
{
	int j = 2 * i +1;
	if(j >= n)// neu vi tri j k ton tao trong damh sach danh xet thi thoat
		return;
	if(j+1 < n) // neu ton tai vi tri j+1 reong danh sach dang xet
		if(a[j] < a[j+1])
			j++;
	// luu vi tri phan tu lon hon trong 2 phan tu vitri j

	if(a[i] >= a [j]) // xet a[i] la pha tu lonw nhat trong 3 phan tu a[i], a[2*I+1], a[2*I+2]
		return;
	else // a[i] k laf pha tu lon nhat trong 3 phan tu a[i], a[2*I+1], a[2*I+2]
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n); // xet tinh lan truyen  tai vi tri phan tu hoan doi
	}
}
 void HeapSort(int a[], int n)
 {
	 int i = n/ 2-1;
	 while(i>=0)// tao heap ban dau
	 {
		 shift(a, i, n);
		 i--;
	 }
	 int right = n-1; // right la vi tri cuoi Heap dang xet
	 while (right > 0)
	 {
		 swap(a[0], a[right]); 
		 right --;// gio han phan tu cuoi day dang xet
		 if(right > 0) // kiem tra day dang xet con nhieu hon 1 phan tu
			 shift(a, 0, right);// tai heap lai tai vitri 0
	 }
 }
 //1.10 Tim kiem tuan tu
 void SearchSequence(int a[], int n, int x)
 {
	 int i = 0;
	 while (i < n && a[i]!= x)
	 {
		 i++;
	 }
	 if (i == n)
	 {
		 cout << "khong tim thay";
	 }
	 else 
	 {
		 cout << "tim thay tai vi tri :" << i << endl ;
	 }
 }
 // cau 1.11 tim kiem nhi phan
 //int SearchBinary(int a[],int l, int r, int x)
 //{
	// if(r >= 1)
	// {
	//	 int mid =  1+(r -1)/2; 
	//	 // neu a[mid] = x , tra ve chi so va key=t thuc
	//	 if(a[mid] == x)
	//		 return mid;
	//	 // neu a[mid] > x ,thuc hien tim kiem nua trai cua mang
	//	  if(a[mid] > x)
	//		  return SearchBinary(a, l, mid -1, x);
	//	   // neu a[mid] > x ,thuc hien tim kiem nua phai cua mang
	//	   return SearchBinary(a, l, mid +1, x);
	// }
	// // neu k tim thay
	// return -1;
 //}
 int SearchBinary(int a[],int n, int x)
 {
	 int left = 0, right = n-1, mid;
	 while(left <= right)
	 {
		 mid = (left + right)/2;
		 if(a[mid] == x)
			 return mid;
		 if(x>a[mid])
			 left =  mid +1;
		 else 
			 right = mid -1;
	 }
	 return -1; // k tim thay x trong danh sach
 }
	
 int main()
 {
	 int b[MAX];
	 clock_t start;
	 double duration;
	 int choice, x, i;
	 system("cls");
     cout<<"-------BAI TAP 1, CHUONG III, XEP THU TU VA TIM KIEM--------------------"<<endl;
	 cout<<"0. Khoi tao danh sach ngau nhien "<< endl;
	 cout<<"1. Nhap danh sach"<< endl;
	 cout<<"2. Xuat danh sach"<< endl;
	 cout<<"3. Xep thu tu danh sach bang SELECTION SORT"<< endl;
	 cout<<"4. Xep thu tu danh sach bang INSERTION SORT"<< endl;
	 cout<<"5. Xep thu tu danh sach bang BUBBLE SORT"<< endl;
	 cout<<"6. Xep thu tu danh sach bang INTERCHANGE SORT"<< endl;
	 cout<<"7. Xep thu tu danh sach bang QUICK SORT"<< endl;
	 cout<<"8. Xep thu tu danh sach bang HEAP SORT"<< endl;
	 cout<<"9. Tim phan tu X bang TIM KIEM TUAN TU"<< endl;
	 cout<<"10. Tim phan tu X bang TIM KIEM NHI PHAN"<< endl;
	 cout<<"11. Thoat"<< endl;
	 do
	 {
		cout<<"Vui long chon so de thuc hien:";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			cout <<"Danh sach da nhap la!\n";
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang SELECTION SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian SELECTION SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang INSERTION SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian INSERTION SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang BUBBLE SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian BUBBLE SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang INTERCHANGE SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian INTERCHANGE SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n-1);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang QUICK SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian QUICK SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << "Danh sach sau khi sap xep bang HEAP SORT la:" << endl;
				output(b, n);
			}
			if(duration > 0)
				cout << "thoi gian HEAP SORT: " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 9:
			cout <<"Vui long nhap X can tim :";
			cin >> x;
			SearchSequence(a, n, x);
			if(i ==  -1)
				cout << "tim khong thay phan tu co gia tri" << x <<endl;
			else
				cout << "tim thay tai vi tri i =" << i <<endl;
			
			if(duration > 0)
				cout << "thoi gian tim phan tu x bang TIM KIEM TUAN TU : " << duration * 1000000 << "Microseconds" << endl;
			break;
		
		case 10:
			cout <<"Vui long nhap X can tim :";
			cin >> x;
			i = SearchBinary(b, n, x);
			if(i == -1)
				cout << "tim khong thay phan tu co gia tri" << x <<endl;
			else
				cout << "tim thay tai vi tri i =" << i <<endl;
			if(duration > 0)
				cout << "thoi gian tim phan tu x bang TIM KIEM NHI PHAN : " << duration * 1000000 << "Microseconds" << endl;
			break;
		case 11:
			cout << "\nGoodbye!";
			break;
		default:
			break;
		}
	 }
	 while(choice!=11);
	system("pause");
	return 0;
 }