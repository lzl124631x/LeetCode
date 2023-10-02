# [1363. Largest Multiple of Three (Hard)](https://leetcode.com/problems/largest-multiple-of-three/)

<p>Given an integer array of <code>digits</code>,&nbsp;return the largest multiple of <strong>three</strong> that can be formed by concatenating some of the given digits in any order.</p>

<p>Since the answer may not fit in an integer data type, return the answer as a string.</p>

<p>If there is no answer return an empty string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> digits = [8,1,9]
<strong>Output:</strong> "981"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> digits = [8,6,7,1,0]
<strong>Output:</strong> "8760"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> digits = [1]
<strong>Output:</strong> ""
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> digits = [0,0,0,0,0,0]
<strong>Output:</strong> "0"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li>The returning answer must not contain unnecessary leading zeros.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

We can safely add all `0, 3, 6, 9` digits.

For the rest `1, 2, 4, 5, 7, 8`, can we add the digit 3 times if its count `>= 3`? No. The following is a counter example.

```
[2,2,1,1,1]   // 2211. Adding `1` 3 times first is not the optimal solution

[2,1,1,1]     // 111
```

In fact, `n % 3` is the same as sum of all the digits in `n` modulo by `3`.

```
999....999 % 3 == 0
1000....000 % 3 == 1
a000....000 % 3 == a % 3
abcdefghijk % 3 == (a+b+c+..+i+j+k) % 3
```

So assume `total` is the sum of all digits.

* If `total % 3 == 0`, we can add all digits.
* If `total % 3 == 1`, we have two options:
  - Removing a digit from `1, 4, 7`.
  - Removing two digits from `2, 5, 8`.
* If `total % 3 == 2`, we have two options:
  - Removing a digit from `2, 5, 8`.
  - Removing two digits from `1, 4, 7`.
* If after all these operations, the `total` is still not divisible by `3`, then we need to remove all `1, 2, 4, 5, 7, 8`.

Since we prefer removing as less digits as possible, we should always try removing one digit first.

```cpp
// OJ: https://leetcode.com/problems/largest-multiple-of-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/largest-multiple-of-three/discuss/517628/Python-Basic-Math
class Solution {
public:
    string largestMultipleOfThree(vector<int>& A) {
        int cnt[10] = {}, total = 0;
        for (int n : A) {
            cnt[n]++;
            total += n;
        }
        auto f = [&](int i) {
            if (cnt[i]) {
                cnt[i]--;
                total -= i;
            }
            return total % 3 == 0;
        };
        bool done = total % 3 == 0;
        if (!done) {
            if (total % 3 == 1) done = f(1) || f(4) || f(7) || f(2) || f(2) || f(5) || f(5) || f(8) || f(8);
            else done = f(2) || f(5) || f(8) || f(1) || f(1) || f(4) || f(4) || f(7) || f(7);
        }
        if (!done) cnt[1] = cnt[2] = cnt[4] = cnt[5] = cnt[7] = cnt[8] = 0;
        string ans;
        for (int i = 9; i >= 0; --i) {
            while (cnt[i]-- > 0) ans += '0' + i;
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/largest-multiple-of-three/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string largestMultipleOfThree(vector<int>& A) {
        int cnt[10] = {}, s = 0, nums[6] = {1,4,7,2,5,8};
        for (int n : A) cnt[n]++, s += n;
        if (s % 3 == 2 && cnt[2]) cnt[2]--, s -= 2;
        if (s % 3 == 2 && cnt[5]) cnt[5]--, s -= 5;
        if (s % 3 == 2 && cnt[8]) cnt[8]--, s -= 8;
        for (int n : nums) {
            while (s % 3 && cnt[n]) cnt[n]--, s -= n;
        }
        if (s == 0) return cnt[0] ? "0" : "";
        string ans;
        for (int i = 9; i >= 0; --i) {
            while (cnt[i]-- > 0) ans += '0' + i;
        }
        return ans;
    }
};
```