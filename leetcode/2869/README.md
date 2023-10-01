# [2869. Minimum Operations to Collect Elements (Easy)](https://leetcode.com/problems/minimum-operations-to-collect-elements)

<p>You are given an array <code>nums</code> of positive integers and an integer <code>k</code>.</p>

<p>In one operation, you can remove the last element of the array and add it to your collection.</p>

<p>Return <em>the <strong>minimum number of operations</strong> needed to collect elements</em> <code>1, 2, ..., k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,5,4,2], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection contains elements 1 and 2. Hence, the answer is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,5,4,2], k = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong> After 5 operations, we collect elements 2, 4, 5, 1, and 3, in this order. Our collection contains elements 1 through 5. Hence, the answer is 5.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,5,3,1], k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> After 4 operations, we collect elements 1, 3, 5, and 2, in this order. Our collection contains elements 1 through 3. Hence, the answer is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
	<li>The input is generated such that you can collect elements <code>1, 2, ..., k</code>.</li>
</ul>


**Similar Questions**:
* [Build an Array With Stack Operations (Medium)](https://leetcode.com/problems/build-an-array-with-stack-operations)

**Hints**:
* Use an occurrence array.
* Iterate over the elements in reverse order.
* If the current element <code>nums[i]</code> is not marked in the occurrence array and <code>nums[i] &lt;= k</code>, mark <code>nums[i]</code>.
* Keep track of how many integers you have marked.
* Return the current index as soon as the number of marked integers becomes equal to <code>k</code>.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-collect-elements
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        int i = A.size() - 1;
        unordered_set<int> s;
        for (; i >= 0; --i) {
            if (A[i] <= k) s.insert(A[i]);
            if (s.size() == k) break;
        }
        return A.size() - i;
    }
};
```