# [2512. Reward Top K Students (Medium)](https://leetcode.com/problems/reward-top-k-students)

<p>You are given two string arrays <code>positive_feedback</code> and <code>negative_feedback</code>, containing the words denoting positive and negative feedback, respectively. Note that <strong>no</strong> word is both positive and negative.</p>
<p>Initially every student has <code>0</code> points. Each positive word in a feedback report <strong>increases</strong> the points of a student by <code>3</code>, whereas each negative word <strong>decreases</strong> the points by <code>1</code>.</p>
<p>You are given <code>n</code> feedback reports, represented by a <strong>0-indexed</strong> string array <code>report</code>&nbsp;and a <strong>0-indexed</strong> integer array <code>student_id</code>, where <code>student_id[i]</code> represents the ID of the student who has received the feedback report <code>report[i]</code>. The ID of each student is <strong>unique</strong>.</p>
<p>Given an integer <code>k</code>, return <em>the top </em><code>k</code><em> students after ranking them in <strong>non-increasing</strong> order by their points</em>. In case more than one student has the same points, the one with the lower ID ranks higher.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> 
Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
<strong>Output:</strong> [2,1]
<strong>Explanation:</strong> 
- The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points. 
- The student with ID 2 has 1 positive feedback, so he has 3 points. 
Since student 2 has more points, [2,1] is returned.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= positive_feedback.length, negative_feedback.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= positive_feedback[i].length, negative_feedback[j].length &lt;= 100</code></li>
	<li>Both <code>positive_feedback[i]</code> and <code>negative_feedback[j]</code> consists of lowercase English letters.</li>
	<li>No word is present in both <code>positive_feedback</code> and <code>negative_feedback</code>.</li>
	<li><code>n == report.length == student_id.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>report[i]</code> consists of lowercase English letters and spaces <code>' '</code>.</li>
	<li>There is a single space between consecutive words of <code>report[i]</code>.</li>
	<li><code>1 &lt;= report[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= student_id[i] &lt;= 10<sup>9</sup></code></li>
	<li>All the values of <code>student_id[i]</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

**Companies**:
[Booking.com](https://leetcode.com/company/booking.com)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [Queue Reconstruction by Height (Medium)](https://leetcode.com/problems/queue-reconstruction-by-height/)
* [K Highest Ranked Items Within a Price Range (Medium)](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reward-top-k-students
// Author: github.com/lzl124631x
// Time: O(pos + neg + NlogN)
// Space: O(pos + neg + N)
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int N = report.size();
        vector<int> score(N), id(N), ans;
        iota(begin(id), end(id), 0);
        unordered_set<string> pos(begin(positive_feedback), end(positive_feedback)), neg(begin(negative_feedback), end(negative_feedback));
        auto getScore = [&](string &s) {
            istringstream iss(s);
            string word;
            int ans = 0;
            while (iss >> word) {
                if (pos.count(word)) ans += 3;
                else if (neg.count(word)) ans--;
            }
            return ans;
        };
        for (int i = 0; i < N; ++i) score[i] = getScore(report[i]);
        sort(begin(id), end(id), [&](int a, int b) { return score[a] != score[b] ? score[a] > score[b] : student_id[a] < student_id[b]; });
        for (int i = 0; i < k; ++i) ans.push_back(student_id[id[i]]);
        return ans;
    }
};
```