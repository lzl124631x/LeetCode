# [415. Add Strings (Easy)](https://leetcode.com/problems/add-strings/)

<p>Given two non-negative integers, <code>num1</code> and <code>num2</code> represented as string, return <em>the sum of</em> <code>num1</code> <em>and</em> <code>num2</code> <em>as a string</em>.</p>

<p>You must solve the problem without using any built-in library for handling large integers (such as <code>BigInteger</code>). You must also not convert the inputs to integers directly.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num1 = "11", num2 = "123"
<strong>Output:</strong> "134"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num1 = "456", num2 = "77"
<strong>Output:</strong> "533"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num1 = "0", num2 = "0"
<strong>Output:</strong> "0"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>num1</code> and <code>num2</code> consist of only digits.</li>
	<li><code>num1</code> and <code>num2</code> don't have any leading zeros except for the zero itself.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Oracle](https://leetcode.com/company/oracle), [Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-strings/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    string addStrings(string a, string b) {
        string sum;
        int carry = 0;
        auto i = a.rbegin(), j = b.rbegin();
        while (i != a.rend() || j != b.rend() || carry) {
            if (i != a.rend()) carry += *i++ - '0';
            if (j != b.rend()) carry += *j++ - '0';
            sum += (carry % 10) + '0';
            carry /= 10;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/add-strings/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    string addStrings(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        int carry = 0;
        string ans;
        for (int i = 0; i < a.size() || i < b.size() || carry; ++i) {
            if (i < a.size()) carry += a[i] - '0';
            if (i < b.size()) carry += b[i] - '0';
            ans.push_back('0' + carry % 10);
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```