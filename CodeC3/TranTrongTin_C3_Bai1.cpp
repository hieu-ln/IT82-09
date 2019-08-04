#include <iostream>
#include <stdio.h>
#include <ctime>
#define MAX 10000
using namespace std;
int a[MAX];
int n;
void input(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
void CoppyArray(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void insertionSort(int a[], int n)
{
	int x, i ,j;
	for(i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}

}
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for(i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		QuickSort(a, left, j);
	if(i < right)
		QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2*i + 1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
		j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n/2;
	while(i >= 0)
	{
		shift(a, i, n - 1);
			i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i; // i la vi tri cua x trong ds a
	else
		return -1;
}
int Search_Binary(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(x = a[mid])
			return mid;
		else
			if(x > a[mid])
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
int main()
{
	int b[MAX];
	int x, t, choice;
	clock_t start;
	double duration;
	while(true) // khoi tao vong lap chay vo han
	{
		cout << "\nNhap chon:\n"
			 << "0. Thoat\n"
			 << "1. Khoi tao danh sach\n"
			 << "2. Xuat danh sach\n"
			 << "3. Xep thu tu bang InsertionSort\n"
			 << "4. Xep thu tu bang SelectionSort\n"
			 << "5. Xep thu tu bang InterchangeSort\n"
			 << "6. Xep thu tu bang BubbleSort\n"
			 << "7. Xep thu tu bang QuickSort\n"
			 << "8. Xep thu tu bang HeapSort\n"
			 << "9. Tim kiem tuan tu\n"
			 << "10. Tim kiem nhi phan\n"
			 << "Chon: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				return 1;
				break;
			case 1:
				cout << "Nhap so phan tu can dung: ";
				cin >> n;
				input(a, n);
				break;
			case 2:
				cout << "Mang vua tao la: \n";
				output(a, n);
				break;
			case 3:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				insertionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000) 
				{
					cout << "Mang sau khi sap xep bang InsertionSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian InsertionSort la: " << duration * 1000000 << " ms\n";
				break;
			case 4:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				SelectionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000)
				{
					cout << "Mang sau khi sap xep bang SelectionSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian SelectionSort la: " << duration * 1000000 << " ms\n";
				break;
			case 5:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				InterchangeSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000)
				{
					cout << "Mang sau khi sap xep bang InterchangeSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian InterchangeSort la: " << duration * 1000000 << " ms\n";
				break;
			case 6:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				BubbleSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000)
				{
					cout << "Mang sau khi sap xep bang BubbleSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian BubbleSort la: " << duration * 1000000 << " ms\n";
				break;
			case 7:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				QuickSort(b, 0, n - 1);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000)
				{
					cout << "Mang sau khi sap xep bang QuickSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian QuickSort la: " << duration * 1000000 << " ms\n";
				break;
			case 8:
				cout << "Mang truoc khi sap xep la: \n";
				output(a, n);
				CoppyArray(a, b, n);
				start = clock();
				HeapSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n < 10000)
				{
					cout << "Mang sau khi sap xep bang HeapSort la: \n";
					output(b, n);
				}
				if(duration > 0)
					cout << "Thoi gian HeapSort la: " << duration * 1000000 << " ms\n";
				break;
			case 9:
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if(Search(a, n, x) != -1)
					cout << "Tim thay " << x << " tai vi tri " << Search(a, n, x) << endl;
				else
					cout << "Khong tim thay " << x << " trong mang\n";
			case 10:
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				t = Search_Binary(b, n, x);
				if(t == -1)
					cout << "Tim khong thay gia tri" << x << endl;
				else
					cout << "Tim thay gia tri " << x << " tai vi tri " << t << endl;
				break;
			default:
				cout << "Gia tri chon khong hop le!\n";
				break;
		}
	}
	return 0;
}