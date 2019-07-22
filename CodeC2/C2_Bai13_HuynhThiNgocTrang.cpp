//#include <iostream>
//using namespace std;
//#define MAX 10
//void xuat(int A[], int n)
//{
//	for (int i = n; i >= 0; i--)
//	{
//		if (i == 0)
//			cout << A[i];
//		else
//			if (A[i] != 0)
//				cout << A[i] << "x^" << i << " + ";
//	}
//	cout << endl;
//}
//void nhap(int A[], int &n)
//{
//	do {
//		cout << "Bac cua da thuc: ";
//		cin >> n;
//		if (n < 1)
//			cout << "bac cua da thuc phai >= 1" << endl;
//		} while (n < 1);
//		for (int i = n; i >= 0; i--)
//		{
//			cout << "Nhap he so thu " << i << ": ";
//			cin >> A[i];
//		}
//		xuat(A,n);
//}
//void cong(int A[], int B[], int C[], int n, int m)
//{
//	int nc;
//	if (n > m)
//		nc = n;
//	else
//		nc = m;
//	for (int i = nc; i >= 0; i--)
//	{
//		if (A[i] != 0 && B[i] != 0)
//			C[i] = A[i] + B[i];
//		else
//		{
//			if (A[i] == 0)
//				C[i] = B[i];
//			else
//				if (B[i] == 0)
//					C[i] = A[i];
//		}
//	}
//	xuat(C, nc);
//}
//int main()
//{
//	int A[MAX] = { 0 }, B[MAX] = { 0 }, C[MAX] = { 0 }, n, m;
//	cout << "Nhap P(x):" << endl;
//	nhap(A, n);
//	cout << "Nhap Q(x):" << endl;
//	nhap(B, m);
//	cout << "P(x) + Q(x): ";
//	cong(A, B, C, n, m);
//	system("pause");
//	return 0;
//}