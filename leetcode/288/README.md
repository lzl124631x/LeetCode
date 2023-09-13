# [288. Unique Word Abbreviation (Medium)](https://leetcode.com/problems/unique-word-abbreviation)

<p>The <strong>abbreviation</strong> of a word is a concatenation of its first letter, the number of characters between the first and last letter, and its last letter. If a word has only two characters, then it is an <strong>abbreviation</strong> of itself.</p>
<p>For example:</p>
<ul>
	<li><code>dog --&gt; d1g</code> because there is one letter between the first letter <code>'d'</code> and the last letter <code>'g'</code>.</li>
	<li><code>internationalization --&gt; i18n</code> because there are 18 letters between the first letter <code>'i'</code> and the last letter <code>'n'</code>.</li>
	<li><code>it --&gt; it</code> because any word with only two characters is an <strong>abbreviation</strong> of itself.</li>
</ul>
<p>Implement the <code>ValidWordAbbr</code> class:</p>
<ul>
	<li><code>ValidWordAbbr(String[] dictionary)</code> Initializes the object with a <code>dictionary</code> of words.</li>
	<li><code>boolean isUnique(string word)</code> Returns <code>true</code> if <strong>either</strong> of the following conditions are met (otherwise returns <code>false</code>):
	<ul>
		<li>There is no word in <code>dictionary</code> whose <strong>abbreviation</strong> is equal to <code>word</code>'s <strong>abbreviation</strong>.</li>
		<li>For any word in <code>dictionary</code> whose <strong>abbreviation</strong> is equal to <code>word</code>'s <strong>abbreviation</strong>, that word and <code>word</code> are <strong>the same</strong>.</li>
	</ul>
	</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique", "isUnique"]
[[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"], ["cake"]]
<strong>Output</strong>
[null, false, true, false, true, true]

<strong>Explanation</strong>
ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);
validWordAbbr.isUnique("dear"); // return false, dictionary word "deer" and word "dear" have the same abbreviation "d2r" but are not the same.
validWordAbbr.isUnique("cart"); // return true, no words in the dictionary have the abbreviation "c2t".
validWordAbbr.isUnique("cane"); // return false, dictionary word "cake" and word "cane" have the same abbreviation  "c2e" but are not the same.
validWordAbbr.isUnique("make"); // return true, no words in the dictionary have the abbreviation "m2e".
validWordAbbr.isUnique("cake"); // return true, because "cake" is already in the dictionary and no other word in the dictionary has "c2e" abbreviation.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= dictionary.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 20</code></li>
	<li><code>dictionary[i]</code> consists of lowercase English letters.</li>
	<li><code>1 &lt;= word.length &lt;= 20</code></li>
	<li><code>word</code> consists of lowercase English letters.</li>
	<li>At most <code>5000</code> calls will be made to <code>isUnique</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)
* [Generalized Abbreviation (Medium)](https://leetcode.com/problems/generalized-abbreviation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/unique-word-abbreviation
// Author: github.com/lzl124631x
// Time:
//      ValidWordAbbr: O(NL) where N is the length of A and L is the maximum length of A[i]
//      isUnique: O(1)
// Space: O(NL)
class ValidWordAbbr {
    unordered_map<string, int> cnt;
    unordered_set<string> seen;
    string abbr(string &s) {
        return s.size() >= 3 ? s[0] + to_string(s.size() -  1) + s.back() : s;
    }
public:
    ValidWordAbbr(vector<string>& A) {
        for (auto &s : A) {
            if (seen.count(s)) continue;
            cnt[abbr(s)]++;
            seen.insert(s);
        }
    }
    bool isUnique(string word) {
        auto s = abbr(word);
        return cnt.count(s) == 0 || (seen.count(word) && cnt[s] == 1);
    }
};
```