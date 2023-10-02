# [158. Read N Characters Given Read4 II - Call multiple times (Hard)](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/)

<p>Given a file and assume that you can only read the file using a given method&nbsp;<code>read4</code>, implement a method <code>read</code> to read <em>n</em> characters. <strong>Your method <code>read</code> may be called multiple times.</strong></p>

<p>&nbsp;</p>

<p><b>Method read4: </b></p>

<p>The API&nbsp;<code>read4</code> reads 4 consecutive characters from the file, then writes those characters into the buffer array <code>buf</code>.</p>

<p>The return value is the number of actual characters read.</p>

<p>Note that&nbsp;<code>read4()</code> has its own file pointer, much like <code>FILE *fp</code> in C.</p>

<p><b>Definition of read4:</b></p>

<pre>    Parameter:  char[] buf
    Returns:    int

Note: buf[] is destination not source, the results from read4 will be copied to buf[]
</pre>

<p>Below is a high level example of how <code>read4</code> works:</p>

<pre><code>File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file</code>
</pre>

<p>&nbsp;</p>

<p><strong>Method read:</strong></p>

<p>By using the <code>read4</code> method, implement the method&nbsp;<code>read</code> that reads <i>n</i> characters from the file and store it in the&nbsp;buffer array&nbsp;<code>buf</code>. Consider that you <strong>cannot</strong> manipulate the file directly.</p>

<p>The return value is the number of actual characters read.</p>

<p><b>Definition of read: </b></p>

<pre>    Parameters:	char[] buf, int n
    Returns:	int

Note: buf[] is destination not source, you will need to write the results to buf[]
</pre>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre>File file("abc");
Solution sol;
// Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre>File file("abc");
Solution sol;
sol.read(buf, 4); // After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>Consider that you <strong>cannot</strong> manipulate the file directly, the file is only accesible for <code>read4</code> but&nbsp;<strong>not</strong> for <code>read</code>.</li>
	<li>The <code>read</code> function may be called <strong>multiple times</strong>.</li>
	<li>Please remember to <b>RESET</b> your class variables declared in Solution, as static/class variables are <b>persisted across multiple test cases</b>. Please see <a href="https://leetcode.com/faq/" target="_blank">here</a> for more details.</li>
	<li>You may assume the destination buffer array,&nbsp;<code>buf</code>,&nbsp;is guaranteed to have enough&nbsp;space for storing&nbsp;<em>n</em>&nbsp;characters.</li>
	<li>It is guaranteed that in a given test case the same buffer <code>buf</code> is called by <code>read</code>.</li>
</ol>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Lyft](https://leetcode.com/company/lyft), [Rubrik](https://leetcode.com/company/rubrik)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Read N Characters Given Read4 (Easy)](https://leetcode.com/problems/read-n-characters-given-read4/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Forward declaration of the read4 API.
int read4(char *buf);
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char leftover[4] = { '\0' };
    int read(char *buf, int n) {
        strcpy(buf, leftover);
        int cnt = strlen(leftover);
        while (cnt < n) {
            int x = read4(buf + cnt);
            if (!x) break;
            cnt += x;
        }
        if (cnt > n) {
            memcpy(leftover, buf + n, cnt - n);
            leftover[cnt - n] = '\0';
        } else leftover[0] = '\0';
        cnt = min(cnt, n);
        return cnt;
    }
};
```