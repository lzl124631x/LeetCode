# [2200. Find All K-Distant Indices in an Array (Easy)](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and two integers <code>key</code> and <code>k</code>. A <strong>k-distant index</strong> is an index <code>i</code> of <code>nums</code> for which there exists at least one index <code>j</code> such that <code>|i - j| &lt;= k</code> and <code>nums[j] == key</code>.</p>

<p>Return <em>a list of all k-distant indices sorted in <strong>increasing order</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,9,1,3,9,5], key = 9, k = 1
<strong>Output:</strong> [1,2,3,4,5,6]
<strong>Explanation:</strong> Here, <code>nums[2] == key</code> and <code>nums[5] == key.
- For index 0, |0 - 2| &gt; k and |0 - 5| &gt; k, so there is no j</code> where <code>|0 - j| &lt;= k</code> and <code>nums[j] == key. Thus, 0 is not a k-distant index.
- For index 1, |1 - 2| &lt;= k and nums[2] == key, so 1 is a k-distant index.
- For index 2, |2 - 2| &lt;= k and nums[2] == key, so 2 is a k-distant index.
- For index 3, |3 - 2| &lt;= k and nums[2] == key, so 3 is a k-distant index.
- For index 4, |4 - 5| &lt;= k and nums[5] == key, so 4 is a k-distant index.
- For index 5, |5 - 5| &lt;= k and nums[5] == key, so 5 is a k-distant index.
- For index 6, |6 - 5| &lt;= k and nums[5] == key, so 6 is a k-distant index.
</code>Thus, we return [1,2,3,4,5,6] which is sorted in increasing order. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,2,2,2], key = 2, k = 2
<strong>Output:</strong> [0,1,2,3,4]
<strong>Explanation:</strong> For all indices i in nums, there exists some index j such that |i - j| &lt;= k and nums[j] == key, so every index is a k-distant index. 
Hence, we return [0,1,2,3,4].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>key</code> is an integer from the array <code>nums</code>.</li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Shortest Word Distance (Easy)](https://leetcode.com/problems/shortest-word-distance/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& A, int key, int k) {
        int N = A.size();
        vector<int> ans, idx;
        for (int i = 0; i < N; ++i){
            if (A[i] == key) idx.push_back(i); // `idx` is a list of indices whose corresponding value is `key`.
        }
        for (int i = 0, j = 0; i < N && j < idx.size(); ++i) {
            if (i < idx[j] - k) continue; // If `i` is not yet in range of the next `key` element at `idx[j]`, skip.
            while (j < idx.size() && i > idx[j] + k) ++j; // While `i > idx[j] + k`, keep incrementing `j` to bring `idx[j]` in range of `i`.
            if (j < idx.size() && i <= idx[j] + k && i >= idx[j] - k) ans.push_back(i); // add `i` to the answer if `idx[j] - k <= i <= idx[j] + k`.
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& A, int key, int k) {
        int N = A.size(), j = 0;
        vector<int> ans;
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && (A[j] != key || j < i - k)) ++j; // Find the first index `j` that `A[j] == key` and `j >= i - k`.
            if (j == N) break;
            if (i <= j + k && i >= j - k) ans.push_back(i); // add `i` to answer if `j - k <= i <= j + k`.
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/discuss/1845499