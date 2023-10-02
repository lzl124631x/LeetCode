# [622. Design Circular Queue (Medium)](https://leetcode.com/problems/design-circular-queue/)

<p>Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".</p>

<p>One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.</p>

<p>Your implementation should support following operations:</p>

<ul>
	<li><code>MyCircularQueue(k)</code>: Constructor, set the size of the queue to be k.</li>
	<li><code>Front</code>: Get the front item from the queue. If the queue is empty, return -1.</li>
	<li><code>Rear</code>: Get the last item from the queue. If the queue is empty, return -1.</li>
	<li><code>enQueue(value)</code>: Insert an element into the circular queue. Return true if the operation is successful.</li>
	<li><code>deQueue()</code>: Delete an element from the circular queue. Return true if the operation is successful.</li>
	<li><code>isEmpty()</code>: Checks whether the circular queue is empty or not.</li>
	<li><code>isFull()</code>: Checks whether the circular queue is full or not.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre>MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1); &nbsp;// return true
circularQueue.enQueue(2); &nbsp;// return true
circularQueue.enQueue(3); &nbsp;// return true
circularQueue.enQueue(4); &nbsp;// return false, the queue is full
circularQueue.Rear(); &nbsp;// return 3
circularQueue.isFull(); &nbsp;// return true
circularQueue.deQueue(); &nbsp;// return true
circularQueue.enQueue(4); &nbsp;// return true
circularQueue.Rear(); &nbsp;// return 4
</pre>
&nbsp;

<p><strong>Note:</strong></p>

<ul>
	<li>All values will be in the range of [0, 1000].</li>
	<li>The number of operations will be in the range of&nbsp;[1, 1000].</li>
	<li>Please do not use the built-in Queue library.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Queue](https://leetcode.com/tag/queue/)

**Similar Questions**:
* [Design Circular Deque (Medium)](https://leetcode.com/problems/design-circular-deque/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-circular-queue/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(K)
class MyCircularQueue {
private:
    vector<int> v;
    int start = 0, len = 0;
public:
    MyCircularQueue(int k): v(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        v[(start + len++) % v.size()] = value;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % v.size();
        --len;
        return true;
    }
    int Front() {
        if (isEmpty()) return -1;
        return v[start];
    }
    int Rear() {
        if (isEmpty()) return -1;
        return v[(start + len - 1) % v.size()];
    }
    bool isEmpty() {
        return !len;
    }
    bool isFull() {
        return len == v.size();
    }
};
```