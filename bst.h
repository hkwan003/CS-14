#ifndef BST_H
#define BST_H
#define TEST
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0
// #define Value int // restore for testing.
template < typename Value >
class BST {
	class Node { // binary tree node
	public:
		Node* root;
		int count;
		Node* left;
		Node* right;
		Value value;
		int level; // for Andersson trees
		Node(const Value v = Value(), int lev = 1)
			: value(v), level(lev), left(nil), right(nil)
		{}
		Value& content() { return value; }
		bool isInternal() { return left != nil && right != nil; }
		bool isExternal() { return left != nil || right != nil; }
		bool isLeaf() { return left == nil && right == nil; }
		int height() 
		{
			if(ptr == 0)
			{
				return -1;
			}
			else
			{
				return Find_Height(root);
			}
		}
			// returns the height of the subtree rooted at this node
			// FILL IN
		int size() 
		{
			// returns the size of the subtree rooted at this node,
			// FILL IN
		}
		int Find_Height(Node* ptr)
		{
			int Lft = Find_Height(ptr.left);
			int Rht = Find_Height(ptr.right);
			if(Lft > Rht)
			{
				return Lft + 1;
			}
			else
			{
				return Rht + 1;
			}	
				
		}
	}; // Node
	// const Node* nil; // later nil will point to a sentinel node.
public:
	int size() 
	{
		
		// size of the overall tree.
		// FILL IN
	}
	bool empty() { return size() == 0; }
	void print_node(const Node* n) {
		// Print the node's value.
		// FILL IN
	}
	bool search(Value x) {
		// search for a Value in the BST and return true iff it was found.
		// FILL IN
	}
	void preorder()const {
		// Traverse and print the tree one Value per line in preorder.
		// FILL IN
	}
	void postorder()const {
		// Traverse and print the tree one Value per line in postorder.
		// FILL IN
	}
	void inorder()const {
		// Traverse and print the tree one Value per line in inorder.
		// FILL IN
	}
	Value& operator[] (int n) {
		// returns reference to the value field of the n-th Node.
		// FILL IN
	}
	BST() : count(0), root(nil) {}
	void insert(Value X) { root = insert(X, root); }
	Node* insert(Value X, Node* T) {
		// The normal binary-tree insertion procedure ...
		if (T == nil) {
			T = new Node(X); // the only place that T gets updated.
		}
		else if (X < T->value) {
			T->left = insert(X, T->left);
		}
		else if (X > T->value) {
			T->right = insert(X, T->right);
		}
		else {
			T->value = X;
		}
		// later, rebalancing code will be installed here
		return T;
	}
	void remove(Value X) { root = remove(X, root); }
	Node* remove(Value X, Node*& T) {
		// The normal binary-tree removal procedure ...
		// Weiss's code is faster but way more intricate.
		if (T != nil) {
			if (X > T->value) {
				T->right = remove(X, T->right);
			}
			else if (X < T->value) {
				T->left = remove(X, T->left);
			}
			else { // X == T->value
				if (T->right != nil) {
					Node* x = T->right;
					while (x->left != nil) x = x->left;
					T->value = x->value; // successor's value
					T->right = remove(T->value, T->right);
				}
				else if (T->left != nil) {
					Node* x = T->left;
					while (x->right != nil) x = x->right;
					T->value = x->value; // predecessor's value
					T->left = remove(T->value, T->left);
				}
				else { // *T is external
					delete T;
					T = nil; // the only updating of T
				}
			}
		}
		// later, rebalancing code will be installed here
		return T;
	}
	void display() { display(root); }
	void display(Node* n) {
		// in-order traversal with indented display.
		static int depth = 0;
		++depth;
		if (n == nil) return;
		if (n->right != nil) display(n->right);
		for (int i = 0; i != depth; ++i) cout << " ";
		cout << n->value << "-" << n->level << endl;
		if (n->left != nil) display(n->left);
		--depth;
	}
	void okay() { okay(root); }
	void okay(Node* T) {
		// diagnostic code can be installed here
		return;
	}
}; // BST
#endif