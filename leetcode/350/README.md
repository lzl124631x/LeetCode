# [350. Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii)

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection</em>. Each element in the result must appear as many times as it shows in both arrays and you may return the result in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [4,9]
<strong>Explanation:</strong> [9,4] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the given array is already sorted? How would you optimize your algorithm?</li>
	<li>What if <code>nums1</code>'s size is small compared to <code>nums2</code>'s size? Which algorithm is better?</li>
	<li>What if elements of <code>nums2</code> are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)
* [Find Common Characters (Easy)](https://leetcode.com/problems/find-common-characters/)
* [Find the Difference of Two Arrays (Easy)](https://leetcode.com/problems/find-the-difference-of-two-arrays/)
* [Choose Numbers From Two Arrays in Range (Easy)](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/)
* [Intersection of Multiple Arrays (Easy)](https://leetcode.com/problems/intersection-of-multiple-arrays/)
* [Minimum Common Value (Easy)](https://leetcode.com/problems/minimum-common-value/)

## Solution 1. Counting

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(D) where D is the data range of the numbers
class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        int ca[1001] = {};
        for (int n : A) ca[n]++;
        vector<int> ans;
        for (int n : B) {
            if (ca[n]-- > 0) ans.push_back(n);
        }
        return ans;
    }
};
```

## Solution 2. Two Pointers

Follow up: What if the given array is already sorted? How would you optimize your algorithm?

We can use two pointers to reduce the space complexity from `O(D)` to `O(1)`.

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays-ii
// Author: github.com/lzl124631x
// Time: O(M + N) assuming the arrays are sorted
// Space: O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        vector<int> ans;
        for (int i = 0, j = 0, M = A.size(), N = B.size(); i < M && j < N; ) {
            if (A[i] == B[j]) ans.push_back(A[i]), ++i, ++j;
            else if (A[i] < B[j]) ++i;
            else ++j;
        }
        return ans;
    }
};
```