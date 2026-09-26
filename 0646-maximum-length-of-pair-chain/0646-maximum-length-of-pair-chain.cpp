int dp[1001][1001];

int fun(int i, int p, vector<vector<int>>& pairs) {
    if (i >= pairs.size())
        return 0;

    if (dp[i][p + 1] != -1) return dp[i][p + 1];

    int take = 0;

    if (p == -1 || pairs[i][0] > pairs[p][1]) {
        take = 1 + fun(i + 1, i, pairs);
    }

    int notTake = fun(i + 1, p, pairs);

    return dp[i][p + 1] = max(take, notTake);
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));

        sort(pairs.begin(), pairs.end());

        return fun(0, -1, pairs);
    }
};