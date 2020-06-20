# [1397. Find All Good Strings (Hard)](https://leetcode.com/problems/find-all-good-strings/)

<p>Given the strings <code>s1</code> and <code>s2</code> of size <code>n</code>, and the string <code>evil</code>. <em>Return the number of <strong>good</strong> strings</em>.</p>

<p>A <strong>good</strong> string has size <code>n</code>, it is alphabetically greater than or equal to <code>s1</code>, it is alphabetically smaller than or equal to <code>s2</code>, and it does not contain the string <code>evil</code> as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2, s1 = "aa", s2 = "da", evil = "b"
<strong>Output:</strong> 51 
<strong>Explanation:</strong> There are 25 good strings starting with 'a': "aa","ac","ad",...,"az". Then there are 25 good strings starting with 'c': "ca","cc","cd",...,"cz" and finally there is one good string starting with 'd': "da".&nbsp;
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
<strong>Output:</strong> 0 
<strong>Explanation:</strong> All strings greater than or equal to s1 and smaller than or equal to s2 start with the prefix "leet", therefore, there is not any good string.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 2, s1 = "gx", s2 = "gz", evil = "x"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s1.length == n</code></li>
	<li><code>s2.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= evil.length &lt;= 50</code></li>
	<li>All strings consist of lowercase English letters.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

Let `dp[i][j][k]`

Let `tr[i][j]` be the maximum suffix length if we prepend character `'a' + j` to a `e`'s suffix of size `i`.

For example, if `e = "abab"`, `i = 2`, `j = 1`, so the new suffix we get by prepending `'a' + 1 = 'b'` to `e[0..(i-1)] = "ab"` is `"bab"`, and `"bab"` is a suffix of `e` that is of size `3`. So `tr[2][1] = 3`.

https://www.youtube.com/watch?v=uqdsHJzlsIc
Digit DP: https://codeforces.com/blog/entry/53960
```cpp

```