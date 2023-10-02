# [1679. Max Number of K-Sum Pairs (Medium)](https://leetcode.com/problems/max-number-of-k-sum-pairs/)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>In one operation, you can pick two numbers from the array whose sum equals <code>k</code> and remove them from the array.</p>

<p>Return <em>the maximum number of operations you can perform on the array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,4,3], k = 6
<strong>Output:</strong> 1
<strong>Explanation:</strong> Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Count Good Meals (Medium)](https://leetcode.com/problems/count-good-meals/)

## Solution 1.

Save the frequence of numbers in a map `m`. 

For each pair `[n, cnt]` in `m`:
* If `k - n == n`, add `cnt / 2` to answer.
* Otherwise, add `c = min(cnt, m[k - n])` to the answer, and deduct `c` from `m[n]` and `m[k - n]`.

```cpp
// OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        int ans = 0;
        for (auto [n, cnt] : m) {
            if (k - n == n) ans += cnt / 2;
            else if (m.count(k - n))  {
                int c = min(cnt, m[k - n]);
                ans += c;
                m[n] -= c;
                m[k - n] -= c;
            }
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxOperations(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = 0;
        while (i < j) {
            int sum = A[i] + A[j];
            if (sum == k) ++ans;
            if (sum >= k) --j;
            if (sum <= k) ++i;
        }
        return ans;
    }
};
```