# [996. Number of Squareful Arrays (Hard)](https://leetcode.com/problems/number-of-squareful-arrays/)

<p>Given an array <code>A</code> of non-negative integers, the array is <em>squareful</em> if for every pair of adjacent elements, their sum is a perfect square.</p>

<p>Return the number of permutations of A that are squareful.&nbsp; Two permutations <code>A1</code> and <code>A2</code> differ if and only if there is some index <code>i</code> such that <code>A1[i] != A2[i]</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,17,8]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>
[1,8,17] and [17,8,1] are the valid permutations.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[2,2,2]</span>
<strong>Output: </strong><span id="example-output-2">1</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 12</code></li>
	<li><code>0 &lt;= A[i] &lt;= 1e9</code></li>
</ol>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)

## Solution 1. Backtracking

Brute force: `next_permutation` + `squareful` check.

Issue: if the leading `x` elements are not squareful, no matter how the rest of the elements are permutated, the result can't be squareful. So we need to make sure the permutation is squareful along the way.

Solution: manually implement `next_permutation`, check if the currently settled subarray is squareful.
Skip this leading section if it's already not squareful.

```cpp
// OJ: https://leetcode.com/problems/number-of-squareful-arrays/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N^2)
class Solution {
    int ans = 0;
    inline bool isSquare(int n) {
        int r = sqrt(n);
        return r * r == n;
    }
    void dfs(vector<int> &A, int start) {
        if (start == A.size()) {
            ++ans;
            return;
        }
        unordered_set<int> s;
        for (int i = start; i < A.size(); ++i) {
            if (s.count(A[i]) || (start - 1 >= 0 && !isSquare(A[start - 1] + A[i]))) continue;
            s.insert(A[i]);
            swap(A[start], A[i]);
            dfs(A, start + 1);
            swap(A[start], A[i]);
        }
    }
public:
    int numSquarefulPerms(vector<int>& A) {
        dfs(A, 0);
        return ans;
    }
};
```