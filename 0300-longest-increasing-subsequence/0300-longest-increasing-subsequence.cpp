int dp[2501][2501];

int fun(int i, int p, vector<int>& nums) {
    if (i >= nums.size()) return 0;

    if (dp[i][p + 1] != -1)
        return dp[i][p + 1];

    int take = 0;

    if (p == -1 || nums[i] > nums[p]) {
        take = 1 + fun(i + 1, i, nums);
    }

    int notTake = fun(i + 1, p, nums);

    return dp[i][p + 1] = max(take, notTake);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return fun(0, -1, nums);
    }
};