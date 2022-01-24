# [2114. Maximum Number of Words Found in Sentences (Easy)](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)

<p>A <strong>sentence</strong> is a list of <strong>words</strong> that are separated by a single space&nbsp;with no leading or trailing spaces.</p>

<p>You are given an array of strings <code>sentences</code>, where each <code>sentences[i]</code> represents a single <strong>sentence</strong>.</p>

<p>Return <em>the <strong>maximum number of words</strong> that appear in a single sentence</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentences = ["alice and bob love leetcode", "i think so too", <u>"this is great thanks very much"</u>]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentences = ["please wait", <u>"continue to fight"</u>, <u>"continue to win"</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentences.length &lt;= 100</code></li>
	<li><code>1 &lt;= sentences[i].length &lt;= 100</code></li>
	<li><code>sentences[i]</code> consists only of lowercase English letters and <code>' '</code> only.</li>
	<li><code>sentences[i]</code> does not have leading or trailing spaces.</li>
	<li>All the words in <code>sentences[i]</code> are separated by a single space.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Number of Valid Words in a Sentence (Easy)](https://leetcode.com/problems/number-of-valid-words-in-a-sentence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int mostWordsFound(vector<string>& A) {
        int ans = 0;
        for (auto &s : A) {
            int cnt = 0;
            for (char c : s) cnt += c == ' ';
            ans = max(ans, cnt + 1);
        }
        return ans;
    }
};
```