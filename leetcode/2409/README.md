# [2409. Count Days Spent Together (Easy)](https://leetcode.com/problems/count-days-spent-together)

<p>Alice and Bob are traveling to Rome for separate business meetings.</p>
<p>You are given 4 strings <code>arriveAlice</code>, <code>leaveAlice</code>, <code>arriveBob</code>, and <code>leaveBob</code>. Alice will be in the city from the dates <code>arriveAlice</code> to <code>leaveAlice</code> (<strong>inclusive</strong>), while Bob will be in the city from the dates <code>arriveBob</code> to <code>leaveBob</code> (<strong>inclusive</strong>). Each will be a 5-character string in the format <code>"MM-DD"</code>, corresponding to the month and day of the date.</p>
<p>Return<em> the total number of days that Alice and Bob are in Rome together.</em></p>
<p>You can assume that all dates occur in the <strong>same</strong> calendar year, which is <strong>not</strong> a leap year. Note that the number of days per month can be represented as: <code>[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no day when Alice and Bob are in Rome together, so we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>All dates are provided in the format <code>"MM-DD"</code>.</li>
	<li>Alice and Bob's arrival dates are <strong>earlier than or equal to</strong> their leaving dates.</li>
	<li>The given dates are valid dates of a <strong>non-leap</strong> year.</li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Number of Days Between Two Dates (Easy)](https://leetcode.com/problems/number-of-days-between-two-dates/)
* [Minimum Number of Operations to Convert Time (Easy)](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-days-spent-together
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    int day(string &s) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, m = stoi(s.
substr(0, 2)), d = stoi(s.substr(3));
        for (int i = 0; i < m - 1; ++i) d += days[i];
        return d;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string 
arriveBob, string leaveBob) {
        int a = day(arriveAlice), b = day(leaveAlice), c = day(arriveBob), d = day
(leaveBob);
        if (a > c) swap(a, c), swap(b, d);
        if (b < c) return 0;
        return b - c + 1 - max(b - d, 0);
    }
};
```