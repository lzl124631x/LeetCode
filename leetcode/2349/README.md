# [2349. Design a Number Container System (Medium)](https://leetcode.com/problems/design-a-number-container-system)

<p>Design a number container system that can do the following:</p>

<ul>
	<li><strong>Insert </strong>or <strong>Replace</strong> a number at the given index in the system.</li>
	<li><strong>Return </strong>the smallest index for the given number in the system.</li>
</ul>

<p>Implement the <code>NumberContainers</code> class:</p>

<ul>
	<li><code>NumberContainers()</code> Initializes the number container system.</li>
	<li><code>void change(int index, int number)</code> Fills the container at <code>index</code> with the <code>number</code>. If there is already a number at that <code>index</code>, replace it.</li>
	<li><code>int find(int number)</code> Returns the smallest index for the given <code>number</code>, or <code>-1</code> if there is no index that is filled by <code>number</code> in the system.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;NumberContainers&quot;, &quot;find&quot;, &quot;change&quot;, &quot;change&quot;, &quot;change&quot;, &quot;change&quot;, &quot;find&quot;, &quot;change&quot;, &quot;find&quot;]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
<strong>Output</strong>
[null, -1, null, null, null, null, 1, null, 2]

<strong>Explanation</strong>
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= index, number &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made <strong>in total</strong> to <code>change</code> and <code>find</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [Design](https://leetcode.com/tag/design), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Ordered Set](https://leetcode.com/tag/ordered-set)

**Similar Questions**:
* [Seat Reservation Manager (Medium)](https://leetcode.com/problems/seat-reservation-manager)
* [Design a Food Rating System (Medium)](https://leetcode.com/problems/design-a-food-rating-system)

**Hints**:
* Use a hash table to efficiently map each number to all of its indices in the container and to map each index to their current number.
* In addition, you can use ordered set to store all of the indices for each number to solve the find method. Do not forget to update the ordered set according to the change method.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-a-number-container-system
// Author: github.com/lzl124631x
// Time:
//      NumberContainers: O(1)
//      change: O(logN)
//      find: O(1)
// Space: O(N)
class NumberContainers {
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
public:
    NumberContainers() {
    }
    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) numberToIndices.erase(oldNumber);
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    int find(int n) {
        if (numberToIndices.count(n) == 0) return -1;
        return *numberToIndices[n].begin();
    }
};
```