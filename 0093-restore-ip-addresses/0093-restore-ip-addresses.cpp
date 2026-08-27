class Solution {
public:
    void solve(int i, string s, string cur, vector<string>& ans, int parts) {
        if (parts == 4) {
            if (i == s.size()) {
                cur.pop_back();
                ans.push_back(cur);
            }
            return;
        }

        for (int len = 1; len <= 3 && i + len <= s.size(); len++) {
            string x = s.substr(i, len);

            if (x.size() > 1 && x[0] == '0') break;

            int num = stoi(x);
            if (num > 255) break;

            solve(i + len, s, cur + x + ".", ans, parts + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0, s, "", ans, 0);
        return ans;
    }
};