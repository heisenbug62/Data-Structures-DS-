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
//	void inorderToList(node* p, linkedlist& ll)
//	{
//		if (p == nullptr)
//			return;
//
//		inorderToList(p->left, ll);
//		ll.insert(p->data);
//		inorderToList(p->right, ll);
//	}
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
//
//	bool isIdentical(node* root1, node* root2)
//	{
//		if (root1 == nullptr && root2 == nullptr)
//			return true;
//
//		if (root1 == nullptr || root2 == nullptr)
//			return false;
//
//		if (root1->data != root2->data)
//			return false;
//
//		return isIdentical(root1->left, root2->left) &&
//			isIdentical(root1->right, root2->right);
//	}
//
//	bool isIdenticalWrapper(tree& t2)
//	{
//		return isIdentical(this->root, t2.root);
//	}
//
//
//};
//
//
//void inorderToList(node* p, linkedlist& ll)
//{
//    if (p == nullptr)
//        return;
//
//    inorderToList(p->left, ll);
//    ll.insert(p->data);
//    inorderToList(p->right, ll);
//}