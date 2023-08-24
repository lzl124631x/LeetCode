# [68. Text Justification (Hard)](https://leetcode.com/problems/text-justification)

<p>Given an array of strings <code>words</code> and a width <code>maxWidth</code>, format the text such that each line has exactly <code>maxWidth</code> characters and is fully (left and right) justified.</p>
<p>You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces <code>' '</code> when necessary so that each line has exactly <code>maxWidth</code> characters.</p>
<p>Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.</p>
<p>For the last line of text, it should be left-justified, and no extra space is inserted between words.</p>
<p><strong>Note:</strong></p>
<ul>
	<li>A word is defined as a character sequence consisting of non-space characters only.</li>
	<li>Each word's length is guaranteed to be greater than <code>0</code> and not exceed <code>maxWidth</code>.</li>
	<li>The input array <code>words</code> contains at least one word.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
<strong>Output:</strong>
[
&nbsp; &nbsp;"This &nbsp; &nbsp;is &nbsp; &nbsp;an",
&nbsp; &nbsp;"example &nbsp;of text",
&nbsp; &nbsp;"justification. &nbsp;"
]</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
<strong>Output:</strong>
[
&nbsp; "What &nbsp; must &nbsp; be",
&nbsp; "acknowledgment &nbsp;",
&nbsp; "shall be &nbsp; &nbsp; &nbsp; &nbsp;"
]
<strong>Explanation:</strong> Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.</pre>
<p><strong class="example">Example 3:</strong></p>
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
[Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Capital One](https://leetcode.com/company/capital-one)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Rearrange Spaces Between Words (Easy)](https://leetcode.com/problems/rearrange-spaces-between-words/)
* [Divide a String Into Groups of Size k (Easy)](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/)
* [Split Message Based on Limit (Hard)](https://leetcode.com/problems/split-message-based-on-limit/)

## Solution 1. Simulation

```cpp
// OJ: https://leetcode.com/problems/text-justification/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int N = words.size();
        vector<string> ans;
        for (int i = 0; i < N;) {
            int width = 0, j = i;
            while (j < N && width + j - i + words[j].size() <= maxWidth) width += words[j++].size();
            int cnt = j - i, space = maxWidth - width, d, r;
            if (cnt - 1 > 0) d = space / (cnt - 1), r = space % (cnt - 1);
            string line;
            for (; i < j; ++i) {
                if (line.size()) {
                    if (j == N) line += ' '; // The last line is left-justified
                    else { // otherwise fully-justified.
                        for (int k = 0; k < d; ++k) line += ' ';
                        if (r-- > 0) line += ' ';
                    }
                }
                line += words[i];
                if (i == j - 1) while (line.size() < maxWidth) line += ' '; // pad space after the last word in this line
            }
            ans.push_back(line);
        }
        return ans;
    }
};
```