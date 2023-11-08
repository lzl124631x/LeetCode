# [2842. Count K-Subsequences of a String With Maximum Beauty (Hard)](https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty)

<p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>A <strong>k-subsequence</strong> is a <strong>subsequence</strong> of <code>s</code>, having length <code>k</code>, and all its characters are <strong>unique</strong>, <strong>i.e</strong>., every character occurs once.</p>

<p>Let <code>f(c)</code> denote the number of times the character <code>c</code> occurs in <code>s</code>.</p>

<p>The <strong>beauty</strong> of a <strong>k-subsequence</strong> is the <strong>sum</strong> of <code>f(c)</code> for every character <code>c</code> in the k-subsequence.</p>

<p>For example, consider <code>s = &quot;abbbdd&quot;</code> and <code>k = 2</code>:</p>

<ul>
	<li><code>f(&#39;a&#39;) = 1</code>, <code>f(&#39;b&#39;) = 3</code>, <code>f(&#39;d&#39;) = 2</code></li>
	<li>Some k-subsequences of <code>s</code> are:
	<ul>
		<li><code>&quot;<u><strong>ab</strong></u>bbdd&quot;</code> -&gt; <code>&quot;ab&quot;</code> having a beauty of <code>f(&#39;a&#39;) + f(&#39;b&#39;) = 4</code></li>
		<li><code>&quot;<u><strong>a</strong></u>bbb<strong><u>d</u></strong>d&quot;</code> -&gt; <code>&quot;ad&quot;</code> having a beauty of <code>f(&#39;a&#39;) + f(&#39;d&#39;) = 3</code></li>
		<li><code>&quot;a<strong><u>b</u></strong>bb<u><strong>d</strong></u>d&quot;</code> -&gt; <code>&quot;bd&quot;</code> having a beauty of <code>f(&#39;b&#39;) + f(&#39;d&#39;) = 5</code></li>
	</ul>
	</li>
</ul>

<p>Return <em>an integer denoting the number of k-subsequences </em><em>whose <strong>beauty</strong> is the <strong>maximum</strong> among all <strong>k-subsequences</strong></em>. Since the answer may be too large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p>A subsequence of a string is a new string formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.</p>

<p><strong>Notes</strong></p>

<ul>
	<li><code>f(c)</code> is the number of times a character <code>c</code> occurs in <code>s</code>, not a k-subsequence.</li>
	<li>Two k-subsequences are considered different if one is formed by an index that is not present in the other. So, two k-subsequences may form the same string.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bcca&quot;, k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> <span style="white-space: normal">From s we have f(&#39;a&#39;) = 1, f(&#39;b&#39;) = 1, and f(&#39;c&#39;) = 2.</span>
The k-subsequences of s are: 
<strong><u>bc</u></strong>ca having a beauty of f(&#39;b&#39;) + f(&#39;c&#39;) = 3 
<strong><u>b</u></strong>c<u><strong>c</strong></u>a having a beauty of f(&#39;b&#39;) + f(&#39;c&#39;) = 3 
<strong><u>b</u></strong>cc<strong><u>a</u></strong> having a beauty of f(&#39;b&#39;) + f(&#39;a&#39;) = 2 
b<strong><u>c</u></strong>c<u><strong>a</strong></u><strong> </strong>having a beauty of f(&#39;c&#39;) + f(&#39;a&#39;) = 3
bc<strong><u>ca</u></strong> having a beauty of f(&#39;c&#39;) + f(&#39;a&#39;) = 3 
There are 4 k-subsequences that have the maximum beauty, 3. 
Hence, the answer is 4. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abbcd&quot;, k = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> From s we have f(&#39;a&#39;) = 1, f(&#39;b&#39;) = 2, f(&#39;c&#39;) = 1, and f(&#39;d&#39;) = 1. 
The k-subsequences of s are: 
<u><strong>ab</strong></u>b<strong><u>cd</u></strong> having a beauty of f(&#39;a&#39;) + f(&#39;b&#39;) + f(&#39;c&#39;) + f(&#39;d&#39;) = 5
<u style="white-space: normal;"><strong>a</strong></u>b<u><strong>bcd</strong></u> having a beauty of f(&#39;a&#39;) + f(&#39;b&#39;) + f(&#39;c&#39;) + f(&#39;d&#39;) = 5 
There are 2 k-subsequences that have the maximum beauty, 5. 
Hence, the answer is 2. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string), [Greedy](https://leetcode.com/tag/greedy), [Combinatorics](https://leetcode.com/tag/combinatorics)

**Similar Questions**:
* [Distinct Subsequences II (Hard)](https://leetcode.com/problems/distinct-subsequences-ii)

**Hints**:
* Since every character appears once in a k-subsequence, we can solve the following problem first: Find the total number of ways to select <code>k</code> characters such that the sum of their frequencies is maximum.
* An obvious case to eliminate is if <code>k</code> is greater than the number of distinct characters in <code>s</code>, then the answer is <code>0</code>.
* We are now interested in the top frequencies among the characters. Using a map data structure, let <code>cnt[x]</code> denote the number of characters that have a frequency of <code>x</code>.
* Starting from the maximum value <code>x</code> in <code>cnt</code>. Let <code>i = min(k, cnt[x])</code> we add to our result <code> <sup>cnt[x]</sup>C<sub>i</sub> * x<sup>i</sup></code> representing the number of ways to select <code>i</code> characters from all characters with frequency <code>x</code>, multiplied by the number of ways to choose each individual character. Subtract <code>i</code> from <code>k</code> and continue downwards to the next maximum value.
* Powers, combinations, and additions should be done modulo <code>10<sup>9</sup> + 7</code>.

## Solution 1.

The max beauty is the sum of top K frequencies. Assume we get this frequency list after sorting it in descending order, `cnt=[5,4,4,2,2,2,2,2]`, and `k=5`, then the max beauty is the sum of the first 5 frequencies `5+4+4+2+2`.

To count the ways to get max beauty, we traverse this sorted frequency list. For `5,4,4`, we have `5`, `4`, and `4` different character options to pick from, so we multiply the answer by `5*4*4`.

For `2,2`, similarly we should multiply the answer by `2*2`. But additionally, since there are `3` additional `2`s that we can pick from, we should multiply the answer by `C(5,2)` which is the combination number of picking `2` elements out of `5` elements.

```cpp
// OJ: https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    long combination(long m, long n) {
        long ans = 1;
        for (int a = m - n + 1, b = 1; b <= n; ++a, ++b) ans = ans * a / b; // m*(m-1)*...*(m-n+1) / n*(n-1)*...*1
        return ans;
    }
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if (k > 26) return 0;
        long cnt[26] = {}, ans = 1, seen = 0, mod = 1e9 + 7;
        for (char c : s) cnt[c - 'a']++;
        sort(begin(cnt), end(cnt), greater<>());
        for (int i = 0; i < 26 && seen < k;) {
            int j = i;
            while (i < 26 && cnt[i] == cnt[j]) ++i;
            int freq = i - j, pick = min((long)k, seen + freq) - seen;
            for (int t = 0; t < pick; ++t) ans = ans * cnt[j] % mod;
            seen += freq;
            if (seen > k) ans = ans * combination(freq, pick) % mod;
        }
        return ans;
    }
};
```