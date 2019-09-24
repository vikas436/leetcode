// 49	Group Anagrams    	
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>>res;
        map<string,vector<string>>mp;
        for(int i=0;i<arr.size();i++) {
            string st = arr[i];
            sort(st.begin(),st.end());
            mp[st].push_back(arr[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
