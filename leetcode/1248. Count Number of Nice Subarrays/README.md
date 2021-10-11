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

**Companies**:  
[Booking.com](https://leetcode.com/company/bookingcom), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Sliding Window](https://leetcode.com/tag/sliding-window/)


## Solution 1. Prefix State Map

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
```

## Solution 3. AtMost to Equal + Find Maximum Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)"

Exactly `k` times = At Most `k` times - At Most `k - 1` times.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/419378/JavaC%2B%2BPython-Sliding-Window-O(1)-Space
class Solution {
    int atMost(vector<int> &A, int k) {
        int N = A.size(), i = 0, ans = 0;
        for (int j = 0; j < N; ++j) {
            k -= A[j] % 2;
            while (k < 0) k += A[i++] % 2;
            ans += j - i;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }
};
```

## Discuss

https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/1515501/C%2B%2B-Prefix-State-Map-Two-Pointers-Sliding-Window