// 6. ZigZag Conversion
// try to do it in O(N) make formula....

class Solution {
public:
    string convert(string s, int num) {
        if(num==s.size() || num<=1) return s;
        map<int,vector<char>>mp;
        int i=0,cnt=0;
        bool flg=true;
        while(i<s.size()) {
            mp[cnt].push_back(s[i]);
            if(flg) {
                cnt++;
            } else cnt--;
            if(cnt==0) flg=true;
            if(cnt+1==num) flg=false;
            i++;
        }
        string res="";
        for(auto it=mp.begin();it!=mp.end();it++) {
            vector<char>vec = it->second;
            for(int i=0;i<vec.size();i++) 
                res+=vec[i];
        }
        return res;
    }    
};
