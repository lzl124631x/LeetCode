# [1825. Finding MK Average (Hard)](https://leetcode.com/problems/finding-mk-average)

<p>You are given two integers, <code>m</code> and <code>k</code>, and a stream of integers. You are tasked to implement a data structure that calculates the <strong>MKAverage</strong> for the stream.</p>

<p>The <strong>MKAverage</strong> can be calculated using these steps:</p>

<ol>
	<li>If the number of the elements in the stream is less than <code>m</code> you should consider the <strong>MKAverage</strong> to be <code>-1</code>. Otherwise, copy the last <code>m</code> elements of the stream to a separate container.</li>
	<li>Remove the smallest <code>k</code> elements and the largest <code>k</code> elements from the container.</li>
	<li>Calculate the average value for the rest of the elements <strong>rounded down to the nearest integer</strong>.</li>
</ol>

<p>Implement the <code>MKAverage</code> class:</p>

<ul>
	<li><code>MKAverage(int m, int k)</code> Initializes the <strong>MKAverage</strong> object with an empty stream and the two integers <code>m</code> and <code>k</code>.</li>
	<li><code>void addElement(int num)</code> Inserts a new element <code>num</code> into the stream.</li>
	<li><code>int calculateMKAverage()</code> Calculates and returns the <strong>MKAverage</strong> for the current stream <strong>rounded down to the nearest integer</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MKAverage&quot;, &quot;addElement&quot;, &quot;addElement&quot;, &quot;calculateMKAverage&quot;, &quot;addElement&quot;, &quot;calculateMKAverage&quot;, &quot;addElement&quot;, &quot;addElement&quot;, &quot;addElement&quot;, &quot;calculateMKAverage&quot;]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
<strong>Output</strong>
[null, null, null, -1, null, 3, null, null, null, 5]

<strong>Explanation</strong>
<code>MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // current elements are [3]
obj.addElement(1);        // current elements are [3,1]
obj.calculateMKAverage(); // return -1, because m = 3 and only 2 elements exist.
obj.addElement(10);       // current elements are [3,1,10]
obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
                          // After removing smallest and largest 1 element the container will be [3].
                          // The average of [3] equals 3/1 = 3, return 3
obj.addElement(5);        // current elements are [3,1,10,5]
obj.addElement(5);        // current elements are [3,1,10,5,5]
obj.addElement(5);        // current elements are [3,1,10,5,5,5]
obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
                          // After removing smallest and largest 1 element the container will be [5].
                          // The average of [5] equals 5/1 = 5, return 5
