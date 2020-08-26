# [412. Fizz Buzz (Easy)](https://leetcode.com/problems/fizz-buzz/)

<p>Write a program that outputs the string representation of numbers from 1 to <i>n</i>.</p>

<p>But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.</p>

<p><b>Example:</b>
</p><pre>n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
</pre>
<p></p>

**Companies**:  
[Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/fizz-buzz/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if (i % 3 == 0) ans.push_back("Fizz");
            else if (i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};
```