# [1612. Check If Two Expression Trees are Equivalent (Medium)](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent)

<p>A <strong><a href="https://en.wikipedia.org/wiki/Binary_expression_tree" target="_blank">binary expression tree</a></strong> is a kind of binary tree used to represent arithmetic expressions. Each node of a binary expression tree has either zero or two children. Leaf nodes (nodes with 0 children) correspond to operands (variables), and internal nodes (nodes with two children) correspond to the operators. In this problem, we only consider the <code>'+'</code> operator (i.e. addition).</p>
<p>You are given the roots of two binary expression trees, <code>root1</code> and <code>root2</code>. Return <code>true</code><em> if the two binary expression trees are equivalent</em>. Otherwise, return <code>false</code>.</p>
<p>Two binary expression trees are equivalent if they <strong>evaluate to the same value</strong> regardless of what the variables are set to.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> root1 = [x], root2 = [x]
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p>
<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/tree1.png" style="width: 211px; height: 131px;"></strong></p>
<pre><strong>Input:</strong> root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,c]
<strong>Output:</strong> true
<strong>Explaination:</strong> <code>a + (b + c) == (b + c) + a</code></pre>
<p><strong class="example">Example 3:</strong></p>
<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/tree2.png" style="width: 211px; height: 131px;"></strong></p>
<pre><strong>Input:</strong> root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,d]
<strong>Output:</strong> false
<strong>Explaination:</strong> <code>a + (b + c) != (b + d) + a</code>
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in both trees are equal, odd and, in the range <code>[1, 4999]</code>.</li>
	<li><code>Node.val</code> is <code>'+'</code> or a lower-case English letter.</li>
	<li>It's <strong>guaranteed</strong> that the tree given is a valid binary expression tree.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> What will you change in your solution if the tree also supports the <code>'-'</code> operator (i.e. subtraction)?</p>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Build Binary Expression Tree From Infix Expression (Hard)](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/)
* [Minimum Flips in Binary Tree to Get Result (Hard)](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result/)
* [Evaluate Boolean Binary Tree (Easy)](https://leetcode.com/problems/evaluate-boolean-binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool checkEquivalence(Node* a, Node* b) {
        int ca[26] = {}, cb[26] = {};
        function<void(Node*, int[26])> dfs = [&](Node *root, int cnt[26]) {
            if (!root) return;
            if (root->val != '+') cnt[root->val - 'a']++;
            dfs(root->left, cnt);
            dfs(root->right, cnt);
        };
        dfs(a, ca);
        dfs(b, cb);
        for (int i = 0; i < 26; ++i) {
            if (ca[i] != cb[i]) return false;
        }
        return true;
    }
};
```

For the follow up question, we add a `sign` to the DFS calls.

```cpp
// OJ: https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool checkEquivalence(Node* a, Node* b) {
        int ca[26] = {}, cb[26] = {};
        function<void(Node*, int[26], int)> dfs = [&](Node *root, int cnt[26], int sign) {
            if (!root) return;
            if (root->val != '+' && root->val != '-') cnt[root->val - 'a'] += sign;
            dfs(root->left, cnt, sign);
            if (root->val == '-') sign *= -1;
            dfs(root->right, cnt, sign);
        };
        dfs(a, ca, 1);
        dfs(b, cb, 1);
        for (int i = 0; i < 26; ++i) {
            if (ca[i] != cb[i]) return false;
        }
        return true;
    }
};
```