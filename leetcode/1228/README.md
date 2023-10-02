# [1228. Missing Number In Arithmetic Progression (Easy)](https://leetcode.com/problems/missing-number-in-arithmetic-progression/)

<p>In some array <code>arr</code>, the values were in arithmetic progression: the values <code>arr[i + 1] - arr[i]</code> are all equal for every <code>0 &lt;= i &lt; arr.length - 1</code>.</p>

<p>A value from <code>arr</code> was removed that <strong>was not the first or last value in the array</strong>.</p>

<p>Given <code>arr</code>, return <em>the removed value</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [5,7,11,13]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The previous array was [5,7,<strong>9</strong>,11,13].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [15,13,12]
<strong>Output:</strong> 14
<strong>Explanation:</strong> The previous array was [15,<strong>14</strong>,13,12].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
	<li>The given array is <strong>guaranteed</strong> to be a valid array.</li>
</ul>


**Companies**:  
[VMware](https://leetcode.com/company/vmware), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/missing-number-in-arithmetic-progression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& A) {
        int N = A.size(), d = (A.back() - A[0]) / N;
        if (d == 0) return A[0];
        for (int i = 1; i < N; ++i) {
            if (A[i] != A[i - 1] + d) return A[i - 1] + d;
        }
        return -1;
    }
};
```

## Solution 2. Binary Search (L <= R)

```cpp
// OJ: https://leetcode.com/problems/missing-number-in-arithmetic-progression/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& A) {
        int N = A.size(), d = (A.back() - A[0]) / N, L = 0, R = N - 1;
        if (d == 0) return A[0];
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == A[0] + d * M) L = M + 1;
            else R = M - 1;
        }
        return A[0] + d * L;
    }
};
```

## Solution 3. Binary Search (L < R)

```cpp
// OJ: https://leetcode.com/problems/missing-number-in-arithmetic-progression/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& A) {
        int N = A.size(), d = (A.back() - A[0]) / N, L = 0, R = N - 1;
        if (d == 0) return A[0];
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] == A[0] + d * M) L = M + 1;
            else R = M;
        }
        return A[0] + d * L;
    }
};
```