# [3002. Maximum Size of a Set After Removals (Medium)](https://leetcode.com/problems/maximum-size-of-a-set-after-removals)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> of even length <code>n</code>.</p>

<p>You must remove <code>n / 2</code> elements from <code>nums1</code> and <code>n / 2</code> elements from <code>nums2</code>. After the removals, you insert the remaining elements of <code>nums1</code> and <code>nums2</code> into a set <code>s</code>.</p>

<p>Return <em>the <strong>maximum</strong> possible size of the set</em> <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,1,2], nums2 = [1,1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We remove two occurences of 1 from nums1 and nums2. After the removals, the arrays become equal to nums1 = [2,2] and nums2 = [1,1]. Therefore, s = {1,2}.
It can be shown that 2 is the maximum possible size of the set s after the removals.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3,4,5,6], nums2 = [2,3,2,3,2,3]
<strong>Output:</strong> 5
<strong>Explanation:</strong> We remove 2, 3, and 6 from nums1, as well as 2 and two occurrences of 3 from nums2. After the removals, the arrays become equal to nums1 = [1,4,5] and nums2 = [2,3,2]. Therefore, s = {1,2,3,4,5}.
It can be shown that 5 is the maximum possible size of the set s after the removals.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,1,2,2,3,3], nums2 = [4,4,5,5,6,6]
<strong>Output:</strong> 6
<strong>Explanation:</strong> We remove 1, 2, and 3 from nums1, as well as 4, 5, and 6 from nums2. After the removals, the arrays become equal to nums1 = [1,2,3] and nums2 = [4,5,6]. Therefore, s = {1,2,3,4,5,6}.
It can be shown that 6 is the maximum possible size of the set s after the removals.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n</code> is even.</li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Greedy](https://leetcode.com/tag/greedy)

**Similar Questions**:
* [Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays)

**Hints**:
* Removing <code>n / 2</code> elements from each array is the same as keeping <code>n / 2<code> elements in each array.
* Think of a greedy algorithm.
* For each array, we will greedily keep the elements that are only in that array. Once we run out of such elements, we will keep the elements that are common to both arrays.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-size-of-a-set-after-removals
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSetSize(vector<int>& A, vector<int>& B) {
        int N = A.size();
        unordered_set<int> sa(begin(A), end(A)), sb(begin(B), end(B));
        int da = N - sa.size(), db = N - sb.size(), common = 0;
        for (int n : sa) {
            if (sb.count(n)) common++;
        }
        if (da >= N / 2 && db >= N / 2) return sa.size() + sb.size() - common;
        int ra = max(0, N / 2 - da), rb = max(0, N / 2 - db), x = ra + rb - common;
        return sa.size() - common + sb.size() - max(x, 0);
    }
};
```