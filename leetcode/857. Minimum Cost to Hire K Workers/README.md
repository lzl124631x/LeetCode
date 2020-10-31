# [857. Minimum Cost to Hire K Workers (Hard)](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)

<p>There are <code>N</code> workers.&nbsp; The <code>i</code>-th worker has a <code>quality[i]</code> and a minimum wage expectation <code>wage[i]</code>.</p>

<p>Now we want to hire exactly <code>K</code>&nbsp;workers to form a <em>paid group</em>.&nbsp; When hiring a group of K workers, we must pay them according to the following rules:</p>

<ol>
	<li>Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.</li>
	<li>Every worker in the paid group must be paid at least their minimum wage expectation.</li>
</ol>

<p>Return the least amount of money needed to form a paid group satisfying the above conditions.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>quality = <span id="example-input-1-1">[10,20,5]</span>, wage = <span id="example-input-1-2">[70,50,30]</span>, K = <span id="example-input-1-3">2</span>
<strong>Output: </strong><span id="example-output-1">105.00000
<strong>Explanation</strong>: </span><span>We pay 70 to 0-th worker and 35 to 2-th worker.</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>quality = <span id="example-input-2-1">[3,1,10,10,1]</span>, wage = <span id="example-input-2-2">[4,8,2,2,7]</span>, K = <span id="example-input-2-3">3</span>
<strong>Output: </strong><span id="example-output-2">30.66667
<strong>Explanation</strong>: </span><span>We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately.</span> 
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= K &lt;= N &lt;= 10000</code>, where <code>N = quality.length = wage.length</code></li>
	<li><code>1 &lt;= quality[i] &lt;= 10000</code></li>
	<li><code>1 &lt;= wage[i] &lt;= 10000</code></li>
	<li>Answers within <code>10^-5</code> of the correct answer will be considered correct.</li>
</ol>
</div>
</div>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/)

## TLE version. Greedy

Try `person[i]` as the baseline. Use her `W[i] / Q[i]` as the factor to get others' wages. Drop those who can't meet their min wages.

For the rest, sum the smallest `K` wages.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solution/
// NOTE: this solution will get TLE
class Solution {
public:
    double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
        int N = Q.size();
        double ans = DBL_MAX;
        for (int i = 0; i < N; ++i) {
            double factor = (double) W[i] / Q[i];
            vector<double> costs;
            for (int j = 0; j < N; ++j) {
                double c = factor * Q[j];
                if (c < W[j]) continue;
                costs.push_back(c);
            }
            if (costs.size() < K) continue;
            sort(costs.begin(), costs.end());
            double sum = accumulate(costs.begin(), costs.begin() + K, 0.0);
            ans = min(ans, sum);
        }
        return ans;
    }
};
```

## Solution 1. Max Heap

If we select `person[i]` as the benchmark, `W[i]/Q[i]` will be used as the `rate`. All other people get `Q[j] * rate`.

If `Q[j] * rate[i]` is smaller than `W[j]`, i.e. `Q[j] * rate[i] < W[j]`, or `rate[i] < rate[j]`, `person[j]` can't work.

So `rate[i]` can only make the people with equal or smaller rates to be able to work.

* The greatest rate can make all people work, but results in greater total wage.
* The smaller rate can make less people work, but results in smaller total wage.

Hence we can iterate people in ascending order of rate.

We use a max heap `pq` to keep the qualities of people, and `sum` to track the sum of qualities of people in the `pq`.

For `person[i]`, we add her quality into the `pq`. And pop if the `pq` has more than `K` people. We update the `sum` accordingly.

If there are `K` people in the `pq`, then `sum * rate[i]` is the total wage. We just need to find the minimal total wage.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& Q, vector<int>& W, int K) {
        int N = Q.size(), sum = 0;
        double ans = DBL_MAX; 
        vector<int> id(N);
        vector<double> rate(N);
        for (int i = 0; i < N; ++i) rate[i] = (double)W[i] / Q[i];
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return rate[a] < rate[b]; });
        priority_queue<int> pq;
        for (int i = 0; i < N; ++i) {
            sum += Q[id[i]];
            pq.push(Q[id[i]]);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) ans = min(ans, rate[id[i]] * sum);
        }
        return ans;
    }
};
```