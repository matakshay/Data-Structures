//
//	Node for Trie (implemented at trie.hpp)
//

#include <unordered_map>
using namespace std;

class node
{
 public:
    char data;
    node* parent;
    unordered_map <char, node*> children;
    int count_words;									// Counts the number of words ending at this node

    node (char data)
    {
        this->data = data;
        count_words = 0;
        parent = NULL;
    }
};
