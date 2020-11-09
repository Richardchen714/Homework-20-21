//Author: Hongzhuo CHEN
//Modified date: Monday November 9, 2020
//实现功能：二叉树的实现：构造函数、拷贝构造函数、析构函数、判断是否为空、返回子树、返回根节点、求叶结点个数、前中后层次遍历
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<stdexcept>
#include<stack>
#include<queue>
using std::cout;
using std::stack;
using std::queue;
using std::runtime_error;
template<typename T>class Node {
public:
	T value;
	Node<T>* lchild;
	Node<T>* rchild;
	Node<T>* parent;
	Node(const T &x)
	{
		value = x;
		lchild = nullptr;
		rchild = nullptr;
		parent = nullptr;
	}
};
template<typename T>class BinaryTree {
private:
	Node<T>* root;
public:
	BinaryTree(const T &x)
	{
		root = new Node<T>(x);
		root->lchild = nullptr;
		root->rchild = nullptr;
		root->parent = nullptr;
	}
	BinaryTree(BinaryTree& tree)
	{
		root = tree.root;
	}
	~BinaryTree()
	{
		DeleteTree(root);
	}
	bool isEmpty()
	{
		if (root == nullptr || (root->lchild == nullptr && root->rchild == nullptr)) return true;
		else return false;
	}
	BinaryTree(BinaryTree b1, Node<T>item, BinaryTree b2)
	{
		root = new Node<T>(item.value);
		root->parent = nullptr;
		root->lchild = b1.root;
		root->rchild = b2.root;
		b1.root->parent = root;
		b2.root->parent = root;
	}
	BinaryTree LChild()
	{
		if (root == nullptr) throw runtime_error("The tree is empty");
		else
		{
			BinaryTree<T>tree(root->lchild->value);
			tree.root = root->lchild;
			return tree;
		}
	}
	Node<T> Data()
	{
		return *root;
	}
	BinaryTree RChild()
	{
		if (isEmpty()) throw runtime_error("The tree is empty");
		else
		{
			BinaryTree<T>tree(root->rchild->value);
			tree.root = root->rchild;
			return tree;
		}
	}
	void DeleteTree(Node<T>* node)
	{
		if (node == nullptr || node == root) return;
		if (node->lchild == nullptr && node->rchild == nullptr) delete node;
		else
		{
			DeleteTree(node->rchild);
			DeleteTree(node->lchild);
		}
	}
	int leafNum()const
	{
		return leafNum(root);
	}
	int leafNum(Node<T>* node)const
	{
		if (node->lchild == nullptr && node->rchild == nullptr) return 1;
		else return leafNum(node->lchild) + leafNum(node->rchild);
	}
	void Preorder()const
	{
		stack<Node<T>*>s;
		Node<T>* cur = root;
		while (cur != nullptr || !s.empty())
		{
			while (cur != nullptr)
			{
				cout << cur->value << " ";
				s.push(cur);
				cur = cur->lchild;
			}
			if (!s.empty())
			{
				cur = s.top();
				s.pop();
				cur = cur->rchild;
			}
		}
	}
	void Postorder()const
	{
		stack<Node<T>*>s;
		Node<T>* cur;
		Node<T>* lastVisit;
		cur = root;
		lastVisit = nullptr;
		while (cur != nullptr)
		{
			s.push(cur);
			cur = cur->lchild;
		}
		while (!s.empty())
		{
			cur = s.top();
			s.pop();
			if (cur->rchild == nullptr || cur->rchild == lastVisit)
			{
				cout << cur->value << " ";
				lastVisit = cur;
			}
			else
			{
				s.push(cur);
				cur = cur->rchild;
				while (cur != nullptr)
				{
					s.push(cur);
					cur = cur->lchild;
				}
			}
		}
	}
	void Inorder()const
	{
		stack<Node<T>*>s;
		Node<T>* cur = root;
		while (cur != nullptr || !s.empty())
		{
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->lchild;
			}
			if (!s.empty())
			{
				cur = s.top();
				s.pop();
				cout << cur->value << " ";
				cur = cur->rchild;
			}
		}
	}
	void Levelorder()const
	{
		queue<Node<T>*> q;
		Node<T>* cur = root;
		q.push(cur);
		while (!q.empty()&&cur != nullptr)
		{
			cur = q.front();
			cout << cur->value << " ";
			q.pop();
			if (cur->lchild) q.push(cur->lchild);
			if (cur->rchild) q.push(cur->rchild);
			
		}
	}
};
#endif