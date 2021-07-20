# [706. Design HashMap (Easy)](https://leetcode.com/problems/design-hashmap/)

<p>Design a HashMap without using any built-in hash table libraries.</p>

<p>Implement the <code>MyHashMap</code> class:</p>

<ul>
	<li><code>MyHashMap()</code> initializes the object with an empty map.</li>
	<li><code>void put(int key, int value)</code> inserts a <code>(key, value)</code> pair into the HashMap. If the <code>key</code> already exists in the map, update the corresponding <code>value</code>.</li>
	<li><code>int get(int key)</code> returns the <code>value</code> to which the specified <code>key</code> is mapped, or <code>-1</code> if this map contains no mapping for the <code>key</code>.</li>
	<li><code>void remove(key)</code> removes the <code>key</code> and its corresponding <code>value</code> if the map contains the mapping for the <code>key</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>Output</strong>
[null, null, null, 1, -1, null, 1, null, -1]

<strong>Explanation</strong>
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>put</code>, <code>get</code>, and <code>remove</code>.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Twitter](https://leetcode.com/company/twitter), [ServiceNow](https://leetcode.com/company/servicenow), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Design HashSet (Easy)](https://leetcode.com/problems/design-hashset/)
* [Design Skiplist (Hard)](https://leetcode.com/problems/design-skiplist/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-hashmap/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashMap {
    const static int N = 1000001;
    int m[N];
public:
    MyHashMap() {
        for (int i = 0; i < N; ++i) m[i] = -1;
    }
    void put(int key, int value) {
        m[key] = value;
    }
    int get(int key) {
        return m[key];
    }
    void remove(int key) {
        m[key] = -1;
    }
};
```