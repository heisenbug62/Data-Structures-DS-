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
//int main()
//{
//	tree obj2;
//	obj2.insert(12);
//	obj2.insert(33);
//	obj2.insert(11);
//	obj2.insert(15);
//	obj2.insert(121);
//	obj2.insert(1);
//	obj2.insert(8);
//	obj2.insert(5);
//
//	obj2.INORDER();
//
//	tree obj;
//	obj.insert(12);
//	obj.insert(33);
//	obj.insert(11);
//	obj.insert(15);
//	obj.insert(121);
//	obj.insert(1);
//	obj.insert(8);
//	obj.insert(5);
//
//	obj.INORDER();
//
//	if (obj.isIdenticalWrapper(obj2))
//	{
//		cout << "Same" << endl;
//	}
//
//	else
//	{
//		cout << "Not same" << endl;
//	}
//}