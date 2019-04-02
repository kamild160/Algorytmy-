#include <iostream>

struct node{
  node (int v = 0, node *p = nullptr) :
    x(v), parent(p) {}

    int x;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;


class iterator
{
private:
	node* currentNode; //wskaźnik na obecny węzeł 

public:
//konstruktor 
	iterator(node* t) :  
		currentNode(t)
	{
	}
	
//wypisuje elementy w kolejności wpisywania 
	iterator begin(node* t)
	{
		if(t)
		{
			while(t->left)
			{
				t = t->left;
			}
		} 
		return iterator(t); //wypisuje ostatni 
	}
	
	iterator end(node* t)
	{
		return iterator(nullptr);
	}
	
	iterator& operator = (node* t)
	{
		this->currentNode = t;//przekazujemy zapisany element 
		return *this;
	}
	
	iterator operator ++ (int)
	{
		currentNode = nextNode(this->currentNode);//przechodzimy na następny element 
		return currentNode;
	}
	
	bool operator != (const iterator& it)
	{
		return currentNode != it.currentNode; //sprawdza czy nasz currentnode nie jest rowny otrzymanemu currentnode danego obiektu 
	}
	
	int operator* ()
	{
		return currentNode->x; //zwraca klucz z currentnode
	}
	
	node* nextNode(node* t)
	{
		node* t1 = t;
		if(t->right == nullptr)
		{
			while(t->parent != nullptr && t1->x > t->parent->x)
			{
				
				t = t->parent;
			}
			return t->parent;
		}
		else
		{
			t = t->right;
			while (t->left != nullptr && t->left->x > t1->x)
			{
				t = t->left;
			}
		return t;
		}
	}
};
};



void insert(node*& t, int x)
{
	node** current = &t;
	node** parent = nullptr;
	
	while(*current)
	{
		parent = current;
		if(x < (*current)->x)
		{
			current = &((*current)->left);
		}
		else
		{
			current = &((*current)->right);
		}
	}
	
	if(parent != nullptr)
	{
		*current = new node(x, *parent);
	}
	else
	{
		*current = new node(x);
	}

}


using namespace std;

int main(int argc, char const *argv[])
{
    
    node* myNode = nullptr;
	
	insert(myNode, 15);
	insert(myNode, 6); 
	insert(myNode, 2); 
	insert(myNode, 10);
	insert(myNode, 8);
	insert(myNode, 7);
	insert(myNode, 9);
	insert(myNode, 12);
	insert(myNode, 17);
	insert(myNode, 20);
	
	
	for(node::iterator it = it.begin(myNode); it != it.end(myNode); it++)
	{
		std::cout << *it << std::endl;
	}

    return 0;
}
