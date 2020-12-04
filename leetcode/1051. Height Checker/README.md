# [1051. Height Checker (Easy)](https://leetcode.com/problems/height-checker/)

<p>Students are asked to stand in non-decreasing order of heights for an annual photo.</p>

<p>Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.</p>

<p>Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students&nbsp;remain on their seats.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> heights = [1,1,4,2,1,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Current array : [1,1,4,2,1,3]
Target array  : [1,1,1,2,3,4]
On index 2 (0-based) we have 4 vs 1 so we have to move this student.
On index 4 (0-based) we have 1 vs 3 so we have to move this student.
On index 5 (0-based) we have 3 vs 4 so we have to move this student.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [5,1,2,3,4]
<strong>Output:</strong> 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [1,2,3,4,5]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 100</code></li>
	<li><code>1 &lt;= heights[i] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/height-checker/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int heightChecker(vector<int>& A) {
        auto B = A;
        sort(begin(B), end(B));
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) ans += A[i] != B[i];
        return ans;
    }
};
```

## Solution 2. Count Sort

```cpp
// OJ: https://leetcode.com/problems/height-checker/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int heightChecker(vector<int>& A) {
        int cnt[101] = {}, ans = 0;
        for (int n : A) cnt[n]++;
        for (int i = 1, j = 0; i <= 100; ++i) {
            for (int k = 0; k < cnt[i]; ++k, ++j) {
                if (A[j] != i) ++ans;
            }
        }
        return ans;
    }
};
```