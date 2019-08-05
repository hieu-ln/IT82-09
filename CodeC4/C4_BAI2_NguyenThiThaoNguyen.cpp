#include <iostream>
#include <stack>

using namespace std;

//2.1.Khai báo cấu trúc cây nhị phân tìm kiếm.
struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
NODE* CreateNode(int x)
{
	NODE* p = new NODE();
	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}

//2.4 Viết thủ tục tìm một phần tử trong cây (không dùng đệ quy).
NODE* FindInsert(NODE* root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	NODE* p = root;
	NODE* f = p;
	while (p != NULL)
	{
		f = p;
		if (p->data > x)
		{
			p = p->pLeft;
		}
		else
		{
			p = p->pRight;
		}
	}
	return f;
}

//2.3 Viết thủ tục thêm một phần tử vào cây (không dùng đệ quy).
void InsertNode(NODE* &root, int x)
{
	NODE* n = CreateNode(x);
	if (root == NULL)
	{
		root = n;
		return;
	}
	else
	{
		NODE* f = FindInsert(root, x);
		if (f != NULL)
		{
			if (f->data > x)
			{
				f->pLeft = n;
			}
			else
			{
				f->pRight = n;
			}
		}
	}
}

int LeftOf(const int value, const NODE* root)
{
	// Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
	return value < root->data;
	//    return value <= root->data;
}

int RightOf(const int value, const NODE* root)
{
	return value > root->data;
}

int LeftMostValue(const NODE* root)
{
	while (root->pLeft != NULL)
		root = root->pLeft;
	return root->data;
}

//2.5 Viết thủ tục xóa một nút trong cây (dùng đệ quy).
NODE* Delete(NODE* root, int value)
{
	if (root == NULL)
		return root;
	if (LeftOf(value, root))
		root->pLeft = Delete(root->pLeft, value);
	else if (RightOf(value, root))
		root->pRight = Delete(root->pRight, value);
	else
	{
		// root->data == value, delete this node
		if (root->pLeft == NULL)
		{
			NODE* newRoot = root->pRight;
			free(root);
			return newRoot;
		}
		if (root->pRight == NULL)
		{
			NODE* newRoot = root->pLeft;
			free(root);
			return newRoot;
		}
		root->data = LeftMostValue(root->pRight);
		root->pRight = Delete(root->pRight, root->data);
	}
	return root;
}

void CreateTree(NODE* &root, int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		InsertNode(root, a[i]);
	}
}

//2.7.Viết thủ tục duyệt cây theo thứ tự LNR(dùng stack)
void inOrder(struct NODE *root)
{
	stack<NODE*> s;
	NODE* curr = root;

	while (curr != NULL || s.empty() == false)
	{
		/* Reach the left most Node of the
		   curr Node */
		while (curr != NULL)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s.push(curr);
			curr = curr->pLeft;
		}

		/* Current must be NULL at this point */
		curr = s.top();
		s.pop();

		cout << curr->data << " ";

		/* we have visited the node and its
		   left subtree.  Now, it's right
		   subtree's turn */
		curr = curr->pRight;

	} /* end of while */
}

//2.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng stack)
void preorder(struct NODE *root) {
	if (root == NULL)
		return;
	stack <NODE *> nodeStack;
	nodeStack.push(root);
	while (nodeStack.empty() == false) {
		struct NODE* temp_node = nodeStack.top();
		cout << temp_node->data << " ";
		nodeStack.pop();
		if (temp_node->pRight)
			nodeStack.push(temp_node->pRight);
		if (temp_node->pLeft)
			nodeStack.push(temp_node->pLeft);
	}
}

//2.8.Viết thủ tục duyệt cây theo thứ tự LRN(dùng STACK)
void postorderIterative(NODE* root)
{
	// create an empty stack and push root node
	stack<NODE*> stk;
	stk.push(root);

	// create another stack to store post-order traversal
	stack<int> out;

	// run till stack is not empty
	while (!stk.empty())
	{
		// we pop a node from the stack and push the data to output stack
		NODE *curr = stk.top();
		stk.pop();

		out.push(curr->data);

		// push left and right child of popped node to the stack
		if (curr->pLeft)
			stk.push(curr->pLeft);

		if (curr->pRight)
			stk.push(curr->pRight);
	}

	// print post-order traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
int main()
{
	//2.2.Viết thủ tục khởi tạo cây rỗng.
	NODE* root = NULL;
	//int a[] = { 41, 6, 36, 46, 16, 54, 47, 11, 14, 49, 47 };
	int a[] = { 40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47 };
	int n = 11;
	CreateTree(root, a, n);
	InsertNode(root, 24);
	InsertNode(root, 8);
	InsertNode(root, 15);
	InsertNode(root, 10);
	printf("Duyet LNR: ");
	inOrder(root);
	printf("\nDuyet NLR: ");
	preorder(root);
	printf("\nDuyet LRN: ");
	postorderIterative(root);
	printf("\nXoa Node: 24");
	root = Delete(root, 24);
	printf("\nDuyet LNR: ");
	inOrder(root);
	printf("\nDuyet NLR: ");
	preorder(root);
	printf("\nDuyet LRN: ");
	postorderIterative(root);
	system ("pause");
	return 0;
}