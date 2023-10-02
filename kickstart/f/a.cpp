#include <bits/stdc++.h>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define PRINTCASE printf("Case #%d: ",case_n++)
#define PRINTCASE_ printf("Case #%d:\n",case_n++)
#define RD(a) scanf("%d", &(a))
#define RDD(a, b) scanf("%d%d", &(a), &(b))
#define PD(a) printf("%d", (a))
#define PD_(a) printf("%d\n", (a))
#define REP(i,s,t) for(int i=(s);i<(t);i++)

int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int solve(int R, int C, vector<vector<int>> A) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            for (auto &[dx, dy] : dirs) {

            }
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    CASET {
        int R, C;
        RDD(R, C);
        vector<vector<int>> A(R, vector<int>(C));
        REP(i, 0, R) {
            REP(j, 0, C) {
                cin >> A[i][j];
            }
        }
        PRINTCASE;
        cout << solve(R, C, A) << endl;
    }
    return 0;
}
