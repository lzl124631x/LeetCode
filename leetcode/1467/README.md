# [1467. Probability of a Two Boxes Having The Same Number of Distinct Balls (Hard)](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)

<p>Given <code>2n</code> balls of <code>k</code> distinct colors. You will be given an integer array <code>balls</code> of size <code>k</code> where <code>balls[i]</code> is the number of balls of color <code>i</code>.&nbsp;</p>

<p>All the balls will be <strong>shuffled uniformly at random</strong>,&nbsp;then we will distribute the first <code>n</code> balls to the first box and the remaining <code>n</code> balls to the other box (Please read the explanation of the second example carefully).</p>

<p>Please note that the two boxes are considered different. For example, if we have two balls of colors <code>a</code> and <code>b</code>, and two boxes <code>[]</code> and <code>()</code>, then the distribution <code>[a] (b)</code> is considered different than the distribution <code>[b] (a)&nbsp;</code>(Please read the explanation of the first&nbsp;example carefully).</p>

<p>We want to <em>calculate the probability</em> that the two boxes have the same number of distinct balls.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> balls = [1,1]
<strong>Output:</strong> 1.00000
<strong>Explanation:</strong> Only 2 ways to divide the balls equally:
- A ball of color 1 to box 1 and a ball of color 2 to box 2
- A ball of color 2 to box 1 and a ball of color 1 to box 2
In both ways, the number of distinct colors in each box is equal. The probability is 2/2 = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> balls = [2,1,1]
<strong>Output:</strong> 0.66667
<strong>Explanation:</strong> We have the set of balls [1, 1, 2, 3]
This set of balls will be shuffled randomly and we may have one of the 12 distinct shuffles with equale probability (i.e. 1/12):
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
After that we add the first two balls to the first box and the second two balls to the second box.
We can see that 8 of these 12 possible random distributions have the same number of distinct colors of balls in each box.
Probability is 8/12 = 0.66667
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> balls = [1,2,1,2]
<strong>Output:</strong> 0.60000
<strong>Explanation:</strong> The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to display all the 180 possible random shuffles of this set but it is easy to check that 108 of them will have the same number of distinct colors in each box.
Probability = 108 / 180 = 0.6
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> balls = [3,2,1]
<strong>Output:</strong> 0.30000
<strong>Explanation:</strong> The set of balls is [1, 1, 1, 2, 2, 3]. It is hard to display all the 60 possible random shuffles of this set but it is easy to check that 18 of them will have the same number of distinct colors in each box.
Probability = 18 / 60 = 0.3
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> balls = [6,6,6,6,6,6]
<strong>Output:</strong> 0.90327
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= balls.length &lt;= 8</code></li>
	<li><code>1 &lt;= balls[i] &lt;= 6</code></li>
	<li><code>sum(balls)</code> is even.</li>
	<li>Answers within <code>10^-5</code> of the actual value will be accepted as correct.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1.

First, compute the total number of distinct shuffles. 

```
total = factorial(sum( A[i] | 0 <= i < k )) / ( factorial(A[0]) * factorial(A[1]) * ... * factorial(A[k-1]) )
```

where `factorial(x)` is the number of permutations of `x` different items. For example, `factorial(3) = 1 * 2 * 3 = 6`.

I denote the right-hand side of the above equation as `perm(A)` where `A` is an array of numbers. We'll need it later.

Then we need to compute the count of valid splits. Assume array `a` and `b` is a split of `A`, then:

* `size(a) == size(b) == size(A) == k`
* For each `0 <= i < k`, `a[i] + b[i] = A[i]`

For example, if `A = [1, 2, 2]`, then `a = [1, 0, 1]`, `b = [0, 2, 1]` is a *valid* split of `A`.

A split is valid if:
* Each of them contains half of the balls: `sum( a[i] | 0 <= i < k ) == sum( b[i] | 0 <= i < k ) == sum( A[i] | 0 <= i < k ) / 2`
* They contain equal number of distinct colors: `count(a) == count(b)` where `count(x)` is the number of positive numbers in array `x`.

For example, if `A = [1, 1, 2]`, then `a = [1, 0, 1]`, `b = [0, 1, 1]` is a split of `A`.

So we can use DFS to get different valid splits of `A`. For each valid split `a, b`, the count of distinct permutation of the split is `perm(a) * perm(b)` .

The answer is `total` divided by the sum of `perm(a) * perm(b)` of all valid splits `a, b`.

```cpp
// OJ: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/
// Author: github.com/lzl124631x
// Time: O((M+1)^K * K) where M is the maximum number of A[i]. It's O(7^8 * 8) given the constraints of this problem.
// Space: O(K)
class Solution {
    double perm(vector<int> &A) {
        double ans = 1;
        for (int i = 0, j = 1; i < A.size(); ++i) {
            int n = A[i];
            for (int k = 1; k <= n; ++k, ++j) ans = ans * j / k; 
        }
        return ans;
    }
    int sum = 0;
    double dfs(vector<int> &A, vector<int>& a, vector<int> &b, int i, int sa, int sb) {
        if (sa > sum / 2 || sb > sum / 2) return 0; // invalid split because either `a` or `b` takes up more than half of the balls.
        if (i == A.size()) {
            int ca = 0, cb = 0;
            for (int i = 0; i < A.size(); ++i) ca += a[i] > 0;
            for (int i = 0; i < A.size(); ++i) cb += b[i] > 0;
            if (ca != cb) return 0; // invalid split because `a` and `b` don't have the same number of distinct colors.
            return perm(a) * perm(b);
        }
        double ans = 0;
        for (int j = 0; j <= A[i]; ++j) { // try different splits at the `i`-th element, i.e. a[i] + b[i] = A[i]`
            a[i] = j;
            b[i] = A[i] - j;
            ans += dfs(A, a, b, i + 1, sa + a[i], sb + b[i]);
        }
        a[i] = b[i] = 0;
        return ans;
    }
public:
    double getProbability(vector<int>& A) {
        sum = accumulate(begin(A), end(A), 0);
        vector<int> a(A.size()), b(A.size());
        return dfs(A, a, b, 0, 0, 0) / perm(A);
    }
};
```