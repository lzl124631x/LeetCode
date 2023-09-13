# [537. Complex Number Multiplication (Medium)](https://leetcode.com/problems/complex-number-multiplication/)

<p>
Given two strings representing two <a href="https://en.wikipedia.org/wiki/Complex_number">complex numbers</a>.</p>

<p>
You need to return a string representing their multiplication. Note i<sup>2</sup> = -1 according to the definition.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "1+1i", "1+1i"
<b>Output:</b> "0+2i"
<b>Explanation:</b> (1 + i) * (1 + i) = 1 + i<sup>2</sup> + 2 * i = 2i, and you need convert it to the form of 0+2i.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "1+-1i", "1+-1i"
<b>Output:</b> "0+-2i"
<b>Explanation:</b> (1 - i) * (1 - i) = 1 + i<sup>2</sup> - 2 * i = -2i, and you need convert it to the form of 0+-2i.
</pre>
<p></p>

<p><b>Note:</b>
</p><ol>
<li>The input strings will not have extra blank.</li>
<li>The input strings will be given in the form of <b>a+bi</b>, where the integer <b>a</b> and <b>b</b> will both belong to the range of [-100, 100]. And <b>the output should be also in this form</b>.</li>
</ol>
<p></p>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/complex-number-multiplication/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> parse(string &s) {
        vector<int> ans(2, 0);
        ans[0] = stoi(s);
        int i = s.find_first_of("+");
        ans[1] = stoi(s.substr(i + 1));
        return ans;
    }
public:
    string complexNumberMultiply(string a, string b) {
        auto m = parse(a), n = parse(b);
        int x = m[0] * n[0] - m[1] * n[1], y = m[1] * n[0] + m[0] * n[1];
        return to_string(x) + "+" + to_string(y) + "i";
    }
};
```