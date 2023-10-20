# [341. Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator)

<p>You are given a nested list of integers <code>nestedList</code>. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.</p>

<p>Implement the <code>NestedIterator</code> class:</p>

<ul>
	<li><code>NestedIterator(List&lt;NestedInteger&gt; nestedList)</code> Initializes the iterator with the nested list <code>nestedList</code>.</li>
	<li><code>int next()</code> Returns the next integer in the nested list.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there are still some integers in the nested list and <code>false</code> otherwise.</li>
</ul>

<p>Your code will be tested with the following pseudocode:</p>

<pre>
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
</pre>

<p>If <code>res</code> matches the expected flattened list, then your code will be judged as correct.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nestedList = [[1,1],2,[1,1]]
<strong>Output:</strong> [1,1,2,1,1]
<strong>Explanation:</strong> By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nestedList = [1,[4,[6]]]
<strong>Output:</strong> [1,4,6]
<strong>Explanation:</strong> By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nestedList.length &lt;= 500</code></li>
	<li>The values of the integers in the nested list is in the range <code>[-10<sup>6</sup>, 10<sup>6</sup>]</code>.</li>
</ul>


**Companies**:
[Yandex](https://leetcode.com/company/yandex), [Netflix](https://leetcode.com/company/netflix), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg), [LinkedIn](https://leetcode.com/company/linkedin), [Airbnb](https://leetcode.com/company/airbnb), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Twitter](https://leetcode.com/company/twitter), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Salesforce](https://leetcode.com/company/salesforce), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Accolite](https://leetcode.com/company/accolite), [Coinbase](https://leetcode.com/company/coinbase), [Workday](https://leetcode.com/company/workday), [instabase](https://leetcode.com/company/instabase)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Design](https://leetcode.com/tag/design), [Queue](https://leetcode.com/tag/queue), [Iterator](https://leetcode.com/tag/iterator)

**Similar Questions**:
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator)
* [Mini Parser (Medium)](https://leetcode.com/problems/mini-parser)
* [Array Nesting (Medium)](https://leetcode.com/problems/array-nesting)

## Solution 1. 

* Preprocess the list in the constructor, and store all the numbers in an array `vals`
* In `next` and `hasNext`, we just traverse the array `vals`

```cpp
// OJ: https://leetcode.com/problems/flatten-nested-list-iterator
// Author: github.com/lzl124631x
// Time:
//      NestedIterator: O(N)
//      next, hasNext: O(1)
// Space: O(N)
class NestedIterator {
    vector<int> vals;
    int i = 0;
public:
    NestedIterator(vector<NestedInteger> &list) {
        deque<NestedInteger> q{begin(list), end(list)};
        while (q.size()) {
            auto i = q.front();
            q.pop_front();
            if (i.isInteger()) {
                vals.push_back(i.getInteger());
            } else {
                auto L = i.getList();
                for (auto it = L.rbegin(); it != L.rend(); ++it) q.push_front(*it);
            }
        }
    }
    int next() {
        return vals[i++];
    }
    bool hasNext() {
        return i < vals.size();
    }
};
```
## Solution 2.

Use a stack to store the `current` and `end` iterators at each level.

```cpp
// OJ: https://leetcode.com/problems/flatten-nested-list-iterator/
// Author: github.com/lzl124631x
// Time: 
//      NestedInteger, next: O(1) amortized
//      hasNext: O(1)
// Space: O(D) where D is the max depth of the list
class NestedIterator {
    typedef vector<NestedInteger>::iterator iter;
    stack<pair<iter, iter>> s;
    void goToInteger() {
        while (s.size()) {
            if (s.top().first == s.top().second) {
                s.pop();
                if (s.size()) s.top().first++;
            } else if (s.top().first->isInteger()) break;
            else {
                auto &list = s.top().first->getList();
                s.emplace(list.begin(), list.end());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &list) {
        s.emplace(list.begin(), list.end());
        goToInteger();
    }
    int next() {
        int val = s.top().first->getInteger();
        s.top().first++;
        goToInteger();
        return val;
    }
    bool hasNext() {
        return s.size();
    }
};
```

## Solution 3.

Similar to solution 1, but instead of generating every number in constructor, we store the `NestedInteger`s in a stack, and stop filling the stack once we've found an integer.

```cpp
// OJ: https://leetcode.com/problems/flatten-nested-list-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(N)
class NestedIterator {
    stack<NestedInteger> s;
    void goToInteger() {
        while (s.size() && !s.top().isInteger()) {
            auto list = s.top().getList();
            s.pop();
            for (int i = list.size() - 1; i >= 0; --i) s.push(list[i]);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) s.push(nestedList[i]);
        goToInteger();
    }
    int next() {
        int val = s.top().getInteger();
        s.pop();
        goToInteger();
        return val;
    }
    bool hasNext() {
        return s.size();
    }
};
```