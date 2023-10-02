# [2615. Sum of Distances (Medium)](https://leetcode.com/problems/sum-of-distances)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. There exists an array <code>arr</code> of length <code>nums.length</code>, where <code>arr[i]</code> is the sum of <code>|i - j|</code> over all <code>j</code> such that <code>nums[j] == nums[i]</code> and <code>j != i</code>. If there is no such <code>j</code>, set <code>arr[i]</code> to be <code>0</code>.</p>

<p>Return <em>the array </em><code>arr</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1,1,2]
<strong>Output:</strong> [5,0,3,4,0]
<strong>Explanation:</strong> 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,5,3]
<strong>Output:</strong> [0,0,0]
<strong>Explanation:</strong> Since each element in nums is distinct, arr[i] = 0 for all i.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[BNY Mellon](https://leetcode.com/company/bny-mellon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Remove Duplicates from Sorted Array (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
* [Find All Duplicates in an Array (Easy)](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
* [Minimum Operations to Make All Array Elements Equal (Easy)](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/)

## Solution 1. Left-to-right State Transition

Group the indices of the same numbers together using an `unordered_map<int, vector<int>> m`.

For the index numbers in each of the group, we keep `rightSum` as sum of all index numbers greater than the current index number, and `leftSum` as the sum of all index numbers smaller than or equal to the current index number. Initially `rightSum` is the sum of all index numbers in the group.

Then, we visit the index numbers one by one. For index number `v[i]`, we deduct it from `rightSum` and add it to `leftSum`. `ans[v[i]]` is `rightSum - (N - i - 1) * v[i] + (i + 1) * v[i] - leftSum = rightSum - leftSum + (2 * (i + 1) - N) * v[i]`.

```cpp
// OJ: https://leetcode.com/problems/sum-of-distances
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> distance(vector<int>& A) {
        int N = A.size();
        vector<long long> ans(N);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < N; ++i) m[A[i]].push_back(i);
        for (auto &[n, v] : m) {
            long long rightSum = 0, leftSum = 0;
            for (int i : v) rightSum += i;
            for (int i = 0; i < v.size(); ++i) {
                rightSum -= v[i];
                leftSum += v[i];
                ans[v[i]] = rightSum - leftSum + (2LL * (i + 1) - v.size()) * v[i];
            }
        }
        return ans;
    }
};
```