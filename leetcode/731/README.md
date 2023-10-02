# [731. My Calendar II (Medium)](https://leetcode.com/problems/my-calendar-ii/)

<p>You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a <strong>triple booking</strong>.</p>

<p>A <strong>triple booking</strong> happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).</p>

<p>The event can be represented as a pair of integers <code>start</code> and <code>end</code> that represents a booking on the half-open interval <code>[start, end)</code>, the range of real numbers <code>x</code> such that <code>start &lt;= x &lt; end</code>.</p>

<p>Implement the <code>MyCalendarTwo</code> class:</p>

<ul>
	<li><code>MyCalendarTwo()</code> Initializes the calendar object.</li>
	<li><code>boolean book(int start, int end)</code> Returns <code>true</code> if the event can be added to the calendar successfully without causing a <strong>triple booking</strong>. Otherwise, return <code>false</code> and do not add the event to the calendar.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
<strong>Output</strong>
[null, true, true, true, false, true, true]

<strong>Explanation</strong>
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event ca not be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= start &lt; end &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>1000</code> calls will be made to <code>book</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [My Calendar I (Medium)](https://leetcode.com/problems/my-calendar-i/)
* [My Calendar III (Hard)](https://leetcode.com/problems/my-calendar-iii/)

## Solution 1. Difference Array

```cpp
// OJ: https://leetcode.com/problems/my-calendar-ii/
// Author: github.com/lzl124631x
// Time:
//      MyCalendarTwo: O(1)
//      book: O(N)
// Space: O(N)
class MyCalendarTwo {
    map<int, int> m; // number -> diff
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;
        for (auto &[n, d] : m) {
            sum += d;
            if (sum > 2) {
                if (--m[start] == 0) m.erase(start);
                if (++m[end] == 0) m.erase(end);
                return false;
            }
        }
        return true;
    }
};
```