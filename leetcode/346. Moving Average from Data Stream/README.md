# [346. Moving Average from Data Stream (Easy)](https://leetcode.com/problems/moving-average-from-data-stream/)

<p>Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.</p>

<p><strong>Example:</strong></p>

<pre>MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
</pre>

<p>&nbsp;</p>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Twitter](https://leetcode.com/company/twitter), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Queue](https://leetcode.com/tag/queue/)

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