# [1823. Find the Winner of the Circular Game (Medium)](https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/)

<p>There are <code>n</code> friends that are playing a game. The friends are sitting in a circle and are numbered from <code>1</code> to <code>n</code> in <strong>clockwise order</strong>. More formally, moving clockwise from the <code>i<sup>th</sup></code> friend brings you to the <code>(i+1)<sup>th</sup></code> friend for <code>1 &lt;= i &lt; n</code>, and moving clockwise from the <code>n<sup>th</sup></code> friend brings you to the <code>1<sup>st</sup></code> friend.</p>

<p>The rules of the game are as follows:</p>

<ol>
	<li><strong>Start</strong> at the <code>1<sup>st</sup></code> friend.</li>
	<li>Count the next <code>k</code> friends in the clockwise direction <strong>including</strong> the friend you started at. The counting wraps around the circle and may count some friends more than once.</li>
	<li>The last friend you counted leaves the circle and loses the game.</li>
	<li>If there is still more than one friend in the circle, go back to step <code>2</code> <strong>starting</strong> from the friend <strong>immediately clockwise</strong> of the friend who just lost and repeat.</li>
	<li>Else, the last friend in the circle wins the game.</li>
</ol>

<p>Given the number of friends, <code>n</code>, and an integer <code>k</code>, return <em>the winner of the game</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png" style="width: 500px; height: 345px;">
<pre><strong>Input:</strong> n = 5, k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 6, k = 5
<strong>Output:</strong> 1
<strong>Explanation:</strong> The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 500</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Simulation

```cpp
// OJ: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        auto it = begin(s);
        while (s.size() > 1) {
            for (int i = 1; i < k; ++i) {
                it = it == prev(s.end()) ? begin(s) : next(it);
            }
            auto j = it == prev(s.end()) ? begin(s) : next(it);
            s.erase(it);
            it = j;
        }
        return *s.begin();
    }
};
```

## Solution 2. Think backwards

Let `f(n,k)` be the 0-based index of the winning person.

Assume we have `n` persons with indexes `0 ~ (n-1)`, the person got kicked out (say Alice) has index `(k - 1) % n`, and the next person (say Bob) of this kicked-out person has index `k % n`.

In the next turn, there are `n - 1` persons, and we start the game from Bob. If Bob has index `0`, the winning person will have index `f(n-1,k)`.

```cpp

```