int dp[101][101];
bool fun(int i, int j, string &s1, string &s2, string &s3) {

    if(i >=s1.size() && j >=s2.size()) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int k=i+j;
    int a=0;
    int b=0;
    if(i < s1.size() && s1[i] == s3[k]) {

         a = fun(i+1,j,s1,s2,s3);
    }

    if(j < s2.size() && s2[j] == s3[k]) {

         b = fun(i,j+1,s1,s2,s3);
    }

    return dp[i][j] = a||b;
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size())
            return false;
        memset(dp, -1, sizeof(dp));
        return fun(0,0,s1,s2,s3);
    }
};