class Solution {
public:
    string getHint(string secret, string guess) {
        int M[10] = {0}, n = secret.size(), A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            M[secret[i] - '0']++;
        }
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A;
                M[secret[i] - '0']--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (secret[i] != guess[i] && M[guess[i] - '0']) {
                ++B;
                M[guess[i] - '0']--;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};