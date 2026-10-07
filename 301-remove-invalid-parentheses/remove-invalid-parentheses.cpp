class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l) l--;
                else r++;
            }
        }

        unordered_set<string> res;
        string path;
        dfs(s, 0, l, r, 0, path, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int i, int l, int r, int open,
             string& path, unordered_set<string>& res) {
        if (i == (int)s.size()) {
            if (l == 0 && r == 0 && open == 0) res.insert(path);
            return;
        }

        char c = s[i];

        if (c == '(' && l > 0) {
            dfs(s, i + 1, l - 1, r, open, path, res);
        } else if (c == ')' && r > 0) {
            dfs(s, i + 1, l, r - 1, open, path, res);
        }

        path.push_back(c);
        if (c == '(') {
            dfs(s, i + 1, l, r, open + 1, path, res);
        } else if (c == ')') {
            if (open > 0) dfs(s, i + 1, l, r, open - 1, path, res);
        } else {
            dfs(s, i + 1, l, r, open, path, res);
        }
        path.pop_back();
    }
};