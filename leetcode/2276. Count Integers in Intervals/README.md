# [2276. Count Integers in Intervals (Hard)](https://leetcode.com/problems/count-integers-in-intervals)

<p>Given an <strong>empty</strong> set of intervals, implement a data structure that can:</p>
<ul>
	<li><strong>Add</strong> an interval to the set of intervals.</li>
	<li><strong>Count</strong> the number of integers that are present in <strong>at least one</strong> interval.</li>
</ul>
<p>Implement the <code>CountIntervals</code> class:</p>
<ul>
	<li><code>CountIntervals()</code> Initializes the object with an empty set of intervals.</li>
	<li><code>void add(int left, int right)</code> Adds the interval <code>[left, right]</code> to the set of intervals.</li>
	<li><code>int count()</code> Returns the number of integers that are present in <strong>at least one</strong> interval.</li>
</ul>
<p><strong>Note</strong> that an interval <code>[left, right]</code> denotes all the integers <code>x</code> where <code>left &lt;= x &lt;= right</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
<strong>Output</strong>
[null, null, null, 6, null, 8]

<strong>Explanation</strong>
CountIntervals countIntervals = new CountIntervals(); // initialize the object with an empty set of intervals. 
countIntervals.add(2, 3);  // add [2, 3] to the set of intervals.
countIntervals.add(7, 10); // add [7, 10] to the set of intervals.
countIntervals.count();    // return 6
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 7, 8, 9, and 10 are present in the interval [7, 10].
countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
countIntervals.count();    // return 8
                           // the integers 2 and 3 are present in the interval [2, 3].
                           // the integers 5 and 6 are present in the interval [5, 8].
                           // the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
                           // the integers 9 and 10 are present in the interval [7, 10].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls <strong>in total</strong> will be made to <code>add</code> and <code>count</code>.</li>
	<li>At least <strong>one</strong> call will be made to <code>count</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Insert Interval (Medium)](https://leetcode.com/problems/insert-interval/)
* [Data Stream as Disjoint Intervals (Hard)](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)
* [My Calendar III (Hard)](https://leetcode.com/problems/my-calendar-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-integers-in-intervals
// Author: github.com/lzl124631x
// Time:
//      CountIntervals: O(1)
//      add: O(N) where N is the maximum number of intervals
//      count: O(1)
// Space: O(N)
class CountIntervals {
    int cnt = 0;
    map<int, int, greater<>> m; // left -> right
    int overlap(int a, int b, int c, int d) {
        if (a > c) swap(a, c), swap(b, d);
        return b - c + 1 - max(0, b - d);
    }
public:
    void add(int left, int right) {
        auto it = m.lower_bound(right); // find the greatest interval whose left boundary <= `right`.
        int d = right - left + 1, L = left, R = right;
        for (; it != m.end() && it->second >= left; it = m.erase(it)) {
            d -= overlap(it->first, it->second, left, right);
            L = min(L, it->first);
            R = max(R, it->second);
        }
        m[L] = R;
        cnt += d;
    }
    int count() {
        return cnt;
    }
};
```