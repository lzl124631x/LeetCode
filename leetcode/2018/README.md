# [2018. Check if Word Can Be Placed In Crossword (Medium)](https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/)

<p>You are given an <code>m x n</code> matrix <code>board</code>, representing the<strong> current </strong>state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), <code>' '</code> to represent any <strong>empty </strong>cells, and <code>'#'</code> to represent any <strong>blocked</strong> cells.</p>

<p>A word can be placed<strong> horizontally</strong> (left to right <strong>or</strong> right to left) or <strong>vertically</strong> (top to bottom <strong>or</strong> bottom to top) in the board if:</p>

<ul>
	<li>It does not occupy a cell containing the character <code>'#'</code>.</li>
	<li>The cell each letter is placed in must either be <code>' '</code> (empty) or <strong>match</strong> the letter already on the <code>board</code>.</li>
	<li>There must not be any empty cells <code>' '</code> or other lowercase letters <strong>directly left or right</strong><strong> </strong>of the word if the word was placed <strong>horizontally</strong>.</li>
	<li>There must not be any empty cells <code>' '</code> or other lowercase letters <strong>directly above or below</strong> the word if the word was placed <strong>vertically</strong>.</li>
</ul>

<p>Given a string <code>word</code>, return <code>true</code><em> if </em><code>word</code><em> can be placed in </em><code>board</code><em>, or </em><code>false</code><em> <strong>otherwise</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/18/crossword-1.png" style="width: 170px; height: 150px;">
<pre><strong>Input:</strong> board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
<strong>Output:</strong> true
<strong>Explanation:</strong> The word "abc" can be placed as shown above (top to bottom).
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/18/c2.png" style="width: 170px; height: 151px;">
<pre><strong>Input:</strong> board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to place the word because there will always be a space/letter above or below it.</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/18/crossword-2.png" style="width: 171px; height: 146px;">
<pre><strong>Input:</strong> board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
<strong>Output:</strong> true
<strong>Explanation:</strong> The word "ca" can be placed as shown above (right to left). 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>board[i][j]</code> will be <code>' '</code>, <code>'#'</code>, or a lowercase English letter.</li>
	<li><code>1 &lt;= word.length &lt;= max(m, n)</code></li>
	<li><code>word</code> will contain only lowercase English letters.</li>
</ul>


## Solution 1. Brute Force

Implement a function `match(A, s)`  which returns `true` if matrix `A` matches word `s` horizontally. To handle the vertical case, we can simply use `B` as the transpose of `A`, and check `match(B, s)`.

Within `match` function, we check line by line. For each line, we scan each segment surrounded by `#`s or line boundaries. For each segment, we check if it equals string `s` from left to right, or from right to left.

The time complexity is `O(MN)` because each cell is matched at most 4 times.

```cpp
// OJ: https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
    bool same(vector<char> &A, int first, int last, string &s) { // returns true if `A[first..last]` equals `s` or reversed `s`.
        if (last - first + 1 != s.size()) return false;
        int i = 0, N = s.size();
        while (i < N && (A[first + i] == ' ' || A[first + i] == s[i])) ++i; // match from left to right
        if (i == N) return true;
        for (i = 0; i < N && (A[last - i] == ' ' || A[last - i] == s[i]);) ++i; // match from right to left
        return i == N;
    }
    bool match(vector<vector<char>> &A, string s) { // returns `true` if matrix `A` matches string `s` horizontally
        int N = A[0].size();
        for (auto &row : A) {
            for (int i = 0; i < N; ) {
                while (i < N && row[i] == '#') ++i;
                int start = i;
                while (i < N && row[i] != '#') ++i;
                if (same(row, start, i - 1, s)) return true; // match `row[start..(i-1)]` with `s`.
            }
        }
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& A, string s) {
        int M = A.size(), N = A[0].size();
        vector<vector<char>> B(N, vector<char>(M)); // `B` is the transpose of `A`
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++ j) {
                B[j][i] = A[i][j];
            }
        }
        return match(A, s) || match(B, s);
    }
};
```