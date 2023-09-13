# [1792. Maximum Average Pass Ratio (Medium)](https://leetcode.com/problems/maximum-average-pass-ratio/)

<p>There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array <code>classes</code>, where <code>classes[i] = [pass<sub>i</sub>, total<sub>i</sub>]</code>. You know beforehand that in the <code>i<sup>th</sup></code> class, there are <code>total<sub>i</sub></code> total students, but only <code>pass<sub>i</sub></code> number of students will pass the exam.</p>

<p>You are also given an integer <code>extraStudents</code>. There are another <code>extraStudents</code> brilliant students that are <strong>guaranteed</strong> to pass the exam of any class they are assigned to. You want to assign each of the <code>extraStudents</code> students to a class in a way that <strong>maximizes</strong> the <strong>average</strong> pass ratio across <strong>all</strong> the classes.</p>

<p>The <strong>pass ratio</strong> of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The <strong>average pass ratio</strong> is the sum of pass ratios of all the classes divided by the number of the classes.</p>

<p>Return <em>the <strong>maximum</strong> possible average pass ratio after assigning the </em><code>extraStudents</code><em> students. </em>Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> classes = [[1,2],[3,5],[2,2]], <code>extraStudents</code> = 2
<strong>Output:</strong> 0.78333
<strong>Explanation:</strong> You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> classes = [[2,4],[3,9],[4,5],[2,10]], <code>extraStudents</code> = 4
<strong>Output:</strong> 0.53485
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= classes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>classes[i].length == 2</code></li>
	<li><code>1 &lt;= pass<sub>i</sub> &lt;= total<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= extraStudents &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/)

## Solution 1. Max Heap

Let `dist(c)` be the increase of pass ratio if we add the student into class `c`.

We should greedily pick the class with the greatest `dist(c)`. We can use a max heap for this.

```cpp
// OJ: https://leetcode.com/problems/maximum-average-pass-ratio/
// Author: github.com/lzl124631x
// Time: O((E + C)logC)
// Space: O(C)
class Solution {
    double dist(pair<int, int> &p) {
        return (double)(p.first + 1) / (p.second + 1) - (double)p.first / p.second;
    }
public:
    double maxAverageRatio(vector<vector<int>>& C, int E) {
        int ones = 0;
        auto cmp = [&](auto &a, auto &b) { return dist(a) < dist(b); };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto &c : C) {
            if (c[0] == c[1]) ++ones;
            else pq.emplace(c[0], c[1]);
        }
        for (int i = 0; i < E && pq.size(); ++i) {
            auto [a, b] = pq.top();
            pq.pop();
            pq.emplace(a + 1, b + 1);
        }
        double total = 0;
        while (pq.size()) {
            auto [a, b] = pq.top();
            pq.pop();
            total += (double)a / b;
        }
        return (total + ones) / C.size();
    }
};
```