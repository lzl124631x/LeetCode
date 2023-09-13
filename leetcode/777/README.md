# [777. Swap Adjacent in LR String (Medium)](https://leetcode.com/problems/swap-adjacent-in-lr-string/)

<p>In a string composed of <code>'L'</code>, <code>'R'</code>, and <code>'X'</code> characters, like <code>"RXXLRXRXL"</code>, a move consists of either replacing one occurrence of <code>"XL"</code> with <code>"LX"</code>, or replacing one occurrence of <code>"RX"</code> with <code>"XR"</code>. Given the starting string <code>start</code> and the ending string <code>end</code>, return <code>True</code> if and only if there exists a sequence of moves to transform one string to the other.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> start = "RXXLRXRXL", end = "XRLXXRRLX"
<strong>Output:</strong> True
<strong>Explanation:</strong>
We can transform start to end following these steps:
RXXLRXRXL -&gt;
XRXLRXRXL -&gt;
XRLXRXRXL -&gt;
XRLXXRRXL -&gt;
XRLXXRRLX
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= len(start) = len(end) &lt;= 10000</code>.</li>
	<li>Both start and end will only consist of characters in <code>{'L', 'R', 'X'}</code>.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/swap-adjacent-in-lr-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canTransform(string start, string end) {
        int N = start.size();
        string a = start, b = end;
        a.erase(remove(a.begin(), a.end(), 'X'), a.end());
        b.erase(remove(b.begin(), b.end(), 'X'), b.end());
        if (a != b) return false;
        for (int i = 0, j = 0; i < N; ++i) {
            if (start[i] == 'L') {
                while (end[j] != 'L') ++j;
                if (i < j++) return false;
            }
        }
        for (int i = 0, j = 0; i < N; ++i) {
            if (start[i] == 'R') {
                while (end[j] != 'R') ++j;
                if (i > j++) return false;
            }
        }
        return true;
    }
}; 
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/swap-adjacent-in-lr-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0, N = start.size();
        for (; i < N && j < N; ++i, ++j) {
            while (i < N && start[i] == 'X') ++i;
            while (j < N && end[j] == 'X') ++j;
            if ((i < N) ^ (j < N)) return false;
            if (i < N && j < N) {
                if (start[i] != end[j]
                   || (start[i] == 'L' && i < j)
                   || (start[i] == 'R' && i > j)) return false;
            }
        }
        return true;
    }
};
```