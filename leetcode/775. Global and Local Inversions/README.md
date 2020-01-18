# [775. Global and Local Inversions (Medium)](https://leetcode.com/problems/global-and-local-inversions/)

<p>We have some permutation <code>A</code> of <code>[0, 1, ..., N - 1]</code>, where <code>N</code> is the length of <code>A</code>.</p>

<p>The number of (global) inversions is the number of <code>i &lt; j</code> with <code>0 &lt;= i &lt; j &lt; N</code> and <code>A[i] &gt; A[j]</code>.</p>

<p>The number of local inversions is the number of <code>i</code> with <code>0 &lt;= i &lt; N</code> and <code>A[i] &gt; A[i+1]</code>.</p>

<p>Return <code>true</code>&nbsp;if and only if the number of global inversions is equal to the number of local inversions.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> A = [1,0,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> There is 1 global inversion, and 1 local inversion.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> A = [1,2,0]
<strong>Output:</strong> false
<strong>Explanation:</strong> There are 2 global inversions, and 1 local inversion.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>A</code> will be a permutation of <code>[0, 1, ..., A.length - 1]</code>.</li>
	<li><code>A</code> will have length in range <code>[1, 5000]</code>.</li>
	<li>The time limit for this problem has been reduced.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

A local inversion must be global inversion, but a global inversion might not be local inversion.

If the number of global and local inversions are the same, global inversions must be all local inversions.

Consider the original array without permutation `[0, 1, 2, ..., N - 1]`, `A[i] = i (0 <= i < N)`.

During the permutation, for each `i`, we can only swap `A[i]` with `A[i - 1]`, `A[i]` or `A[i + 1]`. Otherwise, we will get a global inversion that is not a local inversion.

So we can take a look at the distance (namely, absolute difference) between `i` (the original `A[i]`) and `A[i]` (the `A[i]` after swap) for each `i`. If the distance is greater than 1, it means that we found a non-local global inversion and should return `false`.

Proof:
* If `A[i] > i + 1`, at least one number that is smaller than `A[i]` got kicked out from the first `A[i]` numbers, and the distance between this smaller number and `A[i]` is at least 2, thus it is a non-local global inversion.  
* If `A[i] < i - 1`, at least one number that is greater than `A[i]` got kicked out from the last `n - i` numbers, and the distance between this bigger number and `A[i]` is at least 2, thus it's a non-local global inversion.


```cpp
// OJ: https://leetcode.com/problems/global-and-local-inversions/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/global-and-local-inversions/discuss/113656/My-3-lines-C%2B%2B-Solution
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};
```