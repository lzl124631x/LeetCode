# [957. Prison Cells After N Days (Medium)](https://leetcode.com/problems/prison-cells-after-n-days/)

<p>There are 8 prison cells in a row, and each cell is either occupied or vacant.</p>

<p>Each day, whether the cell is occupied or vacant changes according to the following rules:</p>

<ul>
	<li>If a cell has two adjacent neighbors that are both occupied or both vacant,&nbsp;then the cell becomes occupied.</li>
	<li>Otherwise, it becomes vacant.</li>
</ul>

<p>(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)</p>

<p>We describe the current state of the prison&nbsp;in the following way:&nbsp;<code>cells[i] == 1</code> if the <code>i</code>-th cell is occupied, else <code>cells[i] == 0</code>.</p>

<p>Given the initial state of the prison, return the state of the prison after <code>N</code> days (and <code>N</code> such changes described above.)</p>

<p>&nbsp;</p>

<div>
<ol>
</ol>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>cells = <span id="example-input-1-1">[0,1,0,1,1,0,0,1]</span>, N = <span id="example-input-1-2">7</span>
<strong>Output: </strong><span id="example-output-1">[0,0,1,1,0,0,0,0]</span>
<strong>Explanation: 
</strong><span id="example-output-1">The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]</span>

</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>cells = <span id="example-input-2-1">[1,0,0,1,0,0,1,0]</span>, N = <span id="example-input-2-2">1000000000</span>
<strong>Output: </strong><span id="example-output-2">[0,0,1,1,1,1,1,0]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>cells.length == 8</code></li>
	<li><code>cells[i]</code> is in <code>{0, 1}</code></li>
	<li><code>1 &lt;= N &lt;= 10^9</code></li>
</ol>
</div>
</div>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

Simulate the process. Once find a cycle, we can get the result from within the cycle.

Since there are at most 256 states, we will get the result at at most 256th day. So the time and space complexity is `O(1)`.

```cpp
// OJ: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    char next(char c) {
        char ans = 0;
        for (int i = 1; i < 7; ++i)
            ans |= ((c >> (i - 1) & 1) == (c >> (i + 1) & 1)) << i;
        return ans;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& A, int N) {
        char c = 0;
        for (int i = 0; i < 8; ++i) c |= A[i] << i;
        vector<char> v{c};
        unordered_map<char, int> m{{c, 0}};
        for (int i = 1; i <= N; ++i) {
            c = next(c);
            if (m.count(c)) {
                int d = i - m[c];
                c = v[(N - i) % d + m[c]];
                break;
            }
            v.push_back(c);
            m[c] = i;
        }
        vector<int> ans(8);
        for (int i = 0; i < 8; ++i) ans[i] = (c >> i) & 1;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    char next(char c) {
        char ans = 0;
        for (int i = 0; i < 8; ++i)
            ans |= (i > 0 && i < 7 && ((c >> (i - 1)) & 1) == ((c >> (i + 1)) & 1)) << i;
        return ans;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& A, int N) {
        char c = 0;
        for (int i = 0; i < 8; ++i) c |= A[i] << i;
        unordered_map<char, int> m{{c, 0}};
        for (int i = 1; i <= N; ++i) {
            c = next(c);
            if (m.count(c)) {
                int d = i - m[c];
                N = (N - i) % d;
                while (N--) c = next(c);
                break;
            }
            m[c] = i;
        }
        vector<int> ans(8);
        for (int i = 0; i < 8; ++i) ans[i] = (c >> i) & 1;
        return ans;
    }
};
```