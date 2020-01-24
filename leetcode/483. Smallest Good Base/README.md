# [483. Smallest Good Base (Hard)](https://leetcode.com/problems/smallest-good-base/)

<p>For an integer n, we call k&gt;=2 a <i><b>good base</b></i> of n, if all digits of n base k are 1.</p>

<p>Now given a string representing n, you should return the smallest good base of n in string format.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "13"
<b>Output:</b> "3"
<b>Explanation:</b> 13 base 3 is 111.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "4681"
<b>Output:</b> "8"
<b>Explanation:</b> 4681 base 8 is 11111.
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> "1000000000000000000"
<b>Output:</b> "999999999999999999"
<b>Explanation:</b> 1000000000000000000 base 999999999999999999 is 11.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The range of n is [3, 10^18].</li>
	<li>The string representing n is always valid and will not have leading zeros.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1.

`n - 1` is the greatest good base since `n base(n-1) = 11`.

Assume `x` is the next smaller good base, then `n base(x) = 111` or `x^2 + x + 1 = n`. `x = sqrt(n - x - 1) < sqrt(n)`.

Let `k = sqrt(n)` and assume `val base(k) = 111`. `val` should be greater than `n`.

Then we keep decrement `k` to approach `x`, and the `val` which satisfies `val base(k) = 111` approaches `n` as well.

We keep decrementing `k` until `val <= num`.

If `val == n`, we find a good base `k`; otherwise (`val < n`), `k` is not a good base.

We continue to look for the next smaller good base `y`, then `n base(y) = 1111` or `y^3 + y^2 + y + 1 = n`. `y = cbrt(n - y^2 - y - 1) < cbrt(n)`.

So we can do similar approach as above, let `k = cbrt(n)` and try to approach `y`.

As we keep looking for the next good base `z`, we start from `k = pow(n, 1 / (cnt - 1))` where `cnt` is the number of ones in `n base(z)`.

We stop the process once `k < 2`. The last good base we found is the answer.

```cpp
// OJ: https://leetcode.com/problems/smallest-good-base/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
typedef unsigned long long ULL;
class Solution {
private:
    ULL getValue(ULL base, int cnt) {
        ULL ans = 1, p = 1;
        while (--cnt) ans += (p *= base);
        return ans;
    }
public:
    string smallestGoodBase(string n) {
        ULL num = stoull(n), ans = num - 1, cnt = 3, k, val;
        while (true) {
            k = pow(num, 1 / (double)(cnt - 1));
            if (k < 2) break;
            do {
                val = getValue(k, cnt);
                if (val == num) ans = k;
                --k;
            } while (val > num);
            ++cnt;
        }      
        return to_string(ans);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/smallest-good-base/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/smallest-good-base/discuss/96590/3ms-AC-C++-long-long-int-+-binary-search/101166
class Solution {
    typedef unsigned long long ull;
public:
    string smallestGoodBase(string n) {
        ull num = (ull)stoll(n);
        int maxlen = log(num) / log(2) + 1;
        for(int k = maxlen; k >= 3; --k){
            ull b = pow(num, 1.0 / (k - 1)), sum = 1, cur = 1;
            for (int i = 1; i < k; ++i) sum += (cur *= b);
            if (sum == num) return to_string(b);
        }  
        return to_string(num - 1);
    }
};
```