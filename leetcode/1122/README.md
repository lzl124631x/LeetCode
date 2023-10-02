# [1122. Relative Sort Array (Easy)](https://leetcode.com/problems/relative-sort-array/)

<p>Given two arrays <code>arr1</code> and <code>arr2</code>, the elements of <code>arr2</code> are distinct, and all elements in <code>arr2</code> are also in <code>arr1</code>.</p>

<p>Sort the elements of <code>arr1</code> such that the relative ordering of items in <code>arr1</code> are the same as in <code>arr2</code>.&nbsp; Elements that don't appear in <code>arr2</code> should be placed at the end of <code>arr1</code> in <strong>ascending</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
<strong>Output:</strong> [2,2,2,1,4,3,3,9,6,7,19]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 1000</code></li>
	<li>All the elements of <code>arr2</code> are <strong>distinct</strong>.</li>
	<li>Each&nbsp;<code>arr2[i]</code> is in <code>arr1</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/relative-sort-array/
// Author: github.com/lzl124631x
// Time: O(AlogA)
// Space: O(B)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i) m[B[i]] = i;
        sort(begin(A), end(A), [&](int a, int b) {
            if (m.count(a) && m.count(b)) return m[a] < m[b];
            if (m.count(a) == 0 && m.count(b) == 0) return a < b;
            return m.count(a) > 0;
        });
        return A;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/relative-sort-array/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(max(A, B))
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        int cnt[1001] = {};
        vector<int> ans;
        for (int n : A) cnt[n]++;
        for (int n : B) {
            for (int i = 0; i < cnt[n]; ++i) ans.push_back(n);
            cnt[n] = 0;
        }
        for (int i = 0; i <= 1000; ++i) {
            for (int j = 0; j < cnt[i]; ++j) ans.push_back(i);
        }
        return ans;
    }
};
```