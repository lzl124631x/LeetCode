# [1385. Find the Distance Value Between Two Arrays (Easy)](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/)

<p>Given two integer arrays <code>arr1</code> and <code>arr2</code>, and the integer <code>d</code>, <em>return the distance value between the two&nbsp;arrays</em>.</p>

<p>The distance value is defined as the number of elements <code>arr1[i]</code> such that there is not any element <code>arr2[j]</code> where <code>|arr1[i]-arr2[j]| &lt;= d</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
For arr1[0]=4 we have: 
|4-10|=6 &gt; d=2 
|4-9|=5 &gt; d=2 
|4-1|=3 &gt; d=2 
|4-8|=4 &gt; d=2 
For arr1[1]=5 we have: 
|5-10|=5 &gt; d=2 
|5-9|=4 &gt; d=2 
|5-1|=4 &gt; d=2 
|5-8|=3 &gt; d=2
For arr1[2]=8 we have:
<strong>|8-10|=2 &lt;= d=2</strong>
<strong>|8-9|=1 &lt;= d=2</strong>
|8-1|=7 &gt; d=2
<strong>|8-8|=0 &lt;= d=2</strong>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 500</code></li>
	<li><code>-10^3 &lt;= arr1[i], arr2[j] &lt;= 10^3</code></li>
	<li><code>0 &lt;= d &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            bool found = false;
            for (int j = 0; j < B.size() && !found; ++j) {
                if (abs(A[i] - B[j]) <= d) found = true;
            }
            if (!found) ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Brute Force

```cpp
// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        return count_if(begin(A), end(A), [&](const auto &a) {
            return all_of(begin(B), end(B), [&](const auto &b) {
                return abs(a - b) > d;
            });
        });
    }
};
```

## Solution 3. Binary Search

For each `A[i]`, find the length of range `[A[i] - d, A[i] + d]` in array `B`. If the length is 0, then increment the answer.

The start point of the range (`A[i] - d`) can be found using `lower_bound(begin(B), end(B), A[i] - d)`.

The next element after the end point of the range (the element after `A[i] + d`) can be found using `upper_bound(begin(B), end(B), n + d)`.

If these two iterators are the same, it means the length of the range is 0.

```cpp
// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        sort(begin(B), end(B));
        int ans = 0;
        for (int n : A) {
            if (lower_bound(begin(B), end(B), n - d) == upper_bound(begin(B), end(B), n + d)) ++ans;
        }
        return ans;
    }
};
```