#include<iostream>
#include"BinaryTree.h"
using namespace std;
int main()
{
	BinaryTree<int>t1(1);
	BinaryTree<int>t2(2);
	BinaryTree<int>t3(3);
	BinaryTree<int>t4(t3);
	Node<int>item(4);
	BinaryTree<int>t(t1, item, t2);
	if (t.isEmpty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	if (t1.isEmpty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	if (t.LChild().isEmpty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	if (t.RChild().isEmpty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	Node<int> node = t.Data();
	cout << node.value << endl;
	t.Inorder();
	cout << endl;
	t.Preorder();
	cout << endl;
	t.Postorder();
	cout << endl;
	t.Levelorder();
	cout << endl;
	cout << t.leafNum() << endl;
	return 0;
}