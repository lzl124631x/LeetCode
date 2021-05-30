# [1880. Check if Word Equals Summation of Two Words (Easy)](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/)

<p>The <strong>letter value</strong> of a letter is its position in the alphabet <strong>starting from 0</strong> (i.e. <code>'a' -&gt; 0</code>, <code>'b' -&gt; 1</code>, <code>'c' -&gt; 2</code>, etc.).</p>

<p>The <strong>numerical value</strong> of some string of lowercase English letters <code>s</code> is the <strong>concatenation</strong> of the <strong>letter values</strong> of each letter in <code>s</code>, which is then <strong>converted</strong> into an integer.</p>

<ul>
	<li>For example, if <code>s = "acb"</code>, we concatenate each letter's letter value, resulting in <code>"021"</code>. After converting it, we get <code>21</code>.</li>
</ul>

<p>You are given three strings <code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code>, each consisting of lowercase English letters <code>'a'</code> through <code>'j'</code> <strong>inclusive</strong>.</p>

<p>Return <code>true</code> <em>if the <strong>summation</strong> of the <strong>numerical values</strong> of </em><code>firstWord</code><em> and </em><code>secondWord</code><em> equals the <strong>numerical value</strong> of </em><code>targetWord</code><em>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> firstWord = "acb", secondWord = "cba", targetWord = "cdb"
<strong>Output:</strong> true
<strong>Explanation:</strong>
The numerical value of firstWord is "acb" -&gt; "021" -&gt; 21.
The numerical value of secondWord is "cba" -&gt; "210" -&gt; 210.
The numerical value of targetWord is "cdb" -&gt; "231" -&gt; 231.
We return true because 21 + 210 == 231.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aab"
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The numerical value of firstWord is "aaa" -&gt; "000" -&gt; 0.
The numerical value of secondWord is "a" -&gt; "0" -&gt; 0.
The numerical value of targetWord is "aab" -&gt; "001" -&gt; 1.
We return false because 0 + 0 != 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The numerical value of firstWord is "aaa" -&gt; "000" -&gt; 0.
The numerical value of secondWord is "a" -&gt; "0" -&gt; 0.
The numerical value of targetWord is "aaaa" -&gt; "0000" -&gt; 0.
We return true because 0 + 0 == 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= firstWord.length, </code><code>secondWord.length, </code><code>targetWord.length &lt;= 8</code></li>
	<li><code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code> consist of lowercase English letters from <code>'a'</code> to <code>'j'</code> <strong>inclusive</strong>.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    long num(string &w) {
        long ans = 0;
        for (char c : w) ans = ans * 10 + (c - 'a');
        return ans;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return num(firstWord) + num(secondWord) == num(targetWord);
    }
};
```