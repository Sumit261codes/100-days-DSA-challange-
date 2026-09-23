int dp[1001][1001];

int fun(int i, int j, string &s, string &t) {

    if(i >= s.size()) {
        int sum=0;
        for(;j<t.size();j++){
            sum+=t[j];
        }
        return sum;
    }

    if(j >= t.size()) {
        int sum = 0;
        for(;i<s.size();i++){
                sum+=s[i];
            }
            return sum;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int m = 0;

    if(s[i] == t[j]) {

        m = fun(i + 1, j + 1, s, t);

    }
    else {

        int a = s[i] + fun(i + 1, j, s, t);

        int b = t[j] + fun(i, j + 1, s, t);

        m = min(a, b);
    }

    return dp[i][j] = m;
}

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        memset(dp, -1, sizeof(dp));

        return fun(0, 0, s1, s2);
    }
};