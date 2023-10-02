# [715. Range Module (Hard)](https://leetcode.com/problems/range-module/)

<p>A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.</p>

<p></p><li><code>addRange(int left, int right)</code> Adds the half-open interval <code>[left, right)</code>, tracking every real number in that interval.  Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval <code>[left, right)</code> that are not already tracked.</li><p></p>

<p></p><li><code>queryRange(int left, int right)</code> Returns true if and only if every real number in the interval <code>[left, right)</code>
 is currently being tracked.</li><p></p>

<p></p><li><code>removeRange(int left, int right)</code> Stops tracking every real number currently being tracked in the interval <code>[left, right)</code>.</li><p></p>

<p><b>Example 1:</b><br>
</p><pre><b>addRange(10, 20)</b>: null
<b>removeRange(14, 16)</b>: null
<b>queryRange(10, 14)</b>: true (Every number in [10, 14) is being tracked)
<b>queryRange(13, 15)</b>: false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
<b>queryRange(16, 17)</b>: true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
</pre>
<p></p>

<p><b>Note:</b>
</p><li>A half open interval <code>[left, right)</code> denotes all real numbers <code>left &lt;= x &lt; right</code>.</li>

<li><code>0 &lt; left &lt; right &lt; 10^9</code> in all calls to <code>addRange, queryRange, removeRange</code>.</li>
<li>The total number of calls to <code>addRange</code> in a single test case is at most <code>1000</code>.</li>
<li>The total number of calls to <code>queryRange</code> in a single test case is at most <code>5000</code>.</li>
<li>The total number of calls to <code>removeRange</code> in a single test case is at most <code>1000</code>.</li>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Segment Tree](https://leetcode.com/tag/segment-tree/), [Ordered Map](https://leetcode.com/tag/ordered-map/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Insert Interval (Medium)](https://leetcode.com/problems/insert-interval/)
* [Data Stream as Disjoint Intervals (Hard)](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/range-module/
// Author: github.com/lzl124631x
// Time: 
//      RangeModule: O(1)
//      addRange: O(N)
//      queryRange: O(logN)
//      removeRange: O(N)
// Space: O(N)
class RangeModule {
    map<int, int> m;
public:
    RangeModule() {}
    void addRange(int left, int right) {
        auto it = m.lower_bound(left);
        if (it != begin(m) && prev(it)->second >= left) --it;
        if (it != end(m)) left = min(left, it->first);
        while (it != end(m) && it->first <= right) {
            if (it->second <= right) it = m.erase(it);
            else {
                right = it->second;
                it = m.erase(it);
                right = it->second;
                break;
            }
        }
        m[left] = right;
    }
    bool queryRange(int left, int right) {
        auto it = m.lower_bound(left);
        if (it != begin(m) && prev(it)->second > left) --it;
        if (it == end(m)) return false;
        return it->first <= left && it->second >= right;
    }
    void removeRange(int left, int right) {
        auto it = m.lower_bound(left);
        if (it != begin(m) && prev(it)->second > left) {
            --it;
            int r = it->second;
            it->second = left;
            if (right < r) {
                m[right] = r;
                return;
            }
            ++it;
        }
        while (it != end(m) && it->first < right) {
            if (it->second <= right) it = m.erase(it);
            else {
                int r = it->second;
                m.erase(it);
                m[right] = r;
                break;
            }
        }
    }
};
```

## TODO

Hard to get it right. Learn https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions