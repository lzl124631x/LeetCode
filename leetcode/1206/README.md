# [1206. Design Skiplist (Hard)](https://leetcode.com/problems/design-skiplist/)

<p>Design a <strong>Skiplist</strong> without using any built-in libraries.</p>

<p>A <strong>skiplist</strong> is a data structure that takes <code>O(log(n))</code> time to add, erase and search. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists is just simple linked lists.</p>

<p>For example, we have a Skiplist containing <code>[30,40,50,60,70,90]</code> and we want to add <code>80</code> and <code>45</code> into it. The Skiplist works this way:</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/09/27/1506_skiplist.gif" style="width: 500px; height: 173px;"><br>
<small>Artyom Kalinin [CC BY-SA 3.0], via <a href="https://commons.wikimedia.org/wiki/File:Skip_list_add_element-en.gif" target="_blank" title="Artyom Kalinin [CC BY-SA 3.0 (https://creativecommons.org/licenses/by-sa/3.0)], via Wikimedia Commons">Wikimedia Commons</a></small></p>

<p>You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help of the top layers, add, erase and search can be faster than <code>O(n)</code>. It can be proven that the average time complexity for each operation is <code>O(log(n))</code> and space complexity is <code>O(n)</code>.</p>

<p>See more about Skiplist: <a href="https://en.wikipedia.org/wiki/Skip_list" target="_blank">https://en.wikipedia.org/wiki/Skip_list</a></p>

<p>Implement the <code>Skiplist</code> class:</p>

<ul>
	<li><code>Skiplist()</code> Initializes the object of the skiplist.</li>
	<li><code>bool search(int target)</code> Returns <code>true</code> if the integer <code>target</code> exists in the Skiplist or <code>false</code> otherwise.</li>
	<li><code>void add(int num)</code> Inserts the value <code>num</code> into the SkipList.</li>
	<li><code>bool erase(int num)</code> Removes the value <code>num</code> from the Skiplist and returns <code>true</code>. If <code>num</code> does not exist in the Skiplist, do nothing and return <code>false</code>. If there exist multiple <code>num</code> values, removing any one of them is fine.</li>
</ul>

<p>Note that duplicates may exist in the Skiplist, your code needs to handle this situation.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
<strong>Output</strong>
[null, null, null, null, false, null, true, false, true, false]

<strong>Explanation</strong>
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0); // return False
skiplist.add(4);
skiplist.search(1); // return True
skiplist.erase(0);  // return False, 0 is not in skiplist.
skiplist.erase(1);  // return True
skiplist.search(1); // return False, 1 has already been erased.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num, target &lt;= 2 * 10<sup>4</sup></code></li>
	<li>At most <code>5 * 10<sup>4</sup></code> calls will be made to <code>search</code>, <code>add</code>, and <code>erase</code>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Databricks](https://leetcode.com/company/databricks), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Twitter](https://leetcode.com/company/twitter), [Pure Storage](https://leetcode.com/company/pure-storage), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Design HashSet (Easy)](https://leetcode.com/problems/design-hashset/)
* [Design HashMap (Easy)](https://leetcode.com/problems/design-hashmap/)
* [Design Linked List (Medium)](https://leetcode.com/problems/design-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-skiplist/
// Author: github.com/lzl124631x
// Time: 
//      Skiplist: O(1)
//      search, add, erase: O(logN)
// Space: O(N)
struct Node {
    int val;
    Node *right = nullptr, *down = nullptr;
    Node(int val) : val(val) {};
    Node(int val, Node *right, Node *down) : val(val), right(right), down(down) {}
};
class Skiplist {
    Node *head = new Node(-1, nullptr, nullptr);
public:
    Skiplist() {}
    bool search(int target) {
        auto p = head;
        while (p) {
            while (p->right && p->right->val < target) p = p->right;
            if (p->right && p->right->val == target) return true;
            p = p->down;
        }
        return false;
    }
    void add(int n) {
        vector<Node*> insertionPoints;
        auto p = head;
        while (p) {
            while (p->right && p->right-> val < n) p = p->right;
            insertionPoints.push_back(p);
            p = p->down;
        }
        bool insertUp = true;
        Node *downNode = nullptr;
        while (insertUp && insertionPoints.size()) {
            auto ins = insertionPoints.back();
            insertionPoints.pop_back();
            ins->right = downNode = new Node(n, ins->right, downNode);
            insertUp = rand() % 2;
        }
        if (insertUp) head = new Node(-1, new Node(n, nullptr, downNode), head);
    }
    bool erase(int n) {
        auto p = head;
        bool seen = false;
        while (p) {
            while (p->right && p->right->val < n) p = p->right;
            if (p->right && p->right->val == n) {
                seen = true;
                auto rm = p->right;
                p->right = rm->right;
                delete rm;
            }
            p = p->down;
        }
        return seen;
    }
};
```