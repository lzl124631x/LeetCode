# [2243. Calculate Digit Sum of a String (Easy)](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

<p>You are given a string <code>s</code> consisting of digits and an integer <code>k</code>.</p>

<p>A <strong>round</strong> can be completed if the length of <code>s</code> is greater than <code>k</code>. In one round, do the following:</p>

<ol>
	<li><strong>Divide</strong> <code>s</code> into <strong>consecutive groups</strong> of size <code>k</code> such that the first <code>k</code> characters are in the first group, the next <code>k</code> characters are in the second group, and so on. <strong>Note</strong> that the size of the last group can be smaller than <code>k</code>.</li>
	<li><strong>Replace</strong> each group of <code>s</code> with a string representing the sum of all its digits. For example, <code>"346"</code> is replaced with <code>"13"</code> because <code>3 + 4 + 6 = 13</code>.</li>
	<li><strong>Merge</strong> consecutive groups together to form a new string. If the length of the string is greater than <code>k</code>, repeat from step <code>1</code>.</li>
</ol>

<p>Return <code>s</code> <em>after all rounds have been completed</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "11111222223", k = 3
<strong>Output:</strong> "135"
<strong>Explanation:</strong> 
- For the first round, we divide s into groups of size 3: "111", "112", "222", and "23".
  ​​​​​Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5. 
&nbsp; So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
- For the second round, we divide s into "346" and "5".
&nbsp; Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5. 
&nbsp; So, s becomes "13" + "5" = "135" after second round. 
Now, s.length &lt;= k, so we return "135" as the answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00000000", k = 3
<strong>Output:</strong> "000"
<strong>Explanation:</strong> 
We divide s into "000", "000", and "00".
Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, and 0 + 0 = 0. 
s becomes "0" + "0" + "0" = "000", whose length is equal to k, so we return "000".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>2 &lt;= k &lt;= 100</code></li>
	<li><code>s</code> consists of digits only.</li>
</ul>


**Similar Questions**:
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)
* [Find Triangular Sum of an Array (Medium)](https://leetcode.com/problems/find-triangular-sum-of-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/calculate-digit-sum-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string tmp;
            int sum = 0;
            for (int i = 0; i < s.size(); ++i) {
                sum += s[i] - '0';
                if ((i + 1) % k == 0 || i == s.size() - 1) {
                    tmp += to_string(sum);
                    sum = 0;
                }
            }
            swap(s, tmp);
        }
        return s;
    }
};
```