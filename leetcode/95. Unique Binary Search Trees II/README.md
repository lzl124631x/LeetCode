# [95. Unique Binary Search Trees II (Medium)](https://leetcode.com/problems/unique-binary-search-trees-ii)

<p>Given an integer <code>n</code>, return <em>all the structurally unique <strong>BST'</strong>s (binary search trees), which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>. Return the answer in <strong>any order</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Unique Binary Search Trees (Medium)](https://leetcode.com/problems/unique-binary-search-trees/)
* [Different Ways to Add Parentheses (Medium)](https://leetcode.com/problems/different-ways-to-add-parentheses/)

## Solution 1.

Pick a number `i` for root node.

Numbers `[1, i - 1]` should be put on the left sub-tree, while `[i + 1, N]` on the right.

Both of them are sub-problems. We can simply repeat this process.

```cpp
// OJ: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: github.com/lzl124631x
// Time: O(N*C(N)) where C(N) is Catalan Number which equals
//   the count of unique BST. For each tree we visit each node once.
// Space: O(C(N)) because the intermediate `lefts` and `rights` vectors.
//   The actual nodes and the returned vector are not counted as consumptions.
class Solution {
    vector<TreeNode*> dfs(int first, int last) {
        if (first > last) return {nullptr};
        vector<TreeNode*> ans;
        for (int i = first; i <= last; ++i) {
            for (auto left : dfs(first, i - 1)) {
                for (auto right : dfs(i + 1, last)) {
                    ans.push_back(new TreeNode(i, left, right));
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};
```