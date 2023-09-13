# [2799. Count Complete Subarrays in an Array (Medium)](https://leetcode.com/problems/count-complete-subarrays-in-an-array)

<p>You are given an array <code>nums</code> consisting of <strong>positive</strong> integers.</p>
<p>We call a subarray of an array <strong>complete</strong> if the following condition is satisfied:</p>
<ul>
	<li>The number of <strong>distinct</strong> elements in the subarray is equal to the number of distinct elements in the whole array.</li>
</ul>
<p>Return <em>the number of <strong>complete</strong> subarrays</em>.</p>
<p>A <strong>subarray</strong> is a contiguous non-empty part of an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,5,5,5]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>

**Companies**:
[TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/count-complete-subarrays-in-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& A) {
        unordered_set<int> s(begin(A), end(A));
        int i = 0, j = 0, N = A.size(), ans = 0;
        unordered_map<int, int> m;
        for (; i < N; ++i) {
            while (j < N && m.size() < s.size()) m[A[j++]]++;
            if (m.size() < s.size()) break;
            ans += N - j + 1;
            if (--m[A[i]] == 0) m.erase(A[i]);
        }
        return ans;
    }
};
```

## Solution 2. Find Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/count-complete-subarrays-in-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& A) {
        unordered_set<int> s(begin(A), end(A));
        int i = 0, j = 0, N = A.size(), ans = 0, last = -1;
        unordered_map<int, int> m;
        for (; j < N; ++j) {
            m[A[j]]++;
            while (m.size() == s.size()) {
                if (--m[A[i]] == 0) m.erase(A[i]);
                last = i;
                ++i;
            }
            if (last != -1) ans += last + 1;
        }
        return ans;
    }
};
```