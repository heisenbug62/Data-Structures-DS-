//#include <iostream>
//using namespace std;
//
//struct node {
//	int data;
//	node* left;
//	node* right;
//};
//
//class tree {
//protected:
//	node* root;
//
//public:
//	tree()
//	{
//		root = nullptr;
//	}
//
//	void insert(int val)
//	{
//		node* nn = new node;
//		nn->data = val;
//		nn->left = nullptr;
//		nn->right = nullptr;
//
//		if (root == nullptr)
//		{
//			root = nn;
//		}
//
//		else
//		{
//			node* p = root;
//
//			while (1)
//			{
//				if (val < p->data)
//				{
//					if (p->left == nullptr)
//					{
//						p->left = nn;
//						break;
//					}
//					else
//					{
//						p = p->left;
//					}
//				}
//
//				else if (val > p->data) 
//				{
//					if (p->right == nullptr)
//					{
//						p->right = nn;
//						break;
//					}
//
//					else
//					{
//						p = p->right;
//					}
//				}
//
//				else
//				{
//					cout << "No Duplication is Allowed in BST" << endl;
//					break;
//				}
//			}
//		}
//	}
//	//-------------------
//	void preorder(node* p)
//	{
//		if (p!=nullptr)
//		{
//			cout << p->data << endl;
//			preorder(p->left);
//			preorder(p->right);
//		}
//	}
//
//	void PREORDER()
//	{
//		preorder(root);
//	}
//	//-------------------
//	void inorder(node* p)
//	{
//		if (p != nullptr)
//		{
//			inorder(p->left);
//			cout << p->data << endl;
//			inorder(p->right);
//		}
//	}
//
//	void INORDER()
//	{
//		inorder(root);
//	}
//	//-------------------
//	void postorder(node* p)
//	{
//		if (p != nullptr)
//		{
//			inorder(p->left);
//			inorder(p->right);
//			cout << p->data << endl;
//		}
//	}
//
//	void POSTRDER()
//	{
//		postorder(root);
//	}
//
//	void search(int key)
//	{
//		node* p = root;
//
//		if (p == nullptr)
//		{
//			cout << "BST is empty" << endl;
//			return;
//		}
//
//		while (1)
//		{
//			if (key == p->data)
//			{
//				cout << "Key found in BST" << endl;
//				break;
//			}
//			else if (key < p->data)
//			{
//				if (p->left != nullptr)
//				{
//					p = p->left;
//				}
//				else
//				{
//					cout << "Key not found in BST" << endl;
//					break;
//				}
//			}
//			else 
//			{
//				if (p->right != nullptr)
//				{
//					p = p->right;
//				}
//				else
//				{
//					cout << "Key not found in BST" << endl;
//					break;
//				}
//			}
//		}
//	}
//
//};
//
//int main()
//{
//	tree obj;
//
//	obj.insert(10);
//	obj.insert(2);
//	obj.insert(3);
//	obj.insert(40);
//	obj.insert(54);
//	obj.insert(66);
//
//	obj.PREORDER();
//
//}