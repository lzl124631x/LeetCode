# [134. Gas Station (Medium)](https://leetcode.com/problems/gas-station/)

<p>There are <code>n</code> gas stations along a circular route, where the amount of gas at the <code>i<sup>th</sup></code> station is <code>gas[i]</code>.</p>

<p>You have a car with an unlimited gas tank and it costs <code>cost[i]</code> of gas to travel from the <code>i<sup>th</sup></code> station to its next <code>(i + 1)<sup>th</sup></code> station. You begin the journey with an empty tank at one of the gas stations.</p>

<p>Given two integer arrays <code>gas</code> and <code>cost</code>, return <em>the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return</em> <code>-1</code>. If there exists a solution, it is <strong>guaranteed</strong> to be <strong>unique</strong></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> gas = [1,2,3,4,5], cost = [3,4,5,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> gas = [2,3,4], cost = [3,4,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong>
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>gas.length == n</code></li>
	<li><code>cost.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= gas[i], cost[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [IBM](https://leetcode.com/company/ibm), [tiktok](https://leetcode.com/company/tiktok), [Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Apple](https://leetcode.com/company/apple), [ByteDance](https://leetcode.com/company/bytedance), [Bloomberg](https://leetcode.com/company/bloomberg), [Flipkart](https://leetcode.com/company/flipkart), [Hotstar](https://leetcode.com/company/hotstar)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

Let `A[i] = gas[i] - cost[i]`. The brute force way is to try each start index and see if the prefix sums starting from this index are always `>= 0`.

A better way is to loop at most twice over `A`. Whenever the prefix sum drops under `0`, we simply discard this start index and use `(i + 1) % N` for the next trial.

```cpp
// OJ: https://leetcode.com/problems/gas-station/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size(), len = 0, start = 0;
        for (int i = 0, sum = 0; i < 2 * N && len < N; ++i) {
            sum += gas[i % N] - cost[i % N];
            if (sum < 0) { // sum drops under 0. Discard this start index and start over.
                len = sum = 0;
                start = (i + 1) % N;
            } else ++len;
        }
        return len == N ? start : -1; // If we've found a sequence of length `N` whose prefix sums are all `>= 0`, this start index is the answer.
    }
};
```
## Solution 2. Greedy

*This solution is similar to Solution 1, but it only loops through the arrays once.*

The circuit can be completed if the sum of `gas[i] - cost[i]` is non-negative, which is denoted using `total`.

Use `tank` to denote the current available gas in tank, `ans` to denote the last possible answer.

When `tank` is negative, this point is a dead point, which means moving from `ans` to the current point is impossible.

The current point must have `gas[i] - cost[i] < 0`, so we'll need to try to start from next point -- reset `ans` to `i + 1`, and `tank` to `0`.

When we reached the end of the arrays, if `total` is non-negative, `ans` is the start point.

**Proof**:

First of all, assume the start point we found is `s`. Then this algorithm guarantees we can reach point `0` from `s`.

How can we prove the last part of the roundtrip -- from `0` to `s`?

We use proof by contradiction to prove this works.

Assume there is a point `k` (`0 < k <= s`) that is unreachable in the roundtrip starting from `s`.

Let `D[i] = gas[i] - cost[i]`, and `SUM(i, j) = D[i] + D[i+1] + ... + D[j]`.

Since `total >= 0`, we have `SUM(0, N-1) >= 0`, i.e.:

```
SUM(0, k) + SUM(k+1, s-1) + SUM(s, N-1) >= 0
```

Let them be `a`, `b`, `c` respectively. We have `a + b + c >= 0`.

Since we can't reach `k` from `s`, we have `c + a <= 0`. And because `c >= 0`, we have `a <= 0`. Thus, this algorithm must reset the starting point when we scanned from `0` to `k`. And since we reset the starting point at `s-1` again, we know `b <= 0`.

Given `b <= 0` and `a + b + c >= 0`, we have `a + c >= 0`. This contradicts with `c + a <= 0`. So, there is no such `k` and we must be able to roundtrip from `s`.

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

## Solution 3. Greedy

Let `S[i] = sum(gas[0] + ... + gas[i]) - sum(cost[0] + ... + cost[i])`.

The circuit can be completed as long as `sum(gas) - sum(cost) >= 0`, i.e. `S[N - 1] >= 0`.

The `S` array forms a polygonal line. We should use `x+1` as the start index where `x` is the index of the lowest point of the polygonal line.

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