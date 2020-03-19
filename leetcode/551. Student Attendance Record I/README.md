# [551. Student Attendance Record I (Easy)](https://leetcode.com/problems/student-attendance-record-i/)

You are given a string representing an attendance record for a student. The record only contains the following three characters:

<p>
</p><ol>
<li><b>'A'</b> : Absent. </li>
<li><b>'L'</b> : Late.</li>
<li> <b>'P'</b> : Present. </li>
</ol>
<p></p>

<p>
A student could be rewarded if his attendance record doesn't contain <b>more than one 'A' (absent)</b> or <b>more than two continuous 'L' (late)</b>.    </p>

<p>You need to return whether the student could be rewarded according to his attendance record.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "PPALLP"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "PPALLL"
<b>Output:</b> False
</pre>
<p></p>




**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Student Attendance Record II (Hard)](https://leetcode.com/problems/student-attendance-record-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/student-attendance-record-i/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for (char c : s) {
            if (c == 'A') ++A;
            if (c == 'L') ++L;
            else L = 0;
            if (A > 1 || L > 2) return false;
        }
        return true;
    }
};
```