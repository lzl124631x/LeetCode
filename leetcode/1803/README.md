# [1803. Count Pairs With XOR in a Range (Hard)](https://leetcode.com/problems/count-pairs-with-xor-in-a-range)

<p>Given a <strong>(0-indexed)</strong> integer array <code>nums</code> and two integers <code>low</code> and <code>high</code>, return <em>the number of <strong>nice pairs</strong></em>.</p>

<p>A <strong>nice pair</strong> is a pair <code>(i, j)</code> where <code>0 &lt;= i &lt; j &lt; nums.length</code> and <code>low &lt;= (nums[i] XOR nums[j]) &lt;= high</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,2,7], low = 2, high = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [9,8,4,2,1], low = 5, high = 14
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

**Companies**:
[Google](https://leetcode.com/company/google), [Vimeo](https://leetcode.com/company/vimeo)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Trie](https://leetcode.com/tag/trie)

**Hints**:
* Let's note that we can count all pairs with XOR ≤ K, so the answer would be to subtract the number of pairs withs XOR < low from the number of pairs with XOR ≤ high.
* For each value, find out the number of values when you XOR it with the result is  ≤ K using a trie.

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
const int BIT = 15;
class Solution {
    void addNode(TrieNode *node, int n) {
        for (int i = BIT; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
            node->cnt++;
        }
    }
    int count(TrieNode *node, int n, int low, int high, int i = BIT, int rangeMin = 0, int rangeMax = (1 << (BIT + 1)) - 1) {
        if (rangeMin >= low && rangeMax <= high) return node->cnt;
        if (rangeMax < low || rangeMin > high) return 0;
        int ans = 0, b = n >> i & 1, r = 1 - b, mask = 1 << i;
        if (node->next[b]) ans += count(node->next[b], n, low, high, i - 1, rangeMin & ~mask, rangeMax & ~mask);
        if (node->next[r]) ans += count(node->next[r], n, low, high, i - 1, rangeMin | mask, rangeMax | mask);
        return ans;
    }
public:
    int countPairs(vector<int>& A, int low, int high) {
        TrieNode root;
        int ans = 0;
        for (int n : A) {
            ans += count(&root, n, low, high);
            addNode(&root, n);
        }
        return ans;
    }
};
```

## Solution 2. Trie

```cpp
// OJ: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
struct TrieNode {
    TrieNode *next[2] = {};
    int cnt = 0;
};
const int BIT = 15;
class Solution {
    void addNode(TrieNode *node, int n) {
        for (int i = BIT; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
            node->cnt++;
        }
    }
    int countLessThan(TrieNode *node, int n, int limit) {
        int ans = 0;
        for (int i = BIT; i >= 0 && node; --i) {
            int b = n >> i & 1, r = 1 - b, lb = limit >> i & 1;
            if (lb == 1) {
                if (node->next[b]) ans += node->next[b]->cnt;
                node = node->next[r];
            } else {
                node = node->next[b];
            }
        }
        return ans;
    }
    int count(TrieNode *node, int n, int low, int high) {
        return countLessThan(node, n, high + 1) - countLessThan(node, n, low);
    }
public:
    int countPairs(vector<int>& A, int low, int high) {
        TrieNode root;
        int ans = 0;
        for (int n : A) {
            ans += count(&root, n, low, high);
            addNode(&root, n);
        }
        return ans;
    }
};
```