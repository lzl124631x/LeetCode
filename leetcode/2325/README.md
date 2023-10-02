# [2325. Decode the Message (Easy)](https://leetcode.com/problems/decode-the-message)

<p>You are given the strings <code>key</code> and <code>message</code>, which represent a cipher key and a secret message, respectively. The steps to decode <code>message</code> are as follows:</p>
<ol>
	<li>Use the <strong>first</strong> appearance of all 26 lowercase English letters in <code>key</code> as the <strong>order</strong> of the substitution table.</li>
	<li>Align the substitution table with the regular English alphabet.</li>
	<li>Each letter in <code>message</code> is then <strong>substituted</strong> using the table.</li>
	<li>Spaces <code>' '</code> are transformed to themselves.</li>
</ol>
<ul>
	<li>For example, given <code>key = "<u><strong>hap</strong></u>p<u><strong>y</strong></u> <u><strong>bo</strong></u>y"</code> (actual key would have <strong>at least one</strong> instance of each letter in the alphabet), we have the partial substitution table of (<code>'h' -&gt; 'a'</code>, <code>'a' -&gt; 'b'</code>, <code>'p' -&gt; 'c'</code>, <code>'y' -&gt; 'd'</code>, <code>'b' -&gt; 'e'</code>, <code>'o' -&gt; 'f'</code>).</li>
</ul>
<p>Return <em>the decoded message</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/08/ex1new4.jpg" style="width: 752px; height: 150px;">
<pre><strong>Input:</strong> key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
<strong>Output:</strong> "this is a secret"
<strong>Explanation:</strong> The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "<u><strong>the</strong></u> <u><strong>quick</strong></u> <u><strong>brown</strong></u> <u><strong>f</strong></u>o<u><strong>x</strong></u> <u><strong>j</strong></u>u<u><strong>mps</strong></u> o<u><strong>v</strong></u>er the <u><strong>lazy</strong></u> <u><strong>d</strong></u>o<u><strong>g</strong></u>".
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/08/ex2new.jpg" style="width: 754px; height: 150px;">
<pre><strong>Input:</strong> key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
<strong>Output:</strong> "the five boxing wizards jump quickly"
<strong>Explanation:</strong> The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "<u><strong>eljuxhpwnyrdgtqkviszcfmabo</strong></u>".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>26 &lt;= key.length &lt;= 2000</code></li>
	<li><code>key</code> consists of lowercase English letters and <code>' '</code>.</li>
	<li><code>key</code> contains every letter in the English alphabet (<code>'a'</code> to <code>'z'</code>) <strong>at least once</strong>.</li>
	<li><code>1 &lt;= message.length &lt;= 2000</code></li>
	<li><code>message</code> consists of lowercase English letters and <code>' '</code>.</li>
</ul>

**Companies**:
[Coinbase](https://leetcode.com/company/coinbase)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/decode-the-message
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    string decodeMessage(string key, string message) {
        int m[26] = {[0 ... 25] = -1}, i = 0;
        for (char c : key) {
            if (c == ' ') continue;
            if (m[c - 'a'] == -1) m[c - 'a'] = i++;
            if (i == 26) break;
        }
        for (char &c : message) {
            if (c == ' ') continue;
            c = m[c - 'a'] + 'a';
        }
        return message;
    }
};
```