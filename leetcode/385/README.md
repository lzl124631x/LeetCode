# [385. Mini Parser (Medium)](https://leetcode.com/problems/mini-parser/)

<p>Given a nested list of integers represented as a string, implement a parser to deserialize it.</p>

<p>Each element is either an integer, or a list -- whose elements may also be integers or other lists.</p>

<p><b>Note:</b> You may assume that the string is well-formed:</p>

<ul>
	<li>String is non-empty.</li>
	<li>String does not contain white spaces.</li>
	<li>String contains only digits <code>0-9</code>, <code>[</code>, <code>-</code> <code>,</code>, <code>]</code>.</li>
</ul>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre>Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre>Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Flatten Nested List Iterator (Medium)](https://leetcode.com/problems/flatten-nested-list-iterator/)
* [Ternary Expression Parser (Medium)](https://leetcode.com/problems/ternary-expression-parser/)
* [Remove Comments (Medium)](https://leetcode.com/problems/remove-comments/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/mini-parser/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger(); // empty list
        if (s[0] == '[') { // nested list
            NestedInteger n;
            int i = 1, end = s.size() - 1;
            while (i < end) {
                int begin = i;
                if (s[i] == '[') { // element being nested list
                    int cnt = 0;
                    do {
                        if (s[i] == '[') ++cnt;
                        else if (s[i] == ']') --cnt;
                        ++i;
                    } while (cnt > 0);
                } else {
                    while (isdigit(s[i]) || s[i] == '-') ++i;
                }
                n.add(deserialize(s.substr(begin, i - begin)));
                ++i;
            }
            return n;
        }
        // plain number
        return NestedInteger(stoi(s));
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/mini-parser/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the maximum depth of the output
class Solution {
private:
    NestedInteger deserialize(string s, int &i) {
        NestedInteger ni;
        if (i >= s.size()) return ni;
        if (s[i] != '[') {
            int n = 0, sign = 1;
            if (s[i] == '-') {
                sign = -1;
                ++i;
            }
            while (i < s.size() && isdigit(s[i])) n = n * 10 + s[i++] - '0';
            ni.setInteger(sign * n);
        } else {
            ++i;//[
            while (i < s.size() && s[i] != ']') {
                ni.add(deserialize(s, i));
                if (i < s.size() && s[i] == ',') ++i;
            }
            ++i;//]
        }
        return ni;
    }
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserialize(s, i);
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/mini-parser/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the maximum depth of the output
// Ref: https://discuss.leetcode.com/topic/54258/python-c-solutions
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }
private:
    NestedInteger deserialize(istringstream &in) {
        int number;
        if (in >> number)
            return NestedInteger(number);
        in.clear();
        in.get();
        NestedInteger list;
        while (in.peek() != ']') {
            list.add(deserialize(in));
            if (in.peek() == ',')
                in.get();
        }
        in.get();
        return list;
    }
};
```