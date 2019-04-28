# [793. Preimage Size of Factorial Zeroes Function (Hard)](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/)

<p>Let <code>f(x)</code> be the number of zeroes at the end of <code>x!</code>. (Recall that <code>x! = 1 * 2 * 3 * ... * x</code>, and by convention, <code>0! = 1</code>.)</p>

<p>For example, <code>f(3) = 0</code> because 3! = 6 has no zeroes at the end, while <code>f(11) = 2</code> because 11! = 39916800 has 2 zeroes at the end. Given <code>K</code>, find how many non-negative integers <code>x</code> have the property that <code>f(x) = K</code>.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> K = 0
<strong>Output:</strong> 5
<strong>Explanation:</strong> 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.

<strong>Example 2:</strong>
<strong>Input:</strong> K = 5
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no x such that x! ends in K = 5 zeroes.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>K</code> will be an integer in the range <code>[0, 10^9]</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
// Author: github.com/lzl124631x
// Time: O((logK)^2)
// Space: O(1)
class Solution {
private:
    int getZeros(int i) {
        int ans = 0;
        while (i) {
            ans += i;
            i /= 5;
        }
        return ans;
    }
public:
    int preimageSizeFZF(int K) {
        if (!K) return 5;
        int i = 1;
        while (getZeros(i) < K) i *= 5;
        int L = i / 5, R = i;
        while (L <= R) {
            int M = (L + R) / 2;
            int z = getZeros(M);
            if (z == K) return 5;
            if (z < K) L = M + 1;
            else R = M - 1;
        }
        return 0;
    }
};
```