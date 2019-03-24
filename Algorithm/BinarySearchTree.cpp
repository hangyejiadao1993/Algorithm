#include<iostream>
using  namespace std; 
template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree();

	BinarySearchTree(const BinarySearchTree & rhs);
	~BinarySearchTree(); 
	const Comparable & findMin() const;
	const Comparable & findMax() const;
	bool contains(const Comparable & x) const;
	bool isEmpty() const;
	void printTree() const; 
	void makeEmpty();
	void insert(const Comparable & x);
	void remove(const Comparable & x);

	const BinarySearchTree & operator=(const BinarySearchTree & rhs);

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right; 
		BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
			: element(theElement), left(lt), right(rt) { }
	};

	BinaryNode *root;

	void insert(const Comparable & x, BinaryNode * & t) const;
	void remove(const Comparable & x, BinaryNode * & t) const;
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	bool contains(const Comparable & x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
	BinaryNode * clone(BinaryNode *t) const;
};


template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode*  BinarySearchTree<Comparable>::findMax(BinaryNode *t)const {
	return nullptr;
}

 

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
}


template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs)
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}

template<typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin() const
{
	// TODO: 在此处插入 return 语句
}



template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const
{
	return  contains(x, root);
}


template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x, BinaryNode*& t) const
{
	insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode*& t) const
{
	remove(x, root);
}





 

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode * t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;
}


template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode*&t) {
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
	}
	t = nullptr;
}

 


int main(int argc, char**arv) {



	return 0;
}