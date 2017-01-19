class Node {
public:
    int index;
    vector<Node*> next;
    Node (int i) {
        index = i;
    }
};
class Solution {
private:
    vector<string> dict;
    unordered_map<string, int> m;
    vector<vector<string>> ret;
    int endIndex;
    void dfs(Node *root, vector<string> &path) {
        if (root->index == endIndex) {
            ret.push_back(path);
            return;
        }
        for (auto node : root->next) {
            path.push_back(dict[node->index]);
            dfs(node, path);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);
        dict.assign(wordList.begin(), wordList.end());
        for (int i = 0; i < dict.size(); ++i) m[dict[i]] = i;
        endIndex = m[endWord];
        Node *root = new Node(m[beginWord]);
        queue<Node*> q;
        q.push(root);
        bool found = false;
        while (!q.empty() && !found) {
            int n = q.size();
            unordered_map<int, Node*> nextNodes;
            while (n--) {
                Node *node = q.front();
                q.pop();
                string s = dict[node->index];
                wordList.erase(s);
                for (int i = 0; i < s.size(); ++i) {
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if (wordList.find(s) != wordList.end()) {
                            if (s == endWord) found = true;
                            Node *next;
                            int index = m[s];
                            if (nextNodes.find(index) != nextNodes.end()) {
                                next = nextNodes[index];
                            } else {
                                next = new Node(index);
                                nextNodes[index] = next;
                                q.push(next);
                            }
                            node->next.push_back(next);
                        }
                    }
                    s[i] = c;
                }
            }
        }
        if (!found) return {};
        vector<string> path {beginWord};
        dfs(root, path);
        return ret;
    }
};