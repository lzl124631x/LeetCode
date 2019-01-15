# [202. Happy Number (Easy)](https://leetcode.com/problems/happy-number/)

<p>Write an algorithm to determine if a number is "happy".</p>

<p>A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.</p>

<p><strong>Example:&nbsp;</strong></p>

<pre><strong>Input:</strong> 19
<strong>Output:</strong> true
<strong>Explanation: 
</strong>1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

**Companies**:  
[JPMorgan](https://leetcode.com/company/jpmorgan), [Nutanix](https://leetcode.com/company/nutanix), [Google](https://leetcode.com/company/google), [Pinterest](https://leetcode.com/company/pinterest)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Linked List Cycle (Easy)](https://leetcode.com/problems/linked-list-cycle/)
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)
* [Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)

## Solution 1. unordered_set

```cpp
// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (n != 1 && !s.count(n)) {
      s.insert(n);
      int next = 0;
      while (n) {
        next += pow(n % 10, 2);
        n /= 10;
      }
      n = next;
    }
    return n == 1;
  }
};
```

## Solution 2. Two Pointers

The maximum number is `2^31 - 1`, around `10^9`, i.e. has 10 digits.

The next number of it is at most `9*9*10=810`, which has 3 digits.

The number of digits will drop significantly to less than 4 digits.

```cpp
// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  int happify(int n) {
    int next = 0;
    for (; n; next += pow(n % 10, 2), n /= 10);
    return next;
  }
public:
  bool isHappy(int n) {
    int slow = n, fast = n;
    do {
      slow = happify(slow);
      fast = happify(happify(fast));
    } while (slow != fast && fast != 1);
    return fast == 1;
  }
};
```

## Solution 3. Magic Number 4

```cpp
// OJ: https://leetcode.com/problems/happy-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  int next(int n) {
    int ans = 0;
    for (; n; ans += pow(n % 10, 2), n /= 10);
    return ans;
  }
public:
  bool isHappy(int n) {
    for (; n != 1 && n != 4; n = next(n));
    return n == 1;
  }
};
```