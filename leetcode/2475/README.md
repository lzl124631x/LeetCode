# [2475. Number of Unequal Triplets in Array (Easy)](https://leetcode.com/problems/number-of-unequal-triplets-in-array)

<p>You are given a <strong>0-indexed</strong> array of positive integers <code>nums</code>. Find the number of triplets <code>(i, j, k)</code> that meet the following conditions:</p>
<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; nums.length</code></li>
	<li><code>nums[i]</code>, <code>nums[j]</code>, and <code>nums[k]</code> are <strong>pairwise distinct</strong>.
	<ul>
		<li>In other words, <code>nums[i] != nums[j]</code>, <code>nums[i] != nums[k]</code>, and <code>nums[j] != nums[k]</code>.</li>
	</ul>
	</li>
</ul>
<p>Return <em>the number of triplets that meet the conditions.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,4,2,4,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 &gt; 0.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,1,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> No triplets meet the conditions so we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

**Companies**:
[Paytm](https://leetcode.com/company/paytm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Count Good Triplets (Easy)](https://leetcode.com/problems/count-good-triplets/)
* [Count Square Sum Triples (Easy)](https://leetcode.com/problems/count-square-sum-triples/)
* [Number of Arithmetic Triplets (Easy)](https://leetcode.com/problems/number-of-arithmetic-triplets/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-unequal-triplets-in-array
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int unequalTriplets(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (A[i] == A[j]) continue;
                for (int k = j + 1; k < N; ++k) {
                    if (A[i] == A[k] || A[j] == A[k]) continue;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/number-of-unequal-triplets-in-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int unequalTriplets(vector<int>& A) {
        int N = A.size(), ans = 0, sum = 0, prodSum = 0;
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        for (auto &[n, cnt] : m) {
            ans += prodSum * cnt;
            prodSum += sum * cnt;
            sum += cnt;
        }
        return ans;
    }
};
```