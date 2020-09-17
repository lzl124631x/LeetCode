# [421. Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

<p>Given an integer array <code>nums</code>, return <em>the maximum result of <code>nums[i] XOR nums[j]</code></em>, where <code>0 ≤ i ≤ j &lt; n</code>.</p>

<p><strong>Follow up:</strong> Could you do this in <code>O(n)</code> runtime?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,10,5,25,2,8]
<strong>Output:</strong> 28
<strong>Explanation:</strong> The maximum result is 5 XOR 25 = 28.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [2,4]
<strong>Output:</strong> 6
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [8,10,2]
<strong>Output:</strong> 10
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> nums = [14,70,53,83,49,91,36,80,92,51,66,70]
<strong>Output:</strong> 127
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

Flatten the bits information of the array into a Trie. For each number in array, use Trie to find the maximum value it can get using `xor`.

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/63207/java-o-n-solution-using-trie
struct TrieNode {
    TrieNode *next[2] = {};
};
class Solution {
    void addNode(TrieNode *node, int n) {
        for (int i = 31; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (!node->next[bit]) node->next[bit] = new TrieNode();
            node = node->next[bit];
        }
    }
public:
    int findMaximumXOR(vector<int>& A) {
        TrieNode root;
        for (int n : A) addNode(&root, n);
        int ans = 0;
        for (int n : A) {
             auto node = &root;
            int val = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (n >> i) & 1;
                if (node->next[1 ^ bit]) {
                    val |= 1 << i;
                    node = node->next[1 ^ bit];
                } else node = node->next[bit];
            }
            ans = max(ans, val);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap
class Solution {
public:
    int findMaximumXOR(vector<int>& A) {
        unordered_set<int> s;
        int mask = 0, ans = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= 1 << i;
            s.clear();
            for (int n : A) s.insert(n & mask);
            int next = ans | (1 << i);
            for (int prefix : s) {
                if (!s.count(next ^ prefix)) continue;
                ans |= 1 << i;
                break;
            }
        }
        return ans;
    }
};
```