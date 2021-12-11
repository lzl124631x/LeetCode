# [2099. Find Subsequence of Length K With the Largest Sum (Easy)](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. You want to find a <strong>subsequence </strong>of <code>nums</code> of length <code>k</code> that has the <strong>largest</strong> sum.</p>

<p>Return<em> </em><em><strong>any</strong> such subsequence as an integer array of length </em><code>k</code>.</p>

<p>A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,3,3], k = 2
<strong>Output:</strong> [3,3]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 3 = 6.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-1,-2,3,4], k = 3
<strong>Output:</strong> [-1,3,4]
<strong>Explanation:</strong> 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,3,3], k = 2
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong>
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


**Similar Questions**:
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Maximize Sum Of Array After K Negations (Easy)](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)
* [Sort Integers by The Number of 1 Bits (Easy)](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& A, int k) {
        vector<int> id(A.size());
        iota(begin(id), end(id), 0); // Index array 0, 1, 2, ...
        sort(begin(id), end(id), [&](int a, int b) { return A[a] > A[b]; }); // Sort the indexes in descending order of their corresponding values in `A`
        id.resize(k); // Only keep the first `k` indexes with the greatest `A` values
        sort(begin(id), end(id)); // Sort indexes in ascending order
        vector<int> ans;
        for (int i : id) ans.push_back(A[i]);
        return ans;
    }
};
```

## Solution 2. Quick Select

```cpp
// OJ: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N + KlogK) on average, O(N^2 + KlogK) in the worst case
// Space: O(N)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& A, int k) {
        vector<int> id(A.size());
        iota(begin(id), end(id), 0);
        nth_element(begin(id), begin(id) + k, end(id), [&](int a, int b) { return A[a] > A[b]; });
        id.resize(k);
        sort(begin(id), end(id));
        vector<int> ans;
        for (int i : id) ans.push_back(A[i]);
        return ans;
    }
};
```

## Solution 3. Quick Select

```cpp
// OJ: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(N)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& A, int k) {
        if (k == A.size()) return A;
        vector<int> v(begin(A), end(A)), ans;
        nth_element(begin(v), begin(v) + k - 1, end(v), greater<>());
        int cnt = count(begin(v), begin(v) + k, v[k - 1]);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > v[k - 1] || (A[i] == v[k - 1] && --cnt >= 0)) ans.push_back(A[i]);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/discuss/1623427/C%2B%2B-Sorting-or-Quick-Select