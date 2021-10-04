# [2019. The Score of Students Solving Math Expression (Hard)](https://leetcode.com/problems/the-score-of-students-solving-math-expression/)

<p>You are given a string <code>s</code> that contains digits <code>0-9</code>, addition symbols <code>'+'</code>, and multiplication symbols <code>'*'</code> <strong>only</strong>, representing a <strong>valid</strong> math expression of <strong>single digit numbers</strong> (e.g., <code>3+5*2</code>). This expression was given to <code>n</code> elementary school students. The students were instructed to get the answer of the expression by following this <strong>order of operations</strong>:</p>

<ol>
	<li>Compute <strong>multiplication</strong>, reading from <strong>left to right</strong>; Then,</li>
	<li>Compute <strong>addition</strong>, reading from <strong>left to right</strong>.</li>
</ol>

<p>You are given an integer array <code>answers</code> of length <code>n</code>, which are the submitted answers of the students in no particular order. You are asked to grade the <code>answers</code>, by following these <strong>rules</strong>:</p>

<ul>
	<li>If an answer <strong>equals</strong> the correct answer of the expression, this student will be rewarded <code>5</code> points;</li>
	<li>Otherwise, if the answer <strong>could be interpreted</strong> as if the student used the <strong>incorrect order of operations</strong>, <strong>once</strong> or <strong>multiple</strong> times, this student will be rewarded <code>2</code> points;</li>
	<li>Otherwise, this student will be rewarded <code>0</code> points.</li>
</ul>

