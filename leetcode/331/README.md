# [331. Verify Preorder Serialization of a Binary Tree (Medium)](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree)

<p>One way to serialize a binary tree is to use <strong>preorder traversal</strong>. When we encounter a non-null node, we record the node&#39;s value. If it is a null node, we record using a sentinel value such as <code>&#39;#&#39;</code>.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/pre-tree.jpg" style="width: 362px; height: 293px;" />
<p>For example, the above binary tree can be serialized to the string <code>&quot;9,3,4,#,#,1,#,#,2,#,6,#,#&quot;</code>, where <code>&#39;#&#39;</code> represents a null node.</p>

<p>Given a string of comma-separated values <code>preorder</code>, return <code>true</code> if it is a correct preorder traversal serialization of a binary tree.</p>

<p>It is <strong>guaranteed</strong> that each comma-separated value in the string must be either an integer or a character <code>&#39;#&#39;</code> representing null pointer.</p>

<p>You may assume that the input format is always valid.</p>

<ul>
	<li>For example, it could never contain two consecutive commas, such as <code>&quot;1,,3&quot;</code>.</li>
</ul>

<p><strong>Note:&nbsp;</strong>You are not allowed to reconstruct the tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> preorder = "1,#"
<strong>Output:</strong> false
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> preorder = "9,#,#,1"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 10<sup>4</sup></code></li>
	<li><code>preorder</code> consist of integers in the range <code>[0, 100]</code> and <code>&#39;#&#39;</code> separated by commas <code>&#39;,&#39;</code>.</li>
</ul>


**Companies**:
[TikTok](https://leetcode.com/company/tiktok), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Stack](https://leetcode.com/tag/stack), [Tree](https://leetcode.com/tag/tree), [Binary Tree](https://leetcode.com/tag/binary-tree)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        stringstream ss(preorder);
        string node;
        bool ended = false;
        while (getline(ss, node, ',')) {
            if (ended) return false;
            if (node == "#") {
                while (s.size() && ++s.top() == 2) s.pop();
                if (s.empty()) ended = true;
            } else {
                s.push(0);
            }
        }
        return s.empty();
    }
};
```