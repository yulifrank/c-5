#pragma once
#include "Tree.h"
#include <iostream>
#include "Book.h"
using namespace std;
template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value) override;
	bool  search(T value) override;
	void remove(T value) override;

private:
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	//פונקציות עזר של מחיקה !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void removeNodeWithTwoChildren(typename Tree<T>::Node* node);
    void removeLeafNode(typename Tree<T>::Node* node);
    void removeNodeWithOneChild(typename Tree<T>::Node* node);
};
template <class T>
void SearchTree<T>::add(T val)
{
    // add value to binary search tree
    if (!Tree<T>::root)
    {
        Tree<T>::root = new typename Tree<T>::Node(val);
        return;
    }
    add(Tree<T>::root, val);
}
template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
    if (val < current->value)
    {
        if (!current->left)
        {
            current->left = new typename Tree<T>::Node(val);
            current->left->parent = current;
            return;
        }
        else
        {
            add(current->left, val);
        }
    }
    else if (val > current->value)
    {
        if (!current->right)
        {
            current->right = new typename Tree<T>::Node(val);
            current->right->parent = current;
            return;
        }
        else
        {
            add(current->right, val);
        }
    }
    // If the value is already in the tree, do not add it again
}
template <class T>
bool SearchTree<T>::search( T value)
{
	return search(Tree<T>::root, value);
}
template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
template <class T>
void SearchTree<T>::removeNodeWithTwoChildren(typename Tree<T>::Node* nodeToRemove)
{
    typename Tree<T>::Node* successor = nodeToRemove->right;
    while (successor->left != nullptr)
        successor = successor->left;

    nodeToRemove->value = successor->value;

    if (successor->parent->left == successor)
        successor->parent->left = successor->right;
    else
        successor->parent->right = successor->right;

    if (successor->right != nullptr)
        successor->right->parent = successor->parent;

    delete successor;
}
template <class T>
void SearchTree<T>::removeLeafNode(typename Tree<T>::Node* nodeToRemove) 
{
    if (nodeToRemove->parent == nullptr)
    {
        delete nodeToRemove;
        Tree<T>::root = nullptr;
    }
    else
    {
        if (nodeToRemove->parent->left == nodeToRemove)
            nodeToRemove->parent->left = nullptr;
        else
            nodeToRemove->parent->right = nullptr;

        delete nodeToRemove;
    }
}
template <class T>
void SearchTree<T>::removeNodeWithOneChild(typename Tree<T>::Node* nodeToRemove) 
{
    typename Tree<T>::Node* child;
    if (nodeToRemove->left != nullptr)
        child = nodeToRemove->left;
    else
        child = nodeToRemove->right;

    if (nodeToRemove->parent == nullptr)
    {
        Tree<T>::root = child;
        child->parent = nullptr;
    }
    else
    {
        if (nodeToRemove->parent->left == nodeToRemove)
            nodeToRemove->parent->left = child;
        else
            nodeToRemove->parent->right = child;

        child->parent = nodeToRemove->parent;
    }
    delete nodeToRemove;
}
template <class T>
void SearchTree<T>::remove(T val)
{// חיפוש הNode
    typename Tree<T>::Node* nodeToRemove = Tree<T>::root;
    while (nodeToRemove != nullptr && nodeToRemove->value != val)
    {
        if (val < nodeToRemove->value)
            nodeToRemove = nodeToRemove->left;
        else
            nodeToRemove = nodeToRemove->right;
    }
    //לא קים בכלל
    if (nodeToRemove == nullptr)
        return; 
    //איו לו ילדים כלל 
    if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr)
        removeLeafNode(nodeToRemove);
    // יש לו בן אחד
    else if (nodeToRemove->left == nullptr || nodeToRemove->right == nullptr)
        removeNodeWithOneChild(nodeToRemove);
    // יש לו שתי בנים
    else
        removeNodeWithTwoChildren(nodeToRemove);
}






