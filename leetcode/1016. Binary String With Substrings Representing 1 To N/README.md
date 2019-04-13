# [1016. Binary String With Substrings Representing 1 To N (Medium)](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/)

<p>Given a binary string <code>S</code> (a string consisting only of '0' and '1's) and a positive integer <code>N</code>, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-1-1">"0110"</span>, N = <span id="example-input-1-2">3</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>S = <span id="example-input-2-1">"0110"</span>, N = <span id="example-input-2-2">4</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= S.length &lt;= 1000</code></li>
	<li><code>1 &lt;= N &lt;= 10^9</code></li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
// Author: github.com/lzl124631x
// Time: O(N(S+logN))
// Space: O(logN)
class Solution {
private:
    string toBinary(int N) {
        string ans;
        while (N) {
            ans += '0' + (N % 2);
            N /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    bool queryString(string S, int N) {
        for (int i = N; i >= 1 && i > N / 2; --i) {
            if (S.find(toBinary(i)) == string::npos) return false;
        }
        return true;
    }
};
```