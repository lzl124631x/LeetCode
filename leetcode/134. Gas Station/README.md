# [134. Gas Station (Medium)](https://leetcode.com/problems/gas-station/)

<p>There are <em>N</em> gas stations along a circular route, where the amount of gas at station <em>i</em> is <code>gas[i]</code>.</p>

<p>You have a car with an unlimited gas tank and it costs <code>cost[i]</code> of gas to travel from station <em>i</em> to its next station (<em>i</em>+1). You begin the journey with an empty tank at one of the gas stations.</p>

<p>Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>If there exists a&nbsp;solution, it is guaranteed to be unique.</li>
	<li>Both input arrays are non-empty and have the same length.</li>
	<li>Each element in the input arrays is a non-negative integer.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

<strong>Output:</strong> 3

<strong>Explanation:
</strong>Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
gas  = [2,3,4]
cost = [3,4,3]

<strong>Output:</strong> -1

<strong>Explanation:
</strong>You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

Let `S[i] = sum(gas[0] + ... + gas[i]) - sum(cost[0] + ... + cost[i])`.

The circuit can be completed as long as `sum(gas) - sum(cost) >= 0`, i.e. `S[N - 1] >= 0`.

The `S` array forms a polygonal line. We should pick the `x` value of the lowest point as the start index.


```cpp
// OJ: https://leetcode.com/problems/gas-station
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minVal = INT_MAX, tank = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            tank += gas[i] - cost[i];
            if (tank < minVal) {
                minVal = tank;
                ans = i;
            }
        }
        return tank >= 0 ? (ans + 1) % N : -1;
    }
};
```

## Solution 2. Greedy

The circuit can be completed if the sum of `gas[i] - cost[i]` is non-negative, which is denoted using `total`.

Use `tank` to denote the current available gas in tank, `ans` to denote the last possible answer.

When `tank` is negative, this point is a dead point, which means moving from `ans` to the current point is impossible.

The current point must have `gas[i] - cost[i] < 0`, so we'll need to try to start from next point -- reset `ans` to `i + 1`, and `tank` to `0`.

Finally, if `total` is non-negative, `ans` should be the start point.

Now let's prove this algorithm works.

First of all, assume the start point we found is `s`. Then this algorithm guarantees we can reach point `0` from `s`.

How can we prove the last part of the roundtrip -- from `0` to `s`?

We use proof by contradiction to prove this works.

Assume there is a point `k` (`0 < k <= s`) that is unreachable in the roundtrip starting from `s`.

Let `D[i] = gas[i] - cost[i]`.

Since `total >= 0`, we have `sum{ D[i] | 0 <= i < N } >= 0`, i.e.:

```
sum{ D[i] | 0 < i <= k } + sum{ D[i] | k < i < s } + sum{ D[i] | s <= i <= N } >= 0
```

According to the algorithm, `sum{ D[i] | k < i < s } < 0` must be true.

So `sum{ D[i] | 0 < i <= k } + sum{ D[i] | s <= i <= N } >= 0`.

And because we had the assumption that `k` is unreachable from `s`, we also have `sum{ D[i] | 0 < i <= k } + sum{ D[i] | s <= i <= N } < 0`

So here we have contradiction, which proves that such `k` doesn't exist.

```cpp
// OJ: https://leetcode.com/problems/gas-station
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, total = 0, ans = 0, N = gas.size();
        for (int i = 0; i < N; ++i) {
            total += gas[i] - cost[i];
            if ((tank += gas[i] - cost[i]) < 0) {
                tank = 0;
                ans = i + 1;
            }
        }
        return total < 0 ? -1 : ans;
    }
};
```