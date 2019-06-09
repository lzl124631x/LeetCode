# [5086. Smallest Subsequence of Distinct Characters (Medium)](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

<p>Return the lexicographically smallest subsequence of <code>text</code> that contains all the distinct characters of <code>text</code> exactly once.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"cdadabcc"</span>
<strong>Output: </strong><span id="example-output-1">"adbc"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"abcd"</span>
<strong>Output: </strong><span id="example-output-2">"abcd"</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"ecbacba"</span>
<strong>Output: </strong><span id="example-output-3">"eacb"</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">"leetcode"</span>
<strong>Output: </strong><span id="example-output-4">"letcod"</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code> consists of lowercase English letters.</li>
</ol>

<p>&nbsp;</p>
</div>
</div>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string smallestSubsequence(string text) {
        int cnts[26] = {0}, used[26] = {0};
        for (char c : text) ++cnts[c - 'a'];
        string ans;
        for (char c : text) {
            cnts[c - 'a']--;
            if (used[c - 'a']) continue;
            while (ans.size() && cnts[ans.back() - 'a'] && c < ans.back()) {
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c - 'a'] = 1;
        }
        return ans;
    }
};
```