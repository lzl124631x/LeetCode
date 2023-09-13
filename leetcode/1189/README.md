# [1189. Maximum Number of Balloons (Easy)](https://leetcode.com/problems/maximum-number-of-balloons/)

<p>Given a string&nbsp;<code>text</code>, you want to use the characters of&nbsp;<code>text</code>&nbsp;to form as many instances of the word <strong>"balloon"</strong> as possible.</p>

<p>You can use each character in <code>text</code> <strong>at most once</strong>. Return the maximum number of instances that can be formed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/05/1536_ex1_upd.JPG" style="width: 132px; height: 35px;"></strong></p>

<pre><strong>Input:</strong> text = "nlaebolko"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/05/1536_ex2_upd.JPG" style="width: 267px; height: 35px;"></strong></p>

<pre><strong>Input:</strong> text = "loonbalxballpoon"
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> text = "leetcode"
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^4</code></li>
	<li><code>text</code>&nbsp;consists of lower case English letters only.</li>
</ul>

**Companies**:  
[Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

We can also use `undered_map` which makes the code simpler. But I found it's slower with `unordered_map`.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-balloons/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char c : text) cnt[c - 'a']++;
        return min({ cnt['b' - 'a'], cnt['a' - 'a'], cnt['n' - 'a'],
                     cnt['l' - 'a'] / 2, cnt['o' - 'a'] / 2 });
    }
};
```