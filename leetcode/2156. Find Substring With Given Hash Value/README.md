# [2156. Find Substring With Given Hash Value (Hard)](https://leetcode.com/problems/find-substring-with-given-hash-value/)

<p>The hash of a <strong>0-indexed</strong> string <code>s</code> of length <code>k</code>, given integers <code>p</code> and <code>m</code>, is computed using the following function:</p>

<ul>
	<li><code>hash(s, p, m) = (val(s[0]) * p<sup>0</sup> + val(s[1]) * p<sup>1</sup> + ... + val(s[k-1]) * p<sup>k-1</sup>) mod m</code>.</li>
</ul>

<p>Where <code>val(s[i])</code> represents the index of <code>s[i]</code> in the alphabet from <code>val('a') = 1</code> to <code>val('z') = 26</code>.</p>

<p>You are given a string <code>s</code> and the integers <code>power</code>, <code>modulo</code>, <code>k</code>, and <code>hashValue.</code> Return <code>sub</code>,<em> the <strong>first</strong> <strong>substring</strong> of </em><code>s</code><em> of length </em><code>k</code><em> such that </em><code>hash(sub, power, modulo) == hashValue</code>.</p>

<p>The test cases will be generated such that an answer always <strong>exists</strong>.</p>

<p>A <b>substring</b> is a contiguous non-empty sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
<strong>Output:</strong> "ee"
<strong>Explanation:</strong> The hash of "ee" can be computed to be hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0. 
"ee" is the first substring of length 2 with hashValue 0. Hence, we return "ee".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
<strong>Output:</strong> "fbx"
<strong>Explanation:</strong> The hash of "fbx" can be computed to be hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 31<sup>2</sup>) mod 100 = 23132 mod 100 = 32. 
The hash of "bxz" can be computed to be hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 31<sup>2</sup>) mod 100 = 25732 mod 100 = 32. 
"fbx" is the first substring of length 3 with hashValue 32. Hence, we return "fbx".
Note that "bxz" also has a hash of 32 but it appears later than "fbx".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= power, modulo &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= hashValue &lt; modulo</code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
	<li>The test cases are generated such that an answer always <strong>exists</strong>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Distinct Echo Substrings (Hard)](https://leetcode.com/problems/distinct-echo-substrings/)

## Solution 1. Rolling Hash

In Rabin-Karp algorithm, the hash function is "reversed" `hash(s, p, m) = (val(s[0]) * p^(k-1) + val(s[1]) * p^(k-2) + ... + val(s[k-1]) * p^0) mod m`.

During the contest, I felt that if I generate the hash from left to right, I need to do division and it might cause trouble with modulo.

To be safe, I reversed the string and calculated the hashes using the Rabin-Karp algorithm.

```cpp
// OJ: https://leetcode.com/problems/find-substring-with-given-hash-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N) which can be reduced to `O(1)` if we really calculate from right to left
class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int target) {
        long h = 0, N = s.size(), pp = 1; // `pp` = p^k
        vector<long> hash(N);
        string r(rbegin(s), rend(s));
        for (int i = 0; i < N; ++i) {
            h = (h * p + (r[i] - 'a' + 1)) % mod; // push r[i] into the window
            if (i < k) pp = pp * p % mod;
            else h = (h - (r[i - k] - 'a' + 1) * pp % mod + mod) % mod; // pop r[i-k] out of the window
            if (i >= k - 1) hash[i] = h;
        }
        reverse(begin(hash), end(hash));
        for (int i = 0; i < N; ++i) {
            if (hash[i] == target) return s.substr(i, k);
        }
        return "";
    }
};
```

### FAQ

**1. Why could division + modulo be problematic?**

Because when we do division to a modulo-ed number, we might get the wrong answer.

Assume `mod = 100`, a hash `h`'s real value is `123` and we want to divide it by `3`. So the expected result should be `41`. But in fact we need to do `123 % 100 / 3` which incorrectly returns `7`.

**2. Why do we need division if we calculate from left to right?**

Assume `s = "abcd", k = 3`.

If we calculate from left to right, `hash("abc") = a * p^0 + b * p^1 + c * p^2`. To get `hash("bcd")`, we need to subtract `a` then divide by `p` then add `d * p^2`. Here comes the division.

If we calculate from right to left, we can leverage the Rabin-Karp algorithm which only requires multiplication. We get `hash("dcb") = d * p^2 + c * p^1 + b * p^0` first. To get `hash("abc")`, we just need to multiply by `p` then add `a` then subtract `d * p^3`.

## Solution 2.

Same as Solution 1, but we calculate the hashes backward and only save the last matched index.

```cpp
// OJ: https://leetcode.com/problems/find-substring-with-given-hash-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int target) {
        long h = 0, N = s.size(), pp = 1, start = -1; // `pp` = p^k
        for (int i = N - 1; i >= 0; --i) {
            h = (h * p + (s[i] - 'a' + 1)) % mod; // push r[i] into the window
            if (i + k >= N) pp = pp * p % mod;
            else h = (h - (s[i + k] - 'a' + 1) * pp % mod + mod) % mod; // pop r[i-k] out of the window
            if (i <= N - k && h == target) start = i; 
        }
        return s.substr(start, k);
    }
};
```


## Discuss

https://leetcode.com/problems/find-substring-with-given-hash-value/discuss/1730114/