# [1093. Statistics from a Large Sample (Medium)](https://leetcode.com/problems/statistics-from-a-large-sample/)

<p>You are given a large sample of integers in the range <code>[0, 255]</code>. Since the sample is so large, it is represented by an array <code>count</code>&nbsp;where <code>count[k]</code> is the <strong>number of times</strong> that <code>k</code> appears in the sample.</p>

<p>Calculate the following statistics:</p>

<ul>
	<li><code>minimum</code>: The minimum element in the sample.</li>
	<li><code>maximum</code>: The maximum element in the sample.</li>
	<li><code>mean</code>: The average of the sample, calculated as the total sum of all elements divided by the total number of elements.</li>
	<li><code>median</code>:
	<ul>
		<li>If the sample has an odd number of elements, then the <code>median</code> is the middle element once the sample is sorted.</li>
		<li>If the sample has an even number of elements, then the <code>median</code> is the average of the two middle elements once the sample is sorted.</li>
	</ul>
	</li>
	<li><code>mode</code>: The number that appears the most in the sample. It is guaranteed to be <strong>unique</strong>.</li>
</ul>

<p>Return <em>the statistics of the sample as an array of floating-point numbers </em><code>[minimum, maximum, mean, median, mode]</code><em>. Answers within </em><code>10<sup>-5</sup></code><em> of the actual answer will be accepted.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>Output:</strong> [1.00000,3.00000,2.37500,2.50000,3.00000]
<strong>Explanation:</strong> The sample represented by count is [1,2,2,2,3,3,3,3].
The minimum and maximum are 1 and 3 respectively.
The mean is (1+2+2+2+3+3+3+3) / 8 = 19 / 8 = 2.375.
Since the size of the sample is even, the median is the average of the two middle elements 2 and 3, which is 2.5.
The mode is 3 as it appears the most in the sample.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>Output:</strong> [1.00000,4.00000,2.18182,2.00000,1.00000]
<strong>Explanation:</strong> The sample represented by count is [1,1,1,1,2,2,2,3,3,4,4].
The minimum and maximum are 1 and 4 respectively.
The mean is (1+1+1+1+2+2+2+3+3+4+4) / 11 = 24 / 11 = 2.18181818... (for display purposes, the output shows the rounded number 2.18182).
Since the size of the sample is odd, the median is the middle element 2.
The mode is 1 as it appears the most in the sample.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>count.length == 256</code></li>
	<li><code>0 &lt;= count[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= sum(count) &lt;= 10<sup>9</sup></code></li>
	<li>The mode of the sample that <code>count</code> represents is <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Probability and Statistics](https://leetcode.com/tag/probability-and-statistics/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/statistics-from-a-large-sample/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<double> sampleStats(vector<int>& A) {
        int mx = 0, mn = 255, cnt = 0, total = accumulate(begin(A), end(A), 0), mid = (total + 1) / 2, mode = -1, first = -1;
        long sum = 0;
        double median = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) continue;
            mx = max(mx, i);
            mn = min(mn, i);
            sum += (long)A[i] * i;
            if (median == -1) {
                if (first != -1) {
                    median = (double)(first + i) / 2;
                } else if (cnt < mid && cnt + A[i] >= mid) {
                    if (total % 2 || cnt + A[i] > mid) median = i;
                    else first = i;
                }
            }
            cnt += A[i];
            if (mode == -1 || A[i] > A[mode]) mode = i;
        }
        return { (double)mn, (double)mx, (double)sum / total, median, (double)mode };
    }
};
```