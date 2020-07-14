// #include "node.hpp"
using namespace std;

template <typename T, typename U>

class AVL_node : public node <T, U>
{
public:
	int height;
    AVL_node <T, U>* left;
	AVL_node <T, U>* right;

	AVL_node (T key, U value=NULL, node <T, U>* left=NULL, node <T, U>* right=NULL, int height=0) :
        node <T, U> (key, value, left, right), height(height)
	{    }
};
