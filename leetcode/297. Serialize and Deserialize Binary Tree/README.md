# [297. Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

<p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>

<p><strong>Example:&nbsp;</strong></p>

<pre>You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as <code>"[1,2,3,null,null,4,5]"</code>
</pre>

<p><strong>Clarification:</strong> The above format is the same as <a href="/faq/#binary-tree">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p><strong>Note:&nbsp;</strong>Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.</p>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)
* [Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)
* [Find Duplicate Subtrees (Medium)](https://leetcode.com/problems/find-duplicate-subtrees/)
* [Serialize and Deserialize N-ary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)

## Solution 1.

The tree `[1,2,3,null,null,4,5]` will be serialized to `1,2,3,#,#,4,5,#,#,#,#`.

```cpp
// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
class Codec {
private:
    TreeNode *getNode(vector<string> &v, int &i) {
        string s = v[i++];
        return s == "#" ? NULL : new TreeNode(stoi(s));
    }
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (!ans.empty()) ans += ',';
            if (root) {
                ans += to_string(root->val);
                q.push(root->left);
                q.push(root->right);
            } else ans += '#';
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string val;
        vector<string> v;
        while (getline(ss, val, ',')) v.push_back(val);
        TreeNode *root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < v.size()) {
            TreeNode *node = q.front();
            q.pop();
            node->left = getNode(v, i);
            node->right = getNode(v, i);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
```

## Solution 2.

Same as how LeetCode do it.

```cpp
// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
vector<string> stringToVector(string str) {
	str = str.substr(1, str.size() - 2);
	istringstream ss(str);
	string token;
	vector<string> ans;
	while (getline(ss, token, ',')) ans.push_back(token);
	return ans;
}

string vectorToString(vector<string> v){
	auto i = v.begin();
	ostringstream ans;
    ans << "[";
	for(; i != v.end(); ++i) {
		ans << *i;
		if (i + 1 != v.end()) ans << ",";
	}
	ans << "]";
	return ans.str();
}

class Codec {
private:
    string nilToken = "null";
public:
    TreeNode* deserialize(string str) {
        auto v = stringToVector(str);
        if (v.empty()) return NULL;
        queue<TreeNode*> q;
        auto root = new TreeNode(stoi(v[0]));
        q.push(root);
        for (int i = 1, N = v.size(); i < N;) {
            auto node = q.front();
            q.pop();
            if (v[i] != nilToken) q.push(node->left = new TreeNode(stoi(v[i])));
            ++i;
            if (i < N && v[i] != nilToken) q.push(node->right = new TreeNode(stoi(v[i])));
            ++i;
        }
        return root;
    }

    string serialize(TreeNode* root) {
        vector<string> v;
        if (!root) return vectorToString(v);
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            root = q.front();
            q.pop();
            if (root) {
                v.push_back(to_string(root->val));
                q.push(root->left);
                q.push(root->right);
            } else v.push_back(nilToken);
            
        }
        while (v.back() == nilToken) v.pop_back();
        return vectorToString(v);
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            root = q.front();
            q.pop();
            v.push_back(root);
            if (root) {
                q.push(root->left);
                q.push(root->right);
            }
        }
        while (v.back() == NULL) v.pop_back();
        string ans = "[";
        for (int i = 0; i < v.size(); ++i) {
            ans += v[i] ? to_string(v[i]->val) : "null";
            ans += i == v.size() - 1 ? "]" : ",";
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;
        int i = 1, N = data.size() - 1;
        while (i < N) {
            TreeNode *node = NULL;
            if (data[i] == 'n') i += 4;
            else {
                long n = 0, sign = 1;
                if (data[i] == '-') {
                    sign = -1;
                    ++i;
                }
                while (i < N && isdigit(data[i])) n = n * 10 + (data[i++] - '0');
                node = new TreeNode(sign * n);
            }
            ++i;
            v.push_back(node);
        }
        TreeNode *root;
        queue<TreeNode**> q;
        q.push(&root);
        for (auto node : v) {
            auto p = q.front();
            q.pop();
            *p = node;
            if (node) {
                q.push(&node->left);
                q.push(&node->right);
            }
        }
        return root;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/lzl124631x
// Ref: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
class Codec {
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else out << "# ";
    }
    TreeNode *deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return NULL;
        auto root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};
```