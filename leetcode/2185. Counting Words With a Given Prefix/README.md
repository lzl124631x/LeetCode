# [2185. Counting Words With a Given Prefix (Easy)](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

<p>You are given an array of strings <code>words</code> and a string <code>pref</code>.</p>

<p>Return <em>the number of strings in </em><code>words</code><em> that contain </em><code>pref</code><em> as a <strong>prefix</strong></em>.</p>

<p>A <strong>prefix</strong> of a string <code>s</code> is any leading contiguous substring of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["pay","<strong><u>at</u></strong>tention","practice","<u><strong>at</strong></u>tend"], <code>pref </code>= "at"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The 2 strings that contain "at" as a prefix are: "<u><strong>at</strong></u>tention" and "<u><strong>at</strong></u>tend".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["leetcode","win","loops","success"], <code>pref </code>= "code"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no strings that contain "code" as a prefix.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length, pref.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>pref</code> consist of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Check If a Word Occurs As a Prefix of Any Word in a Sentence (Easy)](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/counting-words-with-a-given-prefix/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(N)
class Solution {
public:
    int prefixCount(vector<string>& A, string pref) {
        int ans = 0;
        for (auto &s : A) {
            if (s.substr(0, pref.size()) == pref) ++ans;
        }
        return ans;
    }
};
```