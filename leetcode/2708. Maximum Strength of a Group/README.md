# [2708. Maximum Strength of a Group (Medium)](https://leetcode.com/problems/maximum-strength-of-a-group)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> representing the score of students in an exam. The teacher would like to form one <strong>non-empty</strong> group of students with maximal <strong>strength</strong>, where the strength of a group of students of indices <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, <code>i<sub>2</sub></code>, ... , <code>i<sub>k</sub></code> is defined as <code>nums[i<sub>0</sub>] * nums[i<sub>1</sub>] * nums[i<sub>2</sub>] * ... * nums[i<sub>k</sub>​]</code>.</p>
<p>Return <em>the maximum strength of a group the teacher can create</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,-1,-5,2,5,-9]
<strong>Output:</strong> 1350
<strong>Explanation:</strong> One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-4,-5,-4]
<strong>Output:</strong> 20
<strong>Explanation:</strong> Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 13</code></li>
	<li><code>-9 &lt;= nums[i] &lt;= 9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-strength-of-a-group
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maxStrength(vector<int>& A) {
        long long prod = 1, maxNeg = INT_MIN, maxNum = INT_MIN, negCnt = 0;
        for (long long n : A) {
            if (n) prod *= n;
            if (n < 0) {
                maxNeg = max(maxNeg, n);
                ++negCnt;
            }
            maxNum = max(maxNum, n);
        }
        if (maxNum == 0 && negCnt < 2) return 0;
        if (maxNum < 0 && negCnt == 1) return maxNeg;
        return prod > 0 ? prod : prod / maxNeg;
    }
};
```