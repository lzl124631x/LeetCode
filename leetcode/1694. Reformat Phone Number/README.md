# [1694. Reformat Phone Number (Easy)](https://leetcode.com/problems/reformat-phone-number/)

<p>You are given a phone number as a string <code>number</code>. <code>number</code> consists of digits, spaces <code>' '</code>, and/or dashes <code>'-'</code>.</p>

<p>You would like to reformat the phone number in a certain manner. Firstly, <strong>remove</strong> all spaces and dashes. Then, <strong>group</strong> the digits from left to right into blocks of length 3 <strong>until</strong> there are 4 or fewer digits. The final digits are then grouped as follows:</p>

<ul>
	<li>2 digits: A single block of length 2.</li>
	<li>3 digits: A single block of length 3.</li>
	<li>4 digits: Two blocks of length 2 each.</li>
</ul>

<p>The blocks are then joined by dashes. Notice that the reformatting process should <strong>never</strong> produce any blocks of length 1 and produce <strong>at most</strong> two blocks of length 2.</p>

<p>Return <em>the phone number after formatting.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> number = "1-23-45 6"
<strong>Output:</strong> "123-456"
<strong>Explanation:</strong> The digits are "123456".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 3 digits remaining, so put them in a single block of length 3. The 2nd block is "456".
Joining the blocks gives "123-456".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> number = "123 4-567"
<strong>Output:</strong> "123-45-67"
<strong>Explanation: </strong>The digits are "1234567".
Step 1: There are more than 4 digits, so group the next 3 digits. The 1st block is "123".
Step 2: There are 4 digits left, so split them into two blocks of length 2. The blocks are "45" and "67".
Joining the blocks gives "123-45-67".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> number = "123 4-5678"
<strong>Output:</strong> "123-456-78"
<strong>Explanation:</strong> The digits are "12345678".
Step 1: The 1st block is "123".
Step 2: The 2nd block is "456".
Step 3: There are 2 digits left, so put them in a single block of length 2. The 3rd block is "78".
Joining the blocks gives "123-456-78".
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> number = "12"
<strong>Output:</strong> "12"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> number = "--17-5 229 35-39475 "
<strong>Output:</strong> "175-229-353-94-75"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= number.length &lt;= 100</code></li>
	<li><code>number</code> consists of digits&nbsp;and the characters <code>'-'</code> and <code>' '</code>.</li>
	<li>There are at least <strong>two</strong> digits in <code>number</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reformat-phone-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reformatNumber(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) s[j++] = s[i];
        }
        s.resize(j);
        string ans;
        for (int i = 0, r = s.size(); i < s.size(); ) { // `r` is the # of remaining digits.
            for (int d = r == 2 || r == 4 ? 2 : 3; d > 0; --d, --r) { // when `r` is 2 or 4, we output 2 digits; otherwise, 3 digits.
                ans += s[i++];
            }
            if (r) ans += '-'; // if there are still remaining digits, append '-'.
        }
        return ans;
    }
};
```