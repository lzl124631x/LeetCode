# [2689. Extract Kth Character From The Rope Tree (Easy)](https://leetcode.com/problems/extract-kth-character-from-the-rope-tree)

<p>You are given the <code>root</code> of a binary tree and an integer <code>k</code>. Besides the left and right children, every node of this tree has two other properties, a <strong>string</strong> <code>node.val</code> containing only lowercase English letters (possibly empty) and a non-negative integer <code>node.len</code>. There are two types of nodes in this tree:</p>
<ul>
	<li><strong>Leaf</strong>: These nodes have no children, <code>node.len = 0</code>, and <code>node.val</code> is some <strong>non-empty</strong> string.</li>
	<li><strong>Internal</strong>: These nodes have at least one child (also at most two children), <code>node.len &gt; 0</code>, and <code>node.val</code> is an <strong>empty</strong> string.</li>
</ul>
<p>The tree described above is called a <em>Rope</em> binary tree. Now we define <code>S[node]</code> recursively as follows:</p>
<ul>
	<li>If <code>node</code> is some leaf node, <code>S[node] = node.val</code>,</li>
	<li>Otherwise if <code>node</code> is some internal node, <code>S[node] = concat(S[node.left], S[node.right])</code> and <code>S[node].length = node.len</code>.</li>
</ul>
<p>Return<em> k-th character of the string</em> <code>S[root]</code>.</p>
<p><strong>Note:</strong> If <code>s</code> and <code>p</code> are two strings, <code>concat(s, p)</code> is a string obtained by concatenating <code>p</code> to <code>s</code>. For example, <code>concat("ab", "zz") = "abzz"</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> root = [10,4,"abcpoe","g","rta"], k = 6
<strong>Output:</strong> "b"
<strong>Explanation:</strong> In the picture below, we put an integer on internal nodes that represents node.len, and a string on leaf nodes that represents node.val.
You can see that S[root] = concat(concat("g", "rta"), "abcpoe") = "grtaabcpoe". So S[root][5], which represents 6th character of it, is equal to "b".
</pre>
<p><img alt="" src="https://assets.leetcode.com/uploads/2023/05/14/example1.png" style="width: 300px; height: 213px; margin-left: 280px; margin-right: 280px;"></p>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> root = [12,6,6,"abc","efg","hij","klm"], k = 3
<strong>Output:</strong> "c"
<strong>Explanation:</strong> In the picture below, we put an integer on internal nodes that represents node.len, and a string on leaf nodes that represents node.val.
You can see that S[root] = concat(concat("abc", "efg"), concat("hij", "klm")) = "abcefghijklm". So S[root][2], which represents the 3rd character of it, is equal to "c".
</pre>
<p><img alt="" src="https://assets.leetcode.com/uploads/2023/05/14/example2.png" style="width: 400px; height: 232px; margin-left: 255px; margin-right: 255px;"></p>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> root = ["ropetree"], k = 8
<strong>Output:</strong> "e"
<strong>Explanation:</strong> In the picture below, we put an integer on internal nodes that represents node.len, and a string on leaf nodes that represents node.val.
You can see that S[root] = "ropetree". So S[root][7], which represents 8th character of it, is equal to "e".
</pre>
<p><img alt="" src="https://assets.leetcode.com/uploads/2023/05/14/example3.png" style="width: 80px; height: 78px; margin-left: 400px; margin-right: 400px;"></p>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>3</sup>]</code></li>
	<li><code>node.val</code> contains only lowercase English letters</li>
	<li><code>0 &lt;= node.val.length &lt;= 50</code></li>
	<li><code>0 &lt;= node.len &lt;= 10<sup>4</sup></code></li>
	<li>for leaf nodes, <code>node.len = 0</code> and <code>node.val</code> is non-empty</li>
	<li>for internal nodes, <code>node.len &gt; 0</code> and <code>node.val</code> is empty</li>
	<li><code>1 &lt;= k &lt;= S[root].length</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/extract-kth-character-from-the-rope-tree
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(H)
class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        if (root->len == 0) return root->val[k - 1];
        int left = root->left ? root->left->len + root->left->val.size() : 0;
        if (left >= k) return getKthCharacter(root->left, k);
        return getKthCharacter(root->right, k - left);
    }
};
```