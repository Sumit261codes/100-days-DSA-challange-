class Solution {
public:
    int dp[1001][1001];

    int fun(int i, int j, string &s) {
        if(i >= j)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = fun(i + 1, j - 1, s);

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));

        int start = 0;
        int len = 1;

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(fun(i, j, s)) {
                    if(j - i + 1 > len) {
                        len = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};