# [630. Course Schedule III (Hard)](https://leetcode.com/problems/course-schedule-iii/)

<p>There are <code>n</code> different online courses numbered from <code>1</code> to <code>n</code>. You are given an array <code>courses</code> where <code>courses[i] = [duration<sub>i</sub>, lastDay<sub>i</sub>]</code> indicate that the <code>i<sup>th</sup></code> course should be taken <b>continuously</b> for <code>duration<sub>i</sub></code> days and must be finished before or on <code>lastDay<sub>i</sub></code>.</p>

<p>You will start on the <code>1<sup>st</sup></code> day and you cannot take two or more courses simultaneously.</p>

<p>Return <em>the maximum number of courses that you can take</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
<strong>Output:</strong> 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1<sup>st</sup> course, it costs 100 days so you will finish it on the 100<sup>th</sup> day, and ready to take the next course on the 101<sup>st</sup> day.
Second, take the 3<sup>rd</sup> course, it costs 1000 days so you will finish it on the 1100<sup>th</sup> day, and ready to take the next course on the 1101<sup>st</sup> day. 
Third, take the 2<sup>nd</sup> course, it costs 200 days so you will finish it on the 1300<sup>th</sup> day. 
The 4<sup>th</sup> course cannot be taken now, since you will finish it on the 3300<sup>th</sup> day, which exceeds the closed date.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> courses = [[1,2]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> courses = [[3,2],[4,3]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= courses.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= duration<sub>i</sub>, lastDay<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)

## TLE Version: DP

```cpp
// OJ: https://leetcode.com/problems/course-schedule-iii/
// Author: github.com/lzl124631x
// Time: O(NT)
// Space: O(NT)
class Solution {
    vector<vector<int>> memo;
    int dp(vector<vector<int>> &A, int i, int time) {
        if (i == A.size()) return 0;
        if (memo[i][time] != -1) return memo[i][time];
        int pick = 0;
        if (time + A[i][0] <= A[i][1]) pick = 1 + dp(A, i + 1, time + A[i][0]);
        int skip = dp(A, i + 1, time);
        return memo[i][time] = max(pick, skip);
    }
public:
    int scheduleCourse(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        memo.assign(A.size(), vector<int>(A.back()[1] + 1, -1));
        return dp(A, 0, 0);
    }
};
```

## Solution 1. Regret Greedy (反悔贪心)

1. We should greedily take the courses whose deadline is earlier.
2. If taking a course won't meet its deadline, what we can try is swapping this course with the longest course we've taken that is longer than the current course. In this way, we won't reduce the number of courses we've taken, but at the same time we reduced the total time we used to take courses. That is, this approach

Example: We have 3 courses, `[[2,3],[4,6],[3,7]]`

* Taking the first course is fine. We spent `2` days and the current deadline is `3`.
* Taking the second course is fine. We spent `2 + 4 = 6` days and the current deadline is `6`.
* We can't the third course additionally because it costs `2 + 4 + 3 = 9` days in total but the deadline is `7`. What we can do is swapping the 2nd and 3rd courses, so we spent `2 + 3 = 5` days in total and the dealine is `7`.

```cpp
// OJ: https://leetcode.com/problems/course-schedule-iii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1]; });
        map<int, int> m;
        int time = 1, ans = 0;
        for (auto &v : A) {
            int duration = v[0], last = v[1];
            if (time + duration - 1 <= last) { // if we can take the current course, take it.
                ++ans;
                time += duration;
                m[duration]++;
            } else if (m.size()) { // if we can't this course, we try swapping this course we've taken previously
                int d = m.rbegin()->first; // use the longest course for swapping
                if (d > duration) { // the course to be swapped must cost longer time than the current one.
                    if (--m[d] == 0) m.erase(d);
                    time += duration - d;
                    m[duration]++;
                }
            }
        }
        return ans;
    }
};
```