# [2873. Maximum Value of an Ordered Triplet I (Easy)](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>

<p>Return <em><strong>the maximum value over all triplets of indices</strong></em> <code>(i, j, k)</code> <em>such that</em> <code>i &lt; j &lt; k</code>. If all such triplets have a negative value, return <code>0</code>.</p>

<p>The <strong>value of a triplet of indices</strong> <code>(i, j, k)</code> is equal to <code>(nums[i] - nums[j]) * nums[k]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,6,1,2,7]
<strong>Output:</strong> 77
<strong>Explanation:</strong> The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,3,4,19]
<strong>Output:</strong> 133
<strong>Explanation:</strong> The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


**Similar Questions**:
* [Number of Arithmetic Triplets (Easy)](https://leetcode.com/problems/number-of-arithmetic-triplets)

**Hints**:
* Use three nested loops to find all the triplets.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long ans = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    ans = max(ans, (long long)(A[i] - A[j]) * A[k]);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/solutions/4111950/java-c-python-one-pass-o-n/
class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long ans = 0, maxa = 0, maxab = 0;
        for (long long n : A) {
            ans = max(ans, (long long)maxab * n);
            maxab = max(maxab, maxa - n);
            maxa = max(maxa, n);
        }
        return ans;
    }
};
```