//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//#define MAX 100
//int A[MAX], n;
//void output(int A[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << setw(4) << A[i];
//	cout << endl;
//}
//void input(int A[], int n)
//{
//	for (int i = 0; i < n; i++)
//		A[i] = rand() % 10;
//	output(A, n);
//}
//int search(int A[], int n, int x)
//{
//	int i = 0;
//	while (i < n && A[i] != x)
//		i++;
//	if (i == n)
//		return -1;
//	return i;
//}
//int binary_search(int A[], int l, int r, int x)
//{
//	if (r >= l)
//	{
//		int mid = (l + r) / 2;   // tranh tran so: l + (r - l) / 2
//		if (A[mid] == x)
//			return mid;
//		if (A[mid] > x)
//			return binary_search(A, l, mid - 1, x);
//		else
//			return binary_search(A, mid + 1, r, x);
//	}
//	return -1;
//}
//int Search_Delete(int A[], int &n, int x)
//{
//	int b = search(A, n, x);
//	if (b >= 0 && b < n)
//	{
//		for (int j = b; j < n - 1; j++)
//			A[j] = A[j + 1];
//		n--;
//		return 1;
//	}
//	return 0;
//}
//void selectionsort(int A[], int n)
//{
//	int min_pos;
//	for (int i = 0; i < n - 1; i++)
//	{
//		min_pos = i;
//		for (int j = i + 1; j < n; j++)
//			if (A[j] < A[min_pos])
//				min_pos = j;
//		swap(A[min_pos], A[i]);
//	}
//}
//int main()
//{
//	int chon, n, x, kq;
//	cout << "---------- BAI TAP 1, CHUONG 2, DANH SACH DAC ----------	" << endl;
//	cout << "1.Nhap danh sach. " << endl;
//	cout << "2.Sap xep danh sach." << endl;
//	cout << "3.Xuat danh sach. " << endl;
//	cout << "4.Tim phan tu bang pp tuan tu. " << endl;
//	cout << "5.Tim phan tu bang pp binayra_search." << endl;
//	cout << "6.Tim phan tu tai vi tri x va xoa no neu co." << endl;
//	cout << "7.Thoat" << endl;
//	do{
//		cout << "chon muc: ";
//		cin >> chon;
//		switch(chon)
//		{
//		case 1:
//			cout << "nhap so phan tu co trong ds: ";
//			cin >> n;
//			input(A,n);
//			break;
//		case 2:
//			selectionsort(A, n);
//			cout << "Danh sach sau khi duoc sap xep: " << endl;
//			output(A,n);
//			break;
//		case 3:
//			cout << "Cac phan tu hien co trong danh sach:" << endl;
//			output(A, n);
//			break;
//		case 4:
//			cout << "nhap so can tim: ";
//			cin >> x;
//			kq = search(a, n, x);
//			if (kq == -1)
//				cout << "Khong tim thay!" << endl;
//			else
//				cout << "Xuat hien tai vitri " << kq << endl;
//			break;
//		case 5:
//			cout << "nhap so can tim: ";
//			cin >> x;
//			kq = binary_search(A, 0, n - 1, x);
//			if (kq == -1)
//				cout << "Khong tim thay!" << endl;
//			else
//				cout << "Xuat hien tai vitri " << kq << endl;
//			break;
//		case 6:
//			cout << "nhap gia tri x muon xoa: ";
//			cin >> x;
//			kq = Search_Delete(A, n, x);
//			if (kq == 0)
//				cout << "Khong tim thay!" << endl;
//			else
//				cout << "ds sau khi xoa: ";
//			output(A, n);
//			break;
//		case 7:
//			cout << "tam biet!" << endl;
//			break;
//		default:
//			cout << "nhap sai, nhap lai!" << endl;
//			break;
//		}
//	}while(chon != 7);
//	_getch();
//	return 0;
//}
