# [163. Missing Ranges (Easy)](https://leetcode.com/problems/missing-ranges/)

<p>You are given an inclusive range <code>[lower, upper]</code> and a <strong>sorted unique</strong> integer array <code>nums</code>, where all elements are in the inclusive range.</p>

<p>A number <code>x</code> is considered <strong>missing</strong> if <code>x</code> is in the range <code>[lower, upper]</code> and <code>x</code> is not in <code>nums</code>.</p>

<p>Return <em>the <strong>smallest sorted</strong> list of ranges that <strong>cover every missing number exactly</strong></em>. That is, no element of <code>nums</code> is in any of the ranges, and each missing number is in one of the ranges.</p>

<p>Each range <code>[a,b]</code> in the list should be output as:</p>

<ul>
	<li><code>"a-&gt;b"</code> if <code>a != b</code></li>
	<li><code>"a"</code> if <code>a == b</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,3,50,75], lower = 0, upper = 99
<strong>Output:</strong> ["2","4-&gt;49","51-&gt;74","76-&gt;99"]
<strong>Explanation:</strong> The ranges are:
[2,2] --&gt; "2"
[4,49] --&gt; "4-&gt;49"
[51,74] --&gt; "51-&gt;74"
[76,99] --&gt; "76-&gt;99"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [], lower = 1, upper = 1
<strong>Output:</strong> ["1"]
<strong>Explanation:</strong> The only missing range is [1,1], which becomes "1".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [], lower = -3, upper = -1
<strong>Output:</strong> ["-3-&gt;-1"]
<strong>Explanation:</strong> The only missing range is [-3,-1], which becomes "-3-&gt;-1".
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [-1], lower = -1, upper = -1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no missing ranges since there are no missing numbers.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> nums = [-1], lower = -2, upper = -1
<strong>Output:</strong> ["-2"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>9</sup> &lt;= lower &lt;= upper &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= nums.length &lt;= 100</code></li>
	<li><code>lower &lt;= nums[i] &lt;= upper</code></li>
	<li>All the values of <code>nums</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Summary Ranges (Easy)](https://leetcode.com/problems/summary-ranges/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/missing-ranges/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    string formatRange(int lower, int upper) {
        if (lower == upper) return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& A, int lower, int upper) {
        vector<string> ans;
        int i = lower, j = 0, N = A.size();
        while (j < N) {
            if (i == A[j]) {
                ++i;
                ++j;
            } else {
                int first = i, last = A[j] - 1;
                ans.push_back(formatRange(first, last));
                i = A[j++] + 1;
            }
        }
        if (i <= upper) ans.push_back(formatRange(i, upper));
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/missing-ranges/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    string formatRange(int lower, int upper) {
        if (lower == upper) return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& A, int lower, int upper) {
        vector<string> ans;
        int prev = lower - 1, N = A.size();
        for (int i = 0; i <= N; ++i) {
            int cur = i < N ? A[i] : upper + 1;
            if (prev + 1 <= cur - 1) ans.push_back(formatRange(prev + 1, cur - 1));
            prev = cur;
        }
        return ans;
    }
};
```