class Solution {
public:
    int solve(vector<int>& nums, int i, bool first, vector<vector<int>>& dp) {
        if(i >= nums.size())
            return 0;

        if(i == nums.size() - 1 && first)
            return 0;

        if(dp[i][first] != -1)
            return dp[i][first];

        int take = nums[i] + solve(nums, i + 2, first || i == 0, dp);
        int skip = solve(nums, i + 1, first, dp);

        return dp[i][first] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(nums, 0, false, dp);
    }
};