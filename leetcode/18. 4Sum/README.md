# [18. 4Sum (Medium)](https://leetcode.com/problems/4sum/)

<p>Given an array <code>nums</code> of <code>n</code> integers, return <em>an array of all the <strong>unique</strong> quadruplets</em> <code>[nums[a], nums[b], nums[c], nums[d]]</code> such that:</p>

<ul>
	<li><code>0 &lt;= a, b, c, d&nbsp;&lt; n</code></li>
	<li><code>a</code>, <code>b</code>, <code>c</code>, and <code>d</code> are <strong>distinct</strong>.</li>
	<li><code>nums[a] + nums[b] + nums[c] + nums[d] == target</code></li>
</ul>

<p>You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,2,2,2], target = 8
<strong>Output:</strong> [[2,2,2,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo), [Snapchat](https://leetcode.com/company/snapchat)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

## Solution 1. Two Pointers

The brute force solution is to enumerating all quadruplets. It will take `O(N^4)` time. Since `N^4 = 1.6e9`, we will get TLE.

We can enumerate the first two elements and use two pointers to get the last two elements, reducing the time complexity to `O(N^3)`. (`N^3 = 8e6`)

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