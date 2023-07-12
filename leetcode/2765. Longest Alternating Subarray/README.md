# [2765. Longest Alternating Subarray (Easy)](https://leetcode.com/problems/longest-alternating-subarray)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. A subarray <code>s</code> of length <code>m</code> is called <strong>alternating</strong> if:</p>
<ul>
	<li><code>m</code> is greater than <code>1</code>.</li>
	<li><code>s<sub>1</sub> = s<sub>0</sub> + 1</code>.</li>
	<li>The <strong>0-indexed</strong> subarray <code>s</code> looks like <code>[s<sub>0</sub>, s<sub>1</sub>, s<sub>0</sub>, s<sub>1</sub>,...,s<sub>(m-1) % 2</sub>]</code>. In other words, <code>s<sub>1</sub> - s<sub>0</sub> = 1</code>, <code>s<sub>2</sub> - s<sub>1</sub> = -1</code>, <code>s<sub>3</sub> - s<sub>2</sub> = 1</code>, <code>s<sub>4</sub> - s<sub>3</sub> = -1</code>, and so on up to <code>s[m - 1] - s[m - 2] = (-1)<sup>m</sup></code>.</li>
</ul>
<p>Return <em>the maximum length of all <strong>alternating</strong> subarrays present in </em><code>nums</code> <em>or </em><code>-1</code><em> if no such subarray exists</em><em>.</em></p>
<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,3,4,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The alternating subarrays are [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [4,5] and [5,6] are the only two alternating subarrays. They are both of length 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Longest Turbulent Subarray (Medium)](https://leetcode.com/problems/longest-turbulent-subarray/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/longest-alternating-subarray
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int N = A.size(), ans = -1;
        for (int i = 0; i + 1 < N; ++i) {
            int a = A[i], b = A[i + 1];
            if (b - a != 1) continue;
            int j = i + 2;
            for (; j < N; ++j) {
                if ((j - i) % 2 == 0 && A[j] != a) break;
                if ((j - i) % 2 == 1 && A[j] != b) break;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-alternating-subarray
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int N = A.size(), ans = -1;
        for (int i = 0; i + 1 < N;) {
            int a = A[i], b = A[i + 1];
            if (b - a != 1) {
                ++i;
                continue;
            }
            int j = i + 2;
            for (; j < N; ++j) {
                if ((j - i) % 2 == 0 && A[j] != a) break;
                if ((j - i) % 2 == 1 && A[j] != b) break;
            }
            ans = max(ans, j - i);
            i = j - 1;
        }
        return ans;
    }
};
```