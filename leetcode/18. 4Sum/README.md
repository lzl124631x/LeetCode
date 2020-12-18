# [18. 4Sum (Medium)](https://leetcode.com/problems/4sum/)

<p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, are there elements <em>a</em>, <em>b</em>, <em>c</em>, and <em>d</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> + <em>d</em> = <code>target</code>? Find all unique quadruplets in the array which gives the sum of <code>target</code>.</p>

<p><strong>Notice</strong>&nbsp;that&nbsp;the solution set must not contain duplicate quadruplets.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

## Solution 1.

The brute force solution is to DFS for the 4 elements. It will take `O(N^4)` time. Since `N^4 = 1.6e9`, we will get TLE.

We can DFS for the first two elements and use two sum solution to reduce the time complexity to `O(N^3)`. (`N^3 = 8e6`)

```cpp
// OJ: https://leetcode.com/problems/4sum/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        int N = A.size();
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            for (int j = i + 1; j < N; ++j) {
                if (j > i + 1 && A[j] == A[j - 1]) continue;
                int t = target - A[i] - A[j];
                for (int p = j + 1, q = N - 1; p < q; ) {
                    if (A[p] + A[q] == t) {
                        ans.push_back({ A[i], A[j], A[p++], A[q--] });
                        while (p < q && A[p] == A[p - 1]) ++p;
                        while (p < q && A[q] == A[q + 1]) --q;
                    } else if (A[p] + A[q] < t) ++p;
                    else --q;
                }
            }
        }
        return ans;
    }
};
```