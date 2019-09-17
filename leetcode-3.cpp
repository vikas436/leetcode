// 3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int max=0,pnt=0;
        for(int i=0;i<s.size();i++) {
            if(mp.find(s[i])==mp.end()) {
                mp[s[i]]=i;
                if(mp.size()>max) max=mp.size();
            } else {
                int ind = mp[s[i]];
                pnt=ind;
                while(ind>=0) {
                    if(mp.find(s[ind])!=mp.end() && mp[s[ind]]<=pnt) {
                        mp.erase(s[ind]);
                    } else break;
                    ind--;
                }
                mp[s[i]]=i;
            }
            if(mp.size()>max) max=mp.size();
        }
        return max;
    }
};
