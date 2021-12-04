# [710. Random Pick with Blacklist (Hard)](https://leetcode.com/problems/random-pick-with-blacklist/)

<p>You are given an integer <code>n</code> and an array of <strong>unique</strong> integers <code>blacklist</code>. Design an algorithm to pick a random integer in the range <code>[0, n - 1]</code> that is <strong>not</strong> in <code>blacklist</code>. Any integer that is in the mentioned range and not in <code>blacklist</code> should be <strong>equally likely</strong> to be returned.</p>

<p>Optimize your algorithm such that it minimizes the number of calls to the <strong>built-in</strong> random function of your language.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(int n, int[] blacklist)</code> Initializes the object with the integer <code>n</code> and the blacklisted integers <code>blacklist</code>.</li>
	<li><code>int pick()</code> Returns a random integer in the range <code>[0, n - 1]</code> and not in <code>blacklist</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
<strong>Output</strong>
[null, 0, 4, 1, 6, 1, 0, 4]

<strong>Explanation</strong>
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // return 0, any integer from [0,1,4,6] should be ok. Note that for every call of pick,
                 // 0, 1, 4, and 6 must be equally likely to be returned (i.e., with probability 1/4).
solution.pick(); // return 4
solution.pick(); // return 1
solution.pick(); // return 6
solution.pick(); // return 1
solution.pick(); // return 0
solution.pick(); // return 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= blacklist.length &lt;- min(10<sup>5</sup>, n - 1)</code></li>
	<li><code>0 &lt;= blacklist[i] &lt; n</code></li>
	<li>All the values of <code>blacklist</code> are <strong>unique</strong>.</li>
	<li>At most <code>2 * 10<sup>4</sup></code> calls will be made to <code>pick</code>.</li>
</ul>


**Companies**:  
[Two Sigma](https://leetcode.com/company/two-sigma), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/), [Randomized](https://leetcode.com/tag/randomized/)

**Similar Questions**:
* [Random Pick Index (Medium)](https://leetcode.com/problems/random-pick-index/)
* [Random Pick with Weight (Medium)](https://leetcode.com/problems/random-pick-with-weight/)
* [Find Unique Binary String (Medium)](https://leetcode.com/problems/find-unique-binary-string/)

## Solution 1.

Create a mapping between blacked numbers to valid numbers.

Example: `n = 7, blacklist=[2,3,5]`:

```
In range: ....
Numbers:  0123456
Blocked:    xx x
Mapped to:  46
```
In this case, we map `2->4`, `3->6`.

```cpp
// OJ: https://leetcode.com/problems/random-pick-with-blacklist/
// Author: github.com/lzl124631x
// Time:
//      Solution: O(BlogB)
//      pick: O(1)
// Space: O(B)
class Solution {
    unordered_map<int, int> m;
    int len;
public:
    Solution(int n, vector<int>& B) {
        len = n - B.size();
        sort(begin(B), end(B));
        int j = lower_bound(begin(B), end(B), len) - begin(B), N = B.size(), next = len;
        for (int i = 0; i < N && B[i] < len; ++i) {
            while (j < N && B[j] == next) ++j, ++next;
            m[B[i]] = next++;
        }
    }
    int pick() {
        int r = rand() % len;
        return m.count(r) ? m[r] : r;
    }
};
```