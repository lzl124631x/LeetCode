// https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst
class Node {
public:
    Node *left = NULL, *right = NULL;
    int val, sum = 0, cnt = 1;
    Node (int val) : val(val) {}
};

class Solution {
private:
    vector<int> ans;
    Node *insert(Node *root, int val, int preSum) {
        if (!root) {
            root = new Node(val);
            ans.push_back(preSum);
        } else if (val == root->val) {
            root->cnt++;
            ans.push_back(preSum + root->sum);
        } else if (val < root->val) {
            root->sum++;
            root->left = insert(root->left, val, preSum);
        } else {
            root->right = insert(root->right, val, preSum + root->cnt + root->sum);
        }
        return root;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; --i) {
            root = insert(root, nums[i], 0);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
// https://discuss.leetcode.com/topic/54203/c-using-binary-index-tree-segment-tree-and-binary-search-tree
class Node {
public:
    Node *left = NULL, *right = NULL;
    int val, sum = 0, dup = 1;
    Node (int val) : val(val) {}
};

class Solution {
private:
    int insert(Node *root, int val) {
        if (root->val == val) {
            root->dup++;
            return root->sum;
        } else if (val > root->val) {
            if (!root->right) {
                root->right = new Node(val);
                return root->sum + root->dup;
            }
            return root->sum + root->dup + insert(root->right, val);
        } else {
            root->sum++;
            if (!root->left) {
                root->left = new Node(val);
                return 0;
            }
            return insert(root->left, val);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> ans(nums.size(), 0);
        Node *root = new Node(nums.back());
        for (int i = nums.size() - 2; i >= 0; --i) {
            ans[i] = insert(root, nums[i]);
        }
        return ans;
    }
};

*/