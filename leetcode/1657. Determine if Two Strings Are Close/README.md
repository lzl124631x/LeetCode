# [1657. Determine if Two Strings Are Close (Medium)](https://leetcode.com/problems/determine-if-two-strings-are-close/)

<p>Two strings are considered <strong>close</strong> if you can attain one from the other using the following operations:</p>

<ul>
	<li>Operation 1: Swap any two <strong>existing</strong> characters.

	<ul>
		<li>For example, <code>a<u>b</u>cd<u>e</u> -&gt; a<u>e</u>cd<u>b</u></code></li>
	</ul>
	</li>
	<li>Operation 2: Transform <strong>every</strong> occurrence of one <strong>existing</strong> character into another <strong>existing</strong> character, and do the same with the other character.
	<ul>
		<li>For example, <code><u>aa</u>c<u>abb</u> -&gt; <u>bb</u>c<u>baa</u></code> (all <code>a</code>'s turn into <code>b</code>'s, and all <code>b</code>'s turn into <code>a</code>'s)</li>
	</ul>
	</li>
</ul>

<p>You can use the operations on either string as many times as necessary.</p>

<p>Given two strings, <code>word1</code> and <code>word2</code>, return <code>true</code><em> if </em><code>word1</code><em> and </em><code>word2</code><em> are <strong>close</strong>, and </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "abc", word2 = "bca"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can attain word2 from word1 in 2 operations.
Apply Operation 1: "a<u>bc</u>" -&gt; "a<u>cb</u>"
Apply Operation 1: "<u>a</u>c<u>b</u>" -&gt; "<u>b</u>c<u>a</u>"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "a", word2 = "aa"
<strong>Output:</strong> false
<strong>Explanation: </strong>It is impossible to attain word2 from word1, or vice versa, in any number of operations.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word1 = "cabbba", word2 = "abbccc"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can attain word2 from word1 in 3 operations.
Apply Operation 1: "ca<u>b</u>bb<u>a</u>" -&gt; "ca<u>a</u>bb<u>b</u>"
<code>Apply Operation 2: "</code><u>c</u>aa<u>bbb</u>" -&gt; "<u>b</u>aa<u>ccc</u>"
Apply Operation 2: "<u>baa</u>ccc" -&gt; "<u>abb</u>ccc"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> word1 = "cabbba", word2 = "aabbss"
<strong>Output:</strong> false
<strong>Explanation: </strong>It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word1</code> and <code>word2</code> contain&nbsp;only lowercase English letters.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Buddy Strings (Easy)](https://leetcode.com/problems/buddy-strings/)
* [Minimum Swaps to Make Strings Equal (Medium)](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)
* [Minimum Number of Steps to Make Two Strings Anagram (Medium)](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

## Solution 1.

1. Both strings should have the same set of characters.
2. Both strings have the same frequence of characters.

```cpp
// OJ: https://leetcode.com/problems/determine-if-two-strings-are-close/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool closeStrings(string a, string b) {
        if (a.size() != b.size()) return false;
        array<int, 26> ca = {}, cb = {}, sa = {}, sb = {};
        for (char c : a) ca[c - 'a']++, sa[c - 'a'] = 1;
        for (char c : b) cb[c - 'a']++, sb[c - 'a'] = 1;
        sort(begin(ca), end(ca));
        sort(begin(cb), end(cb));
        return ca == cb && sa == sb;
    }
};
```