# [1663. Smallest String With A Given Numeric Value (Medium)](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/)

<p>The <strong>numeric value</strong> of a <strong>lowercase character</strong> is defined as its position <code>(1-indexed)</code> in the alphabet, so the numeric value of <code>a</code> is <code>1</code>, the numeric value of <code>b</code> is <code>2</code>, the numeric value of <code>c</code> is <code>3</code>, and so on.</p>

<p>The <strong>numeric value</strong> of a <strong>string</strong> consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string <code>"abe"</code> is equal to <code>1 + 2 + 5 = 8</code>.</p>

<p>You are given two integers <code>n</code> and <code>k</code>. Return <em>the <strong>lexicographically smallest string</strong> with <strong>length</strong> equal to <code>n</code> and <strong>numeric value</strong> equal to <code>k</code>.</em></p>

<p>Note that a string <code>x</code> is lexicographically smaller than string <code>y</code> if <code>x</code> comes before <code>y</code> in dictionary order, that is, either <code>x</code> is a prefix of <code>y</code>, or if <code>i</code> is the first position such that <code>x[i] != y[i]</code>, then <code>x[i]</code> comes before <code>y[i]</code> in alphabetic order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 27
<strong>Output:</strong> "aay"
<strong>Explanation:</strong> The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5, k = 73
<strong>Output:</strong> "aaszz"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n &lt;= k &lt;= 26 * n</code></li>
</ul>


**Companies**:  
[Lendingkart](https://leetcode.com/company/lendingkart)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

**Intuition**: We can do it greedily:

* If picking `a` won't result in unsolvable problem, we prepend `a` to the start of the string.
* Otherwise, if picking `z` won't result in unsolvable problem, we append `z` to the end of the string.
* Otherwise, if there is still a non-zero `k` value left (which must be smaller than 26), we add `'a' + k - 1` in the middle.

**Algorithm**:

How to check if it will become unsolvable problem?

If after picking `'a'`, the remainder numeric value `k - 1` can't be formed even if using all `'z'`s, i.e. `k - 1 >= (n - 1) * 26`, then it's unsolvable.

So if `n - 1 > 0 && k - 1 < (n - 1) * 26`, we should keep prepending `'a'`.

If after picking `'z'`, the remainder numeric value `k - 26` can't be formed even if using all `'a'`s, i.e. `k - 26 < n - 1`, then it's unsolvable.

So if `n - 1 > 0 && k - 26 >= n - 1`, we should keep appending `'z'`.

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        int a = 0, z = 0;
        while (n - 1 > 0 && k - 1 < (n - 1) * 26) ++a, --k, --n;
        while (n - 1 > 0 && k - 26 >= n - 1) ++z, k -= 26, --n;
        while (a-- > 0) s += 'a';
        if (k) s += 'a' + k - 1;
        while (z-- > 0) s += 'z';
        return s;
    }
};
```

## Solution 2. Greedy

Starts with all `'a'`, fill the `k` value from the end of the array backwards.

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; k > 0; --i) {
            int d = min(k, 25);
            s[i] += d;
            k -= d;
        }
        return s;
    }
};
```

## Solution 3. Greedy

Initialize `ans` as all `z`s. Try filling `a` from the left. If we fill `a` at and before index `i`, we have `k - i - 1` values left which should be `<= 26 * (n - i - 1)` i.e. the value of all the `z`s to the right of `i`. So, we keep filling `a` when `k - i - 1 <= 26 * (n - i - 1)`.

When we exit the loop, `ans[i]` might not be `z`. The value left for `ans[i]` is `k` minus the values created by the `a`s to the left, i.e. `i`, and minus the values created by the `z`s to the right, i.e. `26 * (n - i - 1)`. So, the value for `ans[i]` is `k - i - (n - i - 1) * 26`.

```cpp
// OJ: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'z');
        int i = 0;
        for (; i < n && k - i - 1 <= 26 * (n - i - 1); ++i) {
            ans[i] = 'a';
        }
        ans[i] = 'a' + k - i - 1 - (n - i - 1) * 26;
        return ans;
    }
};
```