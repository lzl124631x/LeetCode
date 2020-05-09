# [295. Find Median from Data Stream (Hard)](https://leetcode.com/problems/find-median-from-data-stream/)

<p>Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.</p>
For example,

<p><code>[2,3,4]</code>, the median is <code>3</code></p>

<p><code>[2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code></p>

<p>Design a data structure that supports the following two operations:</p>

<ul>
	<li>void addNum(int num) - Add a integer number from the data stream to the data structure.</li>
	<li>double findMedian() - Return the median of all elements so far.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre>addNum(1)
addNum(2)
findMedian() -&gt; 1.5
addNum(3) 
findMedian() -&gt; 2
</pre>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ol>
	<li>If all integer numbers from the stream are between 0&nbsp;and 100, how would you optimize it?</li>
	<li>If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?</li>
</ol>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Sliding Window Median (Hard)](https://leetcode.com/problems/sliding-window-median/)

## Solution 1. Heap

```cpp
// OJ: https://leetcode.com/problems/find-median-from-data-stream/
// Author: github.com/lzl124631x
// Time:
//      MedianFinder: O(1)
//      addNum: O(logN)
//      findMedian: O(1)
// Space: O(N)
class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> great;
public:
    MedianFinder() {}
    void addNum(int num) {
        if (great.size() && num >= great.top()) {
            great.push(num);
            if (great.size() > small.size() + 1) {
                int n = great.top();
                small.push(n);
                great.pop();
            }
        } else {
            small.push(num);
            if (small.size() > great.size() + 1) {
                int n = small.top();
                great.push(n);
                small.pop();
            }
        }
    }
    double findMedian() {
        return small.size() == great.size() ? (small.top() + great.top()) / 2. : (small.size() > great.size() ? small.top() : great.top());
    }
};
```