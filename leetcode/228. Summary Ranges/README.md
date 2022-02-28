# [228. Summary Ranges (Easy)](https://leetcode.com/problems/summary-ranges/)

<p>You are given a <strong>sorted unique</strong> integer array <code>nums</code>.</p>

<p>Return <em>the <strong>smallest sorted</strong> list of ranges that <strong>cover all the numbers in the array exactly</strong></em>. That is, each element of <code>nums</code> is covered by exactly one of the ranges, and there is no integer <code>x</code> such that <code>x</code> is in one of the ranges but not in <code>nums</code>.</p>

<p>Each range <code>[a,b]</code> in the list should be output as:</p>

<ul>
	<li><code>"a-&gt;b"</code> if <code>a != b</code></li>
	<li><code>"a"</code> if <code>a == b</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,2,4,5,7]
<strong>Output:</strong> ["0-&gt;2","4-&gt;5","7"]
<strong>Explanation:</strong> The ranges are:
[0,2] --&gt; "0-&gt;2"
[4,5] --&gt; "4-&gt;5"
[7,7] --&gt; "7"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,2,3,4,6,8,9]
<strong>Output:</strong> ["0","2-&gt;4","6","8-&gt;9"]
<strong>Explanation:</strong> The ranges are:
[0,0] --&gt; "0"
[2,4] --&gt; "2-&gt;4"
[6,6] --&gt; "6"
[8,9] --&gt; "8-&gt;9"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 20</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>All the values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is sorted in ascending order.</li>
</ul>


**Companies**:  
[Yandex](https://leetcode.com/company/yandex), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Missing Ranges (Easy)](https://leetcode.com/problems/missing-ranges/)
* [Data Stream as Disjoint Intervals (Hard)](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/summary-ranges/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        vector<string> ans;
        int start = 0;
        for (int i = 0, N = A.size(); i < N; ++i) {
            if (i + 1 < N && A[i + 1] == A[i] + 1) continue;
            ans.push_back(to_string(A[start]) + (i == start ? "" : ("->" + to_string(A[i]))));
            start = i + 1;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/summary-ranges/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        vector<string> ans;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            int start = A[i];
            while (i + 1 < N && A[i + 1] == A[i] + 1) ++i;
            ans.push_back(to_string(start) + (A[i] == start ? "" : ("->" + to_string(A[i]))));
        }
        return ans;
    }
};
```