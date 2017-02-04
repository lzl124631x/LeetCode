class Solution {
private:
    struct Item {
        int i, j, v;
        Item (int i, int j, int v) : i(i), j(j), v(v) {}
    };
    struct Cmp {
        bool operator() (Item i, Item j) {
            return i.v > j.v;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Item, vector<Item>, Cmp> q;
        int M = nums1.size(), N = nums2.size();
        if (!M || !N) return {};
        q.push(Item(0, 0, nums1[0] + nums2[0]));
        set<pair<int, int>> visited {{0, 0}};
        vector<pair<int, int>> ans;
        while (!q.empty() && k--) {
            Item it = q.top();
            int i = it.i, j = it.j;
            q.pop();
            ans.push_back(make_pair(nums1[i], nums2[j]));
            if (i + 1 < M && !visited.count(make_pair(i + 1, j))) {
                q.push(Item(i + 1, j, nums1[i + 1] + nums2[j]));
                visited.insert(make_pair(i + 1, j));
            }
            if (j + 1 < N && !visited.count(make_pair(i, j + 1))) {
                q.push(Item(i, j + 1, nums1[i] + nums2[j + 1]));
                visited.insert(make_pair(i, j + 1));
            }
        }
        return ans;
    }
};