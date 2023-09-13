# [949. Largest Time for Given Digits (Easy)](https://leetcode.com/problems/largest-time-for-given-digits/)

<p>Given an array of 4 digits, return the largest 24 hour time that can be made.</p>

<p>The smallest 24 hour time is 00:00, and the largest is 23:59.&nbsp; Starting from 00:00, a time is larger if more time has elapsed since midnight.</p>

<p>Return the answer as a string of length 5.&nbsp; If no valid time can be made, return an empty string.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,4]</span>
<strong>Output: </strong><span id="example-output-1">"23:41"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[5,5,5,5]</span>
<strong>Output: </strong><span id="example-output-2">""</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>A.length == 4</code></li>
	<li><code>0 &lt;= A[i] &lt;= 9</code></li>
</ol>
</div>
</div>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-time-for-given-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    string ans;
    void permute(string &s, int start) {
        if (start == s.size()) {
            ans = max(ans, s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if ((start == 0 && s[i] > '2')
               || (start == 1 && s[start - 1] == '2' && s[i] > '3')
               || (start == 2 && s[i] > '5')) continue;
            swap(s[start], s[i]);
            permute(s, start + 1);
            swap(s[start], s[i]);
        }
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        string s;
        for (int i : A) s.push_back('0' + i);
        permute(s, 0);
        if (ans.size()) ans.insert(2, ":");
        return ans;
    }
};
```