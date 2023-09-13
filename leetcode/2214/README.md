# [2214. Minimum Health to Beat Game (Medium)](https://leetcode.com/problems/minimum-health-to-beat-game/)

<p>You are playing a game that has <code>n</code> levels numbered from <code>0</code> to <code>n - 1</code>. You are given a <strong>0-indexed</strong> integer array <code>damage</code> where <code>damage[i]</code> is the amount of health you will lose to complete the <code>i<sup>th</sup></code> level.</p>

<p>You are also given an integer <code>armor</code>. You may use your armor ability <strong>at most once</strong> during the game on <strong>any</strong> level which will protect you from <strong>at most</strong> <code>armor</code> damage.</p>

<p>You must complete the levels in order and your health must be <strong>greater than</strong> <code>0</code> at all times to beat the game.</p>

<p>Return <em>the <strong>minimum</strong> health you need to start with to beat the game.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> damage = [2,7,4,3], armor = 4
<strong>Output:</strong> 13
<strong>Explanation:</strong> One optimal way to beat the game starting at 13 health is:
On round 1, take 2 damage. You have 13 - 2 = 11 health.
On round 2, take 7 damage. You have 11 - 7 = 4 health.
On round 3, use your armor to protect you from 4 damage. You have 4 - 0 = 4 health.
On round 4, take 3 damage. You have 4 - 3 = 1 health.
Note that 13 is the minimum health you need to start with to beat the game.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> damage = [2,5,3,4], armor = 7
<strong>Output:</strong> 10
<strong>Explanation:</strong> One optimal way to beat the game starting at 10 health is:
On round 1, take 2 damage. You have 10 - 2 = 8 health.
On round 2, use your armor to protect you from 5 damage. You have 8 - 0 = 8 health.
On round 3, take 3 damage. You have 8 - 3 = 5 health.
On round 4, take 4 damage. You have 5 - 4 = 1 health.
Note that 10 is the minimum health you need to start with to beat the game.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> damage = [3,3,3], armor = 0
<strong>Output:</strong> 10
<strong>Explanation:</strong> One optimal way to beat the game starting at 10 health is:
On round 1, take 3 damage. You have 10 - 3 = 7 health.
On round 2, take 3 damage. You have 7 - 3 = 4 health.
On round 3, take 3 damage. You have 4 - 3 = 1 health.
Note that you did not use your armor ability.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == damage.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= damage[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= armor &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Eliminate Maximum Number of Monsters (Medium)](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)

## Solution 1. DP

Let `yes` be the min health needed if we do use armor once.

Let `no` be the min health needed if we don't use armor.

Both of them are initialized as `1`.

From `A[N-1]` to `A[0]`, at each step, we get `newYes` and `newNo` values:

* `newNo` is simply `no + A[i]`.
* `newYes` has two options. It's the min of these two:
  * Use the armor in the current level. The min health needed is `no + max(0, A[i] - armor)`.
  * Don't use the armor in the current level but a previous level. The min health needed is `yes + A[i]`.

In the end, the result is `min(yes, no)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-health-to-beat-game/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    long long minimumHealth(vector<int>& A, int armor) {
        long yes = 1, no = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            long newYes = min(no + max(0, A[i] - armor), yes + A[i]);
            long newNo = no + A[i];
            yes = newYes, no = newNo;
        }
        return min(yes, no);
    }
};
```

## Solution 2. Greedy

We greedily use the armor at the level with the greatest damage. Without armor, we need `1 + sum(A)` min health. The armor can take damange of `min(max(A), armor)`, saving us this amount of health. So in total, we just need `1 + sum(A) - min(max(A), armor)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-health-to-beat-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long minimumHealth(vector<int>& A, int armor) {
        return 1 + accumulate(begin(A), end(A), 0L) - min(*max_element(begin(A), end(A)), armor);
    }
};
```