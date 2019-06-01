/*
二叉搜索树

*/
#include <iostream>
using namespace std;
template <typename Comparable>
class BinarySearchTree
{
  public:
	BinarySearchTree();

	BinarySearchTree(const BinarySearchTree &rhs);
	~BinarySearchTree();
	const Comparable &findMin() const;
	const Comparable &findMax() const;
	bool contains(const Comparable &x) const;
	bool isEmpty() const;
	void printTree() const;
	void makeEmpty();
	void insert(const Comparable &x);
	void remove(const Comparable &x);

	const BinarySearchTree &operator=(const BinarySearchTree &rhs);

  private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
			: element(theElement), left(lt), right(rt) {}
	};

	BinaryNode *root;

	void insert(const Comparable &x, BinaryNode *&t) const;
	void remove(const Comparable &x, BinaryNode *&t) const;
	BinaryNode *findMin(BinaryNode *t) const;
	BinaryNode *findMax(BinaryNode *t) const;
	bool contains(const Comparable &x, BinaryNode *t) const;
	void makeEmpty(BinaryNode *&t);
	void printTree(BinaryNode *t) const;
	BinaryNode *clone(BinaryNode *t) const;
};

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMax(BinaryNode *t) const
{
	return NULL;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMin(BinaryNode *t) const
{

	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs)
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
	makeEmpty();
}

template <typename Comparable>
const Comparable &BinarySearchTree<Comparable>::findMin() const
{
	// TODO: 在此处插入 return 语句
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const
{
	return contains(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, BinaryNode *&t) const
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (x > t->element)
		insert(x, t->right);
	else
		;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode *&t) const
{
	if (t == NULL)
		return;
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) //Tow Children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinaryNode *t) const
{
	if (t == NULL)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode *&t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
	}
	t = NULL;
}
template <typename Comparable>
const BinarySearchTree<Comparable> &BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable> &rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::clone(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

int main(int argc, char **arv)
{

	return 0;
}