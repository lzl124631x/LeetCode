# [838. Push Dominoes (Medium)](https://leetcode.com/problems/push-dominoes/)

<p>There are<font face="monospace">&nbsp;<code>N</code></font> dominoes in a line, and we place each domino vertically upright.</p>

<p>In the beginning, we simultaneously push&nbsp;some of the dominoes either to the left or to the right.</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 160px;"></p>

<p>After each second, each domino that is falling to the left pushes the adjacent domino on the left.</p>

<p>Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.</p>

<p>When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.</p>

<p>For the purposes of this question, we will consider that a falling domino&nbsp;expends no additional force to a falling or already fallen domino.</p>

<p>Given a string "S" representing the initial state.&nbsp;<code>S[i] = 'L'</code>, if the i-th domino has been pushed to the left; <code>S[i] = 'R'</code>, if the i-th domino has been pushed to the right; <code>S[i] = '.'</code>,&nbsp;if the <code>i</code>-th domino has not been pushed.</p>

<p>Return a string representing the final state.&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>".L.R...LR..L.."
<strong>Output: </strong>"LL.RR.LLRRLL.."
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"RR.L"
<strong>Output: </strong>"RR.L"
<strong>Explanation: </strong>The first domino expends no additional force on the second domino.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= N&nbsp;&lt;= 10^5</code></li>
	<li>String&nbsp;<code>dominoes</code> contains only&nbsp;<code>'L</code>', <code>'R'</code> and <code>'.'</code></li>
</ol>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/push-dominoes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string pushDominoes(string s) {
        int N = s.size();
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            if (s[i] == 'L') {
                for (int j = i - 1; j >= 0 && s[j] != 'L'; --j) {
                    if (s[j] == 'R' && v[j] <= i - j) {
                        if (v[j] == i - j) s[j] = '.';
                        break;
                    }
                    s[j] = 'L';
                    v[j] = i - j;
                }
            } else if (s[i] == 'R') {
                if (v[i] != 0) continue;
                for (int j = i + 1; j < N && s[j] == '.'; ++j) {
                    s[j] = 'R';
                    v[j] = j - i;
                }
            }
        }
        return s;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/push-dominoes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string pushDominoes(string s) {
        int N = s.size(), right = -1;
        for (int i = 0; i < N; ++i) {
            if (s[i] == 'L') {
                if (right == -1) {
                    for (int j = i - 1; j >= 0 && s[j] == '.'; --j) s[j] = 'L';
                } else {
                    for (int j = right + 1, k = i - 1; j < k; ++j, --k) s[j] = 'R', s[k] = 'L';
                    right = -1;
                }
            } else if (s[i] == 'R') {
                if (right != -1) {
                    for (int j = right + 1; j < i; ++j) s[j] = 'R';
                }
                right = i;
            }
        }
        if (right != -1) {
            for (int j = right + 1; j < N; ++j) s[j] = 'R';
        }
        return s;
    }
};
```