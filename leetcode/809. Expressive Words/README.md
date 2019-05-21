# [809. Expressive Words (Medium)](https://leetcode.com/problems/expressive-words/)

<p>Sometimes people repeat letters to represent extra feeling, such as "hello" -&gt; "heeellooo", "hi" -&gt; "hiiii".&nbsp; In these strings like "heeellooo", we have <em>groups</em> of adjacent letters that are all the same:&nbsp; "h", "eee", "ll", "ooo".</p>

<p>For some given string <code>S</code>, a query word is <em>stretchy</em> if it can be made to be equal to <code>S</code> by any&nbsp;number of&nbsp;applications of the following <em>extension</em> operation: choose a group consisting of&nbsp;characters <code>c</code>, and add some number of characters <code>c</code> to the group so that the size of the group is 3 or more.</p>

<p>For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.&nbsp; Also, we could do another extension like "ll" -&gt; "lllll" to get "helllllooo".&nbsp; If <code>S = "helllllooo"</code>, then the query word "hello" would be stretchy because of these two extension operations:&nbsp;<code>query = "hello" -&gt; "hellooo" -&gt;&nbsp;"helllllooo" = S</code>.</p>

<p>Given a list of query words, return the number of words that are stretchy.&nbsp;</p>

<p>&nbsp;</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> 
S = "heeellooo"
words = ["hello", "hi", "helo"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
</pre>

<p>&nbsp;</p>

<p><strong>Notes: </strong></p>

<ul>
	<li><code>0 &lt;= len(S) &lt;= 100</code>.</li>
	<li><code>0 &lt;= len(words) &lt;= 100</code>.</li>
	<li><code>0 &lt;= len(words[i]) &lt;= 100</code>.</li>
	<li><code>S</code> and all words in <code>words</code>&nbsp;consist only of&nbsp;lowercase letters</li>
</ul>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/expressive-words/
// Author: github.com/lzl124631x
// Time: O(SW) where S is size of string `S`, W is count of `words`
// Space: O(S)
class Solution {
private:
    vector<pair<char, int>> s;
    vector<pair<char, int>> get(string &s) {
        vector<pair<char, int>> v;
        for (int i = 0, N = s.size(); i < N;) {
            int start = i;
            while (i < N && s[i] == s[start]) ++i;
            v.emplace_back(s[start], i - start);
        }
        return v;
    }
    bool isExpressiveWord(string &word) {
        auto w = get(word);
        if (s.size() != w.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i].first != w[i].first
               || !((s[i].second >= 3 && w[i].second <= s[i].second) || (s[i].second < 3 && w[i].second == s[i].second))) return false;
        }
        return true;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        s = get(S);
        int ans = 0;
        for (auto &word : words) {
            if (isExpressiveWord(word)) ++ans;
        }
        return ans;
    }
};
```