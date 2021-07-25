See my latest update in repo [LeetCode](https://github.com/lzl124631x/LeetCode)

# [1947. Maximum Compatibility Score Sum (Medium)](https://leetcode.com/problems/maximum-compatibility-score-sum/)

<p>There is a survey that consists of <code>n</code> questions where each question's answer is either <code>0</code> (no) or <code>1</code> (yes).</p>

<p>The survey was given to <code>m</code> students numbered from <code>0</code> to <code>m - 1</code> and <code>m</code> mentors numbered from <code>0</code> to <code>m - 1</code>. The answers of the students are represented by a 2D integer array <code>students</code> where <code>students[i]</code> is an integer array that contains the answers of the <code>i<sup>th</sup></code> student (<strong>0-indexed</strong>). The answers of the mentors are represented by a 2D integer array <code>mentors</code> where <code>mentors[j]</code> is an integer array that contains the answers of the <code>j<sup>th</sup></code> mentor (<strong>0-indexed</strong>).</p>

<p>Each student will be assigned to <strong>one</strong> mentor, and each mentor will have <strong>one</strong> student assigned to them. The <strong>compatibility score</strong> of a student-mentor pair is the number of answers that are the same for both the student and the mentor.</p>

<ul>
	<li>For example, if the student's answers were <code>[1, <u>0</u>, <u>1</u>]</code> and the mentor's answers were <code>[0, <u>0</u>, <u>1</u>]</code>, then their compatibility score is 2 because only the second and the third answers are the same.</li>
</ul>

<p>You are tasked with finding the optimal student-mentor pairings to <strong>maximize</strong> the<strong> sum of the compatibility scores</strong>.</p>

<p>Given <code>students</code> and <code>mentors</code>, return <em>the <strong>maximum compatibility score sum</strong> that can be achieved.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
<strong>Output:</strong> 8
<strong>Explanation:</strong>&nbsp;We assign students to mentors in the following way:
- student 0 to mentor 2 with a compatibility score of 3.
- student 1 to mentor 0 with a compatibility score of 2.
- student 2 to mentor 1 with a compatibility score of 3.
The compatibility score sum is 3 + 2 + 3 = 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The compatibility score of any student-mentor pair is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == students.length == mentors.length</code></li>
	<li><code>n == students[i].length == mentors[j].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 8</code></li>
	<li><code>students[i][k]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>mentors[j][k]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


## Solution 1. Brute Force (DFS)

The brute force solution is generating all the permuntations of the mentors and calculate the score of this permutation and the students.

There are `M!` permutations and calculating the score takes `O(N)` time, so the overall time complexity is `O(M! * N)`.

Since `M` and `N` are at most `8` and `8! * 8 = 322,560`, such solution should be able to pass.

```cpp
// OJ: https://leetcode.com/problems/maximum-compatibility-score-sum/
// Author: github.com/lzl124631x
// Time: O(M! * N)
// Space: O(N)
class Solution {
    int used[9] = {}, ans = 0, m, n;
    void dfs(vector<vector<int>>& S, vector<vector<int>>& M, int i, int score) {
        if (i == m) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (used[j]) continue;
            used[j] = 1;
            int s = 0;
            for (int k = 0; k < n; ++k) s += S[i][k] == M[j][k]; // calculate the compatibility score of student `i` and mentor `j`.
            dfs(S, M, i + 1, score + s);
            used[j] = 0;
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& S, vector<vector<int>>& M) {
        m = S.size(), n = S[0].size();
        dfs(S, M, 0, 0);
        return ans;
    }
};
```