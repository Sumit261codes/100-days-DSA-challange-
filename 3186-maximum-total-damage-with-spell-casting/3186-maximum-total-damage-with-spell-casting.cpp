long long dp[100003];

long long fun(int i,vector<int>&nums,map<int,int>&m1){
    if(i>=nums.size()) return 0;

    int id=nums.size();

    if(dp[i]!=-1) return dp[i];

    for(int j=i+1;j<nums.size();j++){
        if(nums[j]>nums[i]+2){
            id=j;
            break;
        }
    }

    long long t=1LL*nums[i]*m1[nums[i]] + fun(id,nums,m1);
    long long nt=fun(i+1,nums,m1);

    return dp[i]=max(t,nt);
}



class Solution {
public:
    long long maximumTotalDamage(vector<int>& nums) {
        map<int,int>m1;

        for(auto a:nums) m1[a]++;

        vector<int>v1;

        for(auto a:m1){
            v1.push_back(a.first);
        }

        memset(dp,-1,sizeof(dp));
        return fun(0,v1,m1);
    }
};