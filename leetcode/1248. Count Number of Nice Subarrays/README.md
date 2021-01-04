# [1248. Count Number of Nice Subarrays (Medium)](https://leetcode.com/problems/count-number-of-nice-subarrays/)

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>. A continuous subarray is called <strong>nice</strong> if there are <code>k</code> odd numbers on it.</p>

<p>Return <em>the number of <strong>nice</strong> sub-arrays</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,1,1], k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,6], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no odd numbers in the array.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,2,1,2,2,1,2,2,2], k = 2
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1. Map

Use a map `m` to store the mapping from the count of odd numbers `cnt` to the first index in the array that has `cnt` numbers in front of it and including itself.

When `cnt >= k`, we add `m[cnt - k + 1] - m[cnt - k]` to the answer.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int N = A.size(), cnt = 0, ans = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < N; ++i) {
            cnt += A[i] % 2;
            if (m.count(cnt) == 0) m[cnt] = i;
            if (cnt >= k) ans += m[cnt - k + 1] - m[cnt - k]; 
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

Assume the current pointer is `j` and the corresponding odd number count is `cj`, we need two pointers to get the answer.

The first pointer `i` is the index whose corresponding odd number count is `cj - k + 1`.

The second pointer `prev` is the index whose corresponding odd number count is `cj - k`.

So when `cj >= k`, we add `i - prev` to the answer.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int N = A.size(), i = 0, j = 0, prev = -1, ans = 0, ci = 0, cj = 0;
        while (j < N) {
            cj += A[j++] % 2;
            if (ci <= cj - k) {
                prev = i;
                while (ci <= cj - k) ci += A[i++] % 2;
            }
            if (cj >= k) ans += i - prev;
        }
        return ans;
    }
};
```

Or use a single count.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int N = A.size(), i = 0, j = 0, prev = -1, ans = 0, cnt = 0;
        while (j < N) {
            int c = A[j++] % 2;
            cnt += c;
            if (c && cnt >= k) {
                prev = i;
                while (A[i] % 2 == 0) ++i;
                ++i;
            }
            if (cnt >= k) ans += i - prev;
        }
        return ans;
    }
};
``