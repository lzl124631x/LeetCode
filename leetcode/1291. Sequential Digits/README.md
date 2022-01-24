# [1291. Sequential Digits (Medium)](https://leetcode.com/problems/sequential-digits/)

<p>An&nbsp;integer has <em>sequential digits</em> if and only if each digit in the number is one more than the previous digit.</p>

<p>Return a <strong>sorted</strong> list of all the integers&nbsp;in the range <code>[low, high]</code>&nbsp;inclusive that have sequential digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> low = 100, high = 300
<strong>Output:</strong> [123,234]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> low = 1000, high = 13000
<strong>Output:</strong> [1234,2345,3456,4567,5678,6789,12345]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>


**Companies**:  
[Splunk](https://leetcode.com/company/splunk)

**Related Topics**:  
[Enumeration](https://leetcode.com/tag/enumeration/)

## Solution 1.

`get` function: Given length and first digit, generate the number.

Get the length of `low`, and start creating numbers from this length. Keep only the numbers in range.

```cpp
// OJ: https://leetcode.com/problems/sequential-digits/
// Author: github.com/lzl124631x
// Time: O(1) since there are limited number of valid integers
// Space: O(1)
class Solution {
    long get(int start, int len) {
        long ans = 0;
        while (len-- > 0) {
            ans = ans * 10 + start;
            ++start;
        }
        return ans;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int len = 0;
        for (int tmp = low; tmp; tmp /= 10) ++len;
        while (len <= 9) {
            for (int i = 1; i <= 9 - len + 1; ++i) {
                long long n = get(i, len);
                if (n < low) continue;
                if (n > high) return ans;
                ans.push_back(n);
            }
            ++len;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sequential-digits/
// Author: github.com/lzl124631x
// Time: O(1) since there are limited number of valid integers
// Space: O(1)
class Solution {
    int next(int n, int increment = 1) {
        int len = log10(n), first = n / pow(10, len) + increment;
        if (first > 9 - len) {
            first = 1;
            ++len;
        }
        int ans = first;
        while (len--) ans = 10 * ans + ++first;
        return ans;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int n = next(low, 0);
        while (n < low) n = next(low);
        for (; n <= high; n = next(n)) {
            ans.push_back(n);
        }
        return ans;
    }
};
```