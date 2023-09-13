# [564. Find the Closest Palindrome (Hard)](https://leetcode.com/problems/find-the-closest-palindrome/)

<p>Given a string <code>n</code> representing an integer, return <em>the closest integer (not including itself), which is a palindrome</em>. If there is a tie, return <em><strong>the smaller one</strong></em>.</p>

<p>The closest is defined as the absolute difference minimized between two integers.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = "123"
<strong>Output:</strong> "121"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = "1"
<strong>Output:</strong> "0"
<strong>Explanation:</strong> 0 and 2 are the closest palindromes but we return the smallest which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 18</code></li>
	<li><code>n</code> consists of only digits.</li>
	<li><code>n</code> does not have leading zeros.</li>
	<li><code>n</code> is representing an integer in the range <code>[1, 10<sup>18</sup> - 1]</code>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Next Palindrome Using Same Digits (Hard)](https://leetcode.com/problems/next-palindrome-using-same-digits/)

## Solution 1.

Calculate the previous and next palindrome and pick the one with less distance to the original number.

This is too length. Need to read discuss.

```cpp
// OJ: https://leetcode.com/problems/find-the-closest-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    string increment(string s) {
        int carry = 1, i = s.size() - 1;
        for (; i >= 0; --i) {
            carry += s[i] - '0';
            s[i] = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) s.insert(begin(s), carry + '0');
        return s;
    }
    string decrement(string s) {
        int carry = -1, i = s.size() - 1;
        for (; i >= 0; --i) {
            carry += s[i] - '0';
            if (carry < 0) {
                s[i] = (carry + 10) % 10 + '0';
                carry = -1;
            } else {
                s[i] = carry % 10 + '0';
                carry /= 10;
            }
        }
        if (s.size() > 1 && s.front() == '0') s.erase(s.begin());
        return s;
    }
    string nextPalindrome(string &n) {
        auto half = n.substr(0, (n.size() + 1) / 2);
        string reverse(half.rbegin(), half.rend());
        if (lt(n.substr(n.size() / 2), reverse)) return half.substr(0, n.size() - reverse.size()) + reverse;
        auto first = increment(half);
        string second(first.rbegin(), first.rend());
        int len = n.size();
        if (first.size() > half.size()) ++len; // the length of the result will be n.size() + 1
        return first.substr(0, len - first.size()) + second;
    }
    string prevPalindrome(string &n) {
        if (n == "1") return "0";
        auto half = n.substr(0, (n.size() + 1) / 2);
        string reverse(half.rbegin(), half.rend());
        if (lt(reverse, n.substr(n.size() / 2))) return half.substr(0, n.size() - reverse.size()) + reverse;
        auto first = decrement(half);
        if (first.size() < half.size() || first == "0") return string(n.size() - 1, '9');
        string second(first.rbegin(), first.rend());
        return first.substr(0, n.size() - first.size()) + second;
    }
    string subtract(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        for (; i >= 0 && j >= 0; --i, --j) {
            carry += a[i] - b[j];
            if (carry >= 0) {
                ans.push_back(carry % 10 + '0');
                carry /= 10;
            } else {
                ans.push_back((carry + 10) % 10 + '0');
                carry = -1;
            }
        }
        while (ans.size() && ans.back() == '0') ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }
    bool lt(string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }
    bool le(string a, string b) { // returns true if a <= b
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return true;
    }
public:
    string nearestPalindromic(string n) {
        auto a = nextPalindrome(n);
        auto b = prevPalindrome(n);
        return le(subtract(n, b), subtract(a, n)) ? b : a;
    }
};
```