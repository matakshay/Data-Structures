<h1>Adelson-Velsky & Landis (AVL) Tree </h1>

<p align="justify">
This is a C++ implementation of an AVL Tree. The header file <code>AVL.hpp</code> contains the class for AVL Tree and <code>AVL_node.hpp</code> contains the class for the node (using which AVL is built).
<br>
AVL Tree is a variant of the Binary Search Tree which uses rotation operations to keep the tree balanced. In this implementation, the class AVLTree inherits class BST and class AVL_node inherits class node. The basic operations of insertion and deletion (of a key-value pair) remains the same as in a BST, only modification being appropriate rotation operations at each level (when needed) to ensure the subtree rooted at each node remains balanced.
</p>

<h2>Public Methods</h2>
<ul>
    <li>
        <h5><code>void insert (const T key, const T value=NULL)</code></h5>
        <p align="justify">
            Inserts a key-value pair into the AVL Tree
            <br>
            If the key already exists, updates its value
            <br>
            Time Complexity: Logarithmic in the number of nodes in the AVL Tree
        </p>
    </li>
    <li>
        <h5><code>void remove (const T key)</code></h5>
        <p align="justify">
            Removes "key" and its corresponding value (if they are present), from the AVL
            <br>
            Time Complexity: Logarithmic in the number of nodes in the AVL Tree
        </p>
    </li>
    <li>
        <h5><code>int size ()</code></h5>
        <p align="justify">
            Returns the number of key-value pairs stored in the AVL Tree
            <br>
            Time Complexity: Constant
        </p>
    </li>
    <li>
        <h5><code>bool consists (const T key)</code></h5>
        <p align="justify">
            Returns true if the AVL Tree contains a key="key", false otherwise
            <br>
            Time Complexity: Logarithmic in the number of nodes in the AVL Tree
        </p>
    </li>
    <li>
        <h5><code>U value (const T key)</code></h5>
        <p align="justify">
            Returns the value which has key="key" in the AVL Tree (if it exists, otherwise returns NULL)
            <br>
            Time Complexity: Logarithmic in the number of nodes in the AVL Tree
        </p>
    </li>
</ul>
