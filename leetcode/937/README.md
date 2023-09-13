# [937. Reorder Data in Log Files (Easy)](https://leetcode.com/problems/reorder-data-in-log-files/)

<p>You have an array of <code>logs</code>.&nbsp; Each log is a space delimited string of words.</p>

<p>For each log, the first word in each log is an alphanumeric <em>identifier</em>.&nbsp; Then, either:</p>

<ul>
	<li>Each word after the identifier will consist only of lowercase letters, or;</li>
	<li>Each word after the identifier will consist only of digits.</li>
</ul>

<p>We will call these two varieties of logs <em>letter-logs</em> and <em>digit-logs</em>.&nbsp; It is guaranteed that each log has at least one word after its identifier.</p>

<p>Reorder the logs so that all of the letter-logs come before any digit-log.&nbsp; The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.&nbsp; The digit-logs should be put in their original order.</p>

<p>Return the final order of the logs.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
<strong>Output:</strong> ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ol>
	<li><code>0 &lt;= logs.length &lt;= 100</code></li>
	<li><code>3 &lt;= logs[i].length &lt;= 100</code></li>
	<li><code>logs[i]</code> is guaranteed to have an identifier, and a word after the identifier.</li>
</ol>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Wrong Answer

This code can pass the OJ, but it is actually wrong. It returns wrong answer for input `["let1 art", "let3 art ball"]` because it compares `let1` with `ball`.

1. Separate logs into `digitLogs` and `letterLogs` according to the first character after the first space. Note that for letter logs, Each identifier is moved to the end of the string in order to facilitate sorting.
2. Sort `letterLogs`
3. Recover `letterLogs` so that the identifiers are moved back the the beginning of logs.
4. Concatenate `letterLogs` with `digitLogs`, return `letterLogs`.

```cpp
// OJ: https://leetcode.com/problems/reorder-log-files
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.push_back(s.substr(i + 1) + " " + s.substr(0, i));
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (string &s : letterLogs) {
            int i = s.size() - 1;
            while (s[i] != ' ') --i;
            s = s.substr(i + 1) + " " + s.substr(0, i);
        }
        for (string &s : digitLogs) letterLogs.push_back(s);
        return letterLogs;
    }
};
```

## Solution 1. Custom Sort

1. Split `logs` into `letterLogs` and `digitLogs`. Separate each `letterLog` as a pair of identifier and log content.
1. Sort `letterLogs`. Try comparing log contents first, if they are the same, use log identifier to break the tie.
1. Return the concatenation of `letterLogs` and `digitLogs`.

```cpp
// OJ: https://leetcode.com/problems/reorder-data-in-log-files/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, ans;
        vector<pair<string, string>> letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for (auto &p : letterLogs) ans.push_back(p.first + " " + p.second);
        for (string &s : digitLogs) ans.push_back(s);
        return ans;
    }
};
```