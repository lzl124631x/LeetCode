# [926. Flip String to Monotone Increasing (Medium)](https://leetcode.com/problems/flip-string-to-monotone-increasing/)

<p>A string of <code>'0'</code>s and <code>'1'</code>s is <em>monotone increasing</em> if it consists of some number of <code>'0'</code>s (possibly 0), followed by some number of <code>'1'</code>s (also possibly 0.)</p>

<p>We are given a string <code>S</code> of <code>'0'</code>s and <code>'1'</code>s, and we may flip any <code>'0'</code> to a <code>'1'</code> or a <code>'1'</code> to a <code>'0'</code>.</p>

<p>Return the minimum number of flips to make <code>S</code>&nbsp;monotone increasing.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"00110"</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>We flip the last digit to get 00111.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"010110"</span>
<strong>Output: </strong><span id="example-output-2">2</span>
<strong>Explanation: </strong>We flip to get 011111, or alternatively 000111.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"00011000"</span>
<strong>Output: </strong><span id="example-output-3">2</span>
<strong>Explanation: </strong>We flip to get 00000000.
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 20000</code></li>
	<li><code>S</code> only consists of <code>'0'</code> and <code>'1'</code> characters.</li>
</ol>
</div>
</div>
</div>


## Solution 1. Two Pass

When we separate the string into two parts, the flip count is the sum of:
* The ones at the left side
* The zeros at the right side.

So we try different separation points from left to right, and for each trial we can easily get the flip count by keeping track of the above two counts.

```cpp
// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int rightZeros = 0, leftOnes = 0;
        for (char c : S) if (c == '0') rightZeros++;
        int ans = rightZeros;
        for (char c : S) {
            if (c == '1') leftOnes++;
            else rightZeros--;
            ans = min(ans, rightZeros + leftOnes);
        }
        return ans;
    }
};
```

## Solution 2. One Pass

Think in the DP way. Assume we've already solved the sub-problem for substring `S[0..i]`, and the solution for it is `flipCount[i]`.

Then we look at the next character `S[i + 1]`.

* If it's `1`, we can simply use the solution for `S[0..i]`, so `flipCount[i + 1] = flipCount[i]`.
* If it's `0`, think about the options we have:
  1. Firstly, we can choose to flip this `0` to `1` and reuse the solution for `S[0..i]`. In this case `flipCount[i + 1] = flipCount[i] + 1`.
  2. What if the best solution is not to flip? Then we need to turn all `1`s in `S[0..i]` into `0`. Assume the count of `1`s in `S[0..i]` is `ones[i]`, then `flipCount[i + 1] = ones[i]`  

  Given these two options, we pick the one with smaller result.

In sum:

```
flipCount[0] = 0
ones[0] = 0

flipCount[i + 1] = flipCount[i]                   (if S[i + 1] == '1')
                   min(flipCount[i] + 1, ones[i]) (if S[i + 1] == '0')
    where 1 <= i <= N - 2
```

```cpp
// OJ: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/189751/C%2B%2B-one-pass-DP-solution-0ms-O(n)-or-O(1)-one-line-with-explaination.
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ones = 0, ans = 0;
        for (char c : S) {
            if (c == '1') ones++;
            else ans = min(ans + 1, ones);
        }
        return ans;
    }
};
```