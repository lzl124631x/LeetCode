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

Simulate the process. Once find cycle, reduce the remaining `k` steps to `k % d` where `d` is the length of cycle.

```cpp
// OJ: https://leetcode.com/problems/prison-cells-after-n-days/
// Author: github.com/lzl124631x
// Time: O(2^N) where N is the length of cells.
// Space: O(2^N)
class Solution {
private:
    char getNext(char c) {
        char next = 0;
        for (int j = 1; j < 7; ++j) {
            next |= ((c >> (j - 1) & 1) == (c >> (j + 1) & 1) ? 1 : 0) << j;
        }
        return next;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        char c = 0;
        for (int i = 0; i < 8; ++i) {
            c |= cells[i] << i;
        }
        unordered_map<char, int> m;
        int dist = -1, from = -1;
        for (int i = 1; i <= N; ++i) {
            c = getNext(c);
            if (m.find(c) != m.end()) {
                dist = i - m[c];
                from = i;
                break;
            }
            m[c] = i;
        }
        if (dist != -1) {
            int d = (N - from) % dist;
            for (int i = 0; i < d; ++i) c = getNext(c);
        }
        vector<int> ans;
        for (int i = 0; i < 8; ++i) ans.push_back((c >> i) & 1);
        return ans;
    }
};
```