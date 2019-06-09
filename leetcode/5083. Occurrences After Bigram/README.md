# [5083. Occurrences After Bigram (Easy)](https://leetcode.com/problems/occurrences-after-bigram/)

<p>Given words <code>first</code> and <code>second</code>, consider occurrences in some&nbsp;<code>text</code> of the form "<code>first second third</code>", where <code>second</code> comes immediately after <code>first</code>, and <code>third</code> comes immediately after <code>second</code>.</p>

<p>For each such occurrence, add "<code>third</code>" to the answer, and return the answer.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>text = <span id="example-input-1-1">"alice is a good girl she is a good student"</span>, first = <span id="example-input-1-2">"a"</span>, second = <span id="example-input-1-3">"good"</span>
<strong>Output: </strong><span id="example-output-1">["girl","student"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>text = <span id="example-input-2-1">"we will we will rock you"</span>, first = <span id="example-input-2-2">"we"</span>, second = <span id="example-input-2-3">"will"</span>
<strong>Output: </strong><span id="example-output-2">["we","rock"]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code> consists of space separated words, where each word consists of lowercase English letters.</li>
	<li><code>1 &lt;= first.length, second.length &lt;= 10</code></li>
	<li><code>first</code> and <code>second</code> consist of lowercase English letters.</li>
</ol>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/occurrences-after-bigram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        istringstream ss(text);
        string prev2, prev, word;
        while (ss >> word) {
            if (prev2 == first && prev == second) ans.push_back(word);
            prev2 = prev;
            prev = word;
        }
        return ans;
    }
};
```