# [2266. Count Number of Texts (Medium)](https://leetcode.com/problems/count-number-of-texts)

<p>Alice is texting Bob using her phone. The <strong>mapping</strong> of digits to letters is shown in the figure below.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png" style="width: 200px; height: 162px;">
<p>In order to <strong>add</strong> a letter, Alice has to <strong>press</strong> the key of the corresponding digit <code>i</code> times, where <code>i</code> is the position of the letter in the key.</p>
<ul>
	<li>For example, to add the letter <code>'s'</code>, Alice has to press <code>'7'</code> four times. Similarly, to add the letter <code>'k'</code>, Alice has to press <code>'5'</code> twice.</li>
	<li>Note that the digits <code>'0'</code> and <code>'1'</code> do not map to any letters, so Alice <strong>does not</strong> use them.</li>
</ul>
<p>However, due to an error in transmission, Bob did not receive Alice's text message but received a <strong>string of pressed keys</strong> instead.</p>
<ul>
	<li>For example, when Alice sent the message <code>"bob"</code>, Bob received the string <code>"2266622"</code>.</li>
</ul>
<p>Given a string <code>pressedKeys</code> representing the string received by Bob, return <em>the <strong>total number of possible text messages</strong> Alice could have sent</em>.</p>
<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> pressedKeys = "22233"
<strong>Output:</strong> 8
<strong>Explanation:</strong>
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> pressedKeys = "222222222222222222222222222222222222"
<strong>Output:</strong> 82876089
<strong>Explanation:</strong>
There are 2082876103 possible text messages Alice could have sent.
Since we need to return the answer modulo 10<sup>9</sup> + 7, we return 2082876103 % (10<sup>9</sup> + 7) = 82876089.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= pressedKeys.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pressedKeys</code> only consists of digits from <code>'2'</code> - <code>'9'</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
* [Decode Ways (Medium)](https://leetcode.com/problems/decode-ways/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-texts
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int countTexts(string s) {
        long ans = 1, mod = 1e9 + 7;
        auto count = [&](int n, int len) {
            vector<long> v(len);
            v.back() = 1;
            for (int i = 0; i < n; ++i) {
                long next = 0;
                for (int j = 0; j < len; ++j) next = (next + v[j]) % mod;
                for (int j = 0; j < len - 1; ++j) v[j] = v[j + 1];
                v.back() = next;
            }
            return v.back();
        };
        for (int i = 0, N = s.size(); i < N; ++i) {
            long cnt = 1;
            while (i + 1 < N && s[i] == s[i + 1]) ++i, ++cnt;
            ans = ans * count(cnt, s[i] == '7' || s[i] == '9' ? 4 : 3) % mod;
        }
        return ans;
    }
};
```