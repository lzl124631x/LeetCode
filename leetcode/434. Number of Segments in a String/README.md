# [434. Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/)

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any **non-printable** characters.

**Example:**

```
Input: "Hello, my name is John"
Output: 5
```

## Key 1: Brute Force

使用两个循环, 一个跳过空格, 一个跳过非空格. 在两个循环之间判断一下, 如果尚未到达字符串末尾, 则计数加一.

```
class Solution {
public:
    int countSegments(string s) {
        int n = s.size(), cnt = 0, i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            if (i < n) ++cnt;
            while (i < n && s[i] != ' ') ++i;
        }
        return cnt;
    }
};
```

## Key 2: Brute Force

定位每个连续非空格子串的开始点. 注意`s[i] != ' ' && (i == 0 || s[i - 1] == ' ')`中一定要将后两个条件用括号包围, 否则根据结合律, 表达式相当于`(s[i] != ' ' && i == 0) || s[i - 1] == ' '`, 是错误的.

> Note: `&&`的优先级高于`||`

```
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) ++cnt;
        }
        return cnt;
    }
};
```

## Key 3: `stringstream`

`stringstream`读取`string`时默认会跳过空格.

```
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        string word;
        stringstream ss(s);
        while (ss >> word) ++cnt;
        return cnt;
    }
};
```