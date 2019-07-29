// Bai 1, chuong 3: XEP THU TU, TIM KIEM
#include<stdio.h>
#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
# define MAX 2000
// 1.1
int a[MAX];
int n;

//0.a Nhap
void init(int a[], int &n){
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n- 1; i ++){
		a[i] = rand() % 1000 + 1;
	}
	cout << "Danh sach da duoc nhap ngau nhien: ";
	for (int i = 0; i < n; i++){
		cout << setw(4) << a[i]	;
	}
	cout << endl;
}

// 1.
int input(int a[], int &n){
	cout << "Nhap so luong phan tu muon nhap: ";
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cout << "a["<< i << "]= ";
		cin >> a[i];
	}
}

//1.2 Xuat
void output(int a[], int n){
	for(int i = 0; i < n ; i++){
		cout  << setw(4) << a[i];
	}
	cout << endl;
}

// cope
void copeArr(int a[], int b[], int n){
	for (int i = 0; i < n ; i++){
		b[i] = a[i];
	}
}

//1.3 insertionSort
void insertionSort(int a[], int n){
	int i, key, j;
	for(i =1; i< n; i ++){
		key = a[i];
		j = i - 1;
		/*Di chuyển cá phàn tử có giá trị lớn hơn giá trị key về sau một vị trí ban đầu cảu nó*/
		while(j >= 0 && a[j] > key){
			a[j = 1] = a[j];
			j = j -1;
		}
		a[j + 1] = key;
	}
}

// hoan doi
void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

// 1.4 selectionSoft
void selectionSort(int a[], int n){
	int i, j , min;
	// di chuyển ranh giới của mảng đã sắp xếp
	for(i =0; i < n - 1; i++){
		// tìm phần tử nhỏ nhất trong mảng chưa sắp xếp 
		min = i;
		for(j = i +1; j < n; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		// đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(a[min], a[i]);
	}
}

// 1.5 interChangeSort
void interChangeSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] < a[j]){
				swap(a[i], a[j]);
			}
		}
	}
}

// 1.6 bubbleSort
void bubbleSort(int a[], int n){
	int i, j;
	bool kt = false;
	for( i =0; i < n - 1; i ++){
		kt = false;
		for (j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
				kt = true;
			}
		}
		if(kt == false){
			break;
		}
	}
}

// 1.7 heapSort
void heapSort(int a[], int n)
{
	int i = n / 2 * i - 1;
	while(i >= 0) // Tạo heap ban đầu 
	{
		shift(a, i, n);
		i--;
	}
	int right = n - 1; // right5 là vị trí cuối HEAP đang xét
	while(right > 0)
	{
		swap(a[0], a[right]); 
		right --;
		if(right > 0) // kiểm tra dãy đang xét còn nhiều hơn 1 phân
		{
			shift(a, 0, right); // Tạo heap tại vị trí 0
		}
	}
}

//1.8
void shift(int a[], int i, int n) {
	int j = 2 * i + 1;
	if (j >= n) {
		return; // nếu vị trí j không tồn tại trong danh sách đang xét thì thoát
	}
	if (j + 1 < n) { // nếu tồn tại vị trí j+1 trong danh sach đang xét
		if (a[j] < a[j + 1]) { // nếu phần tử a[j] < a[j + 1]
			j++; /// lưu phần tử có vị trí lớn hơn trong hai phân tử ở vị trí j
		}
	}
	if (a[i] >= a[j]) {
		return; // thoát khỏi chương trình
	}
	else {// a[i] không là phần tử lớn nhất 3 phần tử a[i], a[2 * i + 1], a[2 * i + 2]
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);// xét tính lan truyền tại vị trí phần tử vừa hoán đổi
	}
}

int partition(int a[], int low, int high) {
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && a[left] < pivot) { left++; }
		while (right >= left && a[right] > pivot) { right--; }
		if (left >= right) {
			break;
		}
		swap(a[left], a[right]);
		return left;
	}
}

void QuickSoft(int a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (a[i] < x) {
			i++;
		}
		while (a[j] > x) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j) {
		QuickSoft(a, left, j);
	}
	if (right > i) {
		QuickSoft(a, i, right);
	}
}

// 1.10
int searchSquence(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i == n) {
		return -1;
	}
	else {
		return i;
	}
}
// 1.11
int searchBinary(int a[], int left, int right, int x) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] > x) {
			return searchBinary(a, left, mid - 1, x);
		}
		if (a[mid] < x) {
			return searchBinary(a, mid + 1, right, x);
		}
	}
	return -1;
}





int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choise, x, i;
	system("cls");
	cout << "---------- BAI TAP 1, CHUONG 3: XAP XEP THU TU va TIM KIEM --------------" ;
	cout << "0. khoi tao danh sach ngau nhien.\n";
	cout << "1. nhap danh sach.\n";
	cout << "2. xuat danh sach.\n";
	cout << "3. Xep thu tu danh sach bang SELECTION SORT.\n";
	cout << "4. Xep thu tu danh sach bang INSERTION SORT.\n";
	cout << "5. Xep thu tu danh sach bang BUBBLE SORT.\n";
	cout << "6. Xep thu tu danh sach bang INTRCHANGE SORT.\n";
	cout << "7. Xep thu tu danh sach bang QUICK SORT.\n";
	cout << "8. Xep thu tu danh sach bang HEAP SORT.\n";
	cout << "9. tim kiem phan tu x bang TIM KIEM TUAN TU.\n";
	cout << "10. tim kiem phan tu x bang TIM KIEM NHI PHAN.\n";
	cout << "11. thoat\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choise;
		switch(choise){
		case 0:
			init(a,n);
			break;
		case 1:
			input(a,n);
			break;
		case 2:
			cout << "Danh sach: ";
			output(a,n);
			break;
		case 3:
			copeArr(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi SELECTION SORT la: "<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 4:
			copeArr(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi INSERTION SORT la: "<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 5:
			copeArr(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi BUBBLE SORT la: "<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 6:
			copeArr(a, b, n);
			start = clock();
			interChangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi INTERCHANGE SORT la: "<< endl;
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian INERTCHANGE SORT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 7:
			copeArr(a, b, n);
			start = clock();
			QuickSoft(b, 0, n-1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi QUICK SOFT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QUICK SOFT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 8:
			copeArr(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi HEAP SOFT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HEAP SOFT: " << duration * 1000000 << "Microseconds\n" << endl;
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			searchSquence(a,n,x);
			if (i == -1) {
				cout << "Khong tim thay x = " << x << " trong day !!!\n";
			}
			else {
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				if (duration > 0) {
					cout << "Thoi gian tim kiem TUAN TU la: " << duration * 1000000 << "Microseconds\n" << endl;
				}
			}
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary(a, 0, n - 1, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1) {
				cout << "Khong tim thay x = " << x << " trong day !!!\n";
			}
			else {
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
				if (duration > 0) {
					cout << "Thoi gian tim kiem NHI PHAN la: " << duration * 1000000 << "Microseconds\n" << endl;
				}	
			}
			break;
		case 11:
			cout << "Goodbye .... !!!";
			break;
		default: 
		}
	}while(choise != 11);
	system("pause");
	return 0;
} 