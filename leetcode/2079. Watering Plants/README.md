# [2079. Watering Plants (Medium)](https://leetcode.com/problems/watering-plants/)

<p>You want to water <code>n</code> plants in your garden with a watering can. The plants are arranged in a row and are labeled from <code>0</code> to <code>n - 1</code> from left to right where the <code>i<sup>th</sup></code> plant is located at <code>x = i</code>. There is a river at <code>x = -1</code> that you can refill your watering can at.</p>

<p>Each plant needs a specific amount of water. You will water the plants in the following way:</p>

<ul>
	<li>Water the plants in order from left to right.</li>
	<li>After watering the current plant, if you do not have enough water to <strong>completely</strong> water the next plant, return to the river to fully refill the watering can.</li>
	<li>You <strong>cannot</strong> refill the watering can early.</li>
</ul>

<p>You are initially at the river (i.e., <code>x = -1</code>). It takes <strong>one step</strong> to move <strong>one unit</strong> on the x-axis.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>plants</code> of <code>n</code> integers, where <code>plants[i]</code> is the amount of water the <code>i<sup>th</sup></code> plant needs, and an integer <code>capacity</code> representing the watering can capacity, return <em>the <strong>number of steps</strong> needed to water all the plants</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> plants = [2,2,3,3], capacity = 5
<strong>Output:</strong> 14
<strong>Explanation:</strong> Start at the river with a full watering can:
- Walk to plant 0 (1 step) and water it. Watering can has 3 units of water.
- Walk to plant 1 (1 step) and water it. Watering can has 1 unit of water.
- Since you cannot completely water plant 2, walk back to the river to refill (2 steps).
- Walk to plant 2 (3 steps) and water it. Watering can has 2 units of water.
- Since you cannot completely water plant 3, walk back to the river to refill (3 steps).
- Walk to plant 3 (4 steps) and water it.
Steps needed = 1 + 1 + 2 + 3 + 3 + 4 = 14.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> plants = [1,1,1,4,2,3], capacity = 4
<strong>Output:</strong> 30
<strong>Explanation:</strong> Start at the river with a full watering can:
- Water plants 0, 1, and 2 (3 steps). Return to river (3 steps).
- Water plant 3 (4 steps). Return to river (4 steps).
- Water plant 4 (5 steps). Return to river (5 steps).
- Water plant 5 (6 steps).
Steps needed = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> plants = [7,7,7,7,7,7,7], capacity = 8
<strong>Output:</strong> 49
<strong>Explanation:</strong> You have to refill before watering each plant.
Steps needed = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == plants.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>max(plants[i]) &lt;= capacity &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Simulation

1. When we can water `A[i]`, consume it `water -= A[i]` and increment `i`.
2. If we haven't reached the last plant, add `2 * i` to the answer; otherwise, add `i`.
3. Refill water. Go back to step 1 if `i < N`.


```cpp
// OJ: https://leetcode.com/problems/watering-plants/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int wateringPlants(vector<int>& A, int C) {
        int N = A.size(), ans = 0, water = C;
        for (int i = 0; i < N; water = C) { // refill water after each round
            for (; i < N && water - A[i] >= 0; ++i) water -= A[i]; // When we can water `A[i]`, consume it and increment `i`.
            ans += (i == N ? 1 : 2) * i; // If we haven't reached the last plant, add `2 * i` to the answer; otherwise, add `i`.
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/watering-plants/discuss/1589015/C%2B%2B-O(N)-One-Pass