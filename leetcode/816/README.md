# [816. Ambiguous Coordinates (Medium)](https://leetcode.com/problems/ambiguous-coordinates/)

<p>We had some 2-dimensional coordinates, like <code>"(1, 3)"</code> or <code>"(2, 0.5)"</code>.&nbsp; Then, we removed&nbsp;all commas, decimal points, and spaces, and ended up with the string&nbsp;<code>S</code>.&nbsp; Return a list of strings representing&nbsp;all possibilities for what our original coordinates could have been.</p>

<p>Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with&nbsp;less digits.&nbsp; Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".</p>

<p>The final answer list can be returned in any order.&nbsp; Also note that all coordinates in the final answer&nbsp;have exactly one space between them (occurring after the comma.)</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> "(123)"
<strong>Output:</strong> ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
</pre>

<pre><strong>Example 2:</strong>
<strong>Input:</strong> "(00011)"
<strong>Output:</strong> &nbsp;["(0.001, 1)", "(0, 0.011)"]
<strong>Explanation:</strong> 
0.0, 00, 0001 or 00.01 are not allowed.
</pre>

<pre><strong>Example 3:</strong>
<strong>Input:</strong> "(0123)"
<strong>Output:</strong> ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
</pre>

<pre><strong>Example 4:</strong>
<strong>Input:</strong> "(100)"
<strong>Output:</strong> [(10, 0)]
<strong>Explanation:</strong> 
1.0 is not allowed.
</pre>

<p>&nbsp;</p>

<p><strong>Note: </strong></p>

<ul>
	<li><code>4 &lt;= S.length &lt;= 12</code>.</li>
	<li><code>S[0]</code> = "(", <code>S[S.length - 1]</code> = ")", and the other elements in <code>S</code> are digits.</li>
</ul>

<p>&nbsp;</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

### Complexity Analysis

We need to loop `O(N)` time to find the split points.

For each split point, we call `getNumbers` to generate a list of possible numbers for the first and second parts.

Each `getNumbers` takes `O(N)` time and `O(N)` space, and could generate a list of `O(N)` elements.

Lastly, we concatenate the numbers which will take `O(N^2)` time.

So, overall this solution takes `O(N^3)` time and `O(N)` space.

```cpp
// OJ: https://leetcode.com/problems/ambiguous-coordinates/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N)
class Solution {
    vector<string> getNumbers(string s) {
        if (s[0] == '0') {
            if (s.size() == 1) return { s };
            if (s.back() == '0') return {};
            s.insert(begin(s) + 1, '.');
            return { s };
        }
        if (s.back() == '0') return { s };
        vector<string> ans;
        ans.push_back(s);
        for (int i = 1; i <= s.size() - 1; ++i) {
            auto tmp = s;
            tmp.insert(begin(tmp) + i, '.');
            ans.push_back(tmp);
        }
        return ans;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        for (int i = 2, N = s.size(); i < N - 1; ++i) {
            auto first = getNumbers(s.substr(1, i - 1));
            if (first.empty()) continue;
            auto second = getNumbers(s.substr(i, N - 1 - i));
            if (second.empty()) continue;
            for (auto &a : first) {
                for (auto &b : second) {
                    ans.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return ans;
    }
};
```