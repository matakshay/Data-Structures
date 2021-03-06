/*
 *	Implementation of a Binary Search Tree
 *
*/

#include "node.hpp"
using namespace std;


template <typename T, typename U>

class BST
{
    public:
    // Constructor
    BST () : root(NULL), SIZE(0)
    {    }


    // Destructor
    ~BST ()
    {
        destroy(this->root);
    }


    void insert (const T key, const U value=NULL)
    {
       node <T, U>* n = new node <T, U> (key, value);
        if (this->root==NULL)
        {
            root = n;
            SIZE = 1;
        }
        else insertNode (this->root, n);
    }


    void remove (const T key)
    {
       removeNode (this->root, key);
    }


    int size ()
    {
       return this->SIZE;
    }


    bool consists (const T key)
    {
        return consistsNode (this->root, key);
    }


    U value (const T key)
    {
       return getValue(this->root, key);
    }


    void printPreorder()
    {
        preOrder (this->root);
        cout << endl;
    }


    void printInorder()
    {
        inOrder (this->root);
        cout << endl;
    }


    void printPostorder()
    {
        postOrder (this->root);
        cout << endl;
    }

 protected:

    node <T, U>* root;
	int SIZE;


	node <T, U>* insertNode (node <T, U>* &n, node <T, U>* &temp)
	{
        if (temp==NULL) return n;
        else if (n==NULL)
        {
            n = temp;
            ++SIZE;
        }
        else if (n->key < temp->key)  n->right = insertNode (n->right, temp);
		else if (n->key > temp->key)  n->left = insertNode (n->left, temp);
		else  n->value = temp->value;

        return n;
	}


    void removeNode (node <T, U>* &n, const T key)
    {
        if (n==NULL)  return;
        else if (n->key < key)  removeNode (n->right, key);
        else if (n->key > key)  removeNode (n->left, key);
        else
        {
            if (n->left==NULL && n->right==NULL)
            {
                n->~node();
                n=NULL;
            }
            else if (n->left==NULL)  n = n->right;
            else if (n->right==NULL)  n = n->left;
            else
            {
                node <T, U>* succ = n->right;
                // Get Inorder Sucessor node
                while (succ->left != NULL)  succ = succ->left;

                n->key = succ->key;
                n->value = succ->value;
                removeNode (succ, succ->key);
                ++SIZE;
            }
             --SIZE;
        }
    }


    bool consistsNode (node <T, U>* &n, const T key)
    {
        if (n==NULL) return false;
        else if (n->key < key)  return consistsNode (n->right, key);
		else if (n->key > key)  return consistsNode (n->left, key);
		else return true;
    }


    U getValue (node <T, U>* &n, const T key)
    {
        if (n==NULL) return NULL;
        else if (n->key < key)  return getValue (n->right, key);
		else if (n->key > key)  return getValue (n->left, key);
		else return n->value;
    }


    void destroy (node <T, U>* &n)
    {
        if (n->left!=NULL) destroy(n->left);
        if (n->right!=NULL) destroy(n->right);

        delete n;
    }


    void preOrder(node <T, U>* n)
    {
        if (n==NULL) return;

        cout<<"("<<n->key<<","<<n->value<<"), ";
        preOrder (n->left);
        preOrder (n->right);
    }


    void inOrder (node <T, U>* n)
    {
        if (n==NULL) return;

        inOrder (n->left);
        cout<<"("<<n->key<<","<<n->value<<"), ";
        inOrder (n->right);
    }


    void postOrder(node <T, U>* n)
    {
        if (n==NULL) return;

        preOrder (n->left);
        preOrder (n->right);
        cout<<"("<<n->key<<","<<n->value<<"), ";
    }
};