<p>Return <em>the sum of the points of the students</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/17/student_solving_math.png" style="width: 678px; height: 109px;">
<pre><strong>Input:</strong> s = "7+3*1*2", answers = [20,13,42]
<strong>Output:</strong> 7
<strong>Explanation:</strong> As illustrated above, the correct answer of the expression is 13, therefore one student is rewarded 5 points: [20,<u><strong>13</strong></u>,42]
A student might have used this incorrect order of operations: 7+3=10, 10*1=10, 10*2=20. Therefore one student is rewarded 2 points: [<u><strong>20</strong></u>,13,42]
The points for the students are: [2,5,0]. The sum of the points is 2+5+0=7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "3+5*2", answers = [13,0,10,13,13,16,16]
<strong>Output:</strong> 19
<strong>Explanation:</strong> The correct answer of the expression is 13, therefore three students are rewarded 5 points each: [<strong><u>13</u></strong>,0,10,<strong><u>13</u></strong>,<strong><u>13</u></strong>,16,16]
A student might have used this incorrect order of operations: 3+5=8, 8*2=16. Therefore two students are rewarded 2 points: [13,0,10,13,13,<strong><u>16</u></strong>,<strong><u>16</u></strong>]
The points for the students are: [5,0,0,5,5,2,2]. The sum of the points is 5+0+0+5+5+2+2=19.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "6+0*1", answers = [12,9,6,4,8,6]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The correct answer of the expression is 6.
If a student had used some incorrect order of operations, the answer would also be 6.
By the rules of grading, the students will still be rewarded 5 points (as they got the correct answer), not 2 points.
The points for the students are: [0,0,5,0,0,5]. The sum of the points is 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 31</code></li>
	<li><code>s</code> represents a valid expression that contains only digits <code>0-9</code>, <code>'+'</code>, and <code>'*'</code> only.</li>
	<li>All the integer operands in the expression are in the <strong>inclusive</strong> range <code>[0, 9]</code>.</li>
	<li><code>1 &lt;=</code> The count of all operators (<code>'+'</code> and <code>'*'</code>) in the math expression <code>&lt;= 15</code></li>
	<li>Test data are generated such that the correct answer of the expression is in the range of <code>[0, 1000]</code>.</li>
	<li><code>n == answers.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= answers[i] &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Basic Calculator (Hard)](https://leetcode.com/problems/basic-calculator/)
* [Different Ways to Add Parentheses (Medium)](https://leetcode.com/problems/different-ways-to-add-parentheses/)

## Solution 1. DP

Let `dp[i][j]` be the possible values the students can get using `s[i..j]`.

```
dp[i][i] = { s[i] - '0' }
```

For `dp[i][j]`, we enumerate all the indexes `k` of the operators between `i` and `j`. Let `a` and `b` be elements in `dp[i][k-1]` and `dp[k+1][j]`.
* If `s[k] == '+'`, we insert `a + b` into `dp[i][j]`
* If `s[k] == '*'`, we insert `a * b` into `dp[i][j]` 

Bottom-up DP:
```cpp
// OJ: https://leetcode.com/problems/the-score-of-students-solving-math-expression/
// Author: github.com/lzl124631x
// Time: O(N^3 * 1000^2)
// Space: O(N^2 * 1000)
class Solution {
public:
    int eval(string &s, int first, int last) {
        if (first == last) return s[first] - '0';
        int i = first + 1;
        for (; i <= last && s[i] == '*'; i += 2); // find the first '+'
        if (i <= last) return eval(s, first, i - 1) + eval(s, i + 1, last); // calculate the first '+'
        int ans = 1;
        for (int i = first; i <= last; i += 2) ans *= s[i] - '0';
        return ans; // If there is no `+`, calculate all the `*`s
    }
    int scoreOfStudents(string s, vector<int>& A) {
        int ans = 0, N = s.size(), correct = eval(s, 0, N - 1);
        unordered_set<long long> dp[32][32];
        for (int i = 0; i < N; i += 2) dp[i][i].insert(s[i] - '0');
        for (int i = N - 3; i >= 0; i -= 2) {
            for (int j = i + 2; j < N; j += 2){
                for (int k = i + 1; k < j; k += 2) { // For s[i..j], enumerate every operators' indexes `k`
                    for (auto a : dp[i][k - 1]) {
                        for (auto b : dp[k + 1][j]) {
                            int val = s[k] == '+' ? a + b : a * b;
                            if (val <= 1000) dp[i][j].insert(val);
                        }
                    }
                }
            }
        }
        for (int n : A) {
            if (n == correct) ans += 5;
            else if (dp[0][N - 1].count(n)) ans += 2;
        }
        return ans;
    }
};
```

Or Top-down DP:

```cpp
// OJ: https://leetcode.com/problems/the-score-of-students-solving-math-expression/
// Author: github.com/lzl124631x
// Time: O(N^3 * 1000^2)
// Space: O(N^2 * 1000)
class Solution {
    int eval(string &s, int first, int last) {
        if (first == last) return s[first] - '0';
        auto it = find(begin(s) + first, begin(s) + last + 1, '+');
        if (it == begin(s) + last + 1) {
            int ans = 1;
            for (int j = first; j <= last; j += 2) ans *= s[j] - '0';
            return ans;
        }
        return eval(s, first, it - begin(s) - 1) + eval(s, it - begin(s) + 1, last);
    }
    unordered_set<int> m[32][32] = {};
    unordered_set<int> *dp(string &s, int first, int last) {
        if (m[first][last].size()) return &m[first][last];
        for (int i = first + 1; i < last; i += 2) {
            for (int a : *dp(s, first, i - 1)) {
                for (int b : *dp(s, i + 1, last)) {
                    int val = s[i] == '+' ? a + b : a * b;
                    if (val <= 1000) m[first][last].insert(val);
                }
            }
        }
        return &m[first][last];
    }
public:
    int scoreOfStudents(string s, vector<int>& A) {
        int correct = eval(s, 0, s.size() - 1), ans = 0;
        for (int i = 0; i < s.size(); i += 2) m[i][i].insert(s[i] - '0');
        auto all = dp(s, 0, s.size() - 1);
        for (int n : A) {
            if (n == correct) ans += 5;
            else if (all->count(n)) ans += 2;
        }
        return ans;
    }
};
```