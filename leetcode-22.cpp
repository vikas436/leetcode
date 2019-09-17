// 22. Generate Parentheses

class Solution {
public:
    bool isValid(string str) {
        stack<char>stk;
        for(int i=0;i<str.size();i++) {
            if(str[i]=='(') {
                stk.push(')');
            } else {
                if(!stk.empty() && stk.top()==')') {
                    stk.pop();
                } else return false;
            }
        }
        return true;
    }
    void paren(vector<string>&res,string &str, int open, int closed, int sz) {
        if(open==closed && closed==sz) {
            if(!isValid(str)) return;
            res.push_back(str);
            return;
        }
        if(open>sz || closed>sz) return;
        if(open<sz) {
            str.push_back('(');
            paren(res,str,open+1,closed,sz);
            str.pop_back();    
        }
        if(closed<sz) {
            str.push_back(')');
            paren(res,str,open,closed+1,sz);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        if(n==0) return res;
        string str;
        paren(res, str, 0, 0, n);
        return res;
    }
};
