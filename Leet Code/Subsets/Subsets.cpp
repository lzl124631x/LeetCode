class Solution {
private:
	vector<vector<int> > v;
public:
	bool isAscending(vector<int> &S){
		for(int i = 1; i < S.size(); ++i){
			if(S[i - 1] > S[i]) return false;
		}
		return true;
	}

	bool isDescending(vector<int> &S){
		for(int i = 1; i < S.size(); ++i){
			if(S[i - 1] < S[i]) return false;
		}
		return true;
	}

	void quickSort(vector<int> &S, int L, int R){
		if(L >= R) return;
		int A = S[L], i = L, j = R;
		while(i < j){
			while(i < j && S[j] >= A) j--;
			if(i < j) S[i] = S[j];
			while(i < j && S[i] <= A) i++;
			if(i < j) S[j] = S[i];
		}
		S[i] = A;
		quickSort(S, L, i - 1);
		quickSort(S, i + 1, R);
	}

	void subsets(vector<int> &S, vector<int> &v1, int layer, int n){
		if(layer == n + 1){
			v.push_back(v1);
			return;
		}
		for(int i = layer; i < S.size() - (n - layer); ++i){
			v1.push_back(S[i]);
			subsets(S, v1, layer + i + 1, n);
			v1.pop_back();
		} 
	}

    vector<vector<int> > subsets(vector<int> &S) {
    	v.clear();
        if(!isAscending(S) && !isDescending(S)){
        	quickSort(S, 0, S.size() - 1);
        }
        for(int n = 0; n <= S.size(); ++n){
        	vector<int> v1;
        	subsets(S, v1, 0, n);
        }
        return v;
    }
};