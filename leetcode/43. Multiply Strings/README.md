# [43. Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)

<p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as strings, return the product of <code>num1</code> and <code>num2</code>, also represented as a string.</p>

<p><strong>Note:</strong>&nbsp;You must not use any built-in BigInteger library or convert the inputs to integer directly.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num1 = "2", num2 = "3"
<strong>Output:</strong> "6"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num1 = "123", num2 = "456"
<strong>Output:</strong> "56088"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 200</code></li>
	<li><code>num1</code> and <code>num2</code> consist of digits only.</li>
	<li>Both <code>num1</code> and <code>num2</code>&nbsp;do not contain any leading zero, except the number <code>0</code> itself.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)
* [Add Binary (Easy)](https://leetcode.com/problems/add-binary/)
* [Add Strings (Easy)](https://leetcode.com/problems/add-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/multiply-strings/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M + N)
class Solution {
    string mul(const string &a, int n, int shift) {
        if (n == 0 || a == "0") return "0";
        int carry = 0;
        string ans;
        for (int N = a.size(), i = N - 1; i >= 0 || carry;) {
            if (i >= 0) carry += (a[i--] - '0') * n;
            ans += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        while (shift--) ans += '0';
        return ans;
    }
    string add(string a, string b) {
        if (a == "0") return b;
        if (b == "0") return a;
        string ans;
        for (int i = a.size() - 1, j = b.size() - 1, carry = 0; i >= 0 || j >= 0 || carry; ) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
public:
    string multiply(string a, string b) {
        string ans = "0";
        for (int i = 0, N = b.size(); i < N; ++i) {
            ans = add(ans, mul(a, b[N - 1 - i] - '0', i));
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/multiply-strings/
// Author: github.com/lzl124631x
// Time: O(M * N)
// Space: O(M + N)
class Solution {
public:
    string multiply(string a, string b) {
        int M = a.size(), N = b.size();
        string ans(M + N, '0');
        for (int j = N - 1; j >= 0; --j) {
            int carry = 0;
            for (int i = M - 1, k = N - 1 - j; i >= 0 || carry; ++k) {
                if (i >= 0) carry += (a[i--] - '0') * (b[j] - '0');
                carry += ans[k] - '0';
                ans[k] = carry % 10 + '0';
                carry /= 10;
            }
        }
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```