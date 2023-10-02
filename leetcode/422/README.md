# [422. Valid Word Square (Easy)](https://leetcode.com/problems/valid-word-square/)

<p>Given a sequence of words, check whether it forms a valid word square.</p>

<p>A sequence of words forms a valid word square if the <i>k</i><sup>th</sup> row and column read the exact same string, where 0 ≤ <i>k</i> &lt; max(numRows, numColumns).</p>

<p><b>Note:</b><br>
</p><ol>
<li>The number of words given is at least 1 and does not exceed 500.</li>
<li>Word length will be at least 1 and does not exceed 500.</li>
<li>Each word contains only lowercase English alphabet <code>a-z</code>.</li>
</ol>
<p></p>

<p><b>Example 1:</b>
</p><pre><b>Input:</b>
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

<b>Output:</b>
true

<b>Explanation:</b>
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b>
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]

<b>Output:</b>
true

<b>Explanation:</b>
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".

Therefore, it is a valid word square.
</pre>
<p></p>

<p><b>Example 3:</b>
</p><pre><b>Input:</b>
[
  "ball",
  "area",
  "read",
  "lady"
]

<b>Output:</b>
false

<b>Explanation:</b>
The third row reads "read" while the third column reads "lead".

Therefore, it is <b>NOT</b> a valid word square.
</pre>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Similar Questions**:
* [Word Squares (Hard)](https://leetcode.com/problems/word-squares/)
* [Toeplitz Matrix (Easy)](https://leetcode.com/problems/toeplitz-matrix/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-word-square/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0, M = words.size(); i < M; ++i) {
            for (int j = 0, N = words[i].size(); j < N; ++j) {
                if (j >= M || i >= words[j].size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};
```