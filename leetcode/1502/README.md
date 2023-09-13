# [1502. Can Make Arithmetic Progression From Sequence (Easy)](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)

<p>Given an array of numbers <code>arr</code>.&nbsp;A sequence of numbers is called an arithmetic progression&nbsp;if the difference between any two consecutive elements is the same.</p>

<p>Return <code>true</code>&nbsp;if the array can be rearranged to form an arithmetic progression, otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,5,1]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4]
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reorder the elements to obtain an arithmetic progression.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>-10^6 &lt;= arr[i] &lt;= 10^6</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& A) {
        sort(begin(A), end(A));
        int d = A[1] - A[0];
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] != d) return false;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/720152/O(n)-time-O(1)-space
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& A) {
        int mn = *min_element(begin(A), end(A)), mx = *max_element(begin(A), end(A)), N = A.size();
        if ((mx - mn) % (N - 1)) return false;
        int d = (mx - mn) / (N - 1);
        for (int i = 0; i < N;) {
            if (A[i] == mn + i * d) ++i;
            else if ((A[i] - mn) % d) return false;
            else {
                int j = (A[i] - mn) / d;
                if (j < i || A[i] == A[j]) return false;
                swap(A[i], A[j]);
            }
        }
        return true;
    }
};
```