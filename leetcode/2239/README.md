# [2239. Find Closest Number to Zero (Easy)](https://leetcode.com/problems/find-closest-number-to-zero/)

<p>Given an integer array <code>nums</code> of size <code>n</code>, return <em>the number with the value <strong>closest</strong> to </em><code>0</code><em> in </em><code>nums</code>. If there are multiple answers, return <em>the number with the <strong>largest</strong> value</em>.</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-4,-2,1,4,8]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,-1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-closest-number-to-zero/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findClosestNumber(vector<int>& A) {
        int diff = INT_MAX, ans = INT_MAX;
        for (int n : A) {
            if (abs(n) < diff || (abs(n) == diff && n > ans)) {
                diff = abs(n);
                ans = n;
            } 
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-closest-number-to-zero/discuss/1953786