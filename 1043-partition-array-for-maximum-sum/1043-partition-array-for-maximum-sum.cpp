int dp[505][505];

int fun(int p, int i, vector<int>& nums, int m, int k) {
    if(i >= nums.size()) return 0;

    if(dp[p][i] != -1)
        return dp[p][i];

    int ans = 0;

    m = max(m, nums[i]);
    int len = i - p + 1;

    if(len == k) {
        int c1 = (m * len) + fun(i + 1, i + 1, nums, 0, k);
        ans = max(ans, c1);
    }
    else {
        int c1 = (m * len) + fun(i + 1, i + 1, nums, 0, k);
        int c2 = fun(p, i + 1, nums, m, k);

        ans = max(ans, c1);
        ans = max(ans, c2);
    }

    return dp[p][i] = ans;
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, arr, 0, k);
    }
};