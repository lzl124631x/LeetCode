# [2962. Count Subarrays Where Max Element Appears at Least K Times (Medium)](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times)

<p>You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.</p>

<p>Return <em>the number of subarrays where the <strong>maximum</strong> element of </em><code>nums</code><em> appears <strong>at least</strong> </em><code>k</code><em> times in that subarray.</em></p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,2,3,3], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,2,1], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> No subarray contains the element 4 at least 3 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

## Solution 1. Map of first occurrence

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        long long N = A.size(), ans = 0, cnt = 0, mx = *max_element(begin(A), end(A));
        unordered_map<int, int> m; // mapping from A[i] to the index of its first occurrence
        for (int i = 0; i < N; ++i) {
            cnt += A[i] == mx;
            if (cnt && m.count(cnt) == 0) m[cnt] = i; // Store the index of its first occurrence
            if (m.count(cnt - k + 1)) {
                ans += m[cnt - k + 1] + 1; // add 1 + frequency of the first occurrence of cnt-k+1
            }
        }
        return ans;
    }
};
```

## Solution 2. Find Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        long long N = A.size(), ans = 0, cnt = 0, mx = *max_element(begin(A), end(A)), i = 0, j = 0;
        for (; j < N; ++j) {
            cnt += A[j] == mx;
            while (i <= j && cnt >= k) cnt -= A[i++] == mx;
            ans += i;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4384450/map-of-first-occurrence-o-n-time/