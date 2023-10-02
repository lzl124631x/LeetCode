# [838. Push Dominoes (Medium)](https://leetcode.com/problems/push-dominoes/)

<p>There are <code>n</code> dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.</p>

<p>After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.</p>

<p>When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.</p>

<p>For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.</p>

<p>You are given a string <code>dominoes</code> representing the initial state where:</p>

<ul>
	<li><code>dominoes[i] = 'L'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the left,</li>
	<li><code>dominoes[i] = 'R'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the right, and</li>
	<li><code>dominoes[i] = '.'</code>, if the <code>i<sup>th</sup></code> domino has not been pushed.</li>
</ul>

<p>Return <em>a string representing the final state</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> dominoes = "RR.L"
<strong>Output:</strong> "RR.L"
<strong>Explanation:</strong> The first domino expends no additional force on the second domino.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 196px; width: 512px;">
<pre><strong>Input:</strong> dominoes = ".L.R...LR..L.."
<strong>Output:</strong> "LL.RR.LLRRLL.."
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == dominoes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>dominoes[i]</code> is either <code>'L'</code>, <code>'R'</code>, or <code>'.'</code>.</li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

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

Or

```cpp
// OJ: https://leetcode.com/problems/push-dominoes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string pushDominoes(string s) {
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '.') continue;
            if (s[i] == 'L') {
                int j = i - 1;
                while (j >= 0 && s[j] == '.') s[j--] = 'L';
            } else {
                int j = i + 1;
                while (j < N && s[j] == '.') ++j;
                if (j == N || s[j] == 'R') {
                    ++i;
                    while (i < j) s[i++] = 'R';
                    --i;
                } else {
                    int p = i + 1, q = j - 1;
                    while (p < q) {
                        s[p++] = 'R';
                        s[q--] = 'L';
                    }
                    i = j;
                }
            }
        }
        return s;
    }
};
```