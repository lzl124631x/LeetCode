# [2410. Maximum Matching of Players With Trainers (Medium)](https://leetcode.com/problems/maximum-matching-of-players-with-trainers)

<p>You are given a <strong>0-indexed</strong> integer array <code>players</code>, where <code>players[i]</code> represents the <strong>ability</strong> of the <code>i<sup>th</sup></code> player. You are also given a <strong>0-indexed</strong> integer array <code>trainers</code>, where <code>trainers[j]</code> represents the <strong>training capacity </strong>of the <code>j<sup>th</sup></code> trainer.</p>
<p>The <code>i<sup>th</sup></code> player can <strong>match</strong> with the <code>j<sup>th</sup></code> trainer if the player's ability is <strong>less than or equal to</strong> the trainer's training capacity. Additionally, the <code>i<sup>th</sup></code> player can be matched with at most one trainer, and the <code>j<sup>th</sup></code> trainer can be matched with at most one player.</p>
<p>Return <em>the <strong>maximum</strong> number of matchings between </em><code>players</code><em> and </em><code>trainers</code><em> that satisfy these conditions.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> players = [4,7,9], trainers = [8,2,5,8]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 &lt;= 8.
- players[1] can be matched with trainers[3] since 7 &lt;= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> players = [1,1,1], trainers = [10]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= players.length, trainers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= players[i], trainers[j] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Most Profit Assigning Work (Medium)](https://leetcode.com/problems/most-profit-assigning-work/)
* [Long Pressed Name (Easy)](https://leetcode.com/problems/long-pressed-name/)
* [Interval List Intersections (Medium)](https://leetcode.com/problems/interval-list-intersections/)
* [Largest Merge Of Two Strings (Medium)](https://leetcode.com/problems/largest-merge-of-two-strings/)
* [Maximum Number of Tasks You Can Assign (Hard)](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/)
* [Successful Pairs of Spells and Potions (Medium)](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)
* [The Latest Time to Catch a Bus (Medium)](https://leetcode.com/problems/the-latest-time-to-catch-a-bus/)
* [Maximize Greatness of an Array (Medium)](https://leetcode.com/problems/maximize-greatness-of-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-matching-of-players-with-trainers
// Author: github.com/lzl124631x
// Time: O(PlogP + TlogT)
// Space: O(1)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& P, vector<int>& T) {
        sort(begin(P), end(P), greater<>());
        sort(begin(T), end(T), greater<>());
        int ans = 0, N = P.size(), i = 0;
        for (int t : T) {
            while (i < N && P[i] > t) ++i;
            if (i == N) break;
            ++i;
            ++ans;
        }
        return ans;
    }
};
```