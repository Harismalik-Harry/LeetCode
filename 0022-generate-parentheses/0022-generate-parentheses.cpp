class Solution {
public:
    void helper(string &p, vector<string> &res, int c1, int c2, int n) {
        if (c1 < n) {
            p.push_back('(');
            helper(p, res, c1 + 1, c2, n);
            p.pop_back();
        }
        if (c2 < c1) {
            p.push_back(')');
            helper(p, res, c1, c2 + 1, n);
            p.pop_back();
        }
        if (c1 + c2 == 2 * n) {
            res.push_back(p);
            return;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string p;
        helper(p, res, 0, 0, n);
        return res;
    }
};