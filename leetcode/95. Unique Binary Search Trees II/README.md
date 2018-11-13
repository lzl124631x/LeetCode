# [95. Unique Binary Search Trees II (Medium)](https://leetcode.com/problems/unique-binary-search-trees-ii/)

Given an integer _n_, generate all structurally unique **BST's** (binary search trees) that store values 1 ... _n_.

**Example:**

**Input:** 3  
**Output:**
```
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
```
**Explanation:**  
The above output corresponds to the 5 unique BST's shown below:
```

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

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
private:
    vector<TreeNode*> generateTrees(int first, int last) {
        if (first > last) return { NULL };
        vector<TreeNode*> v;
        for (int i = first; i <= last; ++i) {
            auto lefts = generateTrees(first, i - 1);
            auto rights = generateTrees(i + 1, last);
            for (auto left : lefts) {
                for (auto right : rights) {
                    v.push_back(new TreeNode(i));
                    v.back()->left = left;
                    v.back()->right = right;
                }
            }
        }
        return v;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        return generateTrees(1, n);
    }
};
```