# [604. Design Compressed String Iterator (Easy)](https://leetcode.com/problems/design-compressed-string-iterator)

Design and implement a data structure for a compressed string iterator. It should support the following operations: `next` and `hasNext`.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

`next()` - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.  
`hasNext()` - Judge whether there is any letter needs to be uncompressed.

**Example:**

```
StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
```

## Solution 1.

Let `index` points to the letter to output, `nextIndex` points to the next letter to output, `cnt` is the number of remaining occurrence of the current letter.

A function `load` is used to load the next letter, if neccessary. It will be called when there is a need to load the next letter, i.e., in constructor and in `next`.


```cpp
// OJ: https://leetcode.com/problems/design-compressed-string-iterator
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class StringIterator {
private:
  string str;
  int index = 0, nextIndex = 0, cnt = 0;
  void load() {
    while (index < str.size() && !cnt) {
      index = nextIndex;
      nextIndex = index + 1;
      while (nextIndex < str.size() && isdigit(str[nextIndex])) cnt = cnt * 10 + str[nextIndex++] - '0';
    }
  }
public:
  StringIterator(string compressedString) : str(compressedString) {
    load();
  }

  char next() {
    if (!hasNext()) return ' ';
    char ans = str[index];
    --cnt;
    load();
    return ans;
  }

  bool hasNext() {
    return index < str.size();
  }
};
```