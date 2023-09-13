# [884. Uncommon Words from Two Sentences (Easy)](https://leetcode.com/problems/uncommon-words-from-two-sentences/)

<p>We are given two sentences <code>A</code> and <code>B</code>.&nbsp; (A <em>sentence</em>&nbsp;is a string of space separated words.&nbsp; Each <em>word</em> consists only of lowercase letters.)</p>

<p>A word is <em>uncommon</em>&nbsp;if it appears exactly once in one of the sentences, and does not appear in the other sentence.</p>

<p>Return a list of all uncommon words.&nbsp;</p>

<p>You may return the list in any order.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">"this apple is sweet"</span>, B = <span id="example-input-1-2">"this apple is sour"</span>
<strong>Output: </strong><span id="example-output-1">["sweet","sour"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">"apple apple"</span>, B = <span id="example-input-2-2">"banana"</span>
<strong>Output: </strong><span id="example-output-2">["banana"]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 200</code></li>
	<li><code>0 &lt;= B.length &lt;= 200</code></li>
	<li><code>A</code> and <code>B</code> both contain only spaces and lowercase letters.</li>
</ol>
</div>
</div>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Author: github.com/lzl124631x
// Time: O(A+B)
// Space: O(A+B)
class Solution {
private:
    unordered_map<string, int> getCounts(string s) {
        istringstream ss(s);
        string word;
        unordered_map<string, int> m;
        while (ss >> word) m[word]++;
        return m;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        auto m = getCounts(A), n = getCounts(B);
        vector<string> ans;
        for (auto &p : m) {
            if (p.second == 1 && n.find(p.first) == n.end()) ans.push_back(p.first);
        }
        for (auto &p : n) {
            if (p.second == 1 && m.find(p.first) == m.end()) ans.push_back(p.first);
        }
        return ans;
    }
};
```