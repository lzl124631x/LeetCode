# [2526. Find Consecutive Integers from a Data Stream (Medium)](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream)

<p>For a stream of integers, implement a data structure that checks if the last <code>k</code> integers parsed in the stream are <strong>equal</strong> to <code>value</code>.</p>

<p>Implement the <strong>DataStream</strong> class:</p>

<ul>
	<li><code>DataStream(int value, int k)</code> Initializes the object with an empty integer stream and the two integers <code>value</code> and <code>k</code>.</li>
	<li><code>boolean consec(int num)</code> Adds <code>num</code> to the stream of integers. Returns <code>true</code> if the last <code>k</code> integers are equal to <code>value</code>, and <code>false</code> otherwise. If there are less than <code>k</code> integers, the condition does not hold true, so returns <code>false</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;DataStream&quot;, &quot;consec&quot;, &quot;consec&quot;, &quot;consec&quot;, &quot;consec&quot;]
[[4, 3], [4], [4], [4], [3]]
<strong>Output</strong>
[null, false, false, true, false]

<strong>Explanation</strong>
DataStream dataStream = new DataStream(4, 3); //value = 4, k = 3 
dataStream.consec(4); // Only 1 integer is parsed, so returns False. 
dataStream.consec(4); // Only 2 integers are parsed.
                      // Since 2 is less than k, returns False. 
dataStream.consec(4); // The 3 integers parsed are all equal to value, so returns True. 
dataStream.consec(3); // The last k integers parsed in the stream are [4,4,3].
                      // Since 3 is not equal to value, it returns False.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= value, num &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>consec</code>.</li>
</ul>


**Companies**:
[Intel](https://leetcode.com/company/intel)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [Design](https://leetcode.com/tag/design), [Queue](https://leetcode.com/tag/queue), [Counting](https://leetcode.com/tag/counting), [Data Stream](https://leetcode.com/tag/data-stream)

**Similar Questions**:
* [Number of Zero-Filled Subarrays (Medium)](https://leetcode.com/problems/number-of-zero-filled-subarrays)

**Hints**:
* Keep track of the last integer which is not equal to <code>value</code>.
* Use a queue-type data structure to store the last <code>k</code> integers.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream
// Author: github.com/lzl124631x
// Time:
//      DataStream: O(1)
//      consec: O(1)
// Space: O(K)
class DataStream {
    queue<int> q;
    int value, k, cnt = 0;
public:
    DataStream(int value, int k) : value(value), k(k) {
    }
    bool consec(int n) {
        q.push(n);
        cnt += n == value;
        if (q.size() > k){
            int x = q.front();
            q.pop();
            cnt -= x == value;
        }
        return cnt == k;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(1)
class DataStream {
    int value, k, cnt = 0;
public:
    DataStream(int value, int k) : value(value), k(k) {}
    bool consec(int n) {
        if (n == value) cnt++;
        else cnt = 0;
        return cnt >= k;
    }
};
```