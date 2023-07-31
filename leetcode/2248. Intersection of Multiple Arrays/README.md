# [2248. Intersection of Multiple Arrays (Easy)](https://leetcode.com/problems/intersection-of-multiple-arrays)

<code>nums</code>
<code>nums[i]</code>
<strong>distinct</strong>
<em>the list of integers that are present in <strong>each array</strong> of</em>
<code>nums</code>
<em> sorted in <strong>ascending order</strong></em>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [[<u><strong>3</strong></u>,1,2,<u><strong>4</strong></u>,5],[1,2,<u><strong>3</strong></u>,<u><strong>4</strong></u>],[<u><strong>3</strong></u>,<u><strong>4</strong></u>,5,6]]
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong> 
The only integers present in each of nums[0] = [<u><strong>3</strong></u>,1,2,<u><strong>4</strong></u>,5], nums[1] = [1,2,<u><strong>3</strong></u>,<u><strong>4</strong></u>], and nums[2] = [<u><strong>3</strong></u>,<u><strong>4</strong></u>,5,6] are 3 and 4, so we return [3,4].</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [[1,2,3],[4,5,6]]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(nums[i].length) &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 1000</code></li>
	<li>All the values of <code>nums[i]</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
* [Find Smallest Common Element in All Rows (Medium)](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/)
* [Intersection of Three Sorted Arrays (Easy)](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)
* [Find the Difference of Two Arrays (Easy)](https://leetcode.com/problems/find-the-difference-of-two-arrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/intersection-of-multiple-arrays
// Author: github.com/lzl124631x
// Time: O(MNlogN)
// Space: O(N)
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& A) {
        for (auto &r : A) sort(begin(r), end(r));
        vector<int> ans = A[0];
        int len = ans.size();
        for (int i = 1; i < A.size(); ++i) {
            int j = 0, k = 0, p = 0, N = A[i].size();
            for (; j < len && k < N;) {
                if (ans[j] < A[i][k]) ++j;
                else if (ans[j] > A[i][k]) ++k;
                else ans[p++] = ans[j], ++j, ++k;
            }
            len = p;
        }
        ans.resize(len);
        return ans;
    }
};
```