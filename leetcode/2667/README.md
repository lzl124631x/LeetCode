# [2667. Create Hello World Function (Easy)](https://leetcode.com/problems/create-hello-world-function)

<code>createHelloWorld</code>
<code>"Hello World"</code>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> args = []
<strong>Output:</strong> "Hello World"
<strong>Explanation:</strong>
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> args = [{},null,42]
<strong>Output:</strong> "Hello World"
<strong>Explanation:</strong>
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= args.length &lt;= 10</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/create-hello-world-function
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};
```