# [2207. Maximize Number of Subsequences in a String (Medium)](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/)

<p>You are given a <strong>0-indexed</strong> string <code>text</code> and another <strong>0-indexed</strong> string <code>pattern</code> of length <code>2</code>, both of which consist of only lowercase English letters.</p>

<p>You can add <strong>either</strong> <code>pattern[0]</code> <strong>or</strong> <code>pattern[1]</code> anywhere in <code>text</code> <strong>exactly once</strong>. Note that the character can be added even at the beginning or at the end of <code>text</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of times</em> <code>pattern</code> <em>can occur as a <strong>subsequence</strong> of the modified </em><code>text</code>.</p>

<p>A <b>subsequence</b> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "abdcdbc", pattern = "ac"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
If we add pattern[0] = 'a' in between text[1] and text[2], we get "ab<u><strong>a</strong></u>dcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
Some other strings which have 4 subsequences "ac" after adding a character to text are "<u><strong>a</strong></u>abdcdbc" and "abd<u><strong>a</strong></u>cdbc".
However, strings such as "abdc<u><strong>a</strong></u>dbc", "abd<u><strong>c</strong></u>cdbc", and "abdcdbc<u><strong>c</strong></u>", although obtainable, have only 3 subsequences "ac" and are thus suboptimal.
It can be shown that it is not possible to get more than 4 subsequences "ac" by adding only one character.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "aabb", pattern = "ab"
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Some of the strings which can be obtained from text and have 6 subsequences "ab" are "<u><strong>a</strong></u>aabb", "aa<u><strong>a</strong></u>bb", and "aab<u><strong>b</strong></u>b".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pattern.length == 2</code></li>
	<li><code>text</code> and <code>pattern</code> consist only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

## Solution 1. Prefix Sum and Suffix Sum

Step 1: count the number of subsequences in `s` without insertion as `sum`.

Step 2: At each index `i`, let `a` be the count of `p[0]` in prefix, and `b` be the count of `p[1]` in the suffix. 

If we append `p[0]`, we get `sum + b` subsequences. IF we append `p[1]`, we get `sum + a` subsequences.

```cpp
// OJ: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maximumSubsequenceCount(string s, string p) {
        long a = 0, b = 0, sum = 0;
        for (char c : s) b += c == p[1];
        long tmp = b;
        for (char c : s) {
            tmp -= c == p[1]; 
            if (c == p[0]) sum += tmp;
        }
        long ans = b;
        for (char c : s) {
            a += c == p[0];
            b -= c == p[1];
            ans = max({ ans, b, a });
        }
        return sum + ans;
    }
};
```

In fact, we can see that, we just need the global maximum of all `a` and `b` values. This leads to solution 2.

## Solution 2. Prefix Sum and Suffix Sum

If we add `p[0]`, the best option is to prepend it at the beginning.

If we add `p[1]`, the best option is to append it at the end.

```cpp
// OJ: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maximumSubsequenceCount(string s, string p) {
        long a = 0, b = 0, sum = 0;
        for (char c : s) {
            if (c == p[1]) sum += a;
            a += c == p[0];
            b += c == p[1];
        }
        return sum + max(a, b);
    }
};
```

## Discuss

https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/discuss/1863963