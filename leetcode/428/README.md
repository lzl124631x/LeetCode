# [428. Serialize and Deserialize N-ary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree)

<p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>
<p>Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>
<p>For example, you may serialize the following <code>3-ary</code> tree</p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 500px; max-width: 300px; height: 321px;">
<p>&nbsp;</p>
<p>as <code>[1 [3[5 6] 2 4]]</code>. Note that this is just an example, you do not necessarily need to follow this format.</p>
<p>Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 500px; height: 454px;">
<p>&nbsp;</p>
<p>For example, the above tree may be serialized as <code>[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]</code>.</p>
<p>You do not necessarily need to follow the above-suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>Output:</strong> [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,5,6]
<strong>Output:</strong> [1,null,3,2,4,null,5,6]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>The height of the n-ary tree is less than or equal to <code>1000</code></li>
	<li>Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.</li>
</ul>

**Companies**:
[Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
* [Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)
* [Encode N-ary Tree to Binary Tree (Hard)](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/)

## Solution 1. Level-order

```cpp
// OJ: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree
// Author: github.com/lzl124631x
// Time:
//      serialize, deserialize: O(N)
// Space: O(N)
class Codec {
    char endOfChildren = '#', childrenDelimiter = ',';
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        queue<Node*> q{{root}};
        string ans = to_string(root->val) + endOfChildren;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                root = q.front();
                q.pop();
                for (int i = 0; i < root->children.size(); ++i) {
                    if (i > 0) ans += childrenDelimiter;
                    auto n = root->children[i];
                    ans += to_string(n->val);
                    q.push(n);
                }
                ans += endOfChildren;
            }
        }
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> val;
        string children, num;
        istringstream ss(data);
        Node dummy;
        queue<Node*> q{{&dummy}};
        while (getline(ss, children, endOfChildren)) {
            istringstream cs(children);
            auto n = q.front();
            q.pop();
            while (getline(cs, num, childrenDelimiter)) {
                auto c = new Node(stoi(num));
                n->children.push_back(c);
                q.push(c);
            }
        }
        return dummy.children[0];
    }
};
```