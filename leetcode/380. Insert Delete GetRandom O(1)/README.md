# [380. Insert Delete GetRandom O(1) (Medium)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

<p>Design a data structure that supports all following operations in <i>average</i> <b>O(1)</b> time.</p>

<p>
</p><ol>
<li><code>insert(val)</code>: Inserts an item val to the set if not already present.</li>
<li><code>remove(val)</code>: Removes an item val from the set if present.</li>
<li><code>getRandom</code>: Returns a random element from current set of elements. Each element must have the <b>same probability</b> of being returned.</li>
</ol>
<p></p>

<p><b>Example:</b>
</p><pre>// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
</pre>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Insert Delete GetRandom O(1) - Duplicates allowed (Hard)](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-delete-getrandom-o1/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;
        int i = m[val];
        m[v.back()] = i;
        swap(v[i], v.back());
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};
```