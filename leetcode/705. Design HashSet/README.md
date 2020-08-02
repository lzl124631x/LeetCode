# [705. Design HashSet (Easy)](https://leetcode.com/problems/design-hashset/)

<p>Design a HashSet&nbsp;without using any built-in hash table libraries.</p>

<p>To be specific, your design should include these functions:</p>

<ul>
	<li><code>add(value)</code>:&nbsp;Insert a value into the HashSet.&nbsp;</li>
	<li><code>contains(value)</code> : Return whether the value exists in the HashSet or not.</li>
	<li><code>remove(value)</code>: Remove a value in&nbsp;the HashSet. If the value does not exist in the HashSet, do nothing.</li>
</ul>

<p><br>
<strong>Example:</strong></p>

<pre>MyHashSet hashSet = new MyHashSet();
hashSet.add(1); &nbsp; &nbsp; &nbsp; &nbsp; 
hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; 
hashSet.contains(1); &nbsp;&nbsp;&nbsp;// returns true
hashSet.contains(3); &nbsp;&nbsp;&nbsp;// returns false (not found)
hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
hashSet.contains(2); &nbsp;&nbsp;&nbsp;// returns true
hashSet.remove(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
hashSet.contains(2); &nbsp;&nbsp;&nbsp;// returns false (already removed)
</pre>

<p><br>
<strong>Note:</strong></p>

<ul>
	<li>All values will be in the range of <code>[0, 1000000]</code>.</li>
	<li>The number of operations will be in the range of&nbsp;<code>[1, 10000]</code>.</li>
	<li>Please do not use the built-in HashSet library.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Design HashMap (Easy)](https://leetcode.com/problems/design-hashmap/)
* [Design Skiplist (Hard)](https://leetcode.com/problems/design-skiplist/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-hashset/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashSet {
private:
    bitset<1000001> bs; 
public:
    MyHashSet() {}
    void add(int key) { bs.set(key); }
    void remove(int key) { bs.reset(key); }
    bool contains(int key) { return bs.test(key); }
};
```