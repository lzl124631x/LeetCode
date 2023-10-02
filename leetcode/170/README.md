# [170. Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)

<p>Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.</p>

<p>Implement the <code>TwoSum</code> class:</p>

<ul>
	<li><code>TwoSum()</code> Initializes the <code>TwoSum</code> object, with an empty array initially.</li>
	<li><code>void add(int number)</code> Adds <code>number</code> to the data structure.</li>
	<li><code>boolean find(int value)</code> Returns <code>true</code> if there exists any pair of numbers whose sum is equal to <code>value</code>, otherwise, it returns <code>false</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
<strong>Output</strong>
[null, null, null, null, true, false]

<strong>Explanation</strong>
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --&gt; [1]
twoSum.add(3);   // [1] --&gt; [1,3]
twoSum.add(5);   // [1,3] --&gt; [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>5</sup> &lt;= number &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= value &lt;= 2<sup>31</sup> - 1</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code> and <code>find</code>.</li>
</ul>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Design](https://leetcode.com/tag/design/), [Data Stream](https://leetcode.com/tag/data-stream/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Unique Word Abbreviation (Medium)](https://leetcode.com/problems/unique-word-abbreviation/)
* [Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Solution 1. Map

```cpp
// OJ: https://leetcode.com/problems/two-sum-iii-data-structure-design/
// Author: github.com/lzl124631x
// Time:
//      TwoSum: O(1)
//      add: O(logN)
//      find: O(NlogN)
// Space: O(N)
class TwoSum {
    map<long, int> m;
public:
    TwoSum() {}
    void add(int n) {
        m[n]++;
    }
    bool find(int n) {
        for (auto &[a, cnt] : m) {
            long b = n - a;
            if (a > b) return false;
            if (a == b) return cnt > 1;
            if (m.count(b)) return true;
        }
        return false;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/two-sum-iii-data-structure-design/
// Author: github.com/lzl124631x
// Time:
//      TwoSum: O(1)
//      add: O(logN)
//      find: O(N)
// Space: O()
class TwoSum {
    multiset<int> s;
public:
    TwoSum() {}
    void add(int n) {
        s.insert(n);
    }
    bool find(int n) {
        if (s.empty()) return false;
        auto i = s.begin(), j = prev(s.end());
        while (i != j) {
            int sum = *i + *j;
            if (sum == n) return true;
            if (sum > n) --j;
            else ++i;
        }
        return false;
    }
};
```