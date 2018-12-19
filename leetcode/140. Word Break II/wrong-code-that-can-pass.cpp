// "kkabcd"
// ["k", "kk","ab","cd", "abc"]
class Solution {
private:
	int maxLen = 0;
	vector<bool> valid;
	vector<string> ans;
    unordered_set<string> dict;
	bool dfs(string &s, int start, string tmp){
		if (!valid[start]) return false;
		if (start == s.size()) {
			ans.push_back(tmp);
			return true;
		}
		valid[start] = false;
		for(int end = start + 1; end <= s.size() && end - start <= maxLen; ++end){
			string sub = s.substr(start, end - start);
			if (dict.find(sub) == dict.end()) continue;
			valid[start] = dfs(s, end, tmp.size() ? tmp + " " + sub : sub);
		}
		return valid[start];
	}
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
    	for (auto &s : wordDict) maxLen = max(maxLen, (int)s.size());
    	valid = vector<bool>(s.size(), true);
    	dfs(s, 0, "");
    	return ans;
    }
};