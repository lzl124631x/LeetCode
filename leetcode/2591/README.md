# [2591. Distribute Money to Maximum Children (Easy)](https://leetcode.com/problems/distribute-money-to-maximum-children)

<p>You are given an integer <code>money</code> denoting the amount of money (in dollars) that you have and another integer <code>children</code> denoting the number of children that you must distribute the money to.</p>
<p>You have to distribute the money according to the following rules:</p>
<ul>
	<li>All money must be distributed.</li>
	<li>Everyone must receive at least <code>1</code> dollar.</li>
	<li>Nobody receives <code>4</code> dollars.</li>
</ul>
<p>Return <em>the <strong>maximum</strong> number of children who may receive <strong>exactly</strong> </em><code>8</code> <em>dollars if you distribute the money according to the aforementioned rules</em>. If there is no way to distribute the money, return <code>-1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> money = 20, children = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
- 8 dollars to the first child.
- 9 dollars to the second child. 
- 3 dollars to the third child.
It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> money = 16, children = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Each child can be given 8 dollars.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= money &lt;= 200</code></li>
	<li><code>2 &lt;= children &lt;= 30</code></li>
</ul>

**Companies**:
[Zendesk](https://leetcode.com/company/zendesk)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Distribute Candies to People (Easy)](https://leetcode.com/problems/distribute-candies-to-people/)
* [Fair Distribution of Cookies (Medium)](https://leetcode.com/problems/fair-distribution-of-cookies/)
* [Calculate Money in Leetcode Bank (Easy)](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/distribute-money-to-maximum-children
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        int ans = money / 8;
        money -= ans * 8;
        children -= ans;
        while (ans > 0 && (money < children || (children == 1 && money == 4) || (children == 0 && money) || children < 0)) {
            --ans;
            money += 8;
            children++;
        }
        return ans;
    }
};
```