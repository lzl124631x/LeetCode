# [2299. Strong Password Checker II (Easy)](https://leetcode.com/problems/strong-password-checker-ii)

<p>A password is said to be <strong>strong</strong> if it satisfies all the following criteria:</p>

<ul>
	<li>It has at least <code>8</code> characters.</li>
	<li>It contains at least <strong>one lowercase</strong> letter.</li>
	<li>It contains at least <strong>one uppercase</strong> letter.</li>
	<li>It contains at least <strong>one digit</strong>.</li>
	<li>It contains at least <strong>one special character</strong>. The special characters are the characters in the following string: <code>"!@#$%^&amp;*()-+"</code>.</li>
	<li>It does <strong>not</strong> contain <code>2</code> of the same character in adjacent positions (i.e., <code>"aab"</code> violates this condition, but <code>"aba"</code> does not).</li>
</ul>

<p>Given a string <code>password</code>, return <code>true</code><em> if it is a <strong>strong</strong> password</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> password = "IloveLe3tcode!"
<strong>Output:</strong> true
<strong>Explanation:</strong> The password meets all the requirements. Therefore, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> password = "Me+You--IsMyDream"
<strong>Output:</strong> false
<strong>Explanation:</strong> The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> password = "1aB!"
<strong>Output:</strong> false
<strong>Explanation:</strong> The password does not meet the length requirement. Therefore, we return false.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= password.length &lt;= 100</code></li>
	<li><code>password</code> consists of letters, digits, and special characters: <code>"!@#$%^&amp;*()-+"</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Strong Password Checker (Hard)](https://leetcode.com/problems/strong-password-checker/)
* [Validate IP Address (Hard)](https://leetcode.com/problems/validate-ip-address/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/strong-password-checker-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if (s.size() < 8) return false;
        int lower = 0, upper = 0, digit = 0, special = 0, N = s.size();
        string specialChars = "!@#$%^&*()-+";
        for (int i = 0; i < N; ++i) {
            if (islower(s[i])) ++lower;
            else if (isupper(s[i])) ++upper;
            else if (isdigit(s[i])) ++digit;
            else if (specialChars.find(s[i]) != string::npos) ++special;
            if (i > 0 && s[i] == s[i - 1]) return false;
        }
        return lower && upper && digit && special;
    }
};
```