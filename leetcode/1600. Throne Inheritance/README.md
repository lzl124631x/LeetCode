# [1600. Throne Inheritance (Medium)](https://leetcode.com/problems/throne-inheritance/)

<p>A kingdom consists of a king, his children, his grandchildren, and so on. Every once in a while, someone in the family dies or a child is born.</p>

<p>The kingdom has a well-defined order of inheritance that consists of the king as the first member. Let's define the recursive function <code>Successor(x, curOrder)</code>, which given a person <code>x</code> and the inheritance order so far, returns who should be the next person after <code>x</code> in the order of inheritance.</p>

<pre>Successor(x, curOrder):
    if x has no children or all of x's children are in curOrder:
        if x is the king return null
        else return Successor(x's parent, curOrder)
    else return x's oldest child who's not in curOrder
</pre>

<p>For example, assume we have a kingdom that consists of the king, his children Alice and Bob (Alice is older than Bob), and finally Alice's son Jack.</p>

<ol>
	<li>In the beginning, <code>curOrder</code> will be <code>["king"]</code>.</li>
	<li>Calling <code>Successor(king, curOrder)</code> will return Alice, so we append to <code>curOrder</code> to get <code>["king", "Alice"]</code>.</li>
	<li>Calling <code>Successor(Alice, curOrder)</code> will return Jack, so we append to <code>curOrder</code> to get <code>["king", "Alice", "Jack"]</code>.</li>
	<li>Calling <code>Successor(Jack, curOrder)</code> will return Bob, so we append to <code>curOrder</code> to get <code>["king", "Alice", "Jack", "Bob"]</code>.</li>
	<li>Calling <code>Successor(Bob, curOrder)</code> will return <code>null</code>. Thus the order of inheritance will be <code>["king", "Alice", "Jack", "Bob"]</code>.</li>
</ol>

<p>Using the above function, we can always obtain a unique order of inheritance.</p>

<p>Implement the <code>ThroneInheritance</code> class:</p>

<ul>
	<li><code>ThroneInheritance(string kingName)</code> Initializes an object of the <code>ThroneInheritance</code> class. The name of the king is given as part of the constructor.</li>
	<li><code>void birth(string parentName, string childName)</code> Indicates that <code>parentName</code> gave birth to <code>childName</code>.</li>
	<li><code>void death(string name)</code> Indicates the death of <code>name</code>. The death of the person doesn't affect the <code>Successor</code> function nor the current inheritance order. You can treat it as just marking the person as dead.</li>
	<li><code>string[] getInheritanceOrder()</code> Returns a list representing the current order of inheritance <strong>excluding</strong> dead people.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
<strong>Output</strong>
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

<strong>Explanation</strong>
ThroneInheritance t= new ThroneInheritance("king"); // order: <strong>king</strong>
t.birth("king", "andy"); // order: king &gt; <strong>andy</strong>
t.birth("king", "bob"); // order: king &gt; andy &gt; <strong>bob</strong>
t.birth("king", "catherine"); // order: king &gt; andy &gt; bob &gt; <strong>catherine</strong>
t.birth("andy", "matthew"); // order: king &gt; andy &gt; <strong>matthew</strong> &gt; bob &gt; catherine
t.birth("bob", "alex"); // order: king &gt; andy &gt; matthew &gt; bob &gt; <strong>alex</strong> &gt; catherine
t.birth("bob", "asha"); // order: king &gt; andy &gt; matthew &gt; bob &gt; alex &gt; <strong>asha</strong> &gt; catherine
t.getInheritanceOrder(); // return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // order: king &gt; andy &gt; matthew &gt; <strong><s>bob</s></strong> &gt; alex &gt; asha &gt; catherine
t.getInheritanceOrder(); // return ["king", "andy", "matthew", "alex", "asha", "catherine"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= kingName.length, parentName.length, childName.length, name.length &lt;= 15</code></li>
	<li><code>kingName</code>, <code>parentName</code>, <code>childName</code>, and <code>name</code> consist of lowercase English letters only.</li>
	<li>All arguments <code>childName</code> and <code>kingName</code> are <strong>distinct</strong>.</li>
	<li>All <code>name</code> arguments of <code>death</code> will be passed to either the constructor or as <code>childName</code> to <code>birth</code> first.</li>
	<li>For each call to&nbsp;<code>birth(parentName, childName)</code>, it is guaranteed that&nbsp;<code>parentName</code> is alive.</li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>birth</code> and <code>death</code>.</li>
	<li>At most <code>10</code> calls will be made to <code>getInheritanceOrder</code>.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/throne-inheritance/
// Author: github.com/lzl124631x
// Time:
//      ThroneInheritance, birth, death: O(1)
//      getInheritanceOrder: O(N)
// Space: O(N)
struct Person {
    string name;
    vector<Person*> children;
    bool alive = true;
};
class ThroneInheritance {
    Person *k = new Person();
    unordered_map<string, Person*> m;
    void dfs(Person *p, vector<string> &ans) {
        if (p->alive) ans.push_back(p->name);
        for (auto & c : p->children) dfs(c, ans);
    }
public:
    ThroneInheritance(string kingName) {
        k->name = kingName;
        m[kingName] = k;
    }
    void birth(string parentName, string childName) {
        auto c = new Person();
        c->name = childName;
        m[parentName]->children.push_back(c);
        m[childName] = c;
    }
    void death(string name) {
        m[name]->alive = false;
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(k, ans);
        return ans;
    }
};
```