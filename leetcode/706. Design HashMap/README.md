# [706. Design HashMap (Easy)](https://leetcode.com/problems/design-hashmap/)

<p>Design a HashMap&nbsp;without using any built-in hash table libraries.</p>

<p>To be specific, your design should include these functions:</p>

<ul>
	<li><code>put(key, value)</code> :&nbsp;Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.</li>
	<li><code>get(key)</code>: Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.</li>
	<li><code>remove(key)</code> :&nbsp;Remove the mapping for the value key if this map contains the mapping for the key.</li>
</ul>

<p><br>
<strong>Example:</strong></p>

<pre>MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
hashMap.put(2, 2); &nbsp; &nbsp; &nbsp; &nbsp; 
hashMap.get(1); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// returns 1
hashMap.get(3); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// returns -1 (not found)
hashMap.put(2, 1); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// update the existing value
hashMap.get(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// returns 1 
hashMap.remove(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// remove the mapping for 2
hashMap.get(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;// returns -1 (not found) 
</pre>

<p><br>
<strong>Note:</strong></p>

<ul>
	<li>All keys and values will be in the range of <code>[0, 1000000]</code>.</li>
	<li>The number of operations will be in the range of&nbsp;<code>[1, 10000]</code>.</li>
	<li>Please do not use the built-in HashMap library.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Salesforce](https://leetcode.com/company/salesforce), [LinkedIn](https://leetcode.com/company/linkedin), [Twitter](https://leetcode.com/company/twitter), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Design HashSet (Easy)](https://leetcode.com/problems/design-hashset/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-hashmap/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class MyHashMap {
private:
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