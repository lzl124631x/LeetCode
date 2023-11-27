# [2942. Find Words Containing Character (Easy)](https://leetcode.com/problems/find-words-containing-character)

<p>You are given a <strong>0-indexed</strong> array of strings <code>words</code> and a character <code>x</code>.</p>

<p>Return <em>an <strong>array of indices</strong> representing the words that contain the character </em><code>x</code>.</p>

<p><strong>Note</strong> that the returned array may be in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;leet&quot;,&quot;code&quot;], x = &quot;e&quot;
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> &quot;e&quot; occurs in both words: &quot;l<strong><u>ee</u></strong>t&quot;, and &quot;cod<u><strong>e</strong></u>&quot;. Hence, we return indices 0 and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;bcd&quot;,&quot;aaaa&quot;,&quot;cbc&quot;], x = &quot;a&quot;
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong> &quot;a&quot; occurs in &quot;<strong><u>a</u></strong>bc&quot;, and &quot;<u><strong>aaaa</strong></u>&quot;. Hence, we return indices 0 and 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;bcd&quot;,&quot;aaaa&quot;,&quot;cbc&quot;], x = &quot;z&quot;
<strong>Output:</strong> []
<strong>Explanation:</strong> &quot;z&quot; does not occur in any of the words. Hence, we return an empty array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>x</code> is a lowercase English letter.</li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Find Target Indices After Sorting Array (Easy)](https://leetcode.com/problems/find-target-indices-after-sorting-array)

**Hints**:
* Use two nested loops.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-words-containing-character
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& A, char x) {
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i].find(x) != string::npos) ans.push_back(i);
        }
        return ans;
    }
};
```