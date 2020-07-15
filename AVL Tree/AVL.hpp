//
//  C++ IMPLEMENTATION OF AVL TREE

#include <iostream>
#include <algorithm>
#include "BST.hpp"
#include "AVL_node.hpp"
using namespace std;


template <typename T, typename U>

class AVLTree : public BST <T, U>
{
 public:
    //  Constructor
    AVLTree () : BST <T, U> ()
    {   }


    //  Destructor
    ~AVLTree ()
    {   }


    // Insert a node with given key & value in AVL tree
    //
    void insert (const T key, const U value=NULL)
    {
        AVL_node <T, U>* n = new AVL_node <T, U> (key, value);
        if (this->root==NULL)
		{
			this->root = n;
			this->SIZE = 1;
		}
		else insertNode (this->root, n);
    }


    void remove (const T key)
    {
        removeNode (this->root, key);
    }


    bool consists (const T key)
    {
        return consistsNode (this->root, key);
    }


    U value (const T key)
    {
       return getValue(this->root, key);
    }

 protected:

    AVL_node <T, U>* root;


    AVL_node <T, U>* insertNode (AVL_node <T, U>* &n, AVL_node <T, U>* temp)
 	{
        if (temp==NULL)  return n;
        else if (n==NULL)
        {
            ++(this->SIZE);
            n = temp;
        }
        else if (n->key < temp->key)  n->right = insertNode (n->right, temp);
 		else if (n->key > temp->key)  n->left = insertNode (n->left, temp);
 		else
        {
            n->value = temp->value;
            return n;
        }

        setHeight (n);

        n = reBalance (n);

        return n;
 	}


    // Verfy if height of "n" has been correctly assigned
    // If not, assign it
    void setHeight (AVL_node <T, U>* &n)
    {
        if (n==NULL)  return;
        n->height = (1 + max(getHeight(n->left), getHeight(n->right)));
    }


    // Check if "n" is Unbalanced.
    // If so, rebalance it by performing rotations
    AVL_node <T, U>* reBalance (AVL_node <T, U>* &n)
    {
        if (n==NULL) return n;
        if (getHeight(n->left) - getHeight(n->right) > 1)
        {
            if (getHeight(n->left->left) >= getHeight(n->left->right))  n = rightRotate (n);
            else
            {
                n->left = leftRotate (n->left);
                n = rightRotate (n);
            }
        }
        if (getHeight(n->right) - getHeight(n->left) > 1)
        {
            if (getHeight(n->right->right) >= getHeight(n->right->right))  n = leftRotate (n);
            else
            {
                n->right = rightRotate (n->right);
                n = leftRotate (n);
            }
        }
        return n;
    }


    // Wrapper function to get the height of a node
    int getHeight (AVL_node <T, U>* n)
    {
        if (n==NULL)  return -1;
        else  return n->height;
    }


    AVL_node <T, U>* rightRotate (AVL_node <T, U>* &n)
    {
        if (n==NULL || n->left==NULL)  return n;

        AVL_node <T, U>* temp1 = n->left;
        AVL_node <T, U> * temp2 = temp1->right;

        temp1->right = n;
        n->left = temp2;

        setHeight (n);
        setHeight (temp1);
        return temp1;
    }


    AVL_node <T, U>* leftRotate (AVL_node <T, U>* &n)
    {
        if (n==NULL || n->right==NULL)  return n;

        AVL_node <T, U>* temp1 = n->right;
        AVL_node <T, U>* temp2 = temp1->left;

        temp1->left = n;
        n->right = temp2;

        setHeight (n);
        setHeight (temp1);
        return temp1;
    }


    AVL_node <T, U>* removeNode (AVL_node <T, U>* &n, T key)
    {
        if (n==NULL)  return n;
        else if (n->key < key)  n->right = removeNode (n->right, key);
        else if (n->key > key)  n->left = removeNode (n->left, key);
        else
        {
            if (n->left==NULL && n->right==NULL)
            {
                n->~AVL_node();
                n=NULL;
            }
            else if (n->left==NULL)  n = n->right;
            else if (n->right==NULL)  n = n->left;
            else
            {
                AVL_node <T, U>* succ = n->right;
                AVL_node <T, U>* parent = n;

                // Get Inorder Sucessor node (and its parent)
                while (succ->left != NULL)
                {
                    parent = succ;
                    succ = succ->left;
                }

                n->key = succ->key;
                n->value = succ->value;

                if (parent->left==succ)  parent->left = NULL;
                else parent->right = NULL;

                succ->~AVL_node();
            }
             --(this->SIZE);
        }

        setHeight (n);

        n = reBalance (n);
        return n;
    }


    bool consistsNode (AVL_node <T, U>* &n, const T key)
    {
        if (n==NULL) return false;
        else if (n->key < key)  return consistsNode (n->right, key);
		else if (n->key > key)  return consistsNode (n->left, key);
		else return true;
    }


    U getValue (AVL_node <T, U>* &n, const T key)
    {
        if (n==NULL) return NULL;
        else if (n->key < key)  return getValue (n->right, key);
		else if (n->key > key)  return getValue (n->left, key);
		else return n->value;
    }
};
