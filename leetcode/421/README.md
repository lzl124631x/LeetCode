# [421. Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

<p>Given an integer array <code>nums</code>, return <em>the maximum result of </em><code>nums[i] XOR nums[j]</code>, where <code>0 &lt;= i &lt;= j &lt; n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,10,5,25,2,8]
<strong>Output:</strong> 28
<strong>Explanation:</strong> The maximum result is 5 XOR 25 = 28.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [14,70,53,83,49,91,36,80,92,51,66,70]
<strong>Output:</strong> 127
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Maximum XOR With an Element From Array (Hard)](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

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
    void add(TrieNode *node, int n) {
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1;
            if (node->next[b] == NULL) node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
    int maxXor(TrieNode *node, int n) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1;
            if (node->next[1 - b]) { // if we can go the opposite direction, do it.
                node = node->next[1 - b];
                ans |= 1 << i;
            } else {
                node = node->next[b];
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& A) {
        TrieNode root;
        int ans = 0;
        for (int n : A) {
            add(&root, n);
            ans = max(ans, maxXor(&root, n));
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

## TODO

There are faster solutions in "Accepted Solutions Runtime Distribution". Learn those solutions.