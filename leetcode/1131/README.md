# [1131. Maximum of Absolute Value Expression (Medium)](https://leetcode.com/problems/maximum-of-absolute-value-expression/)

<p>Given two arrays of integers with equal lengths, return the maximum value of:</p>

<p><code>|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|</code></p>

<p>where the maximum is taken over all <code>0 &lt;= i, j &lt; arr1.length</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
<strong>Output:</strong> 13
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
<strong>Output:</strong> 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr1.length == arr2.length &lt;= 40000</code></li>
	<li><code>-10^6 &lt;= arr1[i], arr2[i] &lt;= 10^6</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

Since `|a - b| = max(a - b, b - a)`.

`|Ai - Aj| + |Bi - Bj| + |i - j|` is the maximum of the following:

1. `+ Ai - Aj + Bi - Bj + i - j = + (Ai + Bi + i) - (Aj + Bj + j)`
2. `+ Ai - Aj + Bi - Bj - i + j = + (Ai + Bi - i) - (Aj + Bj - j)`
3. `+ Ai - Aj - Bi + Bj + i - j = + (Ai - Bi + i) - (Aj - Bj + j)`
4. `+ Ai - Aj - Bi + Bj - i + j = + (Ai - Bi - i) - (Aj - Bj - j)`
5. `- Ai + Aj + Bi - Bj + i - j = - (Ai - Bi - i) + (Aj - Bj - j)`
6. `- Ai + Aj + Bi - Bj - i + j = - (Ai - Bi + i) + (Aj - Bj + j)`
7. `- Ai + Aj - Bi + Bj + i - j = - (Ai + Bi - i) + (Aj + Bj - j)`
8. `- Ai + Aj - Bi + Bj - i + j = - (Ai + Bi + i) + (Aj + Bj + j)`

Take case 1 and 8 for example, we need to find the maximum difference in array `a` where `a[i] = A[i] + B[i] + i`.

Similarly, we need to find the maximum difference in array `b`, `c`, and `d` where `b[i] = A[i] + B[i] - i`, `c[i] = A[i] - B[i] + i`, `d[i] = A[i] - B[i] - i`.

```cpp
// OJ: https://leetcode.com/problems/maximum-of-absolute-value-expression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/340075/c%2B%2B-beats-100-(both-time-and-memory)-with-algorithm-and-image
class Solution {
    int maxDiff(vector<int> &A) {
        int mx = A[0], mn = A[0];
        for (int n : A) {
            mx = max(mx, n);
            mn = min(mn, n);
        }
        return mx - mn;
    }
public:
    int maxAbsValExpr(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> a(N), b(N), c(N), d(N);
        for (int i = 0; i < A.size(); ++i) {
            a[i] = A[i] + B[i] + i;
            b[i] = A[i] + B[i] - i;
            c[i] = A[i] - B[i] + i;
            d[i] = A[i] - B[i] - i;
        }
        return max({ maxDiff(a), maxDiff(b), maxDiff(c), maxDiff(d) });
    }
};
```

## TODO

understand https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/339968/JavaC%2B%2BPython-Maximum-Manhattan-Distance