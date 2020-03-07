# [1079. Letter Tile Possibilities (Medium)](https://leetcode.com/problems/letter-tile-possibilities/)

<p>You have a set of <code>tiles</code>, where each tile has one letter <code>tiles[i]</code> printed on it.&nbsp; Return the number of possible non-empty sequences of letters you can make.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"AAB"</span>
<strong>Output: </strong><span id="example-output-1">8</span>
<strong>Explanation: </strong>The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"AAABBC"</span>
<strong>Output: </strong><span id="example-output-2">188</span>
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= tiles.length &lt;= 7</code></li>
	<li><code>tiles</code> consists of uppercase English letters.</li>
</ol>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/letter-tile-possibilities/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
    int ans = 0, cnts[26] = {};
    long long count(int n) {
        long long val = 1;
        for (int i = 1; i <= n; ++i) val *= i;
        return val;
    }
    void updateAns() {
        long long total = 0, div = 1;
        for (int i = 0; i < 26; ++i) {
            total += cnts[i];
            div *= count(cnts[i]);
        }
        ans += count(total) / div;
    }
    void compute(string &A, int begin) {
        if (begin == A.size()) {
            updateAns();
            return;
        }
        cnts[A[begin] - 'A']++;
        compute(A, begin + 1);
        cnts[A[begin] - 'A']--;
        do { ++begin; } while (begin < A.size() && A[begin] == A[begin - 1]);
        compute(A, begin);
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        compute(tiles, 0);
        return ans - 1;
    }
};
```