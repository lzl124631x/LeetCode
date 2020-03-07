# [1324. Print Words Vertically (Medium)](https://leetcode.com/problems/print-words-vertically/)

<p>Given a string <code>s</code>.&nbsp;Return&nbsp;all the words vertically in the same order in which they appear in <code>s</code>.<br>
Words are returned as a list of strings, complete with&nbsp;spaces when is necessary. (Trailing spaces are not allowed).<br>
Each word would be put on only one column and that in one column there will be only one word.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "HOW ARE YOU"
<strong>Output:</strong> ["HAY","ORO","WEU"]
<strong>Explanation: </strong>Each word is printed vertically. 
 "HAY"
&nbsp;"ORO"
&nbsp;"WEU"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "TO BE OR NOT TO BE"
<strong>Output:</strong> ["TBONTB","OEROOE","   T"]
<strong>Explanation: </strong>Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "CONTEST IS COMING"
<strong>Output:</strong> ["CIC","OSO","N M","T I","E N","S G","T"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code>&nbsp;contains only upper case English letters.</li>
	<li>It's guaranteed that there is only one&nbsp;space between 2 words.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/print-words-vertically/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v, ans;
        stringstream ss(s);
        string word;
        int maxLen = 0;
        while (ss >> word) {
            v.push_back(word);
            maxLen = max(maxLen, (int)word.size());
        }
        for (int i = 0; i < maxLen; ++i) {
            string word;
            for (int j = 0; j < v.size(); ++j)
                word += i < v[j].size() ? v[j][i] : ' ';
            while (word.back() == ' ') word.pop_back();
            ans.push_back(word);
        }
        return ans;
    }
};
```