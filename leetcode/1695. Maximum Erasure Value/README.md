# [1695. Maximum Erasure Value (Medium)](https://leetcode.com/problems/maximum-erasure-value/)

<p>You are given an array of positive integers <code>nums</code> and want to erase a subarray containing&nbsp;<strong>unique elements</strong>. The <strong>score</strong> you get by erasing the subarray is equal to the <strong>sum</strong> of its elements.</p>

<p>Return <em>the <strong>maximum score</strong> you can get by erasing <strong>exactly one</strong> subarray.</em></p>

<p>An array <code>b</code> is called to be a <span class="tex-font-style-it">subarray</span> of <code>a</code> if it forms a contiguous subsequence of <code>a</code>, that is, if it is equal to <code>a[l],a[l+1],...,a[r]</code> for some <code>(l,r)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,4,5,6]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The optimal subarray here is [2,4,5,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,1,2,5,2,1,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The optimal subarray here is [5,2,1] or [1,2,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Cashfree](https://leetcode.com/company/cashfree)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Solution 1. Shrinkable Sliding Window + Hash Map

```cpp
// OJ: https://leetcode.com/problems/maximum-erasure-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int i = 0, ans = 0, N = A.size(); // window [i, j] is a window which only contains unique elements.
        unordered_map<int, int> m; // number -> index of last occurrence.
        vector<int> sum(N + 1);
        partial_sum(begin(A), end(A), begin(sum) + 1);
        for (int j = 0; j < N; ++j) {
            if (m.count(A[j])) i = max(i, m[A[j]] + 1);
            m[A[j]] = j;
            ans = max(ans, sum[j + 1] - sum[i]);
        }
        return ans;
    }
};
```

## Solution 2. Shrinkable Sliding Window + Hash Set

```cpp
// OJ: https://leetcode.com/problems/maximum-erasure-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) where U is the number of unique elements in `A`
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int ans = 0, N = A.size(), sum = 0;
        unordered_set<int> s;
        for (int i = 0, j = 0; j < N; ++j) {
            while (s.count(A[j])) {
                s.erase(A[i]);
                sum -= A[i++];
            }
            s.insert(A[j]);
            sum += A[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Solution 3. Shrinkable Sliding Window + Prefix State Map

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)"

```cpp
// OJ: https://leetcode.com/problems/maximum-erasure-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) where U is the number of unique elements in `A`
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), ans = 0, dup = 0, sum = 0;
        unordered_map<int, int> cnt;
        while (j < N) {
            dup += ++cnt[A[j]] == 2;
            sum += A[j++];
            while (dup) {
                dup -= --cnt[A[i]] == 1;
                sum -= A[i++];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-erasure-value/discuss/1504271