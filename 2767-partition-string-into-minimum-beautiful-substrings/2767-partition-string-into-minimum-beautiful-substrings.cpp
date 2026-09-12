int dp[16];

bool check(string s) {
    if(s[0] == '0')
        return false;

    int num = 0;

    for(int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }

    while(num % 5 == 0)
        num /= 5;

    return num == 1;
}

int fun(int i, string& s) {
    if(i >= s.size())
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int ans = 100;
    string temp = "";

    for(int j = i; j < s.size(); j++) {
        temp += s[j];

        if(check(temp)) {
            int c = 1 + fun(j + 1, s);

            if(c < ans)
                ans = c;
        }
    }

    return dp[i] = ans;
}

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        memset(dp, -1, sizeof(dp));

        int ans = fun(0, s);

        if(ans == 100)
            return -1;

        return ans;
    }
};