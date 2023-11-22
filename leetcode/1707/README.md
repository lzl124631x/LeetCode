# [1707. Maximum XOR With an Element From Array (Hard)](https://leetcode.com/problems/maximum-xor-with-an-element-from-array)

<p>You are given an array <code>nums</code> consisting of non-negative integers. You are also given a <code>queries</code> array, where <code>queries[i] = [x<sub>i</sub>, m<sub>i</sub>]</code>.</p>

<p>The answer to the <code>i<sup>th</sup></code> query is the maximum bitwise <code>XOR</code> value of <code>x<sub>i</sub></code> and any element of <code>nums</code> that does not exceed <code>m<sub>i</sub></code>. In other words, the answer is <code>max(nums[j] XOR x<sub>i</sub>)</code> for all <code>j</code> such that <code>nums[j] &lt;= m<sub>i</sub></code>. If all elements in <code>nums</code> are larger than <code>m<sub>i</sub></code>, then the answer is <code>-1</code>.</p>

<p>Return <em>an integer array </em><code>answer</code><em> where </em><code>answer.length == queries.length</code><em> and </em><code>answer[i]</code><em> is the answer to the </em><code>i<sup>th</sup></code><em> query.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
<strong>Output:</strong> [3,3,7]
<strong>Explanation:</strong>
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
<strong>Output:</strong> [15,-1,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= nums[j], x<sub>i</sub>, m<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Trie](https://leetcode.com/tag/trie)

**Similar Questions**:
* [Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array)
* [Maximum Genetic Difference Query (Hard)](https://leetcode.com/problems/maximum-genetic-difference-query)
* [Minimize XOR (Medium)](https://leetcode.com/problems/minimize-xor)
* [Maximum Strong Pair XOR I (Easy)](https://leetcode.com/problems/maximum-strong-pair-xor-i)
* [Maximum Strong Pair XOR II (Hard)](https://leetcode.com/problems/maximum-strong-pair-xor-ii)

**Hints**:
* In problems involving bitwise operations, we often think on the bits level. In this problem, we can think that to maximize the result of an xor operation, we need to maximize the most significant bit, then the next one, and so on.
* If there's some number in the array that is less than m and whose the most significant bit is different than that of x, then xoring with this number maximizes the most significant bit, so I know this bit in the answer is 1.
* To check the existence of such numbers and narrow your scope for further bits based on your choice, you can use trie.
* You can sort the array and the queries, and maintain the trie such that in each query the trie consists exactly of the valid elements.

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// Author: github.com/lzl124631x
// Time: O(A + Q)
// Space: O(A)
struct TrieNode {
    TrieNode *next[2] = {};
    int minVal = INT_MAX;
};
class Solution {
    void addNumber(TrieNode *node, int n) {
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
            node->minVal = min(node->minVal, n);
        }
    }
    int maxXor(TrieNode *node, int n, int mx) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1, r = 1 - b;
            if (node->next[r] && node->next[r]->minVal <= mx) node = node->next[r], ans |= (1 << i);
            else if (node->next[b] && node->next[b]->minVal <= mx) node = node->next[b];
            else return -1;
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& A, vector<vector<int>>& Q) {
        TrieNode root;
        for (int n : A) addNumber(&root, n);
        vector<int> ans;
        for (auto &q : Q) {
            int x = q[0], m = q[1];
            ans.push_back(maxXor(&root, x, m));
        }
        return ans;
    }
};
```

## Solution 2. Offline Query + Trie

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// Author: github.com/lzl124631x
// Time: O(QlogQ + AlogA + Q + A)
// Space: O(Q + A)
struct TrieNode {
    TrieNode *next[2] = {};
};
class Solution {
    void addNumber(TrieNode *node, int n) {
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1;
            if (!node->next[b]) node->next[b] = new TrieNode();
            node = node->next[b];
        }
    }
    int find(TrieNode *node, int n) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int b = n >> i & 1, r = 1 - b;
            if (node->next[r]) node = node->next[r], ans |= (1 << i);
            else node = node->next[b];
        }
        return ans;
    }
public:
    vector<int> maximizeXor(vector<int>& A, vector<vector<int>>& Q) {
        sort(begin(A), end(A));
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [](auto &a, auto &b) { return a[1] < b[1]; });
        int i = 0, N = A.size();
        TrieNode root;
        vector<int> ans(Q.size());
        for (auto &q : Q) {
            int x = q[0], m = q[1], idx = q[2];
            while (i < N && A[i] <= m) addNumber(&root, A[i++]);
            ans[idx] = i == 0 ? -1 : find(&root, x);
        }
        return ans;
    }
};
```