# [2592. Maximize Greatness of an Array (Medium)](https://leetcode.com/problems/maximize-greatness-of-an-array)

<p>You are given a 0-indexed integer array <code>nums</code>. You are allowed to permute <code>nums</code> into a new array <code>perm</code> of your choosing.</p>
<p>We define the <strong>greatness</strong> of <code>nums</code> be the number of indices <code>0 &lt;= i &lt; nums.length</code> for which <code>perm[i] &gt; nums[i]</code>.</p>
<p>Return <em>the <strong>maximum</strong> possible greatness you can achieve after permuting</em> <code>nums</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,5,2,1,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] &gt; nums[i]. Hence, we return 4.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] &gt; nums[i]. Hence, we return 3.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Twilio](https://leetcode.com/company/twilio)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)
* [Maximum Matching of Players With Trainers (Medium)](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximize-greatness-of-an-array
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximizeGreatness(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0, prev = 0;
        for (int i = 0; i < N; ) {
            int cnt = 1;
            ++i;
            while (i < N && A[i] == A[i - 1]) ++i, ++cnt;
            int d = min(prev, cnt);
            ans += d;
            prev += cnt - d;
        }
        return ans;
    }
};
```