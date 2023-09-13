# [831. Masking Personal Information (Medium)](https://leetcode.com/problems/masking-personal-information/)

<p>We are given a&nbsp;personal information string <code>S</code>, which may represent&nbsp;either <strong>an email address</strong> or <strong>a phone number.</strong></p>

<p>We would like to mask this&nbsp;personal information according to the&nbsp;following rules:</p>

<p><br>
<u><strong>1. Email address:</strong></u></p>

<p>We define a&nbsp;<strong>name</strong> to be a string of <code>length ≥ 2</code> consisting&nbsp;of only lowercase letters&nbsp;<code>a-z</code> or uppercase&nbsp;letters&nbsp;<code>A-Z</code>.</p>

<p>An email address starts with a name, followed by the&nbsp;symbol <code>'@'</code>, followed by a name, followed by the&nbsp;dot&nbsp;<code>'.'</code>&nbsp;and&nbsp;followed by a name.&nbsp;</p>

<p>All email addresses are&nbsp;guaranteed to be valid and in the format of&nbsp;<code>"name1@name2.name3".</code></p>

<p>To mask an email, <strong>all names must be converted to lowercase</strong> and <strong>all letters between the first and last letter of the first name</strong> must be replaced by 5 asterisks <code>'*'</code>.</p>

<p><br>
<u><strong>2. Phone number:</strong></u></p>

<p>A phone number is a string consisting of&nbsp;only the digits <code>0-9</code> or the characters from the set <code>{'+', '-', '(', ')', '&nbsp;'}.</code>&nbsp;You may assume a phone&nbsp;number contains&nbsp;10 to 13 digits.</p>

<p>The last 10 digits make up the local&nbsp;number, while the digits before those make up the country code. Note that&nbsp;the country code is optional. We want to expose only the last 4 digits&nbsp;and mask all other&nbsp;digits.</p>

<p>The local&nbsp;number&nbsp;should be formatted and masked as <code>"***-***-1111",&nbsp;</code>where <code>1</code> represents the exposed digits.</p>

<p>To mask a phone number with country code like <code>"+111 111 111 1111"</code>, we write it in the form <code>"+***-***-***-1111".</code>&nbsp; The <code>'+'</code>&nbsp;sign and the first <code>'-'</code>&nbsp;sign before the local number should only exist if there is a country code.&nbsp; For example, a 12 digit phone number mask&nbsp;should start&nbsp;with <code>"+**-"</code>.</p>

<p>Note that extraneous characters like <code>"(", ")", " "</code>, as well as&nbsp;extra dashes or plus signs not part of the above formatting scheme should be removed.</p>

<p>&nbsp;</p>

<p>Return the correct "mask" of the information provided.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>"LeetCode@LeetCode.com"
<strong>Output: </strong>"l*****e@leetcode.com"
<strong>Explanation:&nbsp;</strong>All names are converted to lowercase, and the letters between the
&nbsp;            first and last letter of the first name is replaced by 5 asterisks.
&nbsp;            Therefore, "leetcode" -&gt; "l*****e".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"AB@qq.com"
<strong>Output: </strong>"a*****b@qq.com"
<strong>Explanation:&nbsp;</strong>There must be 5 asterisks between the first and last letter 
&nbsp;            of the first name "ab". Therefore, "ab" -&gt; "a*****b".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>"1(234)567-890"
<strong>Output: </strong>"***-***-7890"
<strong>Explanation:</strong>&nbsp;10 digits in the phone number, which means all digits make up the local number.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>"86-(10)12345678"
<strong>Output: </strong>"+**-***-***-5678"
<strong>Explanation:</strong>&nbsp;12 digits, 2 digits for country code and 10 digits for local number. 
</pre>

<p><strong>Notes:</strong></p>

<ol>
	<li><code>S.length&nbsp;&lt;=&nbsp;40</code>.</li>
	<li>Emails have length at least 8.</li>
	<li>Phone numbers have length at least 10.</li>
</ol>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/masking-personal-information/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    string maskPhone(string &s) {
        int cnt = 0, N = s.size(), i = 0;
        for (char c : s) cnt += isdigit(c);
        string ans;
        if (cnt > 10) {
            ans += '+';
            for (; cnt > 10; ++i) {
                if (!isdigit(s[i])) continue;
                --cnt;
                ans += '*';
            }
            ans += '-';
        }
        for (; cnt; ++i) {
            if (!isdigit(s[i])) continue;
            --cnt;
            if (cnt > 3) ans += '*';
            else ans += s[i];
            if (cnt == 7 || cnt == 4) ans += '-';
        }
        return ans;
    }
    string maskEmail(string &s) {
        string ans;
        ans += tolower(s[0]);
        for (int i = 0; i < 5; ++i) ans += '*';
        int i = 0;
        while (s[i + 1] != '@') ++i;
        for (; i < s.size(); ++i) ans += tolower(s[i]);
        return ans;
    }
public:
    string maskPII(string S) {
        if (S.find('@') == string::npos) return maskPhone(S);
        return maskEmail(S);
    }
};
```