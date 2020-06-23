# [901. Online Stock Span (Medium)](https://leetcode.com/problems/online-stock-span/)

<p>Write a class <code>StockSpanner</code> which collects daily price quotes for some stock, and returns the <em>span</em>&nbsp;of that stock's price for the current day.</p>

<p>The span of the stock's price today&nbsp;is defined as the maximum number of consecutive days (starting from today and going backwards)&nbsp;for which the price of the stock was less than or equal to today's price.</p>

<p>For example, if the price of a stock over the next 7 days were <code>[100, 80, 60, 70, 60, 75, 85]</code>, then the stock spans would be <code>[1, 1, 1, 2, 1, 4, 6]</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["StockSpanner","next","next","next","next","next","next","next"]</span>, <span id="example-input-1-2">[[],[100],[80],[60],[70],[60],[75],[85]]</span>
<strong>Output: </strong><span id="example-output-1">[null,1,1,1,2,1,4,6]</span>
<strong>Explanation: </strong>
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>Calls to <code>StockSpanner.next(int price)</code> will have <code>1 &lt;= price &lt;= 10^5</code>.</li>
	<li>There will be at most <code>10000</code> calls to <code>StockSpanner.next</code>&nbsp;per test case.</li>
	<li>There will be at most <code>150000</code> calls to <code>StockSpanner.next</code> across all test cases.</li>
	<li>The total&nbsp;time limit for this problem has been reduced by 75% for&nbsp;C++, and 50% for all other languages.</li>
</ol>
</div>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1.

Consider input `[5,3,1,2,4]`. When we scan `4`, we take a look at the previous value `2` which is smaller than `4` so we should continue scanning. We don't need to scan leftwards one by one if we store the index of the previous larger number.

```
index:  0  1  2  3  4
val:    5  3  1  2  4
prev:  -1  0  1  1  0
```

So when scanning `4`, we take a look at `2` first, and since it's smaller than `4`, we can jump to `prev[3] = 1`. The value at `1` is `3` which is again smaller so we continue to jump to `prev[1] = 0` and we see `5` which is greater, so we can know that the span is `4 - 0 = 4`.

```cpp
// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(N)
class StockSpanner {
    vector<int> val = {INT_MAX}, prev = {-1};
public:
    StockSpanner() {}
    
    int next(int price) {
        int i = val.size() - 1;
        while (val[i] <= price) i = prev[i];
        val.push_back(price);
        prev.push_back(i);
        return val.size() - i - 1;
    }
};
```

## Solution 1. Monotonic Stack

We don't need to store those intermediate smaller values since they will be skipped by jumping with the `prev` values.

```cpp
// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(N)
class StockSpanner {
    stack<pair<int, int>> s; // val, index
    int i = 0;
public:
    StockSpanner() {
        s.emplace(INT_MAX, -1);
    }
    int next(int price) {
        while (s.top().first <= price) s.pop();
        int span = i - s.top().second;
        s.emplace(price, i++);
        return span;
    }
};
```