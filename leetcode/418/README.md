# [418. Sentence Screen Fitting (Medium)](https://leetcode.com/problems/sentence-screen-fitting/)

<p>Given a&nbsp;<code>rows x cols</code> screen and a <code>sentence</code> represented as a list of strings, return <em>the number of&nbsp;times the given sentence can be fitted on the screen</em>.</p>

<p>The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sentence = ["hello","world"], rows = 2, cols = 8
<strong>Output:</strong> 1
<strong>Explanation:</strong>
hello---
world---
The character '-' signifies an empty space on the screen.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sentence = ["a", "bcd", "e"], rows = 3, cols = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong>
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sentence = ["i","had","apple","pie"], rows = 4, cols = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong>
i-had
apple
pie-i
had--
The character '-' signifies an empty space on the screen.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= sentence[i].length &lt;= 10</code></li>
	<li><code>sentence[i]</code> consists of lowercase English letters.</li>
	<li><code>1 &lt;= rows, cols &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Minimum Cost to Separate Sentence Into Rows (Medium)](https://leetcode.com/problems/minimum-cost-to-separate-sentence-into-rows/)

## Solution 1.

Spent a lot of time making the details correct. Need to find easier solution.

```cpp
// OJ: https://leetcode.com/problems/sentence-screen-fitting/
// Author: github.com/lzl124631x
// Time: O(N) where N is the length of `A`
// Space: O(N)
class Solution {
public:
    int wordsTyping(vector<string>& A, int rows, int cols) {
        int N = A.size(), mxSize = 0;
        vector<int> sum(N), cntQueue, rowMap(N, -1);
        for (int i = 0, s = 0; i < N; ++i) {
            s += A[i].size();
            if (i > 0) s += 1;
            sum[i] = s;
            mxSize = max(mxSize, (int)A[i].size());
        }
        int repeat = cols / (sum.back() + 1), cnt = 0;
        cols %= sum.back() + 1;
        int ans = repeat * rows;
        if (mxSize > cols) return ans; 
        for (int i = 0, j = 0; i < rows ; ++i) {
            int sum = A[j].size();
            j = (j + 1) % N;
            cnt += j == 0;
            for (; sum + A[j].size() + 1 <= cols; ) {
                sum += A[j].size() + 1;
                j = (j + 1) % N;
                cnt += j == 0;
            }
            int end = (j - 1 + N) % N;
            if (rowMap[end] == -1) {
                rowMap[end] = i;
                cntQueue.push_back(cnt);
            } else {
                int startRow = rowMap[end];
                int c = cnt - cntQueue[startRow];
                int len = i - startRow;
                int r = (rows - startRow) / len;
                if (startRow > 0) ans += cntQueue[startRow - 1];
                ans += r * c;
                int remain = (rows - startRow) % len;
                if (remain) {
                    ans += cntQueue[startRow + remain - 1] - (startRow > 0 ? cntQueue[startRow - 1] : 0);
                }
                return ans;
            }
        }
        return ans + cnt;
    }
};
```