int dp[501][501];

int fun(int i, int j, vector<int>& nums1, vector<int>& nums2) {

    if(i >= nums1.size() || j >= nums2.size())
        return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int m = 0;

    if(nums1[i]==nums2[j]) {

        int a = 1 + fun(i+1,j+1,nums1,nums2);

        m = max(m, a);

    }
    else {

        int a = fun(i+1,j,nums1,nums2);
        int b = fun(i,j+1,nums1,nums2);

        m = max(m,a);
        m = max(m,b);
    }

    return dp[i][j] = m;
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        memset(dp,-1,sizeof(dp));

        return fun(0,0,nums1,nums2);
    }
};