class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,long long> mp;

        for(int x : power)
            mp[x] += x;

        vector<int> a;
        vector<long long> val;

        for(auto it : mp) {
            a.push_back(it.first);
            val.push_back(it.second);
        }

        int n = a.size();
        vector<long long> dp(n);

        dp[0] = val[0];

        for(int i = 1; i < n; i++) {
            dp[i] = dp[i-1];

            int j = i - 1;

            while(j >= 0 && a[j] >= a[i] - 2)
                j--;

            if(j >= 0)
                dp[i] = max(dp[i], dp[j] + val[i]);
            else
                dp[i] = max(dp[i], val[i]);
        }

        return dp[n-1];
    }
};