// 17. Letter Combinations of a Phone Number

class Solution {
public:
    map<char,string>mp;
    void setMap() {
        mp.insert(make_pair('2',"abc"));
        mp.insert(make_pair('3',"def"));
        mp.insert(make_pair('4',"ghi"));
        mp.insert(make_pair('5',"jkl"));
        mp.insert(make_pair('6',"mno"));
        mp.insert(make_pair('7',"pqrs"));
        mp.insert(make_pair('8',"tuv"));
        mp.insert(make_pair('9',"wxyz"));
    }

    void phone(string digits, string &str,  vector<string>&res,int k, int num) {
        if(str.size()>=k) {
            res.push_back(str);
            return ;
        }
        if(num>=k) return;
        char ind = digits[num];
        for(int i=0;i<mp[ind].size();i++) {
            str.push_back(mp[ind][i]);
            phone(digits,str,res,k,num+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        setMap();
        vector<string>res;
        if(digits.size()==0) return res;
        string st="";
        phone(digits,st,res,digits.size(),0);
        return res;
    }
};
