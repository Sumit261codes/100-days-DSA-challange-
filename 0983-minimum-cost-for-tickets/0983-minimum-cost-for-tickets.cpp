int dp[366];

int fun(int i, vector<int>& days, vector<int>& costs) {
    if(i >= days.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int a = costs[0] + fun(i + 1, days, costs);

    int ide = i;
    while(ide < days.size() && days[ide] < days[i] + 7)
        ide++;
    int b = costs[1] + fun(ide, days, costs);

    ide = i;
    while(ide < days.size() && days[ide] < days[i] + 30)
        ide++;
    int c = costs[2] + fun(ide, days, costs);

    return dp[i] = min(a, min(b, c));
}

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return fun(0, days, costs);
    }
};