# [255. Verify Preorder Sequence in Binary Search Tree (Medium)](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)

<p>Given an array of <strong>unique</strong> integers <code>preorder</code>, return <code>true</code> <em>if it is the correct preorder traversal sequence of a binary search tree</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/preorder-tree.jpg" style="width: 292px; height: 302px;">
<pre><strong>Input:</strong> preorder = [5,2,1,3,6]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> preorder = [5,2,6,1,3]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= preorder[i] &lt;= 10<sup>4</sup></code></li>
	<li>All the elements of <code>preorder</code> are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do it using only constant space complexity?</p>


**Companies**:  
[VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Recursion](https://leetcode.com/tag/recursion/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-preorder-traversal/)

## Solution 1. Monotonic Stack

```cpp
// OJ: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool verifyPreorder(vector<int>& A) {
        stack<int> s;
        int mn = INT_MIN;
        for (int n : A) {
            if (n < mn) return false;
            while (s.size() && s.top() < n) {
                mn = s.top();
                s.pop();
            }
            s.push(n);
        }
        return true;
    }
};
```

Or if we are allowed to change the input array to simulate the stack

```cpp
// OJ: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) if we don't count the space used by the input array.
class Solution {
public:
    bool verifyPreorder(vector<int>& A) {
        int mn = INT_MIN, j = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] < mn) return false;
            while (j >= 0 && A[j] < A[i]) mn = A[j--];
            A[++j] = A[i];
        }
        return true;
    }
};
```