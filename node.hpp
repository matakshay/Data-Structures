template <typename T, typename U>

class node
{
 public:
	T key;
	U value;
	node* left;
	node* right;
	node* parent;

	node (T key, U value=NULL, node* left=NULL, node*right=NULL, node* parent=NULL) :
        key(key), value(value), left(left), right(right), parent(parent)
	{    }
};
