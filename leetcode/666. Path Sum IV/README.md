# [666. Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)

<p>
If the depth of a tree is smaller than <code>5</code>, then this tree can be represented by a list of three-digits integers.
</p>

<p>
For each integer in this list:<br>
</p><ol>
<li>The hundreds digit represents the depth <code>D</code> of this node, <code>1 &lt;= D &lt;= 4.</code></li>
<li>The tens digit represents the position <code>P</code> of this node in the level it belongs to, <code>1 &lt;= P &lt;= 8</code>. The position is the same as that in a full binary tree. </li>
<li>The units digit represents the value <code>V</code> of this node, <code>0 &lt;= V &lt;= 9.</code></li>
</ol>
<p></p>

<p>
Given a list of <code>ascending</code> three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [113, 215, 221]
<b>Output:</b> 12
<b>Explanation:</b> 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> [113, 221]
<b>Output:</b> 4
<b>Explanation:</b> 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
</pre>
<p></p>

**Companies**:  
[Alibaba](https://leetcode.com/company/alibaba)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Path Sum III (Easy)](https://leetcode.com/problems/path-sum-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n / 10] = n % 10;
        }
        int sum = 0;
        for (int n : nums) {
            int d = n / 100, p = n / 10 % 10, v = m[d * 10 + p];
            int left = (d + 1) * 10 + p * 2 - 1, right = left + 1;
            if (m.count(left)) m[left] += v;
            if (m.count(right)) m[right] += v;
            if (m.count(left) == 0 && m.count(right) == 0) sum += v;
        }
        return sum;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int vals[33] = {[0 ... 32] = -1}, ans = 0;
    void dfs(int i, int sum) {
        if (vals[i] == -1) return;
        sum += vals[i];
        int left = 2 * i, right = 2 * i + 1;
        if (vals[left] == -1 && vals[right] == -1) {
            ans += sum;
            return;
        }
        dfs(left, sum);
        dfs(right, sum);
    }
public:
    int pathSum(vector<int>& A) {
        for (int n : A) {
            int lv = n / 100, index = n % 100 / 10, val = n % 10, i = (1 << (lv - 1)) - 1 + index;
            vals[i] = val;
        }
        dfs(1, 0);
        return ans;
    }
};
```