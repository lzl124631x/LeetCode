# [1507. Reformat Date (Easy)](https://leetcode.com/problems/reformat-date/)

<p>Given a <code>date</code> string in the form&nbsp;<code>Day Month Year</code>, where:</p>

<ul>
	<li><code>Day</code>&nbsp;is in the set <code>{"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}</code>.</li>
	<li><code>Month</code>&nbsp;is in the set <code>{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}</code>.</li>
	<li><code>Year</code>&nbsp;is in the range <code>[1900, 2100]</code>.</li>
</ul>

<p>Convert the date string to the format <code>YYYY-MM-DD</code>, where:</p>

<ul>
	<li><code>YYYY</code> denotes the 4 digit year.</li>
	<li><code>MM</code> denotes the 2 digit month.</li>
	<li><code>DD</code> denotes the 2 digit day.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> date = "20th Oct 2052"
<strong>Output:</strong> "2052-10-20"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> date = "6th Jun 1933"
<strong>Output:</strong> "1933-06-06"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> date = "26th May 1960"
<strong>Output:</strong> "1960-05-26"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are guaranteed to be valid, so no error handling is necessary.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reformat-date/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string reformatDate(string date) {
        istringstream ss(date);
        string day, mon, year, m;
        ss >> day >> mon >> year;
        if (mon == "Jan") m = "01";
        else if (mon == "Feb") m = "02";
        else if (mon == "Mar") m = "03";
        else if (mon == "Apr") m = "04";
        else if (mon == "May") m = "05";
        else if (mon == "Jun") m = "06";
        else if (mon == "Jul") m = "07";
        else if (mon == "Aug") m = "08";
        else if (mon == "Sep") m = "09";
        else if (mon == "Oct") m = "10";
        else if (mon == "Nov") m = "11";
        else m = "12";
        string d = to_string(stoi(day));
        return year + "-" + m + "-" + (d.size() == 1? "0" + d : d);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/reformat-date/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1) 
class Solution {
public:
    string reformatDate(string date) {
        istringstream ss(date);
        string day, mon, year, m;
        ss >> day >> mon >> year;
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        for (int i = 0; i < 12; ++i) {
            if (months[i] == mon) {
                m = to_string(i + 1);
                if (m.size() == 1) m = "0" + m;
                break;
            }
        }
        string d = to_string(stoi(day));
        return year + "-" + m + "-" + (d.size() == 1? "0" + d : d);
    }
};
```