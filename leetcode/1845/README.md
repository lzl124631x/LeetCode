# [1845. Seat Reservation Manager (Medium)](https://leetcode.com/problems/seat-reservation-manager)

<p>Design a system that manages the reservation state of <code>n</code> seats that are numbered from <code>1</code> to <code>n</code>.</p>

<p>Implement the <code>SeatManager</code> class:</p>

<ul>
	<li><code>SeatManager(int n)</code> Initializes a <code>SeatManager</code> object that will manage <code>n</code> seats numbered from <code>1</code> to <code>n</code>. All seats are initially available.</li>
	<li><code>int reserve()</code> Fetches the <strong>smallest-numbered</strong> unreserved seat, reserves it, and returns its number.</li>
	<li><code>void unreserve(int seatNumber)</code> Unreserves the seat with the given <code>seatNumber</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;SeatManager&quot;, &quot;reserve&quot;, &quot;reserve&quot;, &quot;unreserve&quot;, &quot;reserve&quot;, &quot;reserve&quot;, &quot;reserve&quot;, &quot;reserve&quot;, &quot;unreserve&quot;]
[[5], [], [], [2], [], [], [], [], [5]]
<strong>Output</strong>
[null, 1, 2, null, 2, 3, 4, 5, null]

<strong>Explanation</strong>
SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
seatManager.reserve();    // The only available seat is seat 5, so return 5.
seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= seatNumber &lt;= n</code></li>
	<li>For each call to <code>reserve</code>, it is guaranteed that there will be at least one unreserved seat.</li>
	<li>For each call to <code>unreserve</code>, it is guaranteed that <code>seatNumber</code> will be reserved.</li>
	<li>At most <code>10<sup>5</sup></code> calls <strong>in total</strong> will be made to <code>reserve</code> and <code>unreserve</code>.</li>
</ul>


**Companies**:
[Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Design](https://leetcode.com/tag/design), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Similar Questions**:
* [Design Phone Directory (Medium)](https://leetcode.com/problems/design-phone-directory)
* [Design a Number Container System (Medium)](https://leetcode.com/problems/design-a-number-container-system)

**Hints**:
* You need a data structure that maintains the states of the seats. This data structure should also allow you to get the first available seat and flip the state of a seat in a reasonable time.
* You can let the data structure contain the available seats. Then you want to be able to get the lowest element and erase an element, in a reasonable time.
* Ordered sets support these operations.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/seat-reservation-manager
// Author: github.com/lzl124631x
// Time:
//      SeatManager: O(NlogN)
//      reserve: O(1)
//      unreserve: O(logN)
// Space: O(N)
class SeatManager {
    set<int> s;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) s.insert(i);
    }
    int reserve() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/seat-reservation-manager/
// Author: github.com/lzl124631x
// Time:
//      SeatManager: O(1)
//      reserve: O(1)
//      unreserve: O(logN)
// Space: O(U) where U is the number of unreserves.
class SeatManager {
    set<int> unr;
    int cur = 0;
public:
    SeatManager(int n) {}
    int reserve() {
        if (unr.size()) {
            int r = *unr.begin();
            unr.erase(r);
            return r;
        }
        return ++cur;
    }
    void unreserve(int seatNumber) {
        unr.insert(seatNumber);
    }
};
```