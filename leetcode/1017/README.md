# [1017. Convert to Base -2 (Medium)](https://leetcode.com/problems/convert-to-base-2/)

<p>Given a number <code>N</code>, return a string consisting of <code>"0"</code>s and <code>"1"</code>s&nbsp;that represents its value in base <code><strong>-2</strong></code>&nbsp;(negative two).</p>

<p>The returned string must have no leading zeroes, unless the string is <code>"0"</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">"110"
<strong>Explantion:</strong> (-2) ^ 2 + (-2) ^ 1 = 2</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">3</span>
<strong>Output: </strong><span id="example-output-2">"111"
</span><span id="example-output-1"><strong>Explantion:</strong> (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0</span><span> = 3</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">4</span>
<strong>Output: </strong><span id="example-output-3">"100"
</span><span id="example-output-1"><strong>Explantion:</strong> (-2) ^ 2 = 4</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><span><code>0 &lt;= N &lt;= 10^9</code></span></li>
</ol>
</div>
</div>
</div>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Encode Number (Medium)](https://leetcode.com/problems/encode-number/)

## Solution 1.

For base 2 the bits represent the following numbers

```
base(2)  = 1 1 1 1
base(10) = 8 4 2 1
```

For base -2

```
base(-2) = 1  1  1 1
base(10) = -8 4 -2 1
```

So if `N` base 2 only has ones on even-indexed positions, `N` base -2 should be the same as `N` base 2.

Example: 

```
5 base 2 = 101
5 base -2 = 101
```

If `N` base 2 has ones on odd-indexed positions, then we can get another one to the one-more-significant digit.

This works because `2^i base 2` is the same as `2^(i + 1) base -2` minus `2^i base -2` where `i` is odd. For example, when `i = 1`, `2^i base 2 = 2` is the same as `2^(i+1) base -2 = 4` minus `2^i base -2 = -2`.

Example:

```
2 base 2 = 10
2 base -2 = 110 // add one digit at position 2

3 base 2 = 11
3 base -2 = 111 // add one digit at position 2

7 base 2 = 111
7 base -2 = 11011 // add one digit at position 2, we get 211 = 1011; then we add one digit at position 4, we get 11011
```

```cpp
// OJ: https://leetcode.com/problems/convert-to-base-2/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string ans;
        while (N) {
            ans += '0' + (N % 2);
            N /= 2;
        }
        int carry = 0;
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] += carry;
            if (ans[i] > '1') {
                ans[i] = '0';
                carry = 1;
            } else carry = 0;
            if (ans[i] == '1' && i % 2) carry += 1;
            if (carry && i == ans.size() - 1) {
                ans += '1';
                carry = 0;
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/convert-to-base-2/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/convert-to-base-2/discuss/265507/JavaC%2B%2BPython-2-lines-Exactly-Same-as-Base-2
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string ans;
        while (N) {
            ans += '0' + (N & 1);
            N = -(N >> 1); // divide by -2 and round toward -infinity
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

Or recursively

```cpp
// OJ: https://leetcode.com/problems/convert-to-base-2/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0 || N == 1) return to_string(N);
        return baseNeg2(-(N >> 1)) + to_string(N & 1);
    }
};
```

## Solution 3.

Reference: https://www.geeksforgeeks.org/convert-number-negative-base-representation/

When we get negative `r`, we add `2` to `r` and increment `N`. This works because

```
r = -1, N = 0
the number is -1

r = 1, N = 1
the number is -2 * 1 - 1 = -1
```

Example,

```
N = 3

// first round
r = 3 % -2 = 3 - (3 / -2) * -2 = 3 - (-1 * -2) = 1
N = 3 / -2 = -1

// second round
r = -1 % -2 = -1 - (-1 / -2) * -2 = -1 - (0 * -2) = -1
N = -1 / -2 = 0

// now r is negative, we turn it to be positive
r = -1 + 2 = 1
N = 0 + 1 = 1

// last round
r = 1 % -2 = 1 - (1 / -2) * -2 = 1
N = 1 / -2 = 0

So the result is 111.
```

```cpp
// OJ: https://leetcode.com/problems/convert-to-base-2/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
// Ref: https://leetcode.com/problems/convert-to-base-2/discuss/265544/C%2B%2B-Geeks4Geeks
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string ans;
        while (N) {
            int r = N % -2;
            N /= -2;
            if (r < 0) {
                r += 2;
                N++;
            }
            ans += '0' + r;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```