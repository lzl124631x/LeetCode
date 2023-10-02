# [2284. Sender With Largest Word Count (Medium)](https://leetcode.com/problems/sender-with-largest-word-count)

<p>You have a chat log of <code>n</code> messages. You are given two string arrays <code>messages</code> and <code>senders</code> where <code>messages[i]</code> is a <strong>message</strong> sent by <code>senders[i]</code>.</p>
<p>A <strong>message</strong> is list of <strong>words</strong> that are separated by a single space with no leading or trailing spaces. The <strong>word count</strong> of a sender is the total number of <strong>words</strong> sent by the sender. Note that a sender may send more than one message.</p>
<p>Return <em>the sender with the <strong>largest</strong> word count</em>. If there is more than one sender with the largest word count, return <em>the one with the <strong>lexicographically largest</strong> name</em>.</p>
<p><strong>Note:</strong></p>
<ul>
	<li>Uppercase letters come before lowercase letters in lexicographical order.</li>
	<li><code>"Alice"</code> and <code>"alice"</code> are distinct.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
<strong>Output:</strong> "Alice"
<strong>Explanation:</strong> Alice sends a total of 2 + 3 = 5 words.
userTwo sends a total of 2 words.
userThree sends a total of 3 words.
Since Alice has the largest word count, we return "Alice".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> messages = ["How is leetcode for everyone","Leetcode is useful for practice"], senders = ["Bob","Charlie"]
<strong>Output:</strong> "Charlie"
<strong>Explanation:</strong> Bob sends a total of 5 words.
Charlie sends a total of 5 words.
Since there is a tie for the largest word count, we return the sender with the lexicographically larger name, Charlie.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == messages.length == senders.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= messages[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= senders[i].length &lt;= 10</code></li>
	<li><code>messages[i]</code> consists of uppercase and lowercase English letters and <code>' '</code>.</li>
	<li>All the words in <code>messages[i]</code> are separated by <strong>a single space</strong>.</li>
	<li><code>messages[i]</code> does not have leading or trailing spaces.</li>
	<li><code>senders[i]</code> consists of uppercase and lowercase English letters only.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sender-with-largest-word-count
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string largestWordCount(vector<string>& M, vector<string>& S) {
        unordered_map<string, int> m; // user -> word count
        string ans;
        for (int i = 0, N = M.size(); i < N; ++i) {
            int space = 0;
            for (int j = 0; j < M[i].size(); ++j) space += M[i][j] == ' ';
            m[S[i]] += space + 1;
            if (ans.empty() || m[S[i]] > m[ans] || (m[S[i]] == m[ans] && S[i] > ans)) {
                ans = S[i];
            }
        }
        return ans;
    }
};
```