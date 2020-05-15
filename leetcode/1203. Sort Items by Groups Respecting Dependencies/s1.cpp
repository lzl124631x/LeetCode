// OJ: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// Author: github.com/lzl124631x
// Time: O(M + N + E)
// Space: O(M + N + E)
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, vector<int>> itemGraph; // adjacency list of items. Edges between groups are considered in groupGraph so ignored here.
        unordered_map<int, vector<int>> groupGraph; // adjacency list of groups.
        vector<int> itemIndegree(n); // in-degree of each item
        unordered_map<int, int> groupIndegree; // in-degree of each group
        unordered_map<int, vector<int>> itemInGroup; // map from group id to items in the group
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) group[i] = i + m; // make items without group to be in group `i + m` so that we can treat all the items the same
            itemInGroup[group[i]].push_back(i);
        }
        for (int i = 0; i < beforeItems.size(); ++i) {
            for (int j = 0; j < beforeItems[i].size(); ++j) {
                int from = beforeItems[i][j], to = i, fromGroup = group[from], toGroup = group[to];
                if (fromGroup == toGroup) { // If the edge is in the same group, update itemGraph and itemIndegree
                    itemGraph[from].push_back(to);
                    itemIndegree[to]++;
                } else { // If the edge is cross groups, update groupGraph and groupIndegree
                    groupGraph[fromGroup].push_back(toGroup);
                    groupIndegree[toGroup]++;
                }
            }
        }
        queue<int> groupQueue;
        for (auto &p : itemInGroup) { // Get the initial set of groups without indegree
            if (groupIndegree[p.first] == 0) groupQueue.push(p.first);
        }
        vector<int> ans;
        while (groupQueue.size()) {
            int gid = groupQueue.front();
            groupQueue.pop();
            queue<int> itemQueue; // do topological sort within the same group
            int itemCnt = 0;
            for (int u : itemInGroup[gid]) {
                if (itemIndegree[u] == 0) itemQueue.push(u);
            }
            while (itemQueue.size()) {
                int itemId = itemQueue.front();
                itemQueue.pop();
                ans.push_back(itemId);
                ++itemCnt;
                for (int v : itemGraph[itemId]) {
                    if (--itemIndegree[v] == 0) itemQueue.push(v);
                }
            }
            if (itemCnt != itemInGroup[gid].size()) return {}; // has circle within group, return empty list
            for (int v : groupGraph[gid]) {
                if (--groupIndegree[v] == 0) groupQueue.push(v);
            }
        }
        if (ans.size() != n) return {}; // has circle between group, return empty list
        return ans;
    }
};