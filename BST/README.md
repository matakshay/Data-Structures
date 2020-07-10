<h1>Binary Search Tree</h1>

<p align="justify">
This is a C++ implementation of a Binary Search Tree. The header file <code>BST.hpp</code> contains the class for BST and <code>node.hpp</code> contains the class for the node (using which BST is built). <br>
In this implementation, each node of the Binary Search Tree stores a key and value (can be NULL) pair. The BST property is maintained using the value of the key. Note that the BST here need not be balanced at all times. The operations of insertions, deletion and lookup all run in a time linear in the height of the tree, which itself can be linear in the number of key-value pairs stored in the tree.
</p>

<h2>Public Methods</h2>
<ul>
    <li>
        <h5><code>void insert (const T key, const T value=NULL)</code></h5>
        <p align="justify">
            Inserts a key-value pair into the BST
            <br>
            If the key already exists, updates its value
            <br>
            Time Complexity: Linear in the height of the BST
        </p>
    </li>
    <li>
        <h5><code>void remove (const T key)</code></h5>
        <p align="justify">
            Removes "key" and its corresponding value (if they are present), from the BST
            <br>
            Time Complexity: Linear in the height of the BST
        </p>
    </li>
    <li>
        <h5><code>int size ()</code></h5>
        <p align="justify">
            Returns the number of key-value pairs stored in the BST
            <br>
            Time Complexity: Constant
        </p>
    </li>
    <li>
        <h5><code>bool consists (const T key)</code></h5>
        <p align="justify">
            Returns true is BST contains a key="key", false otherwise
            <br>
            Time Complexity: Linear in the height of the BST
        </p>
    </li>
    <li>
        <h5><code>U value (const T key)</code></h5>
        <p align="justify">
            Returns the value which has key="key" in the BST (if it exists, otherwise returns NULL)
            <br>
            Time Complexity: Linear in the height of the BST
        </p>
    </li>
</ul>
