# [349. Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection</em>. Each element in the result must be <strong>unique</strong> and you may return the result in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [9,4]
<strong>Explanation:</strong> [4,9] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin), [VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
* [Intersection of Three Sorted Arrays (Easy)](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)

## Solution 1. Hash Set

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(A + B)
class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        unordered_set<int> a(begin(A), end(A)), b(begin(B), end(B));
        vector<int> ans;
        for (int n : a) {
            if (b.count(n)) ans.push_back(n);
        }
        return ans;
    }
};
```

## Solution 2. Sort + Two Pointers

If both arrays are already sorted, this algorithm would just take `O(A + B)` time.

```cpp
// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/lzl124631x
// Time: O(AlogA + BlogB)
// Space: O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        vector<int> ans;
        int i = 0, j = 0, M = A.size(), N = B.size();
        while (i < M && j < N) {
            if (A[i] < B[j]) ++i;
            else if (A[i] > B[j]) ++j;
            else {
                int n = A[i];
                while (i < M && A[i] == n) ++i;
                while (j < N && B[j] == n) ++j;
                ans.push_back(n);
            }
        }
        return ans;
    }
};
```