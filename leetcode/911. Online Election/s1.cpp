// OJ: https://leetcode.com/problems/online-election/
// Author: github.com/lzl124631x
// Time:
//     TopVotedCandidate: O(N)
//     q: O(logN)
// Space: O(N)
class TopVotedCandidate {
private:
    vector<int> winners;
    vector<int> times;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times): times(times) {
        unordered_map<int, int> m;
        int winner = 0;
        for (int p : persons) {
            m[p]++;
            if (m[p] >= m[winner]) winner = p;
            winners.push_back(winner);
        }
    }
    
    int q(int t) {
        int n = upper_bound(times.begin(), times.end(), t) - times.begin();
        return winners[n - 1];
    }
};