# [2168. Unique Substrings With Equal Digit Frequency (Medium)](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/)

Given a digit string <code>s</code>, return <em>the number of <strong>unique substrings </strong>of </em><code>s</code><em> where every digit appears the same number of times.</em>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1212"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The substrings that meet the requirements are "1", "2", "12", "21", "1212".
Note that although the substring "12" appears twice, it is only counted once.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "12321"
<strong>Output:</strong> 9
<strong>Explanation:</strong> The substrings that meet the requirements are "1", "2", "3", "12", "23", "32", "21", "123", "321".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of digits.</li>
</ul>


**Companies**:  
[Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Counting](https://leetcode.com/tag/counting/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Number of Equal Count Substrings (Medium)](https://leetcode.com/problems/number-of-equal-count-substrings/)
* [Substrings That Begin and End With the Same Letter (Medium)](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int equalDigitFrequency(string s) {
        int N = s.size();
        unordered_set<string> ans;
        for (int i = 0; i < N; ++i) {
            int cnt[10] = {};
            for (int j = i; j < N; ++j) {
                cnt[s[j] - '0']++;
                int k = 0, c = -1;
                for (; k < 10; ++k) {
                    if (cnt[k] == 0) continue;
                    if (c == -1) c = cnt[k];
                    if (cnt[k] != c) break;
                }
                if (k == 10) ans.insert(s.substr(i, j - i + 1));
            }
        }
        return ans.size();
    }
};
```

## Solution 2. Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int equalDigitFrequency(string s) {
        unordered_set<int> ans;
        for (int i = 0, N = s.size(); i < N; ++i) {
            long long cnt[11] = {}, unique = 0, mxCnt = 0, hash = 0;
            for (int j = i; j < N; ++j) {
                int d = s[j] - '0';
                mxCnt = max(mxCnt, ++cnt[d]);
                unique += cnt[d] == 1;
                hash = (hash * 11 + d + 1) % 1000000007;
                if (mxCnt * unique == j - i + 1) ans.insert(hash);
            }
        }
        return ans.size();
    }
};
```