# [68. Text Justification (Hard)](https://leetcode.com/problems/text-justification/)

<p>Given an array of strings <code>words</code> and a width <code>maxWidth</code>, format the text such that each line has exactly <code>maxWidth</code> characters and is fully (left and right) justified.</p>

<p>You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces <code>' '</code> when necessary so that each line has exactly <code>maxWidth</code> characters.</p>

<p>Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.</p>

<p>For the last line of text, it should be left-justified and no extra space is inserted between words.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>A word is defined as a character sequence consisting of non-space characters only.</li>
	<li>Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.</li>
	<li>The input array <code>words</code> contains at least one word.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
<strong>Output:</strong>
[
&nbsp; &nbsp;"This &nbsp; &nbsp;is &nbsp; &nbsp;an",
&nbsp; &nbsp;"example &nbsp;of text",
&nbsp; &nbsp;"justification. &nbsp;"
]</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
<strong>Output:</strong>
[
&nbsp; "What &nbsp; must &nbsp; be",
&nbsp; "acknowledgment &nbsp;",
&nbsp; "shall be &nbsp; &nbsp; &nbsp; &nbsp;"
]
<strong>Explanation:</strong> Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
<strong>Output:</strong>
[
&nbsp; "Science &nbsp;is &nbsp;what we",
  "understand &nbsp; &nbsp; &nbsp;well",
&nbsp; "enough to explain to",
&nbsp; "a &nbsp;computer. &nbsp;Art is",
&nbsp; "everything &nbsp;else &nbsp;we",
&nbsp; "do &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;"
]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 300</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>words[i]</code> consists of only English letters and symbols.</li>
	<li><code>1 &lt;= maxWidth &lt;= 100</code></li>
	<li><code>words[i].length &lt;= maxWidth</code></li>
</ul>


**Companies**:  
[Intuit](https://leetcode.com/company/intuit), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Karat](https://leetcode.com/company/karat), [Twilio](https://leetcode.com/company/twilio), [Reddit](https://leetcode.com/company/reddit), [LinkedIn](https://leetcode.com/company/linkedin), [Indeed](https://leetcode.com/company/indeed), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [Netflix](https://leetcode.com/company/netflix), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Rearrange Spaces Between Words (Easy)](https://leetcode.com/problems/rearrange-spaces-between-words/)

## Solution 1. Simulation

```cpp
// OJ: https://leetcode.com/problems/text-justification/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> fullJustify(vector<string>& A, int maxWidth) {
        int i = 0, j = 0, N = A.size();
        vector<string> ans;
        while (j < N) {
            int width = A[j++].size();
            for (; j < N && width + A[j].size() + 1 <= maxWidth; ++j) {
                width += A[j].size() + 1;
            }
            int cnt = j - i, space = maxWidth - width + (cnt - 1), d, r;
            if (cnt > 1) {
                d = space / (cnt - 1);
                r = space % (cnt - 1);
            }
            ans.emplace_back();
            for (; i < j; ++i) {
                ans.back() += A[i];
                if (j == N || cnt == 1) { // if this is the last line or there is only one word in the line, the text is left-justified.
                    if (i < j - 1) ans.back() += ' ';
                    else {
                        while (ans.back().size() < maxWidth) ans.back() += ' ';
                    }
                } else if (i < j - 1) { // otherwise, it's full-justified. We only insert space between the words.
                    for (int k = 0; k < d; ++k) {
                        ans.back() += ' ';
                    }
                    if (r > 0) {
                        ans.back() += ' ';
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};
```