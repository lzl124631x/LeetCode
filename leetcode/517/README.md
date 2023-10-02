# [517. Super Washing Machines (Hard)](https://leetcode.com/problems/super-washing-machines/)

<p>You have <b>n</b> super washing machines on a line. Initially, each washing machine has some dresses or is empty. 
</p>

<p>For each <b>move</b>, you could choose <b>any m</b> (1 ≤ m ≤ n) washing machines, and pass <b>one dress</b> of each washing machine to one of its adjacent washing machines <b> at the same time </b>.  </p>

<p>Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the <b>minimum number of moves</b> to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.</p>

<p><b>Example1</b>
</p><pre><b>Input:</b> [1,0,5]

<b>Output:</b> 3

<b>Explanation:</b> 
1st move:    1     0 &lt;-- 5    =&gt;    1     1     4
2nd move:    1 &lt;-- 1 &lt;-- 4    =&gt;    2     1     3    
3rd move:    2     1 &lt;-- 3    =&gt;    2     2     2   
</pre>

<p><b>Example2</b>
</p><pre><b>Input:</b> [0,3,0]

<b>Output:</b> 2

<b>Explanation:</b> 
1st move:    0 &lt;-- 3     0    =&gt;    1     2     0    
2nd move:    1     2 --&gt; 0    =&gt;    1     1     1     
</pre>

<p><b>Example3</b>
</p><pre><b>Input:</b> [0,2,0]

<b>Output:</b> -1

<b>Explanation:</b> 
It's impossible to make all the three washing machines have the same number of dresses. 
</pre>

<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The range of n is [1, 10000].</li>
<li>The range of dresses number in a super washing machine is [0, 1e5].</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Greedy

Let `total` be the total number of dresses in the machines. It's obvious that the problem is solvable if `total` is divisible by `N`.

Let `avg = total / N`, which is the target number for all the machines.

Let `diff[i] = machines[i] - avg`.

Now consider we separate the machines into two parts.

```
[ left part ] | [ right part ]
```

The `diff` must satisfy the following equation for any `0 <= k < N` so as to reach balance.

```
sum{ diff[i] | 0 <= i < k } = -sum{ diff[i] | k <= i < N }
```

The minimum number of moves must be at least euqal to `| sum{ diff[i] | 0 <= i < k } |`.

Let `sum(k) = sum{ diff[i] | 0 <= i < k }`, we know the answer is at least `| sum(k) |` for any `0 <= k < N`.

In other words, the answer is at least `max{ |sum(i)| | 0 <= i < N }`.

Is there any other situations to consider?

Yes, what if the `| diff |` is greater than `| sum |`?

For example, assume `diff = [-3, 5]`, we have `sum = [-3, 2]` and thus `| sum | = [3, 2]`. But `max(|sum|) = 3` is not enough because `max(|diff|) = 5`. We at least need 5 moves to reach balance.

Then we should consider `max(|diff|)` ? Not really. We only need to consider `max(diff)`.

Why doesn't `diff` matters when it's negative?

Because it can add `2` in a single move. For example, for input `[3, 0, 3]`, `diff = [1, -2, 1]`, we can balance the machine in the middle in only one move.

In sum, the minimum number of moves is `max( max(|sum|), max(diff) )`.

Now let's consider some examples:

input | 1 | 0 | 5
---|---|---|---
diff | -1 | -2 | 3
sum | -1 | -3 | 0

So `max(diff) = 3, max(|sum|) = 3`, the result is `3`.

input | 0 | 3 | 0
---|---|---|---
diff | -1 | 2 | -1
sum | -1 | 1 | 0

So `max(diff) = 2, max(|sum|) = 1`, the result is `2`.

input | 0 | 0 | 3 | 5
---|---|---|---|---
diff | -2|-2|1|3
sum | -2|-4|-3|0

So `max(diff) = 3, max(|sum|) = 4`, the result is `4`.

```cpp
// OJ: https://leetcode.com/problems/super-washing-machines/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/super-washing-machines/solution/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int N = machines.size(), total = accumulate(machines.begin(), machines.end(), 0);
        if (total % N) return -1;
        int avg = total / N, sum = 0, maxAbsSum = 0, maxDiff = 0;
        for (int n : machines) {
            int diff = n - avg;
            maxDiff = max(maxDiff, diff);
            sum += diff;
            maxAbsSum = max(maxAbsSum, abs(sum));
        }
        return max(maxAbsSum, maxDiff);
    }
};
```

## Solution 2.

Same as Solution 1, but shorter.

```cpp
// OJ: https://leetcode.com/problems/super-washing-machines/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/79938/very-short-easy-java-o-n-solution
class Solution {
public:
    int findMinMoves(vector<int>& m) {
        int sum = accumulate(m.begin(), m.end(), 0), N = m.size();
        if (sum % N) return -1;
        int target = sum / N, ans = 0, cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += m[i] - target;
            ans = max(ans, max(abs(cnt), m[i] - target));
        }
        return ans;
    }
};
```