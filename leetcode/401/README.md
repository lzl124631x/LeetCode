# [401. Binary Watch (Easy)](https://leetcode.com/problems/binary-watch)

<p>A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent&nbsp;the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.</p>

<ul>
	<li>For example, the below binary watch reads <code>&quot;4:51&quot;</code>.</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/binarywatch.jpg" style="width: 500px; height: 500px;" /></p>

<p>Given an integer <code>turnedOn</code> which represents the number of LEDs that are currently on (ignoring the PM), return <em>all possible times the watch could represent</em>. You may return the answer in <strong>any order</strong>.</p>

<p>The hour must not contain a leading zero.</p>

<ul>
	<li>For example, <code>&quot;01:00&quot;</code> is not valid. It should be <code>&quot;1:00&quot;</code>.</li>
</ul>

<p>The minute must&nbsp;consist of two digits and may contain a leading zero.</p>

<ul>
	<li>For example, <code>&quot;10:2&quot;</code> is not valid. It should be <code>&quot;10:02&quot;</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> turnedOn = 1
<strong>Output:</strong> ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> turnedOn = 9
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= turnedOn &lt;= 10</code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation)

**Similar Questions**:
* [Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number)
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits)

**Hints**:
* Simplify by seeking for solutions that involve comparing bit counts.
* Consider calculating all possible times for comparison purposes.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-watch
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        int h = 0, m = 0;
        function<void(int, int)> dfs = [&](int i, int len) {
            if (len == 0) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
            if (i > 10) return;
            for (int j = i; j < 10; ++j) {
                int dh = 0, dm = 0;
                if (j < 4) dh += (1 << j);
                else dm += (1 << (j - 4));
                h += dh;
                m += dm;
                if (h < 12 && m < 60) dfs(j + 1, len - 1);
                h -= dh;
                m -= dm;
            }
        };
        dfs(0, turnedOn);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/binary-watch
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    vector<string> ans;
    bool valid(int bits) { return (bits >> 6) < 12 && (bits & ((1 << 6) - 1)) < 60; }
    void read(int bits) {
        int h = bits >> 6, m = bits - (h << 6);
        ans.push_back(to_string(h) + ':' + string(m < 10 ? 1 : 0, '0') + to_string(m));
    }
    void dfs(int num, int start, int bits) {
        if (!num) {
            read(bits);
            return;
        }
        for (int i = start; i < 10; ++i) {
            bits |= 1 << i;
            if (valid(bits)) dfs(num - 1, i + 1, bits);
            bits ^= 1 << i;
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        dfs(num, 0, 0);
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/binary-watch
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/59401/straight-forward-6-line-c-solution-no-need-to-explain
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h)
            for (int m = 0; m < 60; ++m)
                if (bitset<10>(h << 6 | m).count() == num)
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return ans;
    }
};
```