# [641. Design Circular Deque (Medium)](https://leetcode.com/problems/design-circular-deque/)

<p>Design your implementation of the circular double-ended queue (deque).</p>

<p>Your implementation should support following operations:</p>

<ul>
	<li><code>MyCircularDeque(k)</code>: Constructor, set the size of the deque to be k.</li>
	<li><code>insertFront()</code>: Adds an item at the front of Deque. Return true if the operation is successful.</li>
	<li><code>insertLast()</code>: Adds an item at the rear of Deque. Return true if the operation is successful.</li>
	<li><code>deleteFront()</code>: Deletes an item from the front of Deque. Return true if the operation is successful.</li>
	<li><code>deleteLast()</code>: Deletes an item from the rear of Deque. Return true if the operation is successful.</li>
	<li><code>getFront()</code>: Gets the front item from the Deque. If the deque is empty, return -1.</li>
	<li><code>getRear()</code>: Gets the last item from Deque. If the deque is empty, return -1.</li>
	<li><code>isEmpty()</code>: Checks whether Deque is empty or not.&nbsp;</li>
	<li><code>isFull()</code>: Checks whether Deque is full or not.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre>MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li>All values will be in the range of [0, 1000].</li>
	<li>The number of operations will be in the range of&nbsp;[1, 1000].</li>
	<li>Please do not use the built-in Deque library.</li>
</ul>


**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Queue](https://leetcode.com/tag/queue/)

**Similar Questions**:
* [Design Circular Queue (Medium)](https://leetcode.com/problems/design-circular-queue/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-circular-deque/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(K)
class MyCircularDeque {
    vector<int> q;
    int begin = 0, end = 0, k, cnt = 0;
public:
    MyCircularDeque(int k) : q(k), k(k) {}
    bool insertFront(int value) {
        if (cnt == k) return false;
        begin = (begin - 1 + k) % k;
        q[begin] = value;
        ++cnt;
        return true;
    }
    bool insertLast(int value) {
        if (cnt == k) return false;
        q[end] = value;
        end = (end + 1) % k;
        ++cnt;
        return true;
    }
    bool deleteFront() {
        if (cnt == 0) return false;
        begin = (begin + 1) % k;
        --cnt;
        return true;
    }
    bool deleteLast() {
        if (cnt == 0) return false;
        end = (end - 1 + k) % k;
        --cnt;
        return true;
    }
    int getFront() {
        if (cnt == 0) return -1;
        return q[begin];
    }
    int getRear() {
        if (cnt == 0) return -1;
        return q[(end - 1 + k) % k];
    }
    bool isEmpty() {
        return cnt == 0;
    }
    bool isFull() {
        return cnt == k;
    }
};
```