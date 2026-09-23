int dp[1001][1001];

int fun(int i,int j,string &s,string &t){
    if(i>=s.size() || j>=t.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int m=0;

    if(s[i]==t[j]){
        int a=1+fun(i+1,j+1,s,t);
        m=max(m,a);
    }else{
        int a=fun(i+1,j,s,t);
        int b=fun(i,j+1,s,t);

        m=max(m,a);
        m=max(m,b);
    }

    return dp[i][j]=m;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int lcs = fun(0, 0, word1, word2);
        return word1.size() + word2.size() - 2 * lcs;
    }
};