# [38. Count and Say (Medium)](https://leetcode.com/problems/count-and-say/)

<p>The <strong>count-and-say</strong> sequence is a sequence of digit strings defined by the recursive formula:</p>

<ul>
	<li><code>countAndSay(1) = "1"</code></li>
	<li><code>countAndSay(n)</code> is the way you would "say" the digit string from <code>countAndSay(n-1)</code>, which is then converted into a different digit string.</li>
</ul>

<p>To determine how you "say" a digit string, split it into the <strong>minimal</strong> number of groups so that each group is a contiguous section all of the <strong>same character.</strong> Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.</p>

<p>For example, the saying and conversion for digit string <code>"3322251"</code>:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg" style="width: 581px; height: 172px;">
<p>Given a positive integer <code>n</code>, return <em>the </em><code>n<sup>th</sup></code><em> term of the <strong>count-and-say</strong> sequence</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> "1"
<strong>Explanation:</strong> This is the base case.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> "1211"
<strong>Explanation:</strong>
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)
* [String Compression (Medium)](https://leetcode.com/problems/string-compression/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/count-and-say/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1), ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            char d = s[i];
            int cnt = 1;
            while (i + 1 < N && s[i + 1] == s[i]) ++i, ++cnt;
            ans += to_string(cnt) + d;
        }
        return ans;
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/count-and-say/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string next;
            int i = 0;
            while (i < ans.size()) {
                char c = ans[i];
                int cnt = 0;
                while (i < ans.size() && ans[i] == c) ++cnt, ++i;
                next += to_string(cnt) + c;
            }
            ans = next;
        }
        return ans;
    }
};
```