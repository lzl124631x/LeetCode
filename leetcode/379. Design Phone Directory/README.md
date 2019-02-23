# [379. Design Phone Directory (Medium)](https://leetcode.com/problems/design-phone-directory/)

<p>Design a Phone Directory which supports the following operations:</p>

<p>
</p><ol>
<li><code>get</code>: Provide a number which is not assigned to anyone.</li>
<li><code>check</code>: Check if a number is available or not.</li>
<li><code>release</code>: Recycle or release a number.</li>
</ol>
<p></p>

<p><b>Example:</b>
</p><pre>// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
</pre>
<p></p>

**Companies**:  
[Dropbox](https://leetcode.com/company/dropbox), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/design-phone-directory/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(N)
class PhoneDirectory {
private:
    unordered_set<int> pool;
public:
    PhoneDirectory(int maxNumbers) {
        while (maxNumbers--) pool.insert(maxNumbers);
    }
    int get() {
        if (pool.empty()) return -1;
        int ans = *pool.begin();
        pool.erase(pool.begin());
        return ans;
    }
    bool check(int number) {
        return pool.find(number) != pool.end();
    }
    void release(int number) {
        if (check(number)) return;
        pool.insert(number);
    }
};
```