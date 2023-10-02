# [854. K-Similar Strings (Hard)](https://leetcode.com/problems/k-similar-strings/)

<p>Strings <code>s1</code> and <code>s2</code> are <code>k</code><strong>-similar</strong> (for some non-negative integer <code>k</code>) if we can swap the positions of two letters in <code>s1</code> exactly <code>k</code> times so that the resulting string equals <code>s2</code>.</p>

<p>Given two anagrams <code>s1</code> and <code>s2</code>, return the smallest <code>k</code> for which <code>s1</code> and <code>s2</code> are <code>k</code><strong>-similar</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "ab", s2 = "ba"
<strong>Output:</strong> 1
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "abc", s2 = "bca"
<strong>Output:</strong> 2
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s1 = "abac", s2 = "baca"
<strong>Output:</strong> 2
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> s1 = "aabc", s2 = "abca"
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length &lt;= 20</code></li>
	<li><code>s2.length == s1.length</code></li>
	<li><code>s1</code> and <code>s2</code> contain only lowercase letters from the set <code>{'a', 'b', 'c', 'd', 'e', 'f'}</code>.</li>
	<li><code>s2</code> is an anagram of <code>s1</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/k-similar-strings/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
// Ref: https://leetcode.com/problems/k-similar-strings/discuss/151500/Logical-Thinking-with-Clear-Java-Code
class Solution {
public:
    int kSimilarity(string s, string t) {
        queue<string> q{{s}};
        unordered_set<string> seen{{s}};
        int step = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto u = q.front();
                q.pop();
                if (u == t) return step;
                int i = 0; // Get all possible neighbor strings
                while (i < s.size() && u[i] == t[i]) ++i; // find the first index that u[i] != t[i]
                for (int j = i + 1; j < s.size(); ++j) { // find a good swap index j such that u[j] == t[i]
                    if (u[j] == t[i]) {
                        swap(u[i], u[j]);
                        if (seen.count(u) == 0) {
                            seen.insert(u);
                            q.push(u);
                        }
                        swap(u[i], u[j]);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```

TODO:

https://leetcode.com/problems/k-similar-strings/discuss/140299/C%2B%2B-6ms-Solution

```cpp
class Solution {
public:
  int kSimilarity(string s1, string s2) {
    
    if (s1 == s2) return 0;

    // remove all matches
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
	s1.erase(s1.begin()+i);
	s2.erase(s2.begin()+i);
--i;

      }
    }

    // find all buddy pairs  (s1[i],s2[i]) == (s2[j],s1[j])
    int buddy = 0;
    for (int i = 0; i < s1.size()-1; ++i) {
      if (s1[i] != ' ') {
	char b1 = s1[i];
	char b2 = s2[i];
	for (int j = i+1; j < s1.size(); ++j) {
	  if ((b1 == s2[j]) && (b2 == s1[j])) {

	    s1.erase(s1.begin()+j);
	    s2.erase(s2.begin()+j);
	    s1.erase(s1.begin()+i);
	    s2.erase(s2.begin()+i);
--i;
	    ++buddy;   // this is a swap, must add to total
	    if (!s1.size()) return buddy;
	    break;
	  }
	}
      }
    }

    int n = s1.size();

    int result = n*(n-1)/2;
    for (int pos = 0; pos < n; ++pos) {
      int count = calc(s1, s2, n, pos, result);
      if (result > count) {
	result = count;
      }
    }
    return result + buddy;
  }

  int calc(std::string s1, const std::string s2, const int n, const int pos, const int result) {

    int count = 0;
    for (int x = 0; x < n; ++x) {
      int i = (x+pos) % n;
      char c1 = s1[i];
      char c2 = s2[i];
      
      if (c1 == ' ') continue;    
      if (c1 != c2) {

	s1[i] = ' ';  // there will always be a match

	// find a pair to swap, prefer a buddy pair
	size_t j = s1.find(c2);  // save this in case no buddy pair

	bool buddy = false;
    // search if swapping c1 to index j creates a buddy
    for (int k = 0; k < n; ++k) {
      if ((c1 == s2[k]) && (s1[k] == s2[j])) {
    s1[j] = s1[k] = ' ';  // it's a buddy, eliminate two characters
    count += 2;

    if (count >= result) return count;
    buddy = true;
    break;
      }
    }
	if (!buddy) {
	  s1[j] = c1;  // no buddies, copy c1 to this slot
	  ++count;

	  if (count >= result) return count;
    	}
      }
    }
    return count;
  }

};
```