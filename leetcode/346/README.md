# [346. Moving Average from Data Stream (Easy)](https://leetcode.com/problems/moving-average-from-data-stream)

<p>Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.</p>

<p>Implement the&nbsp;<code>MovingAverage</code> class:</p>

<ul>
	<li><code>MovingAverage(int size)</code> Initializes&nbsp;the object with the size of the window <code>size</code>.</li>
	<li><code>double next(int val)</code> Returns the moving average of the last <code>size</code> values of the stream.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MovingAverage&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;, &quot;next&quot;]
[[3], [1], [10], [3], [5]]
<strong>Output</strong>
[null, 1.0, 5.5, 4.66667, 6.0]

<strong>Explanation</strong>
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= size &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= val &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>next</code>.</li>
</ul>


**Companies**:
[Facebook](https://leetcode.com/company/facebook), [Spotify](https://leetcode.com/company/spotify), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Design](https://leetcode.com/tag/design), [Queue](https://leetcode.com/tag/queue), [Data Stream](https://leetcode.com/tag/data-stream)

**Similar Questions**:
* [K Radius Subarray Averages (Medium)](https://leetcode.com/problems/k-radius-subarray-averages)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/moving-average-from-data-stream/
// Author: github.com/lzl124631x
// Time:
//     MovingAverage: O(1)
//     next: O(1)
// Space: O(S)
class MovingAverage {
private:
    queue<int> q;
    int size, sum = 0;
public:
    MovingAverage(int size) : size(size) { }
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum / q.size();
    }
};
```