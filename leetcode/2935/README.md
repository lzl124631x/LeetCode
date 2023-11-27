# [2935. Maximum Strong Pair XOR II (Hard)](https://leetcode.com/problems/maximum-strong-pair-xor-ii)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. A pair of integers <code>x</code> and <code>y</code> is called a <strong>strong</strong> pair if it satisfies the condition:</p>

<ul>
	<li><code>|x - y| &lt;= min(x, y)</code></li>
</ul>

<p>You need to select two integers from <code>nums</code> such that they form a strong pair and their bitwise <code>XOR</code> is the <strong>maximum</strong> among all strong pairs in the array.</p>

<p>Return <em>the <strong>maximum</strong> </em><code>XOR</code><em> value out of all possible strong pairs in the array</em> <code>nums</code>.</p>

<p><strong>Note</strong> that you can pick the same integer twice to form a pair.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 11 strong pairs in the array <code>nums</code>: (1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) and (5, 5).
The maximum XOR possible from these pairs is 3 XOR 4 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [10,100]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are 2 strong pairs in the array nums: (10, 10) and (100, 100).
The maximum XOR possible from these pairs is 10 XOR 10 = 0 since the pair (100, 100) also gives 100 XOR 100 = 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [500,520,2500,3000]
<strong>Output:</strong> 1020
<strong>Explanation:</strong> There are 6 strong pairs in the array nums: (500, 500), (500, 520), (520, 520), (2500, 2500), (2500, 3000) and (3000, 3000).
The maximum XOR possible from these pairs is 500 XOR 520 = 1020 since the only other non-zero XOR value is 2500 XOR 3000 = 636.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2<sup>20</sup> - 1</code></li>
</ul>


**Similar Questions**:
* [Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array)
* [Maximum XOR With an Element From Array (Hard)](https://leetcode.com/problems/maximum-xor-with-an-element-from-array)

**Hints**:
* Sort the array, now let <code>x <= y</code> which means <code>|x - y| <= min(x, y)</code> can now be written as <code>y - x <= x</code> or in other words, <code>y <= 2 * x</code>.
* If <code>x</code> and <code>y</code> have the same number of bits, try making<code>y</code>’s bits different from x if possible for each bit starting from the second most significant bit.
* If <code>y</code> has 1 more bit than <code>x</code> and <code>y <= 2 * x</code> use the idea about Digit DP to make <code>y</code>’s prefix smaller than <code>2 * x + 1</code> as well as trying to make each bit different from <code>x</code> using a Hashmap.
* Alternatively, use Trie data structure to find the pair with maximum <code>XOR</code>.

## Solution 1. Trie

* Record the numbers using Trie. For example, `4 = 100`, then we add trie nodes from the top to bottom `1 -> 0 -> 0`.
* Sort `A` in ascending order. Traverse from left to right. For each `A[i]`, we can use two pointers to get the maximum `A[j]` that can form strong pair with `A[i]`.
* Given `A[i]` and corresponding maximum strong pair counterpart `A[j]`, search through the Trie. Greedily try to go the other branch if possible.

```cpp
// OJ: https://leetcode.com/problems/maximum-strong-pair-xor-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
struct TrieNode {
    TrieNode *next[2] = {};
};
class Solution {
    void add(TrieNode *node, int n) {
        for (int i = 19; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
public:
    int maximumStrongPairXor(vector<int>& A) {
        int N = A.size(), ans = 0;
        sort(begin(A), end(A));
        TrieNode root;
        for (int n : A) add(&root, n); // add this number into Trie
        auto find = [&](TrieNode *node, int n, int mx) {
            int val = 0, first = 0;
            for (int i = 19; i >= 0; --i) {
                int b = n >> i & 1, r = 1 - b;
                if (b && !first) first = 1; // this is the first bit 1 in `n`
                // We should pick `r`, i.e. the other branch, if possible, but we have to pick `b`, i.e. the same branch, in the following cases:
                // 1. there is no number with `r` at `i`-th bit
                // 2. If we pick `r`, the formed number `val` will exceed `mx`.
                // 3. This is the first bit 1 in `n`, and `val` is still `0`. Then, if we pick `r = 0`, `val` will be smaller than `n`.
                if (!node->next[r] || (val + (r << i)) > mx || (first && val == 0)) node = node->next[b], val |= (b << i); // choose `b` route
                else node = node->next[r], val |= (r << i); // choose `r` route
            }
            return val < n ? 0 : val ^ n;
        };
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && A[j] - A[i] <= A[i]) ++j;
            ans = max(ans, find(&root, A[i], A[j - 1]));
        }
        return ans;
    }
};
```

## Solution 2. Trie

```cpp
// OJ: https://leetcode.com/problems/maximum-strong-pair-xor-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
struct TrieNode {
    TrieNode *next[2] = {};
    int cnt = 0;
};
class Solution {
    void addNumber(TrieNode *node, int n, int d) {
        for (int i = 19; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
            node->cnt += d;
        }
    }
    int maxXor(TrieNode *node, int n) {
        int ans = 0;
        for (int i = 19; i >= 0; --i) {
            int b = n >> i & 1, r = 1 - b;
            if (node->next[r] && node->next[r]->cnt) node = node->next[r], ans |= (1 << i);
            else node = node->next[b];
        }
        return ans;
    }
public:
    int maximumStrongPairXor(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), i = 0, j = 0, ans = 0;
        TrieNode root;
        for (; j < N; ++j) {
            addNumber(&root, A[j], 1);
            while (i < j && A[j] - A[i] > A[i]) {
                addNumber(&root, A[i], -1);
                ++i;
            }
            ans = max(ans, maxXor(&root, A[j]));
        }
        return ans;
    }
};
```