</code></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k*2 &lt; m</code></li>
	<li><code>1 &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>addElement</code> and <code>calculateMKAverage</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Design](https://leetcode.com/tag/design), [Queue](https://leetcode.com/tag/queue), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Data Stream](https://leetcode.com/tag/data-stream), [Ordered Set](https://leetcode.com/tag/ordered-set)

**Similar Questions**:
* [Find Median from Data Stream (Hard)](https://leetcode.com/problems/find-median-from-data-stream)
* [Kth Largest Element in a Stream (Easy)](https://leetcode.com/problems/kth-largest-element-in-a-stream)
* [Sequentially Ordinal Rank Tracker (Hard)](https://leetcode.com/problems/sequentially-ordinal-rank-tracker)

**Hints**:
* At each query, try to save and update the sum of the elements needed to calculate MKAverage.
* You can use BSTs for fast insertion and deletion of the elements.

## Solution 1. 3 Multisets

* Use 3 `multiset<int>` to track the top `k`, bottom `k` and middle elements.
* Use `queue<int> q` to track the current `m` numbers.
* Use `sum` to track the sum of numbers in `mid`.

```cpp
// OJ: https://leetcode.com/problems/finding-mk-average/
// Author: github.com/lzl124631x
// Time: 
//     MKAverage: O(1)
//     addElement: O(logM)
//     calculateMKAverage: O(1)
// Space: O(M)
class MKAverage {
    multiset<int> top, bot, mid;
    queue<int> q;
    long sum = 0, m, k;
public:
    MKAverage(int m, int k) : m(m), k(k) {}
    
    void addElement(int n) {
        if (q.size() < m) mid.insert(n); // when there are less than `m` numbers, always insert into `mid`.
        q.push(n);
        if (q.size() == m) {
            // when we reached exactly `m` numbers, we nudge numbers from `mid` to `top` and `bot`, and calculate `sum`.
            for (int i = 0; i < k; ++i) {
                bot.insert(*mid.begin());
                mid.erase(mid.begin());
            }
            for (int i = 0; i < k; ++i) {
                top.insert(*mid.rbegin());
                mid.erase(prev(mid.end()));
            }
            for (int x : mid) sum += x;
        } else if (q.size() > m) {
            // when we've seen more than `m` numbers. We first add the new number `n` to where it should belong.
            // If we add `n` to `top` or `bot`, we balance them with `mid` to make sure `top` and `bot` have exactly `k` numbers
            if (n < *bot.rbegin()) {
                bot.insert(n);
                int x = *bot.rbegin();
                bot.erase(prev(bot.end()));
                mid.insert(x);
                sum += x; 
            } else if (n > *top.begin()) {
                top.insert(n);
                int x = *top.begin();
                top.erase(top.begin());
                mid.insert(x);
                sum += x;
            } else {
                mid.insert(n);
                sum += n;
            }
            // Then we remove the number `rm` that is no longer one of the latest `m` numbers.
            int rm = q.front();
            q.pop();
            auto it = mid.find(rm);
            if (it != mid.end()) { // first try removing from `mid`, then `top` or `bot`.
                mid.erase(it);
                sum -= rm;
            } else {
                it = top.find(rm);
                if (it != top.end()) {
                    top.erase(it);
                } else {
                    bot.erase(bot.find(rm));
                }
            }
            // Lastly, balance `top` and `bot` if needed
            if (bot.size() < k) {
                int x = *mid.begin();
                bot.insert(x);
                mid.erase(mid.begin());
                sum -= x;
            } else if (top.size() < k) {
                int x = *mid.rbegin();
                top.insert(x);
                mid.erase(prev(mid.end()));
                sum -= x;
            }
        }
    }
    
    int calculateMKAverage() {
        return q.size() == m ? (sum / (m - 2 * k)) : -1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/finding-mk-average
// Author: github.com/lzl124631x
// Time: 
//     MKAverage: O(1)
//     addElement: O(logM)
//     calculateMKAverage: O(1)
// Space: O(M)
class MKAverage {
    multiset<int> top, mid, bot;
    queue<int> q;
    long m, k, sum = 0;
public:
    MKAverage(int m, int k) : m(m), k(k) {
    }
    void addElement(int n) {
        q.push(n);
        if (q.size() > m) {
            int rm = q.front();
            q.pop();
            if (*top.begin() <= rm) {
                top.erase(top.find(rm));
                rm = *mid.rbegin();
                top.insert(rm);
            }
            if (*mid.begin() <= rm) {
                mid.erase(mid.find(rm));
                sum -= rm;
                rm = *bot.rbegin();
                mid.insert(rm);
                sum += rm;
            }
            bot.erase(bot.find(rm));
        }
        if (top.size() < k || n > *top.begin()) {
            top.insert(n);
            if (top.size() <= k) return;
            n = *top.begin();
            top.erase(top.begin());
        }
        if (mid.size() < m - 2 * k || n > *mid.begin()) {
            mid.insert(n);
            sum += n;
            if (mid.size() <= m - 2 * k) return;
            n = *mid.begin();
            sum -= n;
            mid.erase(mid.begin());
        }
        bot.insert(n);
    }
    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return sum / (m - 2 * k);
    }
};
```

## TODO

Try BIT: https://leetcode.com/problems/finding-mk-average/discuss/1152438/Python3-Fenwick-tree