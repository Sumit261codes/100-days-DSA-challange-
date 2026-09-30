class Solution {
public:
    bool fun(string &s, int i, string &open) {
        if(i == s.size()) {
            return open.empty();
        }

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            open.push_back(s[i]);
            return fun(s, i + 1, open);
        }

        if(open.empty()) {
            return false;
        }

        char x = open.back();
        open.pop_back();

        if(s[i] == ')' && x != '(') return false;
        if(s[i] == '}' && x != '{') return false;
        if(s[i] == ']' && x != '[') return false;

        return fun(s, i+1 , open);
    }

    bool isValid(string s) {
        string open = "";
        return fun(s, 0, open);
    }
};