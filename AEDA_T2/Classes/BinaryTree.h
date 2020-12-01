#ifndef PROJECT1_BINARYTREE_H
#define PROJECT1_BINARYTREE_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class Comparable> class iteratorBST;
template <class Comparable> class BST;
template <class Comparable> class BSTItrIn;

template <class Comparable>
class BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt) : element(theElement), left(lt), right(rt) {}

    friend class BST<Comparable>;
    friend class BSTItrIn<Comparable>;
    friend class iteratorBST<Comparable>;
};

template <class Comparable>
class BST
    {
    public:
        explicit BST(const Comparable & notFound);
        BST(const BST & rhs);
        ~BST();

        const Comparable & findMin() const;
        const Comparable & findMax() const;
        const Comparable & find(const Comparable & x) const;
        bool isEmpty() const;
        void printTree() const;
        void makeEmpty();
        bool insert(const Comparable & x);
        bool remove(const Comparable & x);
        const BST & operator=(const BST & rhs);

        iteratorBST<Comparable> begin() const;
        iteratorBST<Comparable> end() const;

    private:
        BinaryNode<Comparable> *root;
        const Comparable ITEM_NOT_FOUND;
        const Comparable & elementAt( BinaryNode<Comparable> *t ) const;
        bool insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
        bool remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
        BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
        BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
        BinaryNode<Comparable> * find( const Comparable & x, BinaryNode<Comparable> *t ) const;
        void makeEmpty( BinaryNode<Comparable> * & t ) const;
        void printTree( BinaryNode<Comparable> *t ) const;
        BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;

        friend class BSTItrIn<Comparable>;
        friend class iteratorBST<Comparable>;
    };

template <class Comparable>
BST<Comparable>::BST(const Comparable & notFound): root(NULL), ITEM_NOT_FOUND(notFound)
{}

template <class Comparable>
BST<Comparable>::BST(const BST<Comparable> & rhs) : root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND)
{
    *this = rhs;
}

template <class Comparable>
BST<Comparable>::~BST()
{
    makeEmpty();
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable & x)
{
    return insert(x, root);
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable & x)
{
    return remove(x, root);
}

template <class Comparable>
const Comparable & BST<Comparable>::findMin() const
{
    return elementAt(findMin(root));
}

template <class Comparable>
const Comparable & BST<Comparable>::findMax() const
{
    return elementAt(findMax(root));
}

template <class Comparable>
const Comparable & BST<Comparable>::find(const Comparable & x) const
{
    return elementAt(find(x,root));
}

template <class Comparable>
void BST<Comparable>::makeEmpty()
{
    makeEmpty(root);
}

template <class Comparable>
bool BST<Comparable>::isEmpty() const
{
    return root == NULL;
}

template <class Comparable>
void BST<Comparable>::printTree() const
{
    if(isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}

template <class Comparable>
const BST<Comparable> & BST<Comparable>::operator=(const BST<Comparable> & rhs)
{
    if(this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::begin() const {
    iteratorBST<Comparable> it;
    it.setBST(root);
    return it;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::end() const {
    iteratorBST<Comparable> it;
    it.setBST(NULL);
    return it;
}

//private methods

template <class Comparable>
const Comparable & BST<Comparable>::elementAt(BinaryNode<Comparable> *t) const
{
    if(t == NULL)
        return ITEM_NOT_FOUND;
    else
        return t->element;
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable & x, BinaryNode<Comparable> * & t) const
{
    if (t == NULL) {
        t = new BinaryNode<Comparable>(x, NULL, NULL);
        return true;
    }
    else if(*x < *(t->element))
        return insert(x, t->left);
    else if(*(t->element) < *x)
        return insert(x, t->right);
    else
        return false;  // Duplicate; do nothing
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable & x, BinaryNode<Comparable> * & t) const
{
    if(t == NULL)
        return false;   // Item not found; do nothing
    if(x < t->element)
        return remove(x, t->left);
    else if(t->element < x)
        return remove(x, t->right);
    else if(t->left != NULL && t->right != NULL) // Two children
    {
        t->element = findMin(t->right)->element;
        return remove(t->element, t->right);
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
        return true;
    }
}

template <class Comparable>
BinaryNode<Comparable> *BST<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
}


template <class Comparable>
BinaryNode<Comparable> *BST<Comparable>::findMax(BinaryNode<Comparable> *t) const
{
    if(t != NULL)
        while(t->right != NULL)
            t = t->right;
    return t;
}

template <class Comparable>
BinaryNode<Comparable> *BST<Comparable>::find(const Comparable & x, BinaryNode<Comparable> *t) const
{
    while(t != NULL)
        if(x < t->element)
            t = t->left;
        else if(t->element < x)
            t = t->right;
        else
            return t;    // Match

    return NULL;   // No match
}

template <class Comparable>
void BST<Comparable>::makeEmpty( BinaryNode<Comparable> * & t ) const
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

template <class Comparable>
void BST<Comparable>::printTree( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        printTree( t->left );
        cout << *t->element << endl;
        printTree( t->right );
    }
}

template <class Comparable>
BinaryNode<Comparable> *BST<Comparable>::clone( BinaryNode<Comparable> * t ) const
{
    if( t == NULL )
        return NULL;
    else
        return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}


//iterator

template <class Comparable>
class BSTItrIn {
public:
    BSTItrIn(const BST<Comparable> &bt);

    void advance();
    const Comparable &retrieve() { return itrStack.top()->element; }
    bool isAtEnd() {return itrStack.empty(); }

private:
    stack<BinaryNode<Comparable> *> itrStack;

    void slideLeft(BinaryNode<Comparable> *n);
};

template <class Comparable>
BSTItrIn<Comparable>::BSTItrIn (const BST<Comparable> &bt)
{
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class Comparable>
void BSTItrIn<Comparable>::slideLeft(BinaryNode<Comparable> *n)
{
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void BSTItrIn<Comparable>::advance()
{
    BinaryNode<Comparable> * actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable> * seguinte = actual->right;
    if (seguinte)
        slideLeft(seguinte);
}


#endif //PROJECT1_BINARYTREE_H