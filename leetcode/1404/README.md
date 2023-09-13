# [1404. Number of Steps to Reduce a Number in Binary Representation to One (Medium)](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

<p>Given a number&nbsp;<code>s</code> in their binary representation. Return the number of steps to reduce it to 1 under the following rules:</p>

<ul>
	<li>
	<p>If the current number is even, you have to divide it by 2.</p>
	</li>
	<li>
	<p>If the current number is odd, you have to add 1 to it.</p>
	</li>
</ul>

<p>It's guaranteed that you can always reach to one for all testcases.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1101"
<strong>Output:</strong> 6
<strong>Explanation:</strong> "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.&nbsp;
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.&nbsp; 
Step 5) 4 is even, divide by 2 and obtain 2.&nbsp;
Step 6) 2 is even, divide by 2 and obtain 1.&nbsp; 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "10"
<strong>Output:</strong> 1
<strong>Explanation:</strong> "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.&nbsp; 
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1"
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 500</code></li>
	<li><code>s</code> consists of characters '0' or '1'</li>
	<li><code>s[0] == '1'</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            if (s.back() == '1') {
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    --i;
                }
                if (i == -1) s.insert(s.begin(), '1');
                else s[i] = '1';
            } else s.pop_back();
            ++ans;
        }
        return ans;
    }
};
```