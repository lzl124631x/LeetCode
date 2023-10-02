# [359. Logger Rate Limiter (Easy)](https://leetcode.com/problems/logger-rate-limiter/)

<p>Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is <b>not printed in the last 10 seconds</b>.</p>

<p>Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.</p>

<p>It is possible that several messages arrive roughly at the same time.</p>

<p><b>Example:</b></p>

<pre>Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
</pre>

**Companies**:  
[Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Design Hit Counter (Medium)](https://leetcode.com/problems/design-hit-counter/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/logger-rate-limiter/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(M)
class Logger {
private:
    unordered_map<string, int> m;
public:
    Logger() {}
    bool shouldPrintMessage(int timestamp, string message) {
        bool ans = m.find(message) == m.end() || timestamp - m[message] >= 10;
        if (ans) m[message] = timestamp;
        return ans;
    }
};
```