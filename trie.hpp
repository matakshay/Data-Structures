//
//   TRIE IMPLEMENTATION
//
//   Public Functions:   void insert (string)
//                       void remove (string)
//                       void removeAll (string)
//                       bool contains (string)
//                       void clear ()
//                       int count (string)
//                       int totalWords ()
//                       int uniqueWords ()
//
//   This trie implementation distinguishes characters only on the basis of their ASCII values.
//   This trie can be used to store any string made of ASCII characters.
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


	//	Insert a string in the Trie
	//	Do nothing if string is empty
	//
	//	Time Complexity:    O(length of string) if string was not originally present in the Trie
	//					    O(1) if string was originally present in the Trie
	//
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
        node_to_string[temp] = s;
    }


	//	Remove given string from the Trie
	//	Do nothing If trie is empty, given string is empty or Trie doesn't contain given string
	//
	//	Worst case Time Complexity:	O(length of string)
	//	Best case Time Complexity:  O(1)
	//
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
				node_to_string.erase(temp);
				removeEmptyNodes (temp);
			}
		}
    }


	//	Return total number of strings stored in the Trie
	//
	//	Time Complexity:	O(1)
	//
    int totalWords ()
    {
        return size;
    }


	//	Return total number of unique strings stored in the Trie
	//
	//	Time Complexity:	O(1)
	//
    int uniqueWords ()
    {
        return string_to_node.size();
    }

 private:

	//	Helper function for "remove"
	//	Traverse the Trie upwards and removes nodes which are not part of any word
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
    unordered_map <string, node*> string_to_node; 		// Stores a pointer to the corresponding ending node for each string stored in the Trie
    unordered_map <node*, string> node_to_string; 		// Stored the string corresponding to each terminal node
};
