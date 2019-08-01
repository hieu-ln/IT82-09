// bài 1, chương 4: CÂY NHỊ PHÂN TÌM KIẾM
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define COUNT 10

// 1.1 khai báo cấu trúc cây nhị phân tìm kiếm 
struct Node {
	int info;
	Node *left;
	Node *right;
};
Node *root;

// 1.2 Khởi tạo cây rỗng
void Init() {
	root = NULL;
}

// 1.3 Thêm một phần tử sử dụng đệ quy, 
//(không sử dụng địa chỉ con trỏ)
int InsertNodeRecursive(int x, Node *q) {
	if (q->info == x) {
		return 0;
	}
	else if (q->info > x) {
		if (q->left == NULL) {
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else {
			return InsertNodeRecursive(x, q->left);
		}
	}
	else {
		if (q->right == NULL) {
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else {
			return InsertNodeRecursive(x, q->right);
		}
	}
}

// (sử dụng con trỏ)
void  InsertNode(Node *&p, int x) {
	if (p == NULL) {
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else {
		if (p->info == x) {
			return; // đã có được giá trị x
		}
		else if (p->info > x) {
			return InsertNode(p->left, x);
		}
		else {
			return InsertNode(p->right, x);
		}
	}
}

// 1.4: Tìm một phần tử dùng đệ quy
Node *Search(Node *p, int x) {
	if (p != NULL) {
		if (p->info == x) {
			return p;
		}
		else {
			if (x > p->info) {
				return Search(p->right, x);
			}
			else {
				return Search(p->left, x);
			}
		}
	}
	return NULL;
}

// 1.5: Xóa một phần tử trong cây sử dụng đẹ quy
void SearchStandFor(Node *&p, Node *&q) {
	if (q->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else {
		SearchStandFor(p, q->left);
	}
}

int Delete(Node *&T, int x) {
	if (T == NULL) {
		return 0;
	}
	if (T->info == x) {
		Node *p = T;
		if (T->left == NULL) {
			T = T->right;
		}
		else if (T->right == NULL) {
			T = T->left;
		}
		else {
			SearchStandFor(p, T->right);
		}
		delete p;
		return 1;
	}
	if (T->info < x) {
		return Delete(T->right, x);
	}
	if (T->info < x) {
		return Delete(T->right, x);
	}
	if (T->info > x) {
		return Delete(T->left, x);
	}
}

// 1.7: Duyệt cây theo LNR dung Đệ Quy
void DuyetLNR(Node *p) {
	if (p != NULL) {
		DuyetLNR(p->left);
		cout  << p->info<< setw(4);
		DuyetLNR(p->right);
	}
}

// 1.7: Duyệt cây theo NLR dung Đệ Quy
void DuyetNLR(Node *p) {
	if (p != NULL) {
		cout << p->info<< setw(4) ;
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

// 1.8: Duyệt cây theo LRN dung Đệ Quy
void DuyetLRN(Node *p) {
	if (p != NULL) {
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info<< setw(4) ;
	}
}

void print2DUtil(Node *p, int space) {
	//Base case
	if (p == NULL) {
		return;
	}
	// Increase distance between levels
	space += COUNT;
	// process right child first
	print2DUtil(p->right, space);
	// print current node after space 
	// count 
	cout << endl;
	for (int i = COUNT; i < space; i++) {
		cout << "\t";
	}
	cout << p->info << endl;
	// process left child
	print2DUtil(p->left, space);
}

// Wrapper over print2DUtil()
void ProcessTree() {
	// pass initial space count as 0
	print2DUtil(root, 0);
}

int main() {
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "------ Bai tap 1, Chuong 4, cay nhi phan tim kiem -------\n";
	cout << "1. Khoi tao Cay NPTK.\n";
	cout << "2. Them mot phan tu vao Cay NPTK.\n";
	cout << "3. Tim phan tu co gia tri x trong Cay NPTK.\n";
	cout << "4. Xoa phan tu co gia tri x trong Cay NPTK.\n";
	cout << "5. Duyet Cay NPTK theo LNR.\n";
	cout << "6. Duyet Cay NPTK theo NLR.\n";
	cout << "7. Duyet Cay NPTK theo LRN.\n";
	cout << "8. Xuat Cay NPTK.\n";
	cout << "9. Thoat.\n";
	do {
		cout << "Vui long nhap so đe thuc hien chuong trinh: ";
		cin >> choice;
		switch (choice) {

			case 1:
				Init();
				cout << "Bạn vừa khởi tạo cây Nhị Phân Tìm Kiếm thành công.\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x can them: ";
				cin >> x;
				InsertNode(root, x);
				cout << "Cay NPTK sau khi them là: ";
				ProcessTree();
				break;
			case 3:
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				p = Search(root, x);
				if (p != NULL) {
					cout << "Tim thay x = " << x << "trong Cay NPTK.\n";
				}
				break;
			case 4:
				cout << "Vui long nhap gia tri x can xoa: ";
				cin >> x;
				i = Delete(root, x);
				if (i == 0) {
					cout << "Khong tim thay x = " << x << " de xoa !!!\n";
				}
				else {
					cout << "Da xoa thanh cong phan tu x = " << x << endl;
					cout << "Cay NPTK sau khi xoa la: ";
					ProcessTree();
				}
				break;
			case 5:
				cout << "Cay NPTK duyet theo LNR la: ";
				DuyetLNR(root);
				break;
			case 6:
				cout << "Cay NPTK duyet theo NLR la: ";
				DuyetNLR(root);
				break;
			case 7:
				cout << "Cay NPTK duyet theo LRN la: ";
				DuyetLRN(root);
				break;
			case 8:
				cout << "Cay NPTK duyet nhu sau: ";
				ProcessTree();
				break;
			case 9:
				cout << "Goodbye ......! \n";
				break;
			default: 
				break;

		}
	} while (choice != 9);
	system("pause");
	return 0;
}