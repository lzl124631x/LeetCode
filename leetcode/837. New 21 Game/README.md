# [837. New 21 Game (Medium)](https://leetcode.com/problems/new-21-game/submissions/)

<p>Alice plays the following game, loosely based on the card game "21".</p>

<p>Alice starts with <code>0</code> points, and draws numbers while she has less than <code>K</code> points.&nbsp; During each draw, she gains an integer number of points randomly from the range <code>[1, W]</code>, where <code>W</code> is an integer.&nbsp; Each draw is independent and the outcomes have equal probabilities.</p>

<p>Alice stops drawing numbers when she gets <code>K</code> or more points.&nbsp; What is the probability&nbsp;that she has <code>N</code> or less points?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = 10, K = 1, W = 10
<strong>Output: </strong>1.00000
<strong>Explanation: </strong> Alice gets a single card, then stops.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = 6, K = 1, W = 10
<strong>Output: </strong>0.60000
<strong>Explanation: </strong> Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = 21, K = 17, W = 10
<strong>Output: </strong>0.73278</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= K &lt;= N &lt;= 10000</code></li>
	<li><code>1 &lt;= W &lt;= 10000</code></li>
	<li>Answers will be accepted as correct if they are within <code>10^-5</code> of the correct answer.</li>
	<li>The judging time limit has been reduced for this question.</li>
</ol>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Brute Force (TLE)

Let `p[i]` be the possibility to land on node `i`.

For each node `i` in `[0, K)`, try jump `j` step to node `i + j` where `j` is in `[1, W]`. When landing on node `i + j` from node `i`, `p[i + j]` should be increased by `p[i] / W`.

```cpp
// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(KW)
// Space: O(1)
// NOTE: This solution will get TLE
class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> p(K + W + 1);
        p[0] = 1;
        for (int i = 0; i < K; ++i) {
            for (int j = 1; j <= W && i + j <= N; ++j) {
                p[i + j] += p[i] / W;
            }
        }
        double ans = 0;
        for (int i = K; i <= N; ++i) ans += p[i];
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/new-21-game/
// Author: github.com/lzl124631x
// Time: O(K + W)
// Space: O(K + W)
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (!K || N >= K + W - 1) return 1;
        vector<double> p(K + W + 1);
        p[0] = 1;
        double ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (i > 1) p[i] += p[i - 1];
            if (i <= K) p[i] += p[i - 1] / W;
            if (i > W) p[i] -= p[i - W - 1] / W;
            if (i >= K) ans += p[i]; 
        }
        return ans;
    }
};
```