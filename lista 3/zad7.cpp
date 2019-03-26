#include<iostream>

using namespace std;

struct node  // drzewo bez wskaźnika na rodzica
{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};


int poziom(node *&t, int key)
{
	node *n = t;
	int level = 1; // wyznacznik poziomu
	
	while (n != nullptr && n->x != key) {
		level++;
		if (key < n->x)
			n = n->left;
		else n = n->right;
	}
	return n ? level : 0; // jesli n jest nullem to zwroc 0 jak nie to zwroc level 
}



