# [705. Design HashSet (Easy)](https://leetcode.com/problems/design-hashset/solution/)

<p>Design a HashSet without using any built-in hash table libraries.</p>

<p>Implement <code>MyHashSet</code> class:</p>

<ul>
	<li><code>void add(key)</code> Inserts the value <code>key</code> into the HashSet.</li>
	<li><code>bool contains(key)</code> Returns whether the value <code>key</code> exists in the HashSet or not.</li>
	<li><code>void remove(key)</code> Removes the value <code>key</code> in the HashSet. If <code>key</code> does not exist in the HashSet, do nothing.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, true, false, null, true, null, false]

<strong>Explanation</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code>, <code>remove</code>, and <code>contains</code>.</li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Design HashMap (Easy)](https://leetcode.com/problems/design-hashmap/)
* [Design Skiplist (Hard)](https://leetcode.com/problems/design-skiplist/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-hashset/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashSet {
    bitset<1000001> bs;
public:
    MyHashSet() {}
    void add(int key) { bs.set(key); }
    void remove(int key) { bs.reset(key); }
    bool contains(int key) { return bs.test(key); }
};
```


## Separate Chaining

* hash function: the goal of the hash function is to assign an address to store a given value. Ideally, each unique value should have a unique hash value.

* collision handling: since the nature of a hash function is to map a value from a space A into a corresponding value in a **smaller** space B, it could happen that multiple values from space A might be mapped to the same value in space B. This is what we call **collision**. Therefore, it is indispensable for us to have a strategy to handle the collision.

Overall, there are several strategies to resolve the collisions:

*   [Separate Chaining](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining): for values with the same hash key, we keep them in a _bucket_, and each bucket is independent of each other.

*   [Open Addressing](https://en.wikipedia.org/wiki/Hash_table#Open_addressing): whenever there is a collision, we keep on _probing_ on the main space with certain strategy until a free slot is found.

*   [2-Choice Hashing](https://en.wikipedia.org/wiki/2-choice_hashing): we use two hash functions rather than one, and we pick the generated address with fewer collision.

Here we focus on separate chaining.

## Solution 2. Doubly-Linked List

```cpp
// OJ: https://leetcode.com/problems/design-hashset/
// Author: github.com/lzl124631x
// Time:
//		MyHashSet: O(1)
//		add, remove, contains: O(N) in the worst case.
// Space: O(N)
const int keyRange = 769;
class Bucket {
    list<int> items;
public:
    Bucket() {}
    void add(int key) {
        if (!contains(key)) items.push_front(key);
    }
    void remove(int key) {
        auto it = find(begin(items), end(items), key);
        if (it != end(items)) items.erase(it);
    }
    bool contains(int key) {
        return find(begin(items), end(items), key) != end(items);
    }
};
class MyHashSet {
    Bucket buckets[keyRange] = {};
    int hash(int key) { return key % keyRange; };
public:
    MyHashSet() {}
    void add(int key) { buckets[hash(key)].add(key); }
    void remove(int key) { buckets[hash(key)].remove(key); }
    bool contains(int key) { return buckets[hash(key)].contains(key); }
};
```

## Solution 3. Binary Search Tree

Note that we need to use AVL tree that auto-balance itself to achieve average `O(logN)` search time complexity.

```cpp
// OJ: https://leetcode.com/problems/design-hashset/
// Author: github.com/lzl124631x
// Time:
//		MyHashSet: O(1)
//		add, remove, contains: O(logN) on average, O(N) in the worst case.
// Space: O(N)
const int keyRange = 769;
struct BSTreeNode {
    int val;
    BSTreeNode *left = nullptr, *right = nullptr;
    BSTreeNode(int val) : val(val) {}
};
class BSTree {
    BSTreeNode *root = nullptr;
    BSTreeNode* deleteNode(BSTreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (!root->left || !root->right) return root->left ? root->left : root->right;
        auto newRoot = root->right, left = newRoot->left, node = root->left;
        newRoot->left = root->left;
        while (node->right) node = node->right;
        node->right = left;
        return newRoot;
    }
public:
    void add(int key) {
        if (!root) {
            root = new BSTreeNode(key);
            return;
        }
        BSTreeNode *prev = nullptr, *n = root;
        while (n) {
            prev = n;
            if (key == n->val) return;
            if (key < n->val) n = n->left;
            else n = n->right;
        }
        if (key < prev->val) prev->left = new BSTreeNode(key);
        else prev->right = new BSTreeNode(key);
    }
    void remove(int key) {
        root = deleteNode(root, key);
    }
    bool contains(int key) {
        auto n = root;
        while (n) {
            if (n->val == key) return true;
            if (n->val < key) n = n->right;
            else n = n->left;
        }
        return false;
    }
};
class MyHashSet {
    BSTree buckets[keyRange] = {};
    int hash(int key) { return key % keyRange; };
public:
    MyHashSet() {}
    void add(int key) { buckets[hash(key)].add(key); }
    void remove(int key) { buckets[hash(key)].remove(key); }
    bool contains(int key) { return buckets[hash(key)].contains(key); }
};
```
