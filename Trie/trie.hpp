//
//   TRIE IMPLEMENTATION
//

#include <iostream>
#include <string>
#include <unordered_map>
#include "trie_node.hpp"

using namespace std;


class trie
{
 public:

	//	Constructor
    trie ()
    {
        root = new node (NULL);
        size=0;
    }


	//	Destructor
	~trie ()
	{
		freeMem(root);
	}


    void insert (string &s)
    {
        if (s.size()==0) return;

        if (string_to_node.count(s)>0)
        {
            node* n = string_to_node[s];
            ++(n->count_words);
            ++size;
            return;
        }

        node* temp = root;

        for (int i=0; i<s.size(); ++i)
        {
            if (temp->children.count(s[i])==0)
            {
                node* n = new node (s[i]);
                temp->children[s[i]] = n;
                n->parent = temp;
            }

            temp = temp->children[s[i]];
        }

        ++size;
        ++(temp->count_words);

        string_to_node[s] = temp;
    }


    void remove (string &s)
    {
        if (size == 0) return;
        if (s.size() == 0) return;
        if (!contains(s)) return;

        node* temp = string_to_node[s];
        if (temp->count_words == 0) return;
		else
		{
            --size;
            --(temp->count_words);

			if (temp->count_words==0)
			{
				string_to_node.erase(s);
				removeEmptyNodes (temp);
			}
		}
    }


    void removeAll (string &s)
    {
        if (size == 0) return;
        if (s.size() == 0) return;
        if (!contains(s)) return;

        node* temp = string_to_node[s];

        if (temp->count_words == 0) return;
        else
        {
            size -= (temp->count_words);
            temp->count_words = 0;
            string_to_node.erase(s);

            removeEmptyNodes (temp);
        }
    }


    bool contains (string &s)
    {
        if (size==0) return false;
        if (s.size()==0) return false;

        if (string_to_node.count(s)>0) return true;
        else return false;
    }


    void clear ()
    {
		freeMem(root);
		root = new node (NULL);
        size = 0;
        string_to_node.clear();
    }


    int count (string& s)
    {
        if (size==0 || string_to_node.count(s)==0) return 0;

        return string_to_node[s]->count_words;
    }


    int totalWords ()
    {
        return size;
    }


    int uniqueWords ()
    {
        return string_to_node.size();
    }


 private:

	//	Helper function for "remove"
	//	Traverse the Trie upwards and removes the nodes which are not part of any word
	//
    void removeEmptyNodes (node* &n)
    {
		if (n==NULL || n->data == NULL || n->count_words!=0 || n->children.size()!=0) return;

        if (n==root)
        {
			delete root;
            root = new node (NULL);
            size = 0;
        }
		else
        {
            n->parent->children.erase(n->data);
			node* p = n->parent;
			delete n;
            removeEmptyNodes (p);
        }
    }


	//	Frees memory used by current node and its children
	//
	void freeMem (node* &n)
	{
		if (n==NULL) return;
		for (auto p : n->children)
		{
			freeMem(p.second);
		}
		delete n;
	}

    node* root;
    int size; 											// Stores the count of total number of words stored in the Trie
    unordered_map <string, node*> string_to_node; 		// Stores a pointer to the corresponding terminal node for each unique string stored in the Trie
};
