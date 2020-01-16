// https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void generate(vector<string>&res, int l, int r, int n, string &str) {
        if(l>=n && r>=n) {
            res.push_back(str);
            return;
        } else if(l<r) return;
        if(l<n) {
            str.push_back('(');
            generate(res, l+1, r, n, str);
            str.pop_back();
        }
        if(r<n) {
            str.push_back(')');
            generate(res, l, r+1, n, str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string str;
        generate(res, 0, 0, n, str);
        return res;
    }
};
