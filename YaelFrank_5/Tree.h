#pragma once
#include <iostream>
using namespace std;
#include "QueueVector.h"


//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:

	class Node
	{
	public:
		Node* left;
		Node* right;
		Node* parent;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL),parent(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r), parent(NULL) { left->parent =right->parent= this; }
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	virtual ~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); cout << endl; }
	void inOrder() { inOrder(root); cout << endl;}
	void postOrder() { postOrder(root); cout << endl;}
	void breadthScan();

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give accsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

};

//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}
template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}
// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}
// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}
// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
template <class T>
void Tree<T>::breadthScan()
{
	if (root == nullptr) {
		return;
	}
	QueueVector<Node*> q;
	q.enqueue(root);
	while (! q.isEmpty())
	{
		Node* n = q.dequeue();
		process(n->value);
		if (n->left != nullptr)
			q.enqueue(n->left);
		if (n->right != nullptr)
			q.enqueue(n->right);
	}
}

