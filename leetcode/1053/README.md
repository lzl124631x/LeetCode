# [1053. Previous Permutation With One Swap (Medium)](https://leetcode.com/problems/previous-permutation-with-one-swap/)

<p>Given an array <code>A</code> of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than <code>A</code>, that can be <strong>made with one swap</strong> (A <em>swap</em> exchanges the positions of two numbers <code>A[i]</code> and <code>A[j]</code>).&nbsp; If it cannot be done, then return the same array.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[3,2,1]
<strong>Output: </strong>[3,1,2]
<strong>Explanation: </strong>Swapping 2 and 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>[1,1,5]
<strong>Output: </strong>[1,1,5]
<strong>Explanation: </strong>This is already the smallest permutation.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>[1,9,4,6,7]
<strong>Output: </strong>[1,7,4,6,9]
<strong>Explanation: </strong>Swapping 9 and 7.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>[3,1,1,3]
<strong>Output: </strong>[1,3,1,3]
<strong>Explanation: </strong>Swapping 1 and 3.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>1 &lt;= A[i] &lt;= 10000</code></li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int first = -1, second;
        for (int i = A.size() - 1; i > first; --i) {
            while (i - 1 > first && A[i - 1] == A[i]) --i;
            int j = i - 1;
            while (j > first && A[j] <= A[i]) --j;
            if (j > first) {
                first = j;
                second = i;
            }
        }
        if (first > -1) swap(A[first], A[second]);
        return A;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        stack<pair<int, int>> s;
        int first = -1, second = -1;
        for (int i = 0; i < A.size(); ++i) {
            while (s.size() && A[i] >= s.top().second) s.pop();
            if (s.size() && (s.top().first >= second || (s.top().first == first && A[i] != A[second]))) {
                first = s.top().first;
                second = i;
            }
            s.emplace(i, A[i]);
        }
        if (first > -1) swap(A[first], A[second]);
        return A;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 2;
        while (i >= 0 && A[i] <= A[i + 1]) --i;
        if (i < 0) return A;
        int j = i + 1;
        for (int k = i + 2; k < A.size() && A[k] < A[i]; ++k) {
            if (A[k] > A[j]) j = k;
        }
        swap(A[i], A[j]);
        return A;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 2;
        while (i >= 0 && A[i] <= A[i + 1]) --i;
        if (i < 0) return A;
        auto j = lower_bound(A.begin() + i + 1, A.end(), A[i]) - 1;
        auto k = lower_bound(A.begin() + i + 1, j, *j);
        swap(A[i], *k);
        return A;
    }
};
```