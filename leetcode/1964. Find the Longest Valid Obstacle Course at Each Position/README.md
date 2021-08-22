# [1964. Find the Longest Valid Obstacle Course at Each Position (Hard)](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)

<p>You want to build some obstacle courses. You are given a <strong>0-indexed</strong> integer array <code>obstacles</code> of length <code>n</code>, where <code>obstacles[i]</code> describes the height of the <code>i<sup>th</sup></code> obstacle.</p>

<p>For every index <code>i</code> between <code>0</code> and <code>n - 1</code> (<strong>inclusive</strong>), find the length of the <strong>longest obstacle course</strong> in <code>obstacles</code> such that:</p>

<ul>
	<li>You choose any number of obstacles between <code>0</code> and <code>i</code> <strong>inclusive</strong>.</li>
	<li>You must include the <code>i<sup>th</sup></code> obstacle in the course.</li>
	<li>You must put the chosen obstacles in the <strong>same order</strong> as they appear in <code>obstacles</code>.</li>
	<li>Every obstacle (except the first) is <strong>taller</strong> than or the <strong>same height</strong> as the obstacle immediately before it.</li>
</ul>

<p>Return <em>an array</em> <code>ans</code> <em>of length</em> <code>n</code>, <em>where</em> <code>ans[i]</code> <em>is the length of the <strong>longest obstacle course</strong> for index</em> <code>i</code><em> as described above</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> obstacles = [1,2,3,2]
<strong>Output:</strong> [1,2,3,3]
<strong>Explanation:</strong> The longest valid obstacle course at each position is:
- i = 0: [<u>1</u>], [1] has length 1.
- i = 1: [<u>1</u>,<u>2</u>], [1,2] has length 2.
- i = 2: [<u>1</u>,<u>2</u>,<u>3</u>], [1,2,3] has length 3.
- i = 3: [<u>1</u>,<u>2</u>,3,<u>2</u>], [1,2,2] has length 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> obstacles = [2,2,1]
<strong>Output:</strong> [1,2,1]
<strong>Explanation: </strong>The longest valid obstacle course at each position is:
- i = 0: [<u>2</u>], [2] has length 1.
- i = 1: [<u>2</u>,<u>2</u>], [2,2] has length 2.
- i = 2: [2,2,<u>1</u>], [1] has length 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> obstacles = [3,1,5,6,4,2]
<strong>Output:</strong> [1,1,2,3,2,2]
<strong>Explanation:</strong> The longest valid obstacle course at each position is:
- i = 0: [<u>3</u>], [3] has length 1.
- i = 1: [3,<u>1</u>], [1] has length 1.
- i = 2: [<u>3</u>,1,<u>5</u>], [3,5] has length 2. [1,5] is also valid.
- i = 3: [<u>3</u>,1,<u>5</u>,<u>6</u>], [3,5,6] has length 3. [1,5,6] is also valid.
- i = 4: [<u>3</u>,1,5,6,<u>4</u>], [3,4] has length 2. [1,4] is also valid.
- i = 5: [3,<u>1</u>,5,6,4,<u>2</u>], [1,2] has length 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == obstacles.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= obstacles[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

## Solution 1. Binary Search (Regret Greedy)

**Intuition**: A classic extension of [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/) whose optimal solution is regret greedy + binary search. You can find the explanation in [my note](https://github.com/lzl124631x/LeetCode/tree/master/leetcode/300.%20Longest%20Increasing%20Subsequence)

**Algorithm**:

Assume we have a `vector<int> lis` which stands for the longest increasing subsequence. `lis` is initially empty and is always sorting in ascending order.

For each `A[i]`, we find the first `lis[j] > A[i]` by binary searching in the **entire** `lis`, and set `lis[j] = A[i]`. The length of the LIS ending with `A[i]` is `j + 1`, i.e. `ans[i] = j + 1`.

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> ans, lis;
        for (int n : A) {
            int i = upper_bound(begin(lis), end(lis), n) - begin(lis);
            if (i == lis.size()) lis.push_back(n);
            else lis[i] = n;
            ans.push_back(i + 1);
        }
        return ans;
    }
};
```

We can use `len` to keep track of the length of `lis`, and reuse `A` to store the `lis` values.

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> ans;
        int len = 0;
        for (int n : A) {
            int i = upper_bound(begin(A), begin(A) + len, n) - begin(A); // this number `n` should be put at `lis[i]`
            A[i] = n;
            len = max(i + 1, len); // updating the length of LIS
            ans.push_back(i + 1);
        }
        return ans;
    }
};
```

**Follow-up**: [1671. Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) is a great bidirectional extension of this problem.