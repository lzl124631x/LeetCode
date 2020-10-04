# [650. 2 Keys Keyboard (Medium)](https://leetcode.com/problems/2-keys-keyboard/)

<p>Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:</p>

<ol>
	<li><code>Copy All</code>: You can copy all the characters present on the notepad (partial copy is not allowed).</li>
	<li><code>Paste</code>: You can paste the characters which are copied <b>last time</b>.</li>
</ol>

<p>&nbsp;</p>

<p>Given a number <code>n</code>. You have to get <b>exactly</b> <code>n</code> 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get <code>n</code> 'A'.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> 3
<b>Output:</b> 3
<b>Explanation:</b>
Intitally, we have one character 'A'.
In step 1, we use <b>Copy All</b> operation.
In step 2, we use <b>Paste</b> operation to get 'AA'.
In step 3, we use <b>Paste</b> operation to get 'AAA'.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The <code>n</code> will be in the range [1, 1000].</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [4 Keys Keyboard (Medium)](https://leetcode.com/problems/4-keys-keyboard/)
* [Broken Calculator (Medium)](https://leetcode.com/problems/broken-calculator/)

## Solution 1. DP

Let `f(n)` be the answer given input `n`.

```
f(1) = 0
f(2) = 2 (cp [1*2])
f(3) = 3 (cpp [1*3])
f(4) = 4 (cpcp [2*2]; cppp [1*4])
f(5) = 5 (cpppp [1*5])
f(6) = 5 (cppppp [1*6]; cpcpp [2*3]; cppcp [3*2])
f(7) = 7 (cpppppp [1*7])
```

So the pattern is that, if `n = a * b`, then `f(a) + b` is one option of `f(n)`. We can get all combinations of `a` and `b` and `f(n) = min(f(a) + b | n = a * b)`.

```
f(8) = 6 (0+8 [1*8]; 2+4 [2*4]; 4+2 [4*2])
f(9) = 6 (0+9 [1*9]; 3+3 [3*3])
f(10) = 7 (0+10 [1*10]; 2+5 [2*5]; 5+2 [5*2])
f(11) = 11 (0+11 [1*11])
f(12) = 7 (0+12 [1*12]; 2+6 [2*6]; 4+3[3*4]; 4+3 [4*3]; 5+2 [6*2])
```

```cpp
// OJ: https://leetcode.com/problems/2-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N^(3/2))
// Space: O(N)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1, end = sqrt(i); j <= end; ++j) {
                if (i % j) continue;
                dp[i] = min({ dp[i], dp[j] + i / j, j == 1 ? INT_MAX : (dp[i / j] + j) });
            }
        }
        return dp[n];
    }
};
```

## Solution 2. DP

For `n >= 2`, `f(n)` is at most `n`, i.e. `cppp...ppp` (1 `c` and `n - 1` `p`s)

By observation, if `a != 1` is the smallest factor of `n`, then `f(n) = f(n / a) + a`.

```cpp
// OJ: https://leetcode.com/problems/2-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(N^(3/2))
// Space: O(N)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2, end = sqrt(i); j <= end; ++j) {
                if (i % j) continue;
                dp[i] = min(dp[i], dp[i / j] + j);
            }
        }
        return dp[n];
    }
};
```

## Solution 3. Greedy (Integer Factorization)

```cpp
// OJ: https://leetcode.com/problems/2-keys-keyboard/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
// Ref: https://leetcode.com/problems/2-keys-keyboard/solution/
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            ++d;
        }
        return ans;
    }
};
```