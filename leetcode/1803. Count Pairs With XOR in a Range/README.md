# [1803. Count Pairs With XOR in a Range (Hard)](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/)

<p>Given a <strong>(0-indexed)</strong> integer array <code>nums</code> and two integers <code>low</code> and <code>high</code>, return <em>the number of <strong>nice pairs</strong></em>.</p>

<p>A <strong>nice pair</strong> is a pair <code>(i, j)</code> where <code>0 &lt;= i &lt; j &lt; nums.length</code> and <code>low &lt;= (nums[i] XOR nums[j]) &lt;= high</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,2,7], low = 2, high = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [9,8,4,2,1], low = 5, high = 14
<strong>Output:</strong> 8
<strong>Explanation:</strong> All nice pairs (i, j) are as follows:
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
&nbsp;   - (0, 3): nums[0] XOR nums[3] = 11
&nbsp;   - (0, 4): nums[0] XOR nums[4] = 8
&nbsp;   - (1, 2): nums[1] XOR nums[2] = 12
&nbsp;   - (1, 3): nums[1] XOR nums[3] = 10
&nbsp;   - (1, 4): nums[1] XOR nums[4] = 9
&nbsp;   - (2, 3): nums[2] XOR nums[3] = 6
&nbsp;   - (2, 4): nums[2] XOR nums[4] = 5</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

### Complexity Analysis

Adding a number into trie takes `O(16) = O(1)` time.

The `count` will at most visit a perfect binary-tree like trie whose height is `16`, so there are at most `O(2^16-1) = O(1)` nodes. Hence the space complexity is `O(1)`.

Since we repeat the above operations `N` times, the overall time complexity is `O(N)`.

```cpp
// OJ: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
struct TrieNode {
    TrieNode *next[2] = {};
    int cnt = 0;
};
class Solution {
    void add(TrieNode *node, int n) {
        for (int i = 15; i >= 0; --i) {
            int b = n >> i & 1;
            if (node->next[b] == NULL) node->next[b] = new TrieNode();
            node = node->next[b];
            node->cnt++;
        }
    }
    int count(TrieNode *node, int i, int n, int rl, int rh, int low, int high) {
        if (rl >= low && rh <= high) return node->cnt;
        if (rh < low || rl > high) return 0;
        int b = n >> i & 1, r = b ^ 1, mask = ~(1 << i);
        return (node->next[0] ? count(node->next[0], i - 1, n, rl & mask | (b << i), rh & mask | (b << i), low, high) : 0)
            + (node->next[1] ? count(node->next[1], i - 1, n, rl & mask | (r << i), rh & mask | (r << i), low, high) : 0);
    }
public:
    int countPairs(vector<int>& A, int low, int high) {
        TrieNode root;
        int ans = 0;
        for (int n : A) {
            ans += count(&root, 15, n, 0, (1 << 16) - 1, low, high);
            add(&root, n);
        }
        return ans;
    }
};
```