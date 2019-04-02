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
	node* currentNode; // wskaznik na obecny wezel

public:
	iterator(node* t) :
		currentNode(t) //przypisanie node do currentNode
	{ }
//przechodzi przez elementy w kolejnosci inorder
	iterator begin(node* t) //idzie od maxa z gory w lewo 
	{
		if(t)
		{
			while(t->left)
			{
				t = t->left;
			}
		}
		return iterator(t); //zwraca obiekt klasy iterator ostatni po lewej
	}

	iterator end(node* t) //jeeli dojdzie do kona
	{
		return iterator(nullptr);  //zwraca ostatni element
	}

	iterator& operator = (node* t) //przeciąanie operatora przypisania, zeby for działał na node 
	{
		this->currentNode = t; //zapisujemy emelent otrztmany ew argumencie, podobne wykananie jak w konstruktorze 
		return *this;
	}

	iterator operator ++ (int)//przeciązanie operatora, przechodzi do następnego więzła
	{
		currentNode = nextNode(this->currentNode); // przejscie do nastepnego  elementu
		return currentNode;
	}

	bool operator != (const iterator& it) // kontynuacji pentli , const zeby się nie modyfikował 
	{
		return currentNode != it.currentNode; // sprawdza czy nasz currnode nie jest rowny otrzymanemu currentnodowi danego obiektu.
	}

	int operator* ()
	{
		return currentNode->x; // zwraca klucz z current node
	}

	node* nextNode(node* t) //przejście do następnego elementu inorder - do pętli for 
	{
		node* t1 = t; //tworzymy zmienna pomocnicza t1 do ktorej zapisujemy node'a przekazanego w agrumencie.
		if(t->right == nullptr) //dopoki right child node'a "t" jest nullem.
		{
			while(t->parent != nullptr && t1->x > t->parent->x)//dopoki parent node'a "t" nie jest nullem i klucz node'a "t1" jest wiekszy od klucza parenta node'a "t".
			{
				t = t->parent;//Przejdz do nastepnego parenta w nodzie "t"
			}
			return t->parent;// po wyjsciu z petli wihile zwroc ostatniego zapisanego parenta node'a "t"
		}
		else // jesli right child nie jest nullem.
		{
			t = t->right; //przejdz raz do right child'a node'a "t" , przejdź na maxa w lewo
			while (t->left != nullptr && t->left->x > t1->x)//dopoki left child node'a "t" nie jest nullem i klucz left child'a jest ,przejdź na wiekszy od  klucza node'a "t1".
			{
				t = t->left; // Przejdz do nastepnego left child'a w nodzie "t"
			}
		return t;// zwroc node'a "t" z ostatnim zapisanym left child'em z petli while.
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

    node* L = nullptr;

	insert(L, 15);
	insert(L, 6);
	insert(L, 2);
	insert(L, 10);
	insert(L, 8);
	insert(L, 7);
	insert(L, 9);
	insert(L, 12);
	insert(L, 17);
	insert(L, 20);


	for(node::iterator it = it.begin(L); it != it.end(L); it++) //w node towrzę obiekt iterator , idę na maxa w lewo w elemencie; jeli obecny it nie jest ostenim; przejdź do następnego| w porządku inorder
	{
		std::cout << *it << std::endl;
	}
    return 0;

}
