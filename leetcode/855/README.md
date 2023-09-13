# [855. Exam Room (Medium)](https://leetcode.com/problems/exam-room/)

<p>In an exam room, there are <code>N</code> seats in a single row, numbered <code>0, 1, 2, ..., N-1</code>.</p>

<p>When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.&nbsp; If there are multiple such seats, they sit in the seat with the lowest number.&nbsp; (Also, if no one is in the room, then the student sits at seat number 0.)</p>

<p>Return a class <code>ExamRoom(int N)</code>&nbsp;that exposes two functions: <code>ExamRoom.seat()</code>&nbsp;returning an <code>int</code>&nbsp;representing what seat the student sat in, and <code>ExamRoom.leave(int p)</code>&nbsp;representing that the student in seat number <code>p</code>&nbsp;now leaves the room.&nbsp; It is guaranteed that any calls to <code>ExamRoom.leave(p)</code> have a student sitting in seat <code>p</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["ExamRoom","seat","seat","seat","seat","leave","seat"]</span>, <span id="example-input-1-2">[[10],[],[],[],[],[4],[]]</span>
<strong>Output: </strong><span id="example-output-1">[null,0,9,4,2,null,5]</span>
<span><strong>Explanation</strong>:
ExamRoom(10) -&gt; null
seat() -&gt; 0, no one is in the room, then the student sits at seat number 0.
seat() -&gt; 9, the student sits at the last seat number 9.
seat() -&gt; 4, the student sits at the last seat number 4.
seat() -&gt; 2, the student sits at the last seat number 2.
leave(4) -&gt; null
seat() -&gt; 5, the student sits at the last seat number 5.</span>
</pre>

<p><span>​​​​​​​</span></p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 10^9</code></li>
	<li><code>ExamRoom.seat()</code> and <code>ExamRoom.leave()</code> will be called at most <code>10^4</code> times across all test cases.</li>
	<li>Calls to <code>ExamRoom.leave(p)</code> are guaranteed to have a student currently sitting in seat number <code>p</code>.</li>
</ol>


**Related Topics**:  
[Ordered Map](https://leetcode.com/tag/ordered-map/)

**Similar Questions**:
* [Maximize Distance to Closest Person (Medium)](https://leetcode.com/problems/maximize-distance-to-closest-person/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/exam-room/
// Author: github.com/lzl124631x
// Time:
//      ExamRoom: O(1)
//      seat: O(N)
//      leave: O(logN)
// Space: O(N)
class ExamRoom {
    set<int> s;
    int N;
public:
    ExamRoom(int N) : N(N) {}
    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        }
        int prev = -1, ans = 0, dist = 0;
        for (int i : s) {
            if (prev == -1) dist = i;
            else {
                int d = (i - prev) / 2;
                if (d > dist) {
                    dist = d;
                    ans = (i + prev) / 2;
                }
            }
            prev = i;
        }
        if (N - 1 - prev > dist) ans = N - 1;
        s.insert(ans);
        return ans;
    }
    void leave(int p) {
        s.erase(p);
    }
};
```