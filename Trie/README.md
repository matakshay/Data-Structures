<h1> Trie</h1>

<p align="justify">
This is a C++ implementation of the Trie data structure. The header file <code>trie.hpp</code> contains the class for trie and <code>trie_node.hpp</code> contains the class for the node (using which Trie is built). <br>
In this implementation, a single trie object can store multiple copies of the same string efficiently. A string (which is to be stored in the Trie) is not limited to containing alphabetical characters only. It should be non-empty but can contain any valid ASCII character. Two strings are considered identical if they are of the same length and at each valid index, the ASCII value of the characters in both strings are equal.
</p>

<h2>Public Methods</h2>
<ul>
    <li>
        <h5><code>void insert (string &s)</code></h5>
        <p align="justify">
            Inserts string "s" into the Trie
            <br>
            If "s" is already present in the Trie, its occurrence count is increased by one.
            <br>
            Time Complexity: Constant, if "s" is already present in the Trie, otherwise Linear in the length of "s"
        </p>
    </li>
    <li>
        <h5><code>void remove (string &s)</code></h5>
        <p align="justify">
            Removes string "s" from the Trie
            <br>
            Returns immediately if Trie does not contain "s".
            <br>
            If Trie contains multiple occurrences of "s", this method removes one of them
            <br>
            Time Complexity: Constant, if Trie contains more than one occurrence of "s", otherwise Linear in the length of "s"
        </p>
    </li>
    <li>
        <h5><code>void removeAll (string &s)</code></h5>
        <p align="justify">
            Removes all occurrences of string "s" from the Trie
            <br>
            Returns immediately if Trie does not contain "s".
            <br>
            Time Complexity: Linear in the length of "s"
        </p>
    </li>
    <li>
        <h5><code>bool contains (string &s)</code></h5>
        <p align="justify">
            Returns true if the Trie contains "s" (length of "s" > 0), false otherwise
            <br>
            Time Complexity: Constant
        </p>
    </li>
    <li>
        <h5><code>void clear</code></h5>
        <p align="justify">
            Clears the Trie and removes all the strings stored in it. Also frees the memory occupied by the the Trie nodes
            <br>
            Time Complexity: Linear in the number of nodes in the Trie
        </p>
    </li>
    <li>
        <h5><code>int count (string &s)</code></h5>
        <p align="justify">
            Returns the number of occurrences of string "s" in the Trie
            <br>
            Time Complexity: Constant
        </p>
    </li>
    <li>
        <h5><code>int totalWords ()</code></h5>
        <p align="justify">
            Returns the total number of strings stored in the Trie. Duplicate copies of the same string are counted separately
            <br>
            Time Complexity: Constant
        </p>
    </li>
    <li>
        <h5><code>int uniqueWords ()</code></h5>
        <p align="justify">
            Returns the number of unique strings stored in the Trie
            <br>
            Time Complexity: Constant
        </p>
    </li>
</ul>